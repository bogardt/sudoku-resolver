/*
** sudoku.c for sudoku in /home/bogard_t/rendu/sudoku/ex00
**
** Made by thomas bogard
** Login   <bogard_t@epitech.net>
**
** Started on  Wed Oct  8 18:00:48 2014 thomas bogard
** Last update Fri Apr  8 21:41:47 2016 Thomas Bogard
*/

# include	"sudoku.h"

static int	check_chars(char *str)
{
  int	i;

  i = -1;
  while (++i < 9)
    if (str[i] != '.' && (str[i] < '1' || str[i] > '9'))
      return (0);
  return (1);
}

static int	count_chars(char **argv)
{
  int	i;
  int	j;
  int	count;

  i = 0;
  count = 0;
  while (++i < 10)
    {
      j = -1;
      while (++j < 9)
	if (argv[i][j] >= '1' && argv[i][j] <= '9')
	  count++;
    }
  return (count >= 17 ? 1 : 0);
}

static int	resolve(char **tab, int position)
{
  int	row;
  int	column;
  int	number;

  if (position == 81)
    return (1);
  row = position / 9 + 1;
  column = position % 9;
  if (tab[row][column] != '.')
    return (resolve(tab, position + 1));
  number = 1;
  while (number < 10)
    {
      if (check_all(tab, position, number))
	{
	  tab[row][column] = (char)(number + '0');
	  if (resolve(tab, position + 1))
	    return (1);
	}
      number++;
    }
  tab[row][column] = '.';
  return (0);
}

/* int	main(int argc, char **argv) */
int	main()
{
  int	i;

  char *argv[11] =
    {
      "./sudoku",
      "9...7....",
      "2...9..53",
      ".6..124..",
      "84...1.9.",
      "5.....8..",
      ".31..4...",
      "..37..68.",
      ".9..5.741",
      "47.......",
      NULL
    };
  i = 0;
  /* if (argc != 10 || count_chars(argv) == 0) */
  /*   fprintf(stderr, "%s\n", usage); */
  /* else */
    {
      while (++i < 10)
	{
	  if (!check_chars(argv[i]))
	    {
	      fprintf(stderr, "%s\n", "sudoku need 10 row");
	      return (0);
	    }
	}
      if (resolve(argv, 0))
	display_tab(argv);
      else
	fprintf(stderr, "%s\n", "resolve failed");
    }
  return (0);
}
