/*
** eval_expr.c for eval_expr in /home/hervie_g/epidev/projects/eval_expr
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Mon Oct 22 17:17:35 2012 guillaume hervier
** Last update Fri Oct 26 19:38:45 2012 guillaume hervier
*/

#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"
#include "lexer.h"
#include "stack.h"
#include "npi.h"
#include "calc.h"

int		eval_expr(char *expr)
{
  t_stack	*stack;
  int		result;

  stack = npi_make_stack(expr);
  result = calc_eval_stack(stack);
  stack_destroy(stack);
  return (result);
}
