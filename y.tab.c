/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_NUM = 258,
     TK_REAL = 259,
     TK_CHAR = 260,
     TK_BOOL = 261,
     TK_STRING = 262,
     TK_MAIN = 263,
     TK_ID = 264,
     TK_TIPO_VAR = 265,
     TK_TIPO_INT = 266,
     TK_TIPO_FLOAT = 267,
     TK_TIPO_CHAR = 268,
     TK_TIPO_BOOL = 269,
     TK_TIPO_STRING = 270,
     TK_EQUAL = 271,
     TK_GTE = 272,
     TK_LTE = 273,
     TK_NEQUAL = 274,
     TK_AND = 275,
     TK_OR = 276,
     TK_NOT = 277,
     TK_IF = 278,
     TK_ELSE = 279,
     TK_DO = 280,
     TK_WHILE = 281,
     TK_FOR = 282,
     TK_BREAK = 283,
     TK_CONTINUE = 284,
     TK_PRINT = 285,
     TK_READ = 286,
     TK_FIM = 287,
     TK_ERROR = 288
   };
#endif
/* Tokens.  */
#define TK_NUM 258
#define TK_REAL 259
#define TK_CHAR 260
#define TK_BOOL 261
#define TK_STRING 262
#define TK_MAIN 263
#define TK_ID 264
#define TK_TIPO_VAR 265
#define TK_TIPO_INT 266
#define TK_TIPO_FLOAT 267
#define TK_TIPO_CHAR 268
#define TK_TIPO_BOOL 269
#define TK_TIPO_STRING 270
#define TK_EQUAL 271
#define TK_GTE 272
#define TK_LTE 273
#define TK_NEQUAL 274
#define TK_AND 275
#define TK_OR 276
#define TK_NOT 277
#define TK_IF 278
#define TK_ELSE 279
#define TK_DO 280
#define TK_WHILE 281
#define TK_FOR 282
#define TK_BREAK 283
#define TK_CONTINUE 284
#define TK_PRINT 285
#define TK_READ 286
#define TK_FIM 287
#define TK_ERROR 288




/* Copy the first part of user declarations.  */
#line 1 "sintatica.y"

#include <iostream>
#include <string>
#include <sstream>
#include "variaveis.h"

#define YYSTYPE atributos

using namespace std;


struct atributos
{
	string label;
	string traducao;
	int tipo;

	int tamanho;
};

// Variaveis Planistas
string error_msg = "Wubba Lubba Dub Dub";

// roubando pra fazer else if, gambiarra demais
string else_if_string = "";

maps* tack = criarMaps();
varsDeclaradas varsDec;

// Functions
int yylex(void);
void yyerror(string);
string exibirVarsDeclaradas();
variavel criadorDeVariavel(string, string, string, int);
void deletadorDeVariavel(string);
string geradoraDeNomeDeVariaveis();
int getTipoToken(string);
string getTipoString(int);
atributos tratadoraLogic(int, string, int, string, string);
atributos tratarArithComCast(int, string, int, string, string);
atributos concatenarStrings(atributos, atributos);
int tipoResult(int, int);
atributos tratadoraArith(atributos, atributos, string);
variavel getVarPorNome(string);
string geradorTextGoto(int);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 219 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   260

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  132

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,    36,    34,    44,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      46,    38,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    15,    16,    17,    20,    21,    27,
      34,    36,    39,    42,    45,    48,    51,    54,    57,    64,
      72,    74,    76,    78,    86,    92,   102,   105,   109,   111,
     113,   116,   120,   122,   124,   127,   129,   131,   133,   135,
     137,   139,   143,   147,   151,   153,   157,   161,   164,   168,
     172,   176,   180,   184,   188,   192,   196,   200,   204,   208,
     212,   215,   217,   219,   221,   223,   225
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    11,     8,    39,    40,    49,    -1,    50,
      41,    52,    42,    51,    -1,    -1,    -1,    53,    52,    -1,
      -1,    23,    39,    69,    40,    49,    -1,    23,    39,    69,
      40,    49,    54,    -1,    55,    -1,    65,    43,    -1,    68,
      43,    -1,    59,    43,    -1,    62,    43,    -1,    28,    43,
      -1,    29,    43,    -1,    24,    49,    -1,    24,    23,    39,
      69,    40,    49,    -1,    24,    23,    39,    69,    40,    49,
      54,    -1,    56,    -1,    57,    -1,    58,    -1,    25,    49,
      26,    39,    69,    40,    43,    -1,    26,    39,    69,    40,
      49,    -1,    27,    39,    65,    43,    69,    43,    68,    40,
      49,    -1,    30,    60,    -1,    60,    44,    61,    -1,    61,
      -1,    69,    -1,    31,    63,    -1,    63,    44,    64,    -1,
      64,    -1,     9,    -1,    66,    67,    -1,    11,    -1,    12,
      -1,    13,    -1,    14,    -1,    15,    -1,    10,    -1,    67,
      44,     9,    -1,    67,    44,    68,    -1,     9,    38,    69,
      -1,     9,    -1,     9,    38,    69,    -1,    39,    69,    40,
      -1,    35,    69,    -1,    69,    35,    69,    -1,    69,    34,
      69,    -1,    69,    36,    69,    -1,    69,    37,    69,    -1,
      69,    45,    69,    -1,    69,    46,    69,    -1,    69,    17,
      69,    -1,    69,    18,    69,    -1,    69,    16,    69,    -1,
      69,    19,    69,    -1,    69,    20,    69,    -1,    69,    21,
      69,    -1,    22,    69,    -1,     3,    -1,     4,    -1,     5,
      -1,     9,    -1,     6,    -1,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    71,    81,    89,    97,   112,   117,   141,
     173,   177,   183,   187,   192,   197,   201,   209,   220,   255,
     292,   296,   300,   305,   324,   358,   380,   389,   393,   398,
     407,   416,   420,   425,   435,   449,   454,   459,   464,   469,
     475,   481,   496,   511,   589,   614,   707,   711,   728,   732,
     745,   749,   753,   762,   771,   780,   789,   798,   807,   822,
     837,   852,   863,   874,   886,   911,   922
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUM", "TK_REAL", "TK_CHAR",
  "TK_BOOL", "TK_STRING", "TK_MAIN", "TK_ID", "TK_TIPO_VAR", "TK_TIPO_INT",
  "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_BOOL", "TK_TIPO_STRING",
  "TK_EQUAL", "TK_GTE", "TK_LTE", "TK_NEQUAL", "TK_AND", "TK_OR", "TK_NOT",
  "TK_IF", "TK_ELSE", "TK_DO", "TK_WHILE", "TK_FOR", "TK_BREAK",
  "TK_CONTINUE", "TK_PRINT", "TK_READ", "TK_FIM", "TK_ERROR", "'+'", "'-'",
  "'*'", "'/'", "'='", "'('", "')'", "'{'", "'}'", "';'", "','", "'>'",
  "'<'", "$accept", "S", "BLOCO", "PUSH_SCOPE", "POP_SCOPE", "COMANDOS",
  "COMANDO", "ELSE", "LOOP", "DO", "WHILE", "FOR", "PRINT", "PRINT_THINGS",
  "PRINT_THING", "READ", "READ_THINGS", "READ_THING", "DECLARATION",
  "TIPO", "VARLIST", "ATRIB", "E", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    43,    45,    42,    47,    61,    40,
      41,   123,   125,    59,    44,    62,    60
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    54,
      55,    55,    55,    56,    57,    58,    59,    60,    60,    61,
      62,    63,    63,    64,    65,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    67,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     5,     0,     0,     2,     0,     5,     6,
       1,     2,     2,     2,     2,     2,     2,     2,     6,     7,
       1,     1,     1,     7,     5,     9,     2,     3,     1,     1,
       2,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     1,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     4,     2,     0,     7,
       0,    40,    35,    36,    37,    38,    39,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     7,    10,    20,    21,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,    61,    62,    63,    65,    66,    64,     0,
       0,     0,    26,    28,    29,    33,    30,    32,     5,     6,
      13,    14,    11,    44,    34,    12,    45,     0,     0,     0,
       0,    60,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     4,     0,     4,     0,    46,    27,    56,    54,    55,
      57,    58,    59,    49,    48,    50,    51,    52,    53,    31,
      43,    41,    42,     8,     0,    24,     0,     4,     9,     0,
       0,     0,    17,    23,     0,     0,     4,     0,    25,     4,
      18,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     8,    88,    25,    26,   118,    27,    28,
      29,    30,    31,    52,    53,    32,    56,    57,    33,    34,
      64,    35,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -88
