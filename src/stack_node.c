/*
** stack_node.c for bistromathique in /home/hervie_g/epidev/projects/bistromathique/tests/test02
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Thu Oct 18 14:42:17 2012 guillaume hervier
** Last update Fri Oct 26 19:16:50 2012 guillaume hervier
*/

#include <stdlib.h>
#include "stack.h"
#include "lexer.h"

t_stack_node	*stack_node_create(int type, void *data)
{
  t_stack_node	*node;

  node = malloc(sizeof(t_stack_node));
  if (node)
    {
      node->type = type;
      node->data = data;
      node->next = NULL;
      node->prev = NULL;
    }
  return (node);
}

void		stack_node_remove(t_stack *stack, t_stack_node *node)
{
  if (stack && node)
    {
      if (node->prev != NULL)
	node->prev->next = node->next;
      if (node->next != NULL)
	node->next->prev = node->prev;
      if (stack->tail == node)
	stack->tail = node->prev;
    }
}

void		stack_node_destroy(t_stack *stack, t_stack_node *node)
{
  if (stack && node)
    {
      stack_node_remove(stack, node);
      free(((t_lex_token *) node->data)->matched);
      free(node->data);
      free(node);
    }
}
