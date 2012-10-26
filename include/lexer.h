/*
** lexer.h for bistromathique in /home/hervie_g/epidev/projects/bistromathique/tests/test02
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Thu Oct 18 13:39:57 2012 guillaume hervier
** Last update Fri Oct 26 18:49:46 2012 guillaume hervier
*/

#ifndef LEXER_H_
#define LEXER_H_

#define LEX_ASSOC_RIGHT		0
#define LEX_ASSOC_LEFT		1

#define LEX_TYPE_OPERATOR	0
#define LEX_TYPE_NUMBER		1
#define LEX_TYPE_OPEN_PAREN	2
#define LEX_TYPE_CLOSE_PAREN	3

#define LEX_STATE_OPERATOR	0
#define LEX_STATE_NUMBER	1

typedef struct s_lex_context	t_lex_context;
typedef struct s_lex_token	t_lex_token;

struct s_lex_context
{
  char	*expr;
  int	state;
};

struct s_lex_token
{
  int	type;
  int	priority;
  int	assoc;
  char	*matched;
  int	value;
};

t_lex_context		*lex_context_create(char *);

char			*lex_find_number(t_lex_context *);
char			*lex_find_operator(t_lex_context *);

t_lex_token		*lex_gettoken(t_lex_context *);

#endif
