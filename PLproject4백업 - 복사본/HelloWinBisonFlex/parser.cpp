/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "parser.y" /* yacc.c:339  */


#include "AST.h"
#include "interp.h"
	#include <iostream>
	  #define NULL 0
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
	#pragma warning (disable: 4005)
	#pragma warning (disable: 4996)
	

	extern int yylex(); // lexical analyzer
	 

	void yyerror(const char *str) {
	printf("%s", str);
	}

	using namespace std;

	extern FILE *yyin;




#line 94 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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
    MAINPROG_T = 261,
    VAR_T = 262,
    ARRAY_T = 263,
    OF_T = 264,
    FUNCTION_T = 265,
    PROCEDURE_T = 266,
    BEGIN_T = 267,
    END_T = 268,
    IF_T = 269,
    THEN_T = 270,
    ELSE_T = 271,
    NOP_T = 272,
    WHILE_T = 273,
    RETURN_T = 274,
    PRINT_T = 275,
    LESS_T = 276,
    LOE_T = 277,
    GOE_T = 278,
    GREATER_T = 279,
    EQUAL_T = 280,
    DIFF_T = 281,
    MUL_T = 282,
    DIV_T = 283,
    NOT_T = 284,
    SEMICOLON_T = 285,
    DOT_T = 286,
    COMMA_T = 287,
    ASSIGN_T = 288,
    RPARAN_T = 289,
    LPARAN_T = 290,
    LBRACKET_T = 291,
    RBRACKET_T = 292,
    COLON_T = 293,
    INT_T = 294,
    FLOAT_T = 295,
    PLUS_T = 296,
    MINUS_T = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 31 "parser.y" /* yacc.c:355  */

AST *val;
enum Type type;
int intValue;

#line 183 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 198 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     8,     6,     2,     7,     2,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     3,     5,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    65,    68,    76,    76,    77,    77,    79,
      83,    85,    90,    95,    96,   103,   117,   118,   121,   124,
     127,   130,   136,   140,   144,   148,   152,   156,   163,   168,
     172,   174,   177,   180,   183,   186,   190,   193,   197,   200,
     204,   208,   212,   219,   220,   221,   224,   227,   230,   233,
     236,   239,   242,   245,   248,   251,   258,   264,   265,   266,
     267,   271,   274,   278,   279
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "ID", "INTEGER", "FLOAT", "MAINPROG_T", "VAR_T", "ARRAY_T",
  "OF_T", "FUNCTION_T", "PROCEDURE_T", "BEGIN_T", "END_T", "IF_T",
  "THEN_T", "ELSE_T", "NOP_T", "WHILE_T", "RETURN_T", "PRINT_T", "LESS_T",
  "LOE_T", "GOE_T", "GREATER_T", "EQUAL_T", "DIFF_T", "MUL_T", "DIV_T",
  "NOT_T", "SEMICOLON_T", "DOT_T", "COMMA_T", "ASSIGN_T", "RPARAN_T",
  "LPARAN_T", "LBRACKET_T", "RBRACKET_T", "COLON_T", "INT_T", "FLOAT_T",
  "PLUS_T", "MINUS_T", "$accept", "program", "identifier_list",
  "standard_type", "subprogram_declarations", "subprogram_declaration",
  "block", "local_declarations", "arguments", "parameter_list",
  "statement_list", "compound_statement", "statement",
  "actual_parameter_expression", "expression", "primary_expression",
  "sign", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    61,    60,    62,    43,    45,    42,    47,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297
};
# endif