static const yytype_int16 yypact[] =
{
      -6,    -2,    13,   -22,   -88,   -21,   -88,   -88,   -23,   229,
     -13,   -88,   -88,   -88,   -88,   -88,   -88,   -10,   -88,    -8,
      -7,    -5,    10,    17,    21,    16,   229,   -88,   -88,   -88,
     -88,    12,    18,    25,    26,    27,    17,    17,     8,    17,
     102,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,    17,
      17,    17,    28,   -88,   191,   -88,    30,   -88,   -88,   -88,
     -88,   -88,   -88,    22,    32,   -88,   191,    46,    38,    84,
      35,   191,    -9,   115,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    21,   -88,    17,
      60,   -88,    17,   -88,    17,   -88,   -88,   191,   191,   191,
     191,   191,   191,    -9,    -9,    77,    77,   191,   191,   -88,
     191,   -13,   -88,    47,   122,   -88,   153,    56,   -88,    41,
      76,    48,   -88,   -88,    49,    17,   -88,   184,   -88,   -88,
      47,   -88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,   -18,   -88,   -88,    62,   -88,   -24,   -88,   -88,
     -88,   -88,   -88,   -88,    33,   -88,   -88,    23,    69,   -88,
     -88,   -87,   -35
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      38,    66,    67,   112,    69,     1,     3,    75,    76,    77,
      78,    79,    80,     4,    71,    72,    73,     5,     9,     6,
      43,    44,    45,    46,    47,    36,    48,    83,    84,    37,
      55,    39,    40,   124,    68,    63,    85,    86,    41,    49,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    50,    42,   110,    60,    51,   114,    58,   116,
      89,    61,    75,    76,    77,    78,    79,    80,    62,   111,
      65,   117,    74,   113,    87,   115,    90,    92,    94,   121,
      81,    82,    83,    84,   123,    10,    91,   125,    59,   126,
     127,    85,    86,    75,    76,    77,    78,    79,    80,   122,
      75,    76,    77,    78,    79,    80,   131,    96,   128,    70,
     109,   130,    11,    12,    13,    14,    15,    16,    81,    82,
      83,    84,    85,    86,    93,     0,     0,     0,     0,    85,
      86,    75,    76,    77,    78,    79,    80,     0,    75,    76,
      77,    78,    79,    80,     0,     0,     0,     0,     0,    81,
      82,    83,    84,     0,     0,    95,    81,    82,    83,    84,
      85,    86,   119,     0,     0,     0,     0,    85,    86,    75,
      76,    77,    78,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    82,    83,
      84,     0,     0,     0,     0,     0,   120,     0,    85,    86,
      75,    76,    77,    78,    79,    80,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,     0,     0,    81,    82,
      83,    84,     0,     0,   129,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,    85,    86,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,     0,     0,
       0,     0,    17,     0,    18,    19,    20,    21,    22,    23,
      24
};

static const yytype_int16 yycheck[] =
{
      18,    36,    37,    90,    39,    11,     8,    16,    17,    18,
      19,    20,    21,     0,    49,    50,    51,    39,    41,    40,
       3,     4,     5,     6,     7,    38,     9,    36,    37,    39,
       9,    39,    39,   120,    26,     9,    45,    46,    43,    22,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    35,    43,    89,    43,    39,    92,    42,    94,
      38,    43,    16,    17,    18,    19,    20,    21,    43,     9,
      43,    24,    44,    91,    44,    93,    44,    39,    43,    23,
      34,    35,    36,    37,    43,     9,    40,    39,    26,    40,
     125,    45,    46,    16,    17,    18,    19,    20,    21,   117,
      16,    17,    18,    19,    20,    21,   130,    74,   126,    40,
      87,   129,    10,    11,    12,    13,    14,    15,    34,    35,
      36,    37,    45,    46,    40,    -1,    -1,    -1,    -1,    45,
      46,    16,    17,    18,    19,    20,    21,    -1,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    -1,    -1,    40,    34,    35,    36,    37,
      45,    46,    40,    -1,    -1,    -1,    -1,    45,    46,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,
      16,    17,    18,    19,    20,    21,    -1,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    -1,    -1,    40,    34,    35,    36,    37,    45,
      46,    -1,    -1,    -1,    -1,    -1,    45,    46,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    25,    26,    27,    28,    29,    30,
      31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    48,     8,     0,    39,    40,    49,    50,    41,
       9,    10,    11,    12,    13,    14,    15,    23,    25,    26,
      27,    28,    29,    30,    31,    52,    53,    55,    56,    57,
      58,    59,    62,    65,    66,    68,    38,    39,    49,    39,
      39,    43,    43,     3,     4,     5,     6,     7,     9,    22,
      35,    39,    60,    61,    69,     9,    63,    64,    42,    52,
      43,    43,    43,     9,    67,    43,    69,    69,    26,    69,
      65,    69,    69,    69,    44,    16,    17,    18,    19,    20,
      21,    34,    35,    36,    37,    45,    46,    44,    51,    38,
      44,    40,    39,    40,    43,    40,    61,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    64,
      69,     9,    68,    49,    69,    49,    69,    24,    54,    40,
      43,    23,    49,    43,    68,    39,    40,    69,    49,    40,
      49,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 66 "sintatica.y"
    {
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n\n" << exibirVarsDeclaradas()  << "\nint main(void)\n{\n" << else_if_string << (yyvsp[(5) - (5)]).traducao << "\treturn 0;\n}" << endl; 
			}
    break;

  case 3:
#line 72 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(3) - (5)]).traducao;
				(yyval).tamanho = (yyvsp[(3) - (5)]).tamanho;

				cout << "taamnaho aqui 33" << endl;
				cout << (yyval).tamanho << endl;
			}
    break;

  case 4:
