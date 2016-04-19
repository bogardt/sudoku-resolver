/*
** print_str.c for sudoku in /home/bogard_t/rendu/sudoku/ex00
**
** Made by thomas bogard
** Login   <bogard_t@epitech.net>
**
** Started on  Wed Oct  8 18:00:14 2014 thomas bogard
** Last update Fri Apr  8 21:26:11 2016 Thomas Bogard
*/

#include "sudoku.h"

void	display_tab(char **tab)
{
  int	row;
  int	column;

  row = 1;
  while (row < 10)
    {
      column = 0;
      while (column < 9)
	{
	  printf("%c", tab[row][column]);
	  if (column < 8)
	    putchar(' ');
	  column++;
	}
      printf("\n");
      row++;
    }
}