#define YYPACT_NINF -117

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-117)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    15,     9,     1,  -117,    32,    62,    89,  -117,    25,
      65,    72,    49,    89,    88,    16,    59,    59,   197,  -117,
    -117,    60,  -117,  -117,    73,    62,    67,    77,   -23,   197,
      47,  -117,    81,    47,    95,   -10,   107,  -117,   144,    32,
      26,   115,    94,    32,    47,    47,    -8,    91,  -117,  -117,
      69,  -117,  -117,    87,  -117,    69,    47,   171,    47,  -117,
     197,   197,   113,  -117,    20,  -117,   121,  -117,   140,   171,
      56,  -117,    -4,    47,   100,  -117,   207,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,  -117,    97,   119,
    -117,  -117,   124,   146,   120,   127,    32,   197,   125,  -117,
      58,   171,   141,    47,   197,   143,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   217,  -117,    94,   175,
      62,  -117,    -7,    47,    47,  -117,   147,   149,    -1,   227,
     197,  -117,   151,   148,  -117,  -117,   171,   171,    47,  -117,
     168,   197,  -117,     2,    32,   178,   171,   237,     3,  -117,
    -117,    94,   197,  -117,  -117,   158,    40,    62,  -117,  -117
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    13,     0,     7,     3,     0,
       0,     0,     0,     7,     0,     0,    16,    16,     0,     8,
       4,     0,     5,     6,     0,     0,     0,     0,     0,     0,
       0,    40,     0,    39,    30,     0,    26,    22,     0,    13,
       0,     0,     0,    13,     0,     0,     0,    59,    57,    58,
       0,    63,    64,     0,    43,     0,     0,    38,     0,     2,
       0,     0,     0,    14,     0,    17,     0,    11,     0,    29,
       0,    27,     0,     0,    59,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
      25,    23,    24,     0,     0,    18,    13,     0,     0,    62,
       0,    41,     0,     0,     0,     0,    49,    51,    52,    50,
      53,    54,    47,    48,    45,    46,     0,    31,     0,     0,
       0,     9,     0,     0,     0,    61,    60,     0,     0,     0,
       0,    36,     0,     0,    19,    12,    28,    42,     0,    60,
       0,     0,    32,     0,    13,     0,    44,     0,     0,    37,
      15,     0,     0,    33,    34,    20,     0,     0,    35,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,   190,   -40,   195,  -117,   114,    -5,   192,  -116,
     -28,   152,   -55,  -117,   -30,   -39,  -117
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    40,    24,    12,    13,    67,    68,    26,    41,
      35,    36,    37,   100,    53,    54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       7,    46,    66,    57,   134,    91,    47,    48,    49,     4,
      59,    75,    71,   135,    69,    70,    87,    44,     1,   140,
      45,   105,   149,   154,    95,     3,    88,    60,    89,    60,
      60,    21,    50,    92,    63,    94,    60,    99,     5,    60,
      60,   159,   101,   102,    51,    52,     6,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    47,    48,    49,
     158,   131,    22,    23,    14,    14,    22,    23,    18,   122,
      15,    64,     8,   127,   142,    16,   128,    60,   132,    74,
      48,    49,    17,    50,    77,    78,    79,    80,    81,    82,
      83,    84,   153,   136,   137,    51,    52,   124,    20,   125,
      98,    25,   143,    38,    85,    86,    10,    11,   146,    76,
      39,   155,    42,   148,    43,    77,    78,    79,    80,    81,
      82,    83,    84,    56,   156,    77,    78,    79,    80,    81,
      82,    83,    84,    72,    73,    85,    86,    58,   116,   150,
      22,    23,    72,   103,    61,    85,    86,    77,    78,    79,
      80,    81,    82,    83,    84,    62,    65,    93,    96,    97,
     117,    60,   118,   119,   120,   123,   129,    85,    86,    77,
      78,    79,    80,    81,    82,    83,    84,    77,    78,    79,
      80,    81,    82,    83,    84,   126,   133,   138,   144,    85,
      86,   147,   145,   139,   151,   157,     9,    85,    86,    77,
      78,    79,    80,    81,    82,    83,    84,    28,    19,    27,
     121,     0,    90,     0,     0,     0,    29,    28,    30,    85,
      86,    31,    32,    33,    34,     0,   104,    28,    30,     0,
       0,    31,    32,    33,    34,     0,   130,    28,    30,     0,
       0,    31,    32,    33,    34,     0,   141,    28,    30,     0,
       0,    31,    32,    33,    34,     0,   152,     0,    30,     0,
       0,    31,    32,    33,    34
};

