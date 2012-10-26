/*
** stack.c for bistromathique in /home/hervie_g/epidev/projects/bistromathique/tests/test02
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Thu Oct 18 09:59:16 2012 guillaume hervier
** Last update Fri Oct 26 10:41:26 2012 guillaume hervier
*/

#include <stdlib.h>
#include "stack.h"

t_stack		*stack_create()
{
  t_stack	*stack;

  stack = malloc(sizeof(t_stack));
  if (stack)
    stack->tail = NULL;
  return (stack);
}

void		stack_destroy(t_stack *stack)
{
  t_stack_node	*cur;

  if (stack)
    {
      cur = stack->tail;
      while (cur != NULL)
	{
	  stack_node_destroy(stack, cur);
	  cur = cur->prev;
	}
      free(stack);
    }
}

t_stack_node	*stack_push(t_stack *stack, int type, void *data)
{
  t_stack_node	*node;

  node = NULL;
  if (stack)
    {
      node = stack_node_create(type, data);
      stack_push_node(stack, node);
    }
  return (node);
}

t_stack_node	*stack_pop(t_stack *stack)
{
  t_stack_node	*node;

  node = NULL;
  if (stack)
    {
      node = stack->tail;
      if (node)
	stack_node_remove(stack, node);
    }
  return (node);
}

void		stack_push_node(t_stack *stack, t_stack_node *node)
{
  if (stack && node)
    {
      if (stack->tail != 0)
	{
	  stack->tail->next = node;
	  node->prev = stack->tail;
	}
      stack->tail = node;
    }
}

