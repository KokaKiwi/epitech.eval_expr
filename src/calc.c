/*
** calc.c for eval_expr in /home/hervie_g/epidev/projects/eval_expr
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Fri Oct 26 15:31:31 2012 guillaume hervier
** Last update Fri Oct 26 19:42:16 2012 guillaume hervier
*/

#include <stdlib.h>
#include "my.h"
#include "calc.h"
#include "stack.h"
#include "lexer.h"
#include "npi.h"

int		calc_do(int left, int right,
			t_stack_node *op)
{
  int		i;
  t_calc_op	*top;
  t_lex_token	*tok;
  char		cop;

  i = 0;
  tok = op->data;
  cop = tok->matched[0];
  while (i < CALC_OPS)
    {
      top = &(g_op_handlers[i]);
      if (top->op == cop)
	return (top->handler(left, right));
      i++;
    }
  return (0);
}

void		calc_loop(t_stack *stack,
			  t_stack_node *node)
{
  t_stack_node	*right;
  t_stack_node	*op;
  int		search;

  search = 1;
  while (search && right != NULL && op != NULL)
    {
      right = node->next;
      op = right->next;
      if (node->type == NPI_TYPE_NUMBER && right->type == NPI_TYPE_NUMBER
	  && op->type == NPI_TYPE_OPERATOR)
	{
	  search = 0;
	  node->value = calc_do(node->value,
				right->value, op);
	  stack_node_destroy(stack, right);
	  stack_node_destroy(stack, op);
	}
      else
	{
	  node = right;
	  right = op;
	  op = op->next;
	}
    }
}

int		calc_resolve(t_stack *stack,
			     t_stack_node *node)
{
  int		right;
  t_stack_node	*nright;
  t_stack_node	*nop;

  while (node->next != NULL)
    calc_loop(stack, node);
  return (node->value);
}

int		calc_eval_stack(t_stack *stack)
{
  t_stack_node	*start;

  start = stack->tail;
  while (start->prev != NULL)
    start = start->prev;
  return (calc_resolve(stack, start));
}
