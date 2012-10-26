/*
** main.c for eval_expr in /home/hervie_g/epidev/projects/eval_expr
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Mon Oct 22 17:14:30 2012 guillaume hervier
** Last update Mon Oct 22 17:17:22 2012 guillaume hervier
*/

#include "my.h"
#include "eval_expr.h"

int	main(int argc, char **argv)
{
  if (argc > 1)
    {
      my_put_nbr(eval_expr(argv[1]));
      my_putchar('\n');
    }
  return (0);
}