static const yytype_int16 yycheck[] =
{
       5,    29,    42,    33,   120,    60,    10,    11,    12,     0,
      20,    50,    20,    20,    44,    45,    55,    40,    13,    20,
      43,    76,    20,    20,    64,    10,    56,    37,    58,    37,
      37,    15,    36,    61,    39,    15,    37,    41,    37,    37,
      37,   157,    72,    73,    48,    49,    14,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    10,    11,    12,
      20,   116,    46,    47,    39,    39,    46,    47,    19,    97,
      45,    45,    10,   103,   129,    10,   104,    37,   118,    10,
      11,    12,    10,    36,    28,    29,    30,    31,    32,    33,
      34,    35,   147,   123,   124,    48,    49,    39,    10,    41,
      44,    42,   130,    43,    48,    49,    17,    18,   138,    22,
      37,   151,    45,   141,    37,    28,    29,    30,    31,    32,
      33,    34,    35,    42,   152,    28,    29,    30,    31,    32,
      33,    34,    35,    42,    43,    48,    49,    42,    41,   144,
      46,    47,    42,    43,    37,    48,    49,    28,    29,    30,
      31,    32,    33,    34,    35,    11,    41,    44,    37,    19,
      41,    37,    16,    43,    37,    40,    23,    48,    49,    28,
      29,    30,    31,    32,    33,    34,    35,    28,    29,    30,
      31,    32,    33,    34,    35,    44,    11,    40,    37,    48,
      49,    23,    44,    44,    16,    37,     6,    48,    49,    28,
      29,    30,    31,    32,    33,    34,    35,    10,    13,    17,
      96,    -1,    60,    -1,    -1,    -1,    19,    10,    21,    48,
      49,    24,    25,    26,    27,    -1,    19,    10,    21,    -1,
      -1,    24,    25,    26,    27,    -1,    19,    10,    21,    -1,
      -1,    24,    25,    26,    27,    -1,    19,    10,    21,    -1,
      -1,    24,    25,    26,    27,    -1,    19,    -1,    21,    -1,
      -1,    24,    25,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    51,    10,     0,    37,    14,    57,    10,    52,
      17,    18,    54,    55,    39,    45,    10,    10,    19,    54,
      10,    15,    46,    47,    53,    42,    58,    58,    10,    19,
      21,    24,    25,    26,    27,    60,    61,    62,    43,    37,
      52,    59,    45,    37,    40,    43,    60,    10,    11,    12,
      36,    48,    49,    64,    65,    66,    42,    64,    42,    20,
      37,    37,    11,    57,    45,    41,    53,    56,    57,    64,
      64,    20,    42,    43,    10,    65,    22,    28,    29,    30,
      31,    32,    33,    34,    35,    48,    49,    65,    64,    64,
      61,    62,    60,    44,    15,    53,    37,    19,    44,    41,
      63,    64,    64,    43,    19,    62,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    41,    41,    16,    43,
      37,    56,    60,    40,    39,    41,    44,    64,    60,    23,
      19,    62,    53,    11,    59,    20,    64,    64,    40,    44,
      20,    19,    62,    60,    37,    44,    64,    23,    60,    20,
      57,    16,    19,    62,    20,    53,    60,    37,    20,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    55,    56,    57,    57,    57,    58,    58,    59,    59,
      59,    59,    60,    60,    60,    60,    60,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     3,     1,     1,     0,     2,     7,
       0,     5,     4,     0,     6,    11,     0,     3,     3,     5,
       8,    10,     1,     3,     3,     3,     1,     3,     6,     3,
       1,     4,     6,     8,     8,    10,     5,     7,     2,     1,
       1,     1,     3,     1,     6,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     1,     1,
       4,     4,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 59 "parser.y" /* yacc.c:1646  */
    {
	AST *maintemp = makeAST(BLOCK_STATEMENT,(yyvsp[-4].val),(yyvsp[-1].val));
	AST *temp = makeSymbol("main");
	defineFunction(getSymbol(temp),NULL,maintemp);
}
#line 1384 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 65 "parser.y" /* yacc.c:1646  */
    {
					(yyval.val) = makeList1((yyvsp[0].val));
				}
#line 1392 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 68 "parser.y" /* yacc.c:1646  */
    {
					(yyval.val) = addLast((yyvsp[-2].val),(yyvsp[0].val));
				}
#line 1400 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=I;}
#line 1406 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 76 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=F;}
#line 1412 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 80 "parser.y" /* yacc.c:1646  */
    {
defineFunction(getSymbol((yyvsp[-5].val)),(yyvsp[-4].val),(yyvsp[0].val));
}
#line 1420 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 86 "parser.y" /* yacc.c:1646  */
    {
defineFunction(getSymbol((yyvsp[-3].val)),(yyvsp[-2].val),(yyvsp[0].val));
}
#line 1428 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 90 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = makeAST(BLOCK_STATEMENT,(yyvsp[-3].val),(yyvsp[-1].val));
	//cout<<"block op : "<<$$->op<<endl;
}
#line 1437 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 95 "parser.y" /* yacc.c:1646  */
    {(yyval.val)=NULL;}