#line 81 "sintatica.y"
    {
				Var_table escopo;
				pushEsc(tack,escopo);
				
				(yyval).traducao = "";
				(yyval).label = "";
			}
    break;

  case 5:
#line 89 "sintatica.y"
    {
				popEsc(tack);
				
				(yyval).traducao = "";
				(yyval).label = "";
			}
    break;

  case 6:
#line 98 "sintatica.y"
    {

				cout << "taamnaho aqui 22" << endl;
				cout << (yyval).tamanho << endl;

				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;

				(yyval).tamanho = (yyvsp[(1) - (2)]).tamanho;




			}
    break;

  case 7:
#line 112 "sintatica.y"
    {
				(yyval).traducao = "";
			}
    break;

  case 8:
#line 118 "sintatica.y"
    {

				int tipo_atual = tipoResult((yyvsp[(3) - (5)]).tipo, (yyvsp[(3) - (5)]).tipo);

				// IF aceita bool e int
				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT )
				{
					cout << "nao aceita esse tipo no if" << endl;
					exit(0);
				}

				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), (yyvsp[(3) - (5)]).tamanho);
				string gotoText = geradorTextGoto(TK_IF); //$1.tipo

				string line = (yyvsp[(3) - (5)]).traducao; 
				line += "\t" +nome+ " = !" +(yyvsp[(3) - (5)]).label+ ";\n";

				(yyval).traducao = line + "\tif(" +nome+ ") goto " +gotoText+ ";\n";
				(yyval).traducao += (yyvsp[(5) - (5)]).traducao+ "\n";
				(yyval).traducao += "\t" +gotoText+ ":\n";

			}
    break;

  case 9:
#line 142 "sintatica.y"
    {
				int tipo_atual = tipoResult((yyvsp[(3) - (6)]).tipo, (yyvsp[(3) - (6)]).tipo);

				// IF aceita bool e int
				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT )
				{
					cout << "nao aceita esse tipo no if" << endl;
					exit(0);
				}

				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), (yyvsp[(3) - (6)]).tamanho);
				string gotoText_ir_para_else = geradorTextGoto(TK_IF); //$1.tipo

				string line = (yyvsp[(3) - (6)]).traducao;
				line += "\t" +nome+ " = !" +(yyvsp[(3) - (6)]).label+ ";\n";


				// $$.traducao = line + "\tif(" +$3.label+ "){\n" +$5.traducao+ "\t}\n";
				// $$.traducao += $6.traducao;

				(yyval).traducao = line + "\tif(" +nome+ ") goto " +gotoText_ir_para_else+ ";\n";
				(yyval).traducao += (yyvsp[(5) - (6)]).traducao+ "\n";
				(yyval).traducao += "\tgoto " +(yyvsp[(6) - (6)]).label+ ";\n";
				(yyval).traducao += "\t" +gotoText_ir_para_else+ ":\n";
				(yyval).traducao += (yyvsp[(6) - (6)]).traducao;


				

			}
    break;

  case 10:
#line 174 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 11:
#line 178 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);

				// cout << "AQUIII ________ \n" << "Label: " << $1.label << "\nTrad: " << $1.traducao << "\n ACABOUU ---" <<endl; 
			}
    break;

  case 12:
#line 184 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
			}
    break;

  case 13:
#line 188 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);

			}
    break;

  case 14:
#line 193 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);

			}
    break;

  case 15:
#line 198 "sintatica.y"
    {
				(yyval).traducao = "\tbreak;\n";
			}
    break;

  case 16:
#line 202 "sintatica.y"
    {
				(yyval).traducao = "\tcontinue;\n";

			}
    break;

  case 17:
#line 210 "sintatica.y"
    {
				string gotoText_final_if = geradorTextGoto(TK_IF); // ou $1.tipo e mudar a func

				(yyval).traducao += (yyvsp[(2) - (2)]).traducao+ "\n";
				(yyval).traducao += "\t" +gotoText_final_if+ ":\n";

				(yyval).label = gotoText_final_if;


			}
    break;

  case 18:
#line 221 "sintatica.y"
    {

				int tipo_atual = tipoResult((yyvsp[(4) - (6)]).tipo, (yyvsp[(4) - (6)]).tipo);

				// IF aceita bool e int
				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT )
				{
					cout << "nao aceita esse tipo no if" << endl;
					exit(0);
				}

				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), (yyvsp[(4) - (6)]).tamanho);
				string gotoText_final_if = geradorTextGoto(TK_IF); //$1.tipo

				string line = (yyvsp[(4) - (6)]).traducao; 
				line += "\t" +nome+ " = !" +(yyvsp[(4) - (6)]).label+ ";\n";

				(yyval).traducao = line + "\tif(" +nome+ ") goto " +gotoText_final_if+ ";\n";
				(yyval).traducao += (yyvsp[(6) - (6)]).traducao+ "\n";
				(yyval).traducao += "\t" +gotoText_final_if+ ":\n";


				(yyval).label = gotoText_final_if;


				// // string line = $4.traducao;
				// else_if_string += $4.traducao;
				// // deletadorDeVariavel($4.label);


				// $$.traducao = "\telse if(" +$4.label+ "){\n" +$6.traducao+ "\t}\n";

			}
    break;

  case 19:
