/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    INTEGER = 259,
    FLOAT = 260,
    INT_T = 261,
    FLOAT_T = 262,
    MAINPROG_T = 263,
    VAR_T = 264,
    ARRAY_T = 265,
    OF_T = 266,
    FUNCTION_T = 267,
    PROCEDURE_T = 268,
    BEGIN_T = 269,
    END_T = 270,
    IF_T = 271,
    THEN_T = 272,
    ELSE_T = 273,
    NOP_T = 274,
    WHILE_T = 275,
    RETURN_T = 276,
    PRINT_T = 277,
    LESS_T = 278,
    LOE_T = 279,
    GOE_T = 280,
    GREATER_T = 281,
    EQUAL_T = 282,
    DIFF_T = 283,
    PLUS_T = 284,
    MINUS_T = 285,
    MUL_T = 286,
    DIV_T = 287,
    NOT_T = 288,
    SEMICOLON_T = 289,
    DOT_T = 290,
    COMMA_T = 291,
    ASSIGN_T = 292,
    RPARAN_T = 293,
    LPARAN_T = 294,
    LBRACKET_T = 295,
    RBRACKET_T = 296,
    COLON_T = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 28 "parser.y" /* yacc.c:1909  */

AST *val;

#line 101 "parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
