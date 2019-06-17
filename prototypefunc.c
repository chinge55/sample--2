#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <prototype.h>



//newast
struct ast* newast(int nodetype, struct ast *l. struct ast *r)
{
	struct ast *a = malloc(sizeof(struct ast));
	if(!a)
	{
		yyerror("out of space");
		exit(0);
	}
	a-> nodetype = nodetype;
	a-> l = l;
	a-> r = r;
	return a;
}

// printast
struct ast* print_ast(struct ast *data)
{
	
	struct ast *a = malloc(sizeof(struct printast));
	if(!a)
	{
		yyerror("out of space");
		exit(0);
	}
	a-> nodetype = 'P';
	a-> data = data;
	return (struct ast *)a;
}

// for loops and conditions
struct ast* new_flow(int nodetype, struct ast *cond, struct ast *l, struct ast *r)
{
	struct flow *a = malloc(sizeof(struct flow));
	if(!a)
	{
		yyerror("out of space");
		exit(0);
	}
	a-> nodetype = nodetype;
	a-> cond = cond;
	a-> l = l;
	a-> r = r;
	return (struct ast*)a;
}

// for reference to variable(identifier = expression)
struct ast* new_assign(struct ast *identifier, struct ast *exp)
{
	
	struct flow *a = malloc(sizeof(struct assignment));
	if(!a)
	{
		yyerror("out of space");
		exit(0);
	}
	a-> nodetype = 'A';
	a-> identifier = identifier;
	a-> exp = exp;
	return (struct ast*)a;
}

// for reference to String

struct ast* new_strassign(struct ast *identifier, struct ast *exp)
{
	
	struct flow *a = malloc(sizeof(struct assignment));
	if(!a)
	{
		yyerror("out of space");
		exit(0);
	}
	a-> nodetype = 'S';
	a-> identifier = identifier;
	a-> exp = exp;
	return (struct ast*)a;
}
struct ast* new_numbref(struct ast *num)
{
	struct flow *a = malloc(sizeof(struct num_val));
	if(!a)
	{
		yyerror("out of space");
		exit(0);
	}
	a-> nodetype = 'N';
	a-> num = num;
	return (struct ast *)a;
	
}
struct ast* new_reference(struct ast *identifier)
{
	
	struct flow *a = malloc(sizeof(struct identifier_val));
	if(!a)
	{
		yyerror("out of space");
		exit(0);
	}
	a-> nodetype = 'I';
	a-> val = identifier;
	return (struct ast *)a;
}
void yyerror(char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	fprintf(stderr, "%d Error", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr);
}

int main()
{
	return yyparse();
}
