/*
** stack.h for bistromathique in /home/hervie_g/epidev/projects/bistromathique/tests/test02
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Thu Oct 18 09:40:36 2012 guillaume hervier
** Last update Fri Oct 26 15:24:07 2012 guillaume hervier
*/

#ifndef STACK_H_
#define STACK_H_

typedef struct s_stack		t_stack;
typedef struct s_stack_node	t_stack_node;

struct s_stack
{
  t_stack_node	*tail;
};

struct s_stack_node
{
  int		type;
  void		*data;
  t_stack_node	*next;
  t_stack_node	*prev;
};

t_stack		*stack_create(void);

void		stack_destroy(t_stack *);

t_stack_node	*stack_push(t_stack *, int, void *);
t_stack_node	*stack_pop(t_stack *);

t_stack_node	*stack_peek(t_stack *);

void		stack_push_node(t_stack *, t_stack_node *);

t_stack_node	*stack_node_create(int, void *);

void		stack_node_remove(t_stack *, t_stack_node *);
void		stack_node_destroy(t_stack *, t_stack_node *);

void		stack_insert_node_after(t_stack_node *, t_stack_node *);

t_stack_node	*stack_get_relative(t_stack_node *, int);

#endif
