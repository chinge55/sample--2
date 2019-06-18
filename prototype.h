// Declarations for the prototype
extern int yylineno;
void yyerror(char *s, ...);

struct ast
{
	int nodetype;
	struct ast *l;
	struct ast *r;
}

struct printast
{
	int nodetype;
	struct ast data;
}

struct flow
{
	int nodetype;
	struct ast *cond;
	struct ast *l;
	struct ast *r;
}

struct assignment
{
	int nodetype;
	struct ast *identifier;
	struct ast *exp;
}
struct num_val
{
	int nodetype;
	struct ast *num;
}
struct identifier_val
{
	int nodetype;
	struct ast *val;
}
struct stmtlist
{
	int nodetype;
	struct ast *stmt_list;
	struct ast *stmt;
}

struct ast* newast(int nodetype, struct ast *l, struct ast *r);
struct ast* print_ast(struct ast *data);
struct ast* new_flow(int nodetype, struct ast *cond, struct ast *l, struct ast *r);
struct ast* new_assign(struct ast *identifier, struct ast *exp);
struct ast* new_numbref(struct ast *num);
struct ast* new_reference(struct ast *identifier);

