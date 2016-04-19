/*
** sudoku.h for sudoku in /home/bogard_t/rendu/sudoku/ex00
**
** Made by thomas bogard
** Login   <bogard_t@epitech.net>
**
** Started on  Wed Oct  8 18:01:07 2014 thomas bogard
** Last update Fri Apr  8 21:25:51 2016 Thomas Bogard
*/

#ifndef		_SUDOKU_H_
# define	_SUDOKU_H_

# include	<unistd.h>
# include	<stdio.h>

# define	usage	"Usage : ./sudoku <first row> <snd row> <third row> ... <nineth row>"

/*
** check.c
*/
int			check_all(char **tab, int position, int number);

/*
** display.c
*/
void			display_tab(char **tab);

#endif		/* !_SUDOKU_H */
