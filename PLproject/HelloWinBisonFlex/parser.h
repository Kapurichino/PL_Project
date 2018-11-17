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
    NAME = 258,
    INTEGER = 259,
    FLOAT = 260,
    ID = 261,
    INT_T = 262,
    FLOAT_T = 263,
    MAINPROG_T = 264,
    VAR_T = 265,
    ARRAY_T = 266,
    OF_T = 267,
    FUNCTION_T = 268,
    PROCEDURE_T = 269,
    BEGIN_T = 270,
    END_T = 271,
    IF_T = 272,
    THEN_T = 273,
    ELSE_T = 274,
    NOP_T = 275,
    WHILE_T = 276,
    RETURN_T = 277,
    PRINT_T = 278,
    LESS_T = 279,
    LOE_T = 280,
    GOE_T = 281,
    GREATER_T = 282,
    EQUAL_T = 283,
    DIFF_T = 284,
    PLUS_T = 285,
    MINUS_T = 286,
    MUL_T = 287,
    DIV_T = 288,
    NOT_T = 289,
    SEMICOLON_T = 290,
    DOT_T = 291,
    COMMA_T = 292,
    ASSIGN_T = 293,
    RPARAN_T = 294,
    LPARAN_T = 295,
    LBRACKET_T = 296,
    RBRACKET_T = 297,
    COLON_T = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 31 "parser.y" /* yacc.c:1909  */

char *stringValue;
int intValue;
float floatValue;
struct vartab *vart;

#line 105 "parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
