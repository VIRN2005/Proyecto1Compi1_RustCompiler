/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    STRING = 259,                  /* STRING  */
    CHAR = 260,                    /* CHAR  */
    NUMBER = 261,                  /* NUMBER  */
    FN = 262,                      /* FN  */
    LET = 263,                     /* LET  */
    MUT = 264,                     /* MUT  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    FOR = 268,                     /* FOR  */
    RETURN = 269,                  /* RETURN  */
    IN = 270,                      /* IN  */
    LBRACE = 271,                  /* LBRACE  */
    RBRACE = 272,                  /* RBRACE  */
    LPAREN = 273,                  /* LPAREN  */
    RPAREN = 274,                  /* RPAREN  */
    SEMICOLON = 275,               /* SEMICOLON  */
    COMMA = 276,                   /* COMMA  */
    ASSIGN = 277,                  /* ASSIGN  */
    EQ = 278,                      /* EQ  */
    NEQ = 279,                     /* NEQ  */
    LT = 280,                      /* LT  */
    GT = 281,                      /* GT  */
    PLUS = 282,                    /* PLUS  */
    MINUS = 283,                   /* MINUS  */
    MUL = 284,                     /* MUL  */
    DIV = 285,                     /* DIV  */
    ARROW = 286,                   /* ARROW  */
    AND = 287,                     /* AND  */
    MOD = 288,                     /* MOD  */
    I32 = 289,                     /* I32  */
    F64 = 290,                     /* F64  */
    BOOL = 291,                    /* BOOL  */
    CHAR_TYPE = 292,               /* CHAR_TYPE  */
    STR_TYPE = 293,                /* STR_TYPE  */
    COLON = 294,                   /* COLON  */
    OTHER = 295                    /* OTHER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "parser.y"

    char *name;
    double number;

#line 109 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
