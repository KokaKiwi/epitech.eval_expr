/*
** error.c for bistromathique in /home/hervie_g/epidev/projects/bistromathique/tests/test02
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Thu Oct 18 18:10:27 2012 guillaume hervier
** Last update Fri Oct 26 10:03:50 2012 guillaume hervier
*/

#include "errors.h"
#include "my.h"

void	lex_error(char *msg)
{
  my_putstr("Error: ");
  my_putstr(msg);
  my_putchar('\n');
}
