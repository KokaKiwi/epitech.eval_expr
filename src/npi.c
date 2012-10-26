/*
** npi.c for eval_expr in /home/hervie_g/epidev/projects/eval_expr
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Fri Oct 26 09:51:24 2012 guillaume hervier
** Last update Fri Oct 26 15:07:05 2012 guillaume hervier
*/

#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "lexer.h"
#include "stack.h"
#include "my.h"

void		put_op_in_stack(t_stack *stack, t_stack *ops,
				t_lex_token *op)
{
  t_stack_node	*cur;
  t_lex_token	*tok;
  int		search;

  search = 1;
  while (search)
    {
      cur = stack_peek(ops);
      if (cur != NULL && cur->type == NPI_TYPE_OPERATOR)
	{
	  tok = cur->data;
	  if ((op->assoc == LEX_ASSOC_LEFT
	       && op->priority <= tok->priority) ||
	      (op->assoc == LEX_ASSOC_RIGHT
	       && op->priority < tok->priority))
	    stack_push_node(stack, stack_pop(ops));
	  else
	    search = 0;
	}
      else
	search = 0;
    }
  stack_push(ops, NPI_TYPE_OPERATOR, op);
}

int		npi_handle_paren(t_stack *stack, t_stack *ops)
{
  t_stack_node	*cur;

  while ((cur = stack_pop(ops)) != NULL
	 && cur->type != NPI_TYPE_PAREN)
    {
      stack_push_node(stack, cur);
    }
  if (cur == NULL)
    {
      my_putstr("Error: Missing parenthesis.\n");
      return (1);
    }
  return (0);
}

void		npi_handle_token(t_stack *stack, t_stack *ops,
			     t_lex_token *token)
{
  if (token->type == LEX_TYPE_NUMBER)
    stack_push(stack, NPI_TYPE_NUMBER, token);
  else if (token->type == LEX_TYPE_OPERATOR)
    put_op_in_stack(stack, ops, token);
  else if (token->type == LEX_TYPE_OPEN_PAREN)
    stack_push(ops, NPI_TYPE_PAREN, token);
  else if (token->type == LEX_TYPE_CLOSE_PAREN)
    npi_handle_paren(stack, ops);
}

t_stack		*npi_make_stack(char *expr)
{
  t_stack	*stack;
  t_stack	*ops;
  t_lex_context	*context;
  t_lex_token	*token;
  t_stack_node	*cur;

  context = lex_context_create(expr);
  stack = stack_create();
  ops = stack_create();
  while ((token = lex_gettoken(context)) != NULL)
    {
      npi_handle_token(stack, ops, token);
    }
  while ((cur = stack_pop(ops)) != NULL)
    {
      if (cur->type == NPI_TYPE_PAREN)
	my_putstr("Error: Missing parenthesis.\n");
      else
	stack_push_node(stack, cur);
    }
  stack_destroy(ops);
  return (stack);
}