#line 256 "sintatica.y"
    {
				int tipo_atual = tipoResult((yyvsp[(4) - (7)]).tipo, (yyvsp[(4) - (7)]).tipo);

				// IF aceita bool e int
				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT )
				{
					cout << "nao aceita esse tipo no if" << endl;
					exit(0);
				}

				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), (yyvsp[(4) - (7)]).tamanho);
				string gotoText_ir_para_else = geradorTextGoto(TK_IF); //$1.tipo

				string line = (yyvsp[(4) - (7)]).traducao;
				line += "\t" +nome+ " = !" +(yyvsp[(4) - (7)]).label+ ";\n";

				(yyval).traducao = line + "\tif(" +nome+ ") goto " +gotoText_ir_para_else+ ";\n";
				(yyval).traducao += (yyvsp[(6) - (7)]).traducao+ "\n";
				(yyval).traducao += "\tgoto " +(yyvsp[(7) - (7)]).label+ ";\n";
				(yyval).traducao += "\t" +gotoText_ir_para_else+ ":\n";
				(yyval).traducao += (yyvsp[(7) - (7)]).traducao;

				(yyval).label = (yyvsp[(7) - (7)]).label;


				// else_if_string += $4.traducao;
				// // deletadorDeVariavel($4.label);



				// $$.traducao = "\telse if(" +$4.label+ "){\n" +$6.traducao+ "\t}\n";
				// $$.traducao += $7.traducao;
			}
    break;

  case 20:
#line 293 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 21:
#line 297 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 22:
#line 301 "sintatica.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			}
    break;

  case 23:
#line 306 "sintatica.y"
    {
				int tipo_atual = tipoResult((yyvsp[(5) - (7)]).tipo, (yyvsp[(5) - (7)]).tipo);

				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT)
				{
					cout << "nao aceita esse tipo no while" << endl;
					exit(0);
				}

				// string nome = geradoraDeNomeDeVariaveis();

				else_if_string += (yyvsp[(5) - (7)]).traducao;

				(yyval).traducao = "\tdo{\n" +(yyvsp[(2) - (7)]).traducao+ "\t}\n\twhile(" +(yyvsp[(5) - (7)]).label+ ")\n";
				// $$.traducao = "\tdo{\n" +$2.traducao+ "\t}\n\twhile(" +$5.label+ ");\n";
				// $$.traducao = "\twhile(" +$5.label+ "){\n" +$5.traducao+ "\t}\n";
			}
    break;

  case 24:
#line 325 "sintatica.y"
    {
				int tipo_atual = tipoResult((yyvsp[(3) - (5)]).tipo, (yyvsp[(3) - (5)]).tipo);

				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT)
				{
					cout << "nao aceita esse tipo no while" << endl;
					exit(0);
				}
				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), (yyvsp[(3) - (5)]).tamanho);
				string gotoText_final_if = geradorTextGoto(TK_IF); //$1.tipo

				string line = (yyvsp[(3) - (5)]).traducao; 
				line += "\t" +nome+ " = !" +(yyvsp[(3) - (5)]).label+ ";\n";

				(yyval).traducao = line + "\tif(" +nome+ ") goto " +gotoText_final_if+ ";\n";
				(yyval).traducao += (yyvsp[(5) - (5)]).traducao+ "\n";
				(yyval).traducao += "\t" +gotoText_final_if+ ":\n";


				(yyval).label = gotoText_final_if;


				// else_if_string += $3.traducao;

				// $$.traducao = "\twhile(" +$3.label+ "){\n" +$5.traducao+ "\t}\n";





			}
    break;

  case 25:
#line 359 "sintatica.y"
    {

				int tipo_atual = tipoResult((yyvsp[(3) - (9)]).tipo, (yyvsp[(3) - (9)]).tipo);

				if (tipo_atual != TK_TIPO_INT)
				{
					cout << "nao aceita esse tipo no for" << endl;
					exit(0);
				}

				else_if_string += (yyvsp[(3) - (9)]).traducao;

				(yyval).traducao = "\tfor(" +(yyvsp[(3) - (9)]).label+ " ; " +(yyvsp[(5) - (9)]).label+ ";" +(yyvsp[(7) - (9)]).label+ "){\n" +(yyvsp[(9) - (9)]).traducao+ "\t}\n";


				cout << (yyvsp[(3) - (9)]).label <<endl;



			}
    break;

  case 26:
#line 381 "sintatica.y"
    {

				(yyval).traducao = "\tstd::cout << " +(yyvsp[(2) - (2)]).traducao+ "std::endl;\n";

				// cout << "DSADSADSA<" << endl;

			}
    break;

  case 27:
#line 390 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
			}
    break;

  case 28:
#line 394 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 29:
#line 399 "sintatica.y"
    {
				else_if_string += (yyvsp[(1) - (1)]).traducao;
				// deletadorDeVariavel($1.label);
				(yyval).traducao = (yyvsp[(1) - (1)]).label + " << ";

			}
    break;

  case 30:
#line 408 "sintatica.y"
    {

				(yyval).traducao = "\tstd::cin " +(yyvsp[(2) - (2)]).traducao+ ";\n";

				// cout << "DSADSADSA<" << endl;

			}
    break;

  case 31:
#line 417 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
			}
    break;

  case 32:
#line 421 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 33:
#line 426 "sintatica.y"
    {
				else_if_string += (yyvsp[(1) - (1)]).traducao;
				// deletadorDeVariavel($1.label);
				(yyval).traducao = " >> " +(yyvsp[(1) - (1)]).label;

			}
    break;

  case 34:
#line 436 "sintatica.y"
    {
				(yyvsp[(2) - (2)]).tipo = (yyvsp[(1) - (2)]).tipo;
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;

				(yyval).tamanho = (yyvsp[(2) - (2)]).tamanho;



				// cout << "AQUIII ________ \n" << "Label: " << $$.label << "\nTrad: " << $$.traducao << "\n ACABOUU ---" <<endl; 

			}
    break;

  case 35:
#line 450 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_INT;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 36:
#line 455 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_FLOAT;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 37:
#line 460 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_CHAR;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 38:
#line 465 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 39:
#line 470 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_STRING;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 40:
#line 476 "sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 41:
#line 482 "sintatica.y"
    {
				// cout << "VARLIST, TK_ID _______" <<endl;

				string nome = geradoraDeNomeDeVariaveis();
				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;

				variavel v = criadorDeVariavel((yyvsp[(3) - (3)]).label, nome, getTipoString((yyvsp[(0) - (3)]).tipo), 0);
				// addVarEsc(tack, v);

				// cout << " ->>>> " << tack->variaveis_map[0][$3.label].var_name << endl;
				// cout << " ->>>> " << tack->variaveis_map[0][$3.label].temp_name << endl;
				// cout << " ->>>> " << tack->variaveis_map[0][$3.label].tipo << endl;

			}
    break;

  case 42:
