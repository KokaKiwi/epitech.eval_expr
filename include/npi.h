/*
** npi.h for eval_expr in /home/hervie_g/epidev/projects/eval_expr
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Fri Oct 26 09:51:49 2012 guillaume hervier
** Last update Fri Oct 26 14:50:40 2012 guillaume hervier
*/

#ifndef NPI_H_
#define NPI_H_

#include "stack.h"

#define NPI_TYPE_OPERATOR	0
#define NPI_TYPE_NUMBER		1
#define NPI_TYPE_PAREN		2

t_stack	*npi_make_stack(char *);

#endif
