// Declarations for the prototype


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
