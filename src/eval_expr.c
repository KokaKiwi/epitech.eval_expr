/*
** eval_expr.c for eval_expr in /home/hervie_g/epidev/projects/eval_expr
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Mon Oct 22 17:17:35 2012 guillaume hervier
** Last update Fri Oct 26 16:54:04 2012 guillaume hervier
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"
#include "lexer.h"
#include "stack.h"
#include "npi.h"
#include "calc.h"

void		stack_display(t_stack *stack)
{
  t_stack_node	*cur;

  cur = stack->tail;
  while (cur != NULL)
    {
      my_putstr(((t_lex_token *) cur->data)->matched);
      my_putchar('\n');
      cur = cur->prev;
    }
}

int		eval_expr(char *expr)
{
  t_stack	*stack;
  int		result;

  stack = npi_make_stack(expr);
  stack_display(stack);
  result = calc_eval_stack(stack);
  stack_destroy(stack);
  return (result);
}
