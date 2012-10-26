/*
** lexer.c for bistromathique in /home/hervie_g/epidev/projects/bistromathique/tests/test02
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Thu Oct 18 13:40:32 2012 guillaume hervier
** Last update Fri Oct 26 18:54:17 2012 guillaume hervier
*/

#include <stdlib.h>
#include "lexer.h"
#include "errors.h"
#include "my.h"

t_lex_context		*lex_context_create(char *expr)
{
  t_lex_context		*context;

  context = malloc(sizeof(t_lex_context));
  context->expr = expr;
  context->state = LEX_STATE_NUMBER;
  return (context);
}

t_lex_token		*lex_gettoken_paren(t_lex_context *context)
{
  t_lex_token		*token;
  char			*expr;
  int			type;

  token = NULL;
  type = 0;
  expr = context->expr;
  if (*expr == '(' || *expr == ')')
    {
      if (*expr == '(' && context->state == LEX_STATE_NUMBER)
	type = LEX_TYPE_OPEN_PAREN;
      else if (*expr == ')' && context->state == LEX_STATE_OPERATOR)
	type = LEX_TYPE_CLOSE_PAREN;
      else
	lex_error("Wrong paren position!");
      if (type)
	{
	  token = malloc(sizeof(t_lex_token));
	  token->matched = NULL;
	  token->type = type;
	  context->expr++;
	}
    }
  return (token);
}

t_lex_token             *lex_gettoken_number(t_lex_context *context)
{
  t_lex_token		*token;
  char			*matched;

  matched = lex_find_number(context);
  token = NULL;
  if (matched)
    {
      token = malloc(sizeof(t_lex_token));
      token->matched = matched;
      token->type = LEX_TYPE_NUMBER;
    }
  else
    lex_error("TYPE 2.");
  context->state = LEX_STATE_OPERATOR;
  return (token);
}

t_lex_token             *lex_gettoken_op(t_lex_context *context)
{
  t_lex_token		*token;
  char			*matched;

  matched = lex_find_operator(context);
  token = NULL;
  if (matched)
    {
      token = malloc(sizeof(t_lex_token));
      token->matched = matched;
      token->type = LEX_TYPE_OPERATOR;
      token->assoc = LEX_ASSOC_LEFT;
      if (token->matched[0] == '+' || token->matched[0] == '-')
	token->priority = 1;
      else
	token->priority = 2;
    }
  else if (*(context->expr))
    lex_error("TYPE 3.");
  context->state = LEX_STATE_NUMBER;
  return (token);
}

t_lex_token		*lex_gettoken(t_lex_context *context)
{
  t_lex_token		*token;

  while (*(context->expr) == ' ')
    context->expr++;
  token = lex_gettoken_paren(context);
  if (!token)
    {
      if (context->state == LEX_STATE_NUMBER)
	token = lex_gettoken_number(context);
      else if (context->state == LEX_STATE_OPERATOR)
	token = lex_gettoken_op(context);
    }
  return (token);
}
