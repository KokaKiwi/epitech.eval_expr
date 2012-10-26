/*
** tokens.c for bistromathique in /home/hervie_g/epidev/projects/bistromathique/tests/test02
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Thu Oct 18 18:53:14 2012 guillaume hervier
** Last update Fri Oct 26 10:03:33 2012 guillaume hervier
*/

#include <stdlib.h>
#include "my.h"
#include "lexer.h"

char                    *lex_find_operator(t_lex_context *context)
{
  char                  *buf;
  char                  *expr;

  buf = NULL;
  expr = context->expr;
  if (*expr == '-' || *expr == '+' || *expr == '*'
      || *expr == '/' || *expr == '%')
    {
      buf = malloc(2);
      buf[0] = *expr;
      buf[1] = 0;
      context->expr++;
    }
  return (buf);
}

char			*lex_findnum_createbuf(char *start, char *end,
					       int sign)
{
  char			*buf;

  buf = NULL;
  if (end - start > 0)
    {
      buf = malloc(end - start + sign + 1);
      buf[0] = '-';
      my_strncpy(buf + sign, start, end - start);
    }
  return (buf);
}

char                    *lex_find_number(t_lex_context *context)
{
  char                  *buf;
  char                  *expr;
  char                  m;
  char                  search;

  m = 1;
  buf = NULL;
  while (*(context->expr) == '-' || *(context->expr) == '+')
    {
      if (*(context->expr) == '-')
        m *= -1;
      context->expr++;
    }
  expr = context->expr;
  search = 1;
  while (*expr && search)
    {
      if (*expr < '0' || *expr > '9')
	search = 0;
      else
	expr++;
    }
  buf = lex_findnum_createbuf(context->expr, expr, m == 1 ? 0 : 1);
  context->expr = expr;
  return (buf);
}

