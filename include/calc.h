/*
** calc.h for eval_expr in /home/hervie_g/epidev/projects/eval_expr
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Fri Oct 26 15:26:24 2012 guillaume hervier
** Last update Fri Oct 26 19:28:44 2012 guillaume hervier
*/

#ifndef CALC_H_
#define CALC_H_

#include "stack.h"

#define CALC_OPS	5

typedef struct s_calc_op t_calc_op;
struct s_calc_op
{
  char			op;
  int			(*handler)(int, int);
};

int			calc_eval_stack(t_stack *);

int			calc_op_add(int, int);
int			calc_op_sub(int, int);
int			calc_op_mul(int, int);
int			calc_op_div(int, int);
int			calc_op_mod(int, int);

extern t_calc_op	g_op_handlers[CALC_OPS];

#endif
