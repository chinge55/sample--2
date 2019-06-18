%{
    #include "prototype.h"
    #include "prototype.tab.h"    
    int yylex();    // Entry point for lex
%}
%%
// Comparison Start
// fn need to be declared in yacc
">"     { yylval.fn = 1; return CMP; }
"<"     { yylval.fn = 2; return CMP; }
"<>"    { yylval.fn = 3; return CMP; }
"=="    { yylval.fn = 4; return CMP; }
">="    { yylval.fn = 5; return CMP; }
"<="    { yylval.fn = 6; return CMP; }



// Comparison End
//Branching Start
"if"    { return IF; }
"then"  { return THEN; }
"else"  { return ELSE; }
"while" { return WHILE; }

//Branching End
//identifiers start
"int"   {return IDENTIFIER;}

[a-zA-Z][a-zA-Z0-9]*  { return NAME; }
[0-9]+"."[0-9]*{EXP}? |
"."?[0-9]+{EXP}? { yylval.d = atof(yytext); return NUMBER; }
[-+=/*|()]      {return yytext[0];}
\n              {return EOL;}
"//".*
[ \t]           {/*ignore whitespace*/}
%%
int yywrap(void)    {return 1;}
