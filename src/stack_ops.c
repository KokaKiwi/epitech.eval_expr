/*
** stack_ops.c for eval_expr in /home/hervie_g/epidev/projects/eval_expr
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Fri Oct 26 10:46:20 2012 guillaume hervier
** Last update Fri Oct 26 17:19:20 2012 guillaume hervier
*/

#include <stdlib.h>
#include "stack.h"

t_stack_node		*stack_peek(t_stack *stack)
{
  return (stack->tail);
}

t_stack_node		*stack_get_node_at(t_stack *stack, int pos)
{
  t_stack_node		*cur;

  cur = stack->tail;
  if (pos > 0)
    {
      while (cur->prev != NULL)
	cur = cur->prev;
      while (pos--)
	cur = cur->next;
    }
  else
    {
      while (pos--)
	cur = cur->prev;
    }
  return (cur);
}

void			stack_insert_after(t_stack_node *prev,
					   t_stack_node *node)
{
  if (prev->next)
    prev->next->prev = node;
  node->prev = prev;
  node->next = prev->next;
  prev->next = node;
}

t_stack_node		*stack_get_relative(t_stack_node *start,
					    int offset)
{
  while (offset-- && start->next != NULL)
    start = start->next;
  if (offset >= 0 && start->next == NULL)
    return (NULL);
  return (start);
}

int			stack_size(t_stack *stack)
{
  t_stack_node		*cur;
  int			size;

  size = 0;
  cur = stack->tail;
  while (cur != NULL)
    {
      size++;
      cur = cur->prev;
    }
  return (size);
}
