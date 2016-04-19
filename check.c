/*
** check.c for sudoku in /home/bogard_t/rendu/sudoku/ex00
**
** Made by thomas bogard
** Login   <bogard_t@epitech.net>
**
** Started on  Wed Oct  8 17:59:57 2014 thomas bogard
** Last update Fri Apr  8 21:21:26 2016 Thomas Bogard
*/

#include "sudoku.h"

static int	check_line(char **tab, int position, int number)
{
  int	row;
  int	column;

  row = position / 9 + 1;
  column = 0;
  while (tab[row][column] != '\0')
    {
      if (tab[row][column] == (char)(number + '0'))
	return (0);
      column++;
    }
  return (1);
}

static int	check_column(char **tab, int position, int number)
{
  int	row;
  int	column;

  row = 1;
  column = position % 9;
  while (row < 10)
    {
      if (tab[row][column] == (char)(number + '0'))
	return (0);
      row++;
    }
  return (1);
}

static int	check_block(char **tab, int	position, int number)
{
  int	case_row;
  int	case_column;
  int	current_row;
  int	current_column;

  case_row = position / 9 + 1;
  case_column = position % 9;
  current_row = case_row - ((case_row - 1) % 3);
  while (current_row < case_row - ((case_row - 1) % 3) + 3)
    {
      current_column = case_column - (case_column % 3);
      while (current_column < case_column - (case_column % 3) + 3)
	{
	  if (tab[current_row][current_column] == (char)(number + '0'))
	    return (0);
	  current_column++;
	}
      current_row++;
    }
  return (1);
}

int	check_all(char **tab, int position, int number)
{
  if (check_line(tab, position, number))
    if (check_column(tab, position, number))
      if (check_block(tab, position, number))
	return (1);
  return (0);
}