#line 497 "sintatica.y"
    {
				// verificar [to-do] tudo
				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;

				(yyvsp[(1) - (3)]).tipo = (yyvsp[(0) - (3)]).tipo;
				(yyvsp[(3) - (3)]).tipo = (yyvsp[(0) - (3)]).tipo;

				cout << "label>>>>> " << (yyvsp[(1) - (3)]).label << endl;
				cout << "traducao>>>>> " << (yyvsp[(1) - (3)]).traducao << endl;

				cout << "label>>>>> " << (yyvsp[(3) - (3)]).label << endl;
				cout << "traducao>>>>> " << (yyvsp[(3) - (3)]).traducao << endl;

			}
    break;

  case 43:
#line 512 "sintatica.y"
    {
				// cout << "TK_ID = E_______ " << $1.label <<endl;
				string nome = geradoraDeNomeDeVariaveis();
				// inferir tipo
				string tipo_v = "";

				// se o tipo foi dito -> int x = 9
				if (getTipoString((yyvsp[(0) - (3)]).tipo) != "")
				{	
					// cout << "1" << endl;
					tipo_v = getTipoString((yyvsp[(0) - (3)]).tipo);
				}
				else // se tipo nao foi dito -> x = 9
				{
					// cout << "2" << endl;
					// cout << $3.tipo << endl;

					tipo_v = getTipoString((yyvsp[(3) - (3)]).tipo);
				}

				// tipo da expressao = bool e tipo da variavel nao for bool
				if ((yyvsp[(3) - (3)]).tipo == TK_TIPO_BOOL && tipo_v != "bool")
				{
					cout << error_msg << endl;
					cout << "tipo de expressao = bool e tipo variavel != bool" << endl;
					exit(0);
				}

				// if (tipo_v == "string")
				// {
					// cout << "é igual string" << endl;
					// cout << $3.label << endl;
					// cout << $3.tamanho << endl;
				// }


				variavel v = criadorDeVariavel((yyvsp[(1) - (3)]).label, nome, tipo_v, (yyvsp[(3) - (3)]).tamanho);
				(yyval).tamanho = (yyvsp[(3) - (3)]).tamanho;

				cout << "Tamanhoa aqui" << endl;
				cout << (yyval).tamanho << endl;

				// addVarEsc(tack, v);

				// cout << " ->>>> " << tack->variaveis_map[0][$1.label].var_name << endl;
				// cout << " ->>>> " << tack->variaveis_map[0][$1.label].temp_name << endl;
				// cout << " ->>>> " << tack->variaveis_map[0][$1.label].tipo << endl;

				// cout << " ->>>> " << getTipoString($3.tipo) << endl;


				// cout << " ->>>> " << getVarPorNome($1.label).var_name << endl;
				// cout << " ->>>> " << getVarPorNome($1.label).temp_name << endl;
				// cout << " ->>>> " << getVarPorNome($1.label).tipo << endl;


				variavel minha_var = getVarPorNome((yyvsp[(1) - (3)]).label);

				// variavel com tipo diferente da expressao
				if (minha_var.tipo != getTipoString((yyvsp[(3) - (3)]).tipo))
				{
					string nomeReal = geradoraDeNomeDeVariaveis();

					// castiando [to-do] verificar isso aqui, se nomeReal troca de lugar com nome
					(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao; 
					(yyval).traducao += "\t" + nome + " = (" + minha_var.tipo + ") " + (yyvsp[(3) - (3)]).label +";\n";
					(yyval).traducao += "\t" + nomeReal + " = " + nome + ";\n";
					
					v = criadorDeVariavel(nomeReal, nomeReal, minha_var.tipo, 0);
				}
				else{ // se o tipo eh igual

					(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\t" + nome + " = " + (yyvsp[(3) - (3)]).label + ";\n";

				}
	 
			}
    break;

  case 44:
#line 590 "sintatica.y"
    {
				// cout << "TK_ID _______" <<endl;

				// tipo nome_var;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).label = (yyvsp[(1) - (1)]).label;

				variavel v = criadorDeVariavel((yyval).label, geradoraDeNomeDeVariaveis(), getTipoString((yyvsp[(0) - (1)]).tipo), 0);

				// cout << v.var_name << endl;

				// addVarEsc(tack, v);

				// for (int i = 0; i < tack->variaveis_map.size(); ++i)
				// {
					// cout << " ->>>> " << tack->variaveis_map[0][$$.label].var_name << endl;
					// cout << " ->>>> " << tack->variaveis_map[0][$$.label].temp_name << endl;
					// cout << " ->>>> " << tack->variaveis_map[0][$$.label].tipo << endl;
					 
				// }

			}
    break;

  case 45:
#line 615 "sintatica.y"
    {
				variavel v = getVarPorNome((yyvsp[(1) - (3)]).label);
				string nome = v.temp_name;

				(yyval).tamanho = (yyvsp[(3) - (3)]).tamanho;


				// variavel nao existe
				if (nome == "")
				{
					string tipo_v;

					nome = geradoraDeNomeDeVariaveis();


					// cout << getTipoString($-2.tipo) << endl;

					// cout << getTipoString($3.tipo) << endl;

					// $-2 pois pra chegar em ATRIB eu vim por VARLIST de DECLARATION
					// se vier direto de COMANDO deve ser $0
					if (getTipoString((yyvsp[(-2) - (3)]).tipo) != "")
					{	
						tipo_v = getTipoString((yyvsp[(-2) - (3)]).tipo);
						// cout << "1" << endl;
					}
					else // se tipo nao foi dito -> x = 9
					{
						tipo_v = getTipoString((yyvsp[(3) - (3)]).tipo);
						// cout << "2" << endl;
						
					}

					// tipo da expressao = bool e tipo da variavel nao for bool
					if ((yyvsp[(3) - (3)]).tipo == TK_TIPO_BOOL && tipo_v != "bool")
					{
						cout << error_msg << endl;
						cout << "tipo de expressao = bool e tipo variavel != bool" << endl;

						exit(0);
					}

					v = criadorDeVariavel((yyvsp[(1) - (3)]).label, nome, tipo_v, (yyvsp[(3) - (3)]).tamanho);




				}
				else{
					// if (getTipoString($0.tipo) != "")
					// {	
					// 	tipo_v = getTipoString($0.tipo);
					// 	cout << "1" << endl;
					// }
					
					if ((yyvsp[(3) - (3)]).tipo == TK_TIPO_BOOL && v.tipo != "bool")
					{
						cout << error_msg << endl;
						cout << "tipo de expressao = bool e tipo variavel != bool" << endl;

						exit(0);
					}
				}




				if (v.tipo != getTipoString((yyvsp[(3) - (3)]).tipo))
				{
					string nomeReal = geradoraDeNomeDeVariaveis();

					// castiando [to-do] verificar isso aqui, se nomeReal troca de lugar com nome
					(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao; 
					(yyval).traducao += "\t" + nome + " = (" + v.tipo + ") " + (yyvsp[(3) - (3)]).label +";\n";
					(yyval).traducao += "\t" + nomeReal + " = " + nome + ";\n";
					
					v = criadorDeVariavel(nomeReal, nomeReal, v.tipo, 0);
				}
				else{ // se o tipo eh igual

					(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\t" + nome + " = " + (yyvsp[(3) - (3)]).label + ";\n";

				}

				// cout << "TA AQUI2" << endl;




			}
    break;

  case 46:
#line 708 "sintatica.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
			}
    break;

  case 47:
#line 712 "sintatica.y"
    {
				(yyval).tipo = (yyvsp[(2) - (2)]).tipo;

				string nome = geradoraDeNomeDeVariaveis();
				// temp(x+1) = -temp(x); usa -temp(x)
				// $$.label = "-" + $2.label; 
				// temp(x+1) = -temp(x); usa temp(x+1)
				(yyval).label = nome;

				(yyval).traducao = (yyvsp[(2) - (2)]).traducao + "\t" + nome + " = -" + (yyvsp[(2) - (2)]).label + ";\n";

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);

				 

			}
    break;

  case 48:
#line 729 "sintatica.y"
    {
				(yyval) = tratadoraArith((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), "-");
			}
    break;

  case 49:
#line 733 "sintatica.y"
    {
				if ((yyvsp[(1) - (3)]).tipo == TK_TIPO_STRING && (yyvsp[(3) - (3)]).tipo == TK_TIPO_STRING)
				{
					cout << "TAAAAMMAMAMA" << endl;
					cout << (yyvsp[(1) - (3)]).tamanho << endl;
					cout << (yyvsp[(3) - (3)]).tamanho << endl;
					(yyval) = concatenarStrings((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				}
				else{
					(yyval) = tratadoraArith((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), "+");
				}
			}
    break;

  case 50:
#line 746 "sintatica.y"
    {
				(yyval) = tratadoraArith((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), "*");
			}
    break;

  case 51:
#line 750 "sintatica.y"
    {
				(yyval) = tratadoraArith((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), "/");
			}
    break;

  case 52:
#line 754 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic((yyvsp[(1) - (3)]).tipo, (yyvsp[(1) - (3)]).label, (yyvsp[(3) - (3)]).tipo, (yyvsp[(3) - (3)]).label, ">");

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + result.traducao;
				(yyval).label = result.label;
			}
    break;

  case 53:
#line 763 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic((yyvsp[(1) - (3)]).tipo, (yyvsp[(1) - (3)]).label, (yyvsp[(3) - (3)]).tipo, (yyvsp[(3) - (3)]).label, "<");

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + result.traducao;
				(yyval).label = result.label;
			}
    break;

  case 54:
#line 772 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic((yyvsp[(1) - (3)]).tipo, (yyvsp[(1) - (3)]).label, (yyvsp[(3) - (3)]).tipo, (yyvsp[(3) - (3)]).label, ">=");

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + result.traducao;
				(yyval).label = result.label;
			}
    break;

  case 55:
#line 781 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic((yyvsp[(1) - (3)]).tipo, (yyvsp[(1) - (3)]).label, (yyvsp[(3) - (3)]).tipo, (yyvsp[(3) - (3)]).label, "<=");

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + result.traducao;
				(yyval).label = result.label;
			}
    break;

  case 56:
#line 790 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic((yyvsp[(1) - (3)]).tipo, (yyvsp[(1) - (3)]).label, (yyvsp[(3) - (3)]).tipo, (yyvsp[(3) - (3)]).label, "==");

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + result.traducao;
				(yyval).label = result.label;
			}
    break;

  case 57:
#line 799 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic((yyvsp[(1) - (3)]).tipo, (yyvsp[(1) - (3)]).label, (yyvsp[(3) - (3)]).tipo, (yyvsp[(3) - (3)]).label, "!=");

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + result.traducao;
				(yyval).label = result.label;
			}
    break;

  case 58:
#line 808 "sintatica.y"
    {	
				// bool ou tipo 
				// $$.tipo = TK_TIPO_BOOL;
				string nome = geradoraDeNomeDeVariaveis();

				(yyval).tipo = TK_TIPO_BOOL;
				(yyval).tipo = tipoResult((yyvsp[(1) - (3)]).tipo, (yyvsp[(3) - (3)]).tipo);

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\t" + nome +" = "+ (yyvsp[(1) - (3)]).label +" && "+ (yyvsp[(3) - (3)]).label +";\n";
				
				(yyval).label = nome;
			}
    break;

  case 59:
#line 823 "sintatica.y"
    {	
				// bool ou tipo 
				// $$.tipo = TK_TIPO_BOOL;
				string nome = geradoraDeNomeDeVariaveis();

				(yyval).tipo = TK_TIPO_BOOL;
				(yyval).tipo = tipoResult((yyvsp[(1) - (3)]).tipo, (yyvsp[(3) - (3)]).tipo);

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);

				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao + "\t" + nome +" = "+ (yyvsp[(1) - (3)]).label +" || "+ (yyvsp[(3) - (3)]).label +";\n";

				(yyval).label = nome;
			}
    break;

  case 60:
#line 838 "sintatica.y"
    {	
				// bool ou tipo 
				// $$.tipo = TK_TIPO_BOOL;
				string nome = geradoraDeNomeDeVariaveis();

				(yyval).tipo = tipoResult((yyvsp[(2) - (2)]).tipo, (yyvsp[(2) - (2)]).tipo);

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);


				(yyval).traducao = (yyvsp[(2) - (2)]).traducao + "\t" + nome +" = !"+ (yyvsp[(2) - (2)]).label +";\n";

				(yyval).label = nome;
			}
    break;

  case 61:
#line 853 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_INT;

				string nome = geradoraDeNomeDeVariaveis();
				(yyval).traducao = "\t" + nome + " = " + (yyvsp[(1) - (1)]).label + ";\n";
				(yyval).label = nome;

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);

			}
    break;

  case 62:
#line 864 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_FLOAT;

				string nome = geradoraDeNomeDeVariaveis();
				(yyval).traducao = "\t" + nome + " = " + (yyvsp[(1) - (1)]).label + ";\n";
				(yyval).label = nome;

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);

			}
    break;

  case 63:
#line 875 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_CHAR;

				string nome = geradoraDeNomeDeVariaveis();
				(yyval).traducao = "\t" + nome + " = " + (yyvsp[(1) - (1)]).label + ";\n";
				(yyval).label = nome;

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);
				// [to-do] checar isso $1.label.size() - 2

			}
    break;

  case 64:
#line 887 "sintatica.y"
    {
				variavel v = getVarPorNome((yyvsp[(1) - (1)]).label);

				(yyval).tamanho = v.tamanho;


				// verifica se variavel existe
				if (v.var_name == "")
				{
					cout << error_msg << endl;
					cout << "variavel nao existe" << endl;
					exit(0);
				}
				else{
					(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
					(yyval).label = v.temp_name;
					(yyval).tipo = getTipoToken(v.tipo);
				}

				// cout << "TA AQUI" << endl;
				// cout << $$.label << endl;
				// cout << $$.tipo << endl;

			}
    break;

  case 65:
#line 912 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_BOOL;

				string nome = geradoraDeNomeDeVariaveis();
				(yyval).traducao = "\t" + nome + " = " + (yyvsp[(1) - (1)]).label + ";\n";
				(yyval).label = nome;

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), 0);

			}
    break;

  case 66:
#line 923 "sintatica.y"
    {
				(yyval).tipo = TK_TIPO_STRING;

				string nome = geradoraDeNomeDeVariaveis();
				(yyval).traducao = "\tstrcpy(" + nome + "," + (yyvsp[(1) - (1)]).label + ");\n";
				(yyval).label = nome;

				(yyval).tamanho = (yyvsp[(1) - (1)]).label.size()-2;

				variavel v = criadorDeVariavel(nome, nome, getTipoString((yyval).tipo), (yyvsp[(1) - (1)]).label.size()-2);

			}
    break;


/* Line 1267 of yacc.c.  */
#line 2586 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 937 "sintatica.y"


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

	// for (int i = 0; i < varsDec.size(); ++i)
	// {
	// 	cout << " ->>>> " << getVarPorNome(varsDec[i].var_name).var_name << endl;
	// 	cout << " ->>>> " << getVarPorNome(varsDec[i].var_name).temp_name << endl;
	// 	cout << " ->>>> " << getVarPorNome(varsDec[i].var_name).tipo << "\n" << endl;
	// }

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}

string exibirVarsDeclaradas(){

	// varsDeclaradas varsDec_aux;

	// for (int i = 0; i < varsDec.size(); ++i)
	// {
	// 	variavel v = getVarPorNome(varsDec[i].var_name);

	// 	cout << "VAAAA " << varsDec[i].var_name << endl;
	// 	if ( varsDec.count(v.var_name) )
	// 	{
	// 		cout << "VBBBB " << v.var_name << endl;
		
	// 	}

	// 	varsDec_aux.push_back(v);
	// 	cout << "VCCCC " << varsDec_aux[i].var_name << endl;

	// }

	return getDeclaradas(varsDec);
}
variavel criadorDeVariavel(string nome, string temp_nome, string tipo, int tamanho){

	variavel v;

	if (tipo == "string" && tamanho == 0)
	{
		// criando sting com tamanho predeterminado, deve melhorar [to-do]
		v = criarVar(nome, temp_nome, tipo, 0);
		
	}else{
		v = criarVar(nome, temp_nome, tipo, tamanho);
	}

	addVarEsc(tack, v);
	varsDec.push_back(v);

	return v;
}
 
void deletadorDeVariavel(string nome){

	tack->variaveis_map[tack->escopo_num].erase(nome);
	cout << "APAGOU " << nome << endl;

	exibirVarsDeclaradas();

	// variavel v = getVarPorNome(nome);
	// cout << v.var_name << endl;
	// variavel v = getVarPorNome(nome);
	// delete v;

}
string geradoraDeNomeDeVariaveis(){
	static int num_para_gerar_nomes = 0;
	// string nome;
	// nome = "temp_" + to_string(num_para_gerar_nomes);

	// num_para_gerar_nomes++;
	return "temp_" + to_string(num_para_gerar_nomes++);
}

int getTipoToken(string tipo){

	if (tipo == "int")
		return TK_TIPO_INT;
	if (tipo == "float")
		return TK_TIPO_FLOAT;
	if (tipo == "char")
		return TK_TIPO_CHAR;
	if (tipo == "bool")
		return TK_TIPO_BOOL;
	if (tipo == "string")
		return TK_TIPO_STRING;

	return 0;
}

string getTipoString(int tipo){

	if (tipo == TK_TIPO_INT)
		return "int";
	if (tipo == TK_TIPO_FLOAT)
		return "float";
	if (tipo == TK_TIPO_CHAR)
		return "char";
	if (tipo == TK_TIPO_BOOL)
		return "bool";
	if (tipo == TK_TIPO_STRING)
		return "string";

	return "";
}

atributos tratadoraLogic(int t1, string atr1_label, int t2, string atr2_label, string sinal){

	atributos retorno;
	// o retorno de uma expressao logica deve ser bool
	retorno.tipo = TK_TIPO_BOOL;
	string nome = geradoraDeNomeDeVariaveis();

	// usando a mesma da arith, depois devo mudar pra uma tabela [to-do]
	int tipo_das_entradas = tipoResult(t1, t2);

	if (tipo_das_entradas == TK_TIPO_INT)
	{
		retorno.label = nome;

		retorno.traducao = "\t" + nome + " = " + atr1_label + " " + sinal + " " + atr2_label + ";\n";

		// tipo da variavel deve ser do tipo int por ser um bool, ou deve ser o tipo da tipo_das_entradas? [to-do]
		variavel v =  criadorDeVariavel(nome, nome, getTipoString(tipo_das_entradas), 0);
	}
	else if(tipo_das_entradas == TK_TIPO_FLOAT){

		string nomeReal = geradoraDeNomeDeVariaveis();
		
		retorno.label = nomeReal;

		// variavel usada pra fazer o cast pra float
		variavel v =  criadorDeVariavel(nome, nome, "float", 0);
		// int por ser bool? [to-do]
		v =  criadorDeVariavel(nomeReal, nomeReal, "int", 0);

		if (t1 == TK_TIPO_INT)
		{
			retorno.traducao = "\t" + nome + " = (float) " + atr1_label + ";\n";
			retorno.traducao += "\t" + nomeReal + " = " + nome + " " + sinal + " " + atr2_label + ";\n";
		}
		else if (t2 == TK_TIPO_INT)
		{	
			retorno.traducao = "\t" + nome + " = (float) " + atr2_label + ";\n";
			retorno.traducao += "\t" + nomeReal + " = " + atr1_label + " " + sinal + " " + nomeReal + ";\n";
		}

	}




	return retorno;


}