#line 1443 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 96 "parser.y" /* yacc.c:1646  */
    {
	for(AST *l = (yyvsp[-4].val); l != NULL; l = l->right){ 
		l->left->sym->type = (yyvsp[-2].type);
	}	
	(yyval.val)=addList((yyvsp[-4].val),(yyvsp[0].val));
}
#line 1454 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 103 "parser.y" /* yacc.c:1646  */
    {
	for(AST *l = (yyvsp[-9].val); l != NULL; l = l->right){ 
		if((yyvsp[-2].type)==I){
		l->left->sym->type = IA;
		} else {
		l->left->sym->type = FA;
		}
	}	
	
	(yyval.val)=addList((yyvsp[-9].val),(yyvsp[0].val));

	//지역 변수 배열
}
#line 1472 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.val) = NULL; }
#line 1478 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 118 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = (yyvsp[-1].val);
}
#line 1486 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 121 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = (yyvsp[-2].val);
}
#line 1494 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 124 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = addList((yyvsp[-4].val),(yyvsp[0].val));
}
#line 1502 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 127 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = (yyvsp[-7].val);
}
#line 1510 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 130 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = addList((yyvsp[-9].val),(yyvsp[0].val));
}
#line 1518 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 136 "parser.y" /* yacc.c:1646  */
    {
(yyval.val)=makeList1((yyvsp[0].val));
}
#line 1526 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 140 "parser.y" /* yacc.c:1646  */
    {
(yyval.val)=addLast((yyvsp[-2].val),(yyvsp[0].val));
}
#line 1534 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 144 "parser.y" /* yacc.c:1646  */
    {
(yyval.val)=addList((yyvsp[-2].val),(yyvsp[0].val));
}
#line 1542 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 148 "parser.y" /* yacc.c:1646  */
    {
(yyval.val)=addList((yyvsp[-2].val),(yyvsp[0].val));
}
#line 1550 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 152 "parser.y" /* yacc.c:1646  */
    {
(yyval.val)=(yyvsp[0].val);
}
#line 1558 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 156 "parser.y" /* yacc.c:1646  */
    {
(yyval.val)=(yyvsp[-1].val);
cout<<"COMP"<<endl;
}
#line 1567 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 163 "parser.y" /* yacc.c:1646  */
    {
//setArray
	(yyval.val) = makeAST(SET_ARRAY_OP,makeList2((yyvsp[-5].val),(yyvsp[-3].val)),(yyvsp[0].val));
}
#line 1576 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 168 "parser.y" /* yacc.c:1646  */
    {
//cout<<"assign expression"<<endl;
(yyval.val) = makeAST(EQ_OP,(yyvsp[-2].val),(yyvsp[0].val));
}
#line 1585 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 172 "parser.y" /* yacc.c:1646  */
    {
}
#line 1592 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 174 "parser.y" /* yacc.c:1646  */
    {
(yyval.val) = makeAST(PRINTLN_OP,(yyvsp[-1].val),NULL);
}
#line 1600 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 177 "parser.y" /* yacc.c:1646  */
    {
(yyval.val) = makeAST(IF_STATEMENT,(yyvsp[-4].val),makeList2(makeList1((yyvsp[-2].val)),makeList1((yyvsp[0].val))));
}
#line 1608 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 180 "parser.y" /* yacc.c:1646  */
    {
(yyval.val) = makeAST(IF_STATEMENT,(yyvsp[-6].val),makeList2((yyvsp[-3].val),makeList1((yyvsp[0].val))));
}
#line 1616 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 183 "parser.y" /* yacc.c:1646  */
    {
(yyval.val) = makeAST(IF_STATEMENT,(yyvsp[-6].val),makeList2(makeList1((yyvsp[-4].val)),(yyvsp[-1].val)));
}
#line 1624 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 186 "parser.y" /* yacc.c:1646  */
    {
(yyval.val) = makeAST(IF_STATEMENT,(yyvsp[-8].val),makeList2((yyvsp[-5].val),(yyvsp[-1].val)));
}
#line 1632 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 190 "parser.y" /* yacc.c:1646  */
    {
(yyval.val) = makeAST(WHILE_STATEMENT,(yyvsp[-2].val),makeList1((yyvsp[0].val)));
}
#line 1640 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 193 "parser.y" /* yacc.c:1646  */
    {
(yyval.val) = makeAST(WHILE_STATEMENT,(yyvsp[-4].val),(yyvsp[-1].val));
}
#line 1648 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 197 "parser.y" /* yacc.c:1646  */
    {
(yyval.val) = makeAST(RETURN_STATEMENT,(yyvsp[0].val),NULL);
}
#line 1656 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 200 "parser.y" /* yacc.c:1646  */
    {
(yyval.val) = makeAST(RETURN_STATEMENT,NULL,NULL);
}
#line 1664 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 208 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = makeList1((yyvsp[0].val));
}
#line 1672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 212 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = addLast((yyvsp[-2].val),(yyvsp[0].val));

}
#line 1681 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 221 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = makeAST(PLUS_OP,(yyvsp[-2].val),(yyvsp[0].val)); 
}
#line 1689 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 224 "parser.y" /* yacc.c:1646  */
    {
(yyval.val) = makeAST(MINUS_OP,(yyvsp[-2].val),(yyvsp[0].val)); 
}
#line 1697 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 227 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = makeAST(MUL_OP,(yyvsp[-2].val),(yyvsp[0].val)); 
}
#line 1705 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 230 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = makeAST(DIV_OP,(yyvsp[-2].val),(yyvsp[0].val)); 
}
#line 1713 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 233 "parser.y" /* yacc.c:1646  */
    {
(yyval.val) = makeAST(LT_OP,(yyvsp[-2].val),(yyvsp[0].val)); 
}
#line 1721 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 236 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = makeAST(GT_OP,(yyvsp[-2].val),(yyvsp[0].val)); 
}
#line 1729 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 239 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = makeAST(LOE_OP,(yyvsp[-2].val),(yyvsp[0].val)); 
}
#line 1737 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 242 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = makeAST(GOE_OP,(yyvsp[-2].val),(yyvsp[0].val)); 
}
#line 1745 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 245 "parser.y" /* yacc.c:1646  */
    { // ==
	(yyval.val) = makeAST(EQUAL_OP,(yyvsp[-2].val),(yyvsp[0].val)); 
}
#line 1753 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 248 "parser.y" /* yacc.c:1646  */
    { // !=
	(yyval.val) = makeAST(DIFF_OP,(yyvsp[-2].val),(yyvsp[0].val)); 
}
#line 1761 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 251 "parser.y" /* yacc.c:1646  */
    {
	if((yyvsp[-1].intValue)==-1){
	(yyval.val) = makeAST(MINUS_OP,makeNum(0),(yyvsp[0].val));
	} else {
	(yyval.val) = (yyvsp[0].val);
	}
}
#line 1773 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 258 "parser.y" /* yacc.c:1646  */
    {
cout<<"NOT_TTTTT"<<endl;
	(yyval.val) = makeAST(NOT_OP,(yyvsp[0].val),NULL);
}
#line 1782 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 267 "parser.y" /* yacc.c:1646  */
    {
//getArray
	(yyval.val) = makeAST(GET_ARRAY_OP,(yyvsp[-3].val),(yyvsp[-1].val));
}
#line 1791 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 271 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = makeAST(CALL_OP,(yyvsp[-3].val),(yyvsp[-1].val));
}
#line 1799 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 274 "parser.y" /* yacc.c:1646  */
    {
	(yyval.val) = makeAST(CALL_OP,(yyvsp[-2].val),NULL);
}
#line 1807 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 278 "parser.y" /* yacc.c:1646  */
    { (yyval.intValue) = 1;}
#line 1813 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 279 "parser.y" /* yacc.c:1646  */
    {(yyval.intValue) = -1;}
#line 1819 "parser.cpp" /* yacc.c:1646  */
    break;


#line 1823 "parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 281 "parser.y" /* yacc.c:1906  */
 
