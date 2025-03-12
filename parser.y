%{
#include <stdio.h>
int yylex();
int yyerror(char *s);
extern int line;
%}

%union {
    char *name;
    double number;
}

%token <name> IDENTIFIER STRING CHAR
%token <number> NUMBER
%token FN LET MUT IF ELSE WHILE FOR RETURN IN 
%token LBRACE RBRACE LPAREN RPAREN SEMICOLON COMMA ASSIGN EQ NEQ LT GT PLUS MINUS MUL DIV
%token ARROW AND MOD I32 F64 BOOL CHAR_TYPE STR_TYPE COLON
%token OTHER

%left AND
%left LT GT EQ NEQ
%left PLUS MINUS
%left MUL DIV MOD

%%

prog: stmts ;

stmts:
    | stmt stmts
;

stmt:
    function
    | declaration SEMICOLON
    | if_stmt
    | return_stmt SEMICOLON
    | expr SEMICOLON
;

function:
    FN IDENTIFIER LPAREN params RPAREN ARROW type LBRACE stmts RBRACE
;

declaration:
    LET opt_mut IDENTIFIER COLON type ASSIGN expr
    | LET opt_mut IDENTIFIER ASSIGN expr  /* Para permitir inferencia de tipos */
;

if_stmt:
    IF expr LBRACE stmts RBRACE opt_else
;

return_stmt:
    RETURN expr
;

params:
    param
    | param COMMA params
    | /* vacío */
;

param:
    IDENTIFIER COLON type
;

type:
    I32
    | F64
    | BOOL
    | CHAR_TYPE
    | STR_TYPE
;

opt_else:
    | ELSE LBRACE stmts RBRACE
;

opt_mut:
    | MUT
;

expr:
    logic_expr
;

logic_expr:
    comp_expr
    | logic_expr AND comp_expr
;

comp_expr:
    arith_expr
    | arith_expr LT arith_expr
    | arith_expr GT arith_expr
    | arith_expr EQ arith_expr
    | arith_expr NEQ arith_expr
;

arith_expr:
    term
    | arith_expr PLUS term
    | arith_expr MINUS term
;

term:
    factor
    | term MUL factor
    | term DIV factor
    | term MOD factor
;

factor:
    NUMBER
    | IDENTIFIER
    | CHAR
    | STRING
    | LPAREN expr RPAREN
    | IDENTIFIER LPAREN args RPAREN  /* Llamada a función */
;

args:
    expr
    | expr COMMA args
    | /* vacío */
;

%%

int yyerror(char *s) {
    printf("\n[ERROR SINTÁCTICO] %s en línea %d!!!\n", s, line);
    return 0;
}

int main() {
    printf("\n>>> ANÁLISIS LÉXICO Y SINTÁCTICO <<<\n");
    printf("Procesando el archivo...\n\n");
    yyparse();
    printf("\n>>> ANÁLISIS COMPLETADO <<<\n");
    return 0;
}