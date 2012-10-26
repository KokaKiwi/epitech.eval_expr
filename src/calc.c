/*
** calc.c for eval_expr in /home/hervie_g/epidev/projects/eval_expr
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Fri Oct 26 15:31:31 2012 guillaume hervier
** Last update Fri Oct 26 17:14:04 2012 guillaume hervier
*/

#include <stdlib.h>
#include "my.h"
#include "calc.h"
#include "stack.h"
#include "lexer.h"
#include "npi.h"

int		calc_number(t_stack_node *node)
{
  t_lex_token	*tok;

  tok = node->data;
  return (my_getnbr(tok->matched));
}

int		calc_do(int left, int right,
			t_stack_node *op)
{
  my_putstr("Op: ");
  my_put_nbr(left);
  my_putstr(" + ");
  my_put_nbr(right);
  my_putchar('\n');
  return (left + right);
}

int		calc_resolve(t_stack *stack,
			     t_stack_node *node)
{
  int		left;
  int		right;
  t_stack_node	*nright;
  t_stack_node	*nop;

  left = calc_number(node);
  while (node->next != NULL)
    {
      nright = node->next;
      if (nright->next->type == NPI_TYPE_OPERATOR)
	{
	  nop = nright->next;
	  right = calc_number(nright);
	}
      else
	{
	  right = calc_resolve(stack, nright);
	}
      left = calc_do(left, right, nop);
      my_putstr("Left: ");
      my_put_nbr(left);
      my_putchar('\n');
      stack_node_destroy(stack, nop);
    }
  stack_node_destroy(stack, node);
  return (left);
}

int		calc_eval_stack(t_stack *stack)
{
  t_stack_node	*start;

  start = stack->tail;
  while (start->prev != NULL)
    start = start->prev;
  return (calc_resolve(stack, start));
}