int tipoResult(int t1, int t2){

	// verificando com if, deveria ter uma tabela, fazer depois por demandar mais tempo

	if ( (t1 != TK_TIPO_FLOAT && t1 != TK_TIPO_INT) || (t2 != TK_TIPO_FLOAT && t2 != TK_TIPO_INT) )
	{

		if (t1 == TK_TIPO_CHAR && t2 == TK_TIPO_CHAR)
		{
			return TK_TIPO_CHAR;
		}
		else if (t1 == TK_TIPO_BOOL && t2 == TK_TIPO_BOOL)
		{
			return TK_TIPO_BOOL;
		}
		else if (t1 == TK_TIPO_STRING && t2 == TK_TIPO_STRING)
		{
			return TK_TIPO_STRING;
		}
		// tipo de operadores invalidos
		cout << error_msg << endl;
		cout << "tipo de operadores invalidos" << endl;
		exit(0);

	}

	if (t1 == TK_TIPO_FLOAT || t2 == TK_TIPO_FLOAT)
	{
		return TK_TIPO_FLOAT;
	}
	else{
		return TK_TIPO_INT;
	}
}

atributos tratarArithComCast(int tipo1, string atr1_label, int tipo2, string atr2_label, string sinal){

	int tipo_atual = tipoResult(tipo1, tipo2);

	string line = "", line2 = "";

	string nome = geradoraDeNomeDeVariaveis();
	string nomeReal = geradoraDeNomeDeVariaveis();

	// devo castiar
	if (tipo_atual == TK_TIPO_FLOAT)
	{
		
		if (tipo1 == TK_TIPO_INT)
		{
			line = "\t" + nome + " = (float) " + atr1_label + ";\n";
			line2 = "\t" + nomeReal + " = " + nome + " " + sinal + " " + atr2_label + ";\n";
		}
		else if (tipo2 == TK_TIPO_INT)
		{
			line = "\t" + nome + " = (float) " + atr2_label + ";\n";
			line2 = "\t" + nomeReal + " = " + atr1_label + " " + sinal + " " + nome + ";\n";
		}

		variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), 0);
		v = criadorDeVariavel(nomeReal, nomeReal, getTipoString(tipo_atual), 0);

	}

	atributos turn;
	turn.traducao = line + line2;
	turn.label = nomeReal;
	return turn;

}

atributos tratadoraArith(atributos a1, atributos a2, string sinal){
	
	atributos retorno;
	cout << "tipo" << endl;
	cout << a1.tipo << endl;
	cout << a2.tipo << endl;
	cout << a1.label << endl;
	retorno.tipo = tipoResult(a1.tipo, a2.tipo);
	

	// sem precisar cast
	if (a1.tipo == a2.tipo)
	{
		string nome = geradoraDeNomeDeVariaveis();
		
		retorno.traducao = a1.traducao + a2.traducao + "\t" + nome + " = " + a1.label + " " + sinal + " " + a2.label + ";\n";
	
		retorno.label = nome;

		variavel v = criadorDeVariavel(nome, nome, getTipoString(retorno.tipo), 0);

	}
	else{ // CASTando

		// fazer o cast dependendo do tipo
		atributos atr = tratarArithComCast(a1.tipo, a1.label, a2.tipo, a2.label, sinal);
		atr.tipo = retorno.tipo;

		retorno.traducao = a1.traducao + a2.traducao + atr.traducao;
	
		retorno.label = atr.label;
	}
	

	return retorno;
}	

atributos concatenarStrings(atributos a1, atributos a2){

	string nome = geradoraDeNomeDeVariaveis();

	variavel v1 = getVarPorNome(a1.label);
	variavel v2 = getVarPorNome(a2.label);
	
	variavel v = criadorDeVariavel(nome, nome, getTipoString(TK_TIPO_STRING), (a1.tamanho + a2.tamanho));

	cout << "nome" << endl;
	cout << nome << endl;
	cout << a1.tamanho << endl;
	cout << a2.tamanho << endl;
	cout << v.tamanho << endl;

	string l1 = "\tstrcat(" +nome+ ", " +a1.label+ ");\n";
	string l2 = "\tstrcat(" +nome+ ", " +a2.label+ ");\n";

	atributos atr;
	atr.label = nome;
	atr.traducao = l1 + l2;
	atr.tipo = TK_TIPO_STRING;
	atr.tamanho = (a1.tamanho + a2.tamanho);

	cout << "nome" << endl;

	return atr;

}


variavel getVarPorNome(string name){

	// quando for blocos devo procurar no vetor

	Var_table vt = tack->variaveis_map[tack->escopo_num];

	// variavel ja declarada
	if ( vt.count(name) )
	{
		// cout << "achou " << name <<endl;
		return vt[name];
	}
	else {
		int esc = tack->escopo_num-1;
		// cout << "esc " << esc << endl;
		for (int i = esc; i > -1; i--)
		{
			Var_table vt = tack->variaveis_map[i];

			if ( vt.count(name) )
			{
				// cout << "achou " << name <<endl;

				return vt[name];
			}
		} 
	}
	// cout << "_______ " << tack->variaveis_map[tack->escopo_num][name].var_name << endl;
	// return criarVar("", "", "",  0);
	// return tack->variaveis_map[tack->escopo_num][name];

	cout << "Essa variavel nao 'existe'" << endl;
	return vt[0];
}

string geradorTextGoto(int token){
	static int num_label = 0;
	
	if (token == TK_IF)
	{
		return "token_if_" + to_string(num_label++);
	}
	else if (token == TK_FOR)
	{
		return "token_for_" +to_string(num_label++);
	}

	return "ISSo nao deveria estar retornando 1 ";
}




