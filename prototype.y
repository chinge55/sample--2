%{
void yyerror(char *s);
int yylex();
#include <stdio.h>
#include <stdlib.h>
#include "prototype.h"
%}

%union
{
	struct ast *a;
	int num;
	struct symbol *s;
}
%start stmt_list
%token print_cmd
%token exit_cmd
%token <num> number
%token <s> str
%token <s> identifier

%token  IF THEN ELSE WHILE 
%token declaration
%nonassoc cmp
%type <s> cmp
%right '='
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%type <a> stmt_list exp stmt
%type <a> assignment
%%
stmt_list: stmt
	 | stmt_list stmt		{$$ = new_list($1, $2);}
	 ;

stmt	 : assignment ';'		{;}
         | exit_cmd ';'			{exit(EXIT_SUCCESS);}
	 | print_cmd exp ';'		{$$ = printast($2);}
	 | exp THEN stmt_list ELSE stmt_list ';' {$$ = new_flow($1, $3, $5);}
 	 | exp THEN stmt_list ';'	{$$ = new_flow($1, $3, NULL);}
	 | exp WHILE stmt_list ';'	{$$ = new_flow($1, $3, NULL);}
	 | exp ';'			{;}
	 ;
// declaration: decl identifer ';'

assignment: identifier '=' exp		{$$ = new_assign($1, $3);}
	  | identifier '=' str		{$$ = new_strassign($1, $3);}
	  ;

exp:	  number			{$$ = new_numbref($1);}
   	| '(' exp ')'			{$$ = $2;}
	| identifier			{$$ = new_reference($1);}
	| exp '+' exp			{$$ = new_ast('+', $1, $3);}
	| exp '-' exp			{$$ = new_ast('-', $1, $3);}
	| exp '*' exp			{$$ = new_ast('*', $1, $3);}
	| exp '/' exp			{$$ = new_ast('/', $1, $3);}
	| exp cmp exp			{$$ = new_cmp($2, $1, $3);}	
	;
