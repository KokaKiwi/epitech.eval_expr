/*
** calc_ops.c for eval_expr in /home/hervie_g/epidev/projects/eval_expr
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Fri Oct 26 19:23:20 2012 guillaume hervier
** Last update Fri Oct 26 19:29:32 2012 guillaume hervier
*/

#include "my.h"
#include "calc.h"

t_calc_op	g_op_handlers[CALC_OPS] = {
  { '+', &calc_op_add },
  { '-', &calc_op_sub },
  { '*', &calc_op_mul },
  { '/', &calc_op_div },
  { '%', &calc_op_mod }
};

int		calc_op_add(int a, int b)
{
  return (a + b);
}

int		calc_op_sub(int a, int b)
{
  return (a - b);
}

int		calc_op_mul(int a, int b)
{
  return (a * b);
}

int		calc_op_div(int a, int b)
{
  return (a / b);
}

int		calc_op_mod(int a, int b)
{
  return (a % b);
}
