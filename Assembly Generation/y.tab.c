/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#line 1 "1505088_Offline4.y" /* yacc.c:339  */

#include<bits/stdc++.h>
#include<stdio.h>
#include "SymbolTable.h"
//#define YYSTYPE SymbolInfo*

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
extern int line_count;
extern int error_count;
FILE *logout;	
FILE *errorFile;
FILE *codeFile;
string typeInfo;
int labelCount = 0;
int tempCount =0;
vector<string> idVect;
vector<string> arrayVect;
vector<int> arrayVectIndex;

SymbolTable table(7);

void yyerror(const char *s)
{
	//write your code
	fprintf(errorFile,"At line no. %d: %s\n",line_count,s);
	error_count++;
	return;
}

char *newLable()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	strcat(t,b);
	return t;
}



#line 124 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    DO = 262,
    BREAK = 263,
    CONTINUE = 264,
    INT = 265,
    FLOAT = 266,
    CHAR = 267,
    DOUBLE = 268,
    VOID = 269,
    RETURN = 270,
    SWITCH = 271,
    CASE = 272,
    DEFAULT = 273,
    LPAREN = 274,
    RPAREN = 275,
    LCURL = 276,
    RCURL = 277,
    LTHIRD = 278,
    RTHIRD = 279,
    SEMICOLON = 280,
    COMMA = 281,
    STRING = 282,
    NOT = 283,
    PRINTLN = 284,
    COMMENT = 285,
    INCOP = 286,
    DECOP = 287,
    ASSIGNOP = 288,
    BITOP = 289,
    ID = 290,
    CONST_INT = 291,
    CONST_FLOAT = 292,
    CHAR_CONST = 293,
    ADDOP = 294,
    MULOP = 295,
    RELOP = 296,
    LOGICOP = 297,
    less_than_else = 298
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define CONTINUE 264
#define INT 265
#define FLOAT 266
#define CHAR 267
#define DOUBLE 268
#define VOID 269
#define RETURN 270
#define SWITCH 271
#define CASE 272
#define DEFAULT 273
#define LPAREN 274
#define RPAREN 275
#define LCURL 276
#define RCURL 277
#define LTHIRD 278
#define RTHIRD 279
#define SEMICOLON 280
#define COMMA 281
#define STRING 282
#define NOT 283
#define PRINTLN 284
#define COMMENT 285
#define INCOP 286
#define DECOP 287
#define ASSIGNOP 288
#define BITOP 289
#define ID 290
#define CONST_INT 291
#define CONST_FLOAT 292
#define CHAR_CONST 293
#define ADDOP 294
#define MULOP 295
#define RELOP 296
#define LOGICOP 297
#define less_than_else 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 58 "1505088_Offline4.y" /* yacc.c:355  */

symboInfo* symbol;

#line 254 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 271 "y.tab.c" /* yacc.c:358  */

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   132

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,   116,   125,   134,   139,   144,   151,   172,
     193,   235,   285,   306,   311,   330,   338,   338,   338,   338,
     346,   346,   346,   354,   362,   370,   378,   388,   416,   469,
     498,   553,   559,   571,   576,   581,   586,   605,   620,   639,
     657,   674,   686,   692,   703,   736,   777,   782,   804,   809,
     864,   869,   917,   922,   949,   954,   988,  1000,  1010,  1017,
    1033,  1070,  1077,  1088,  1096,  1103,  1112,  1116,  1119,  1123
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DO",
  "BREAK", "CONTINUE", "INT", "FLOAT", "CHAR", "DOUBLE", "VOID", "RETURN",
  "SWITCH", "CASE", "DEFAULT", "LPAREN", "RPAREN", "LCURL", "RCURL",
  "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", "STRING", "NOT", "PRINTLN",
  "COMMENT", "INCOP", "DECOP", "ASSIGNOP", "BITOP", "ID", "CONST_INT",
  "CONST_FLOAT", "CHAR_CONST", "ADDOP", "MULOP", "RELOP", "LOGICOP",
  "less_than_else", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "parameter_list",
  "compound_statement", "$@1", "$@2", "$@3", "$@4", "$@5",
  "var_declaration", "type_specifier", "declaration_list", "statements",
  "statement", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -21

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      18,   -75,   -75,   -75,     6,    18,   -75,   -75,   -75,   -75,
      -9,   -75,   -75,    11,    -7,     3,     4,   -75,    -2,    25,
      -5,    16,    34,    39,    42,   -75,   -75,    27,    18,   -75,
     -75,    44,    60,    55,   -75,   -75,    43,    58,    64,    67,
      68,    75,    75,   -75,    75,    72,    30,   -75,   -75,    75,
     -75,   -75,    57,    60,   -75,   -75,    28,    73,   -75,    63,
      15,    66,   -75,   -75,   -75,   -75,   -75,    75,    65,    75,
      82,    88,    41,   -75,    74,    75,    75,   -75,    90,    93,
     -75,   -75,   -75,    75,   -75,    75,    75,    75,    75,   -75,
      96,    65,    97,   -75,   -75,    98,   -75,    99,    94,   100,
     -75,   -75,   -75,    66,    83,   -75,    60,    75,    60,   101,
     -75,    75,   -75,   -75,   117,   103,   -75,   -75,   -75,    60,
      60,   -75,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    24,    25,    26,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    29,     0,     0,     0,    23,     0,     0,
       0,    15,     0,    27,    16,     9,    11,     0,     0,    14,
      30,     0,     0,     0,     8,    10,    13,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    44,    62,    63,     0,
      35,    33,     0,    17,    31,    34,    59,     0,    46,    48,
      50,    52,    54,    58,    21,    12,    28,     0,     0,     0,
       0,     0,    59,    57,     0,    67,     0,    56,    29,     0,
      32,    64,    65,     0,    43,     0,     0,     0,     0,    22,
       0,     0,     0,    41,    61,     0,    69,     0,    66,     0,
      18,    47,    49,    53,    51,    55,     0,     0,     0,     0,
      60,     0,    45,    19,    37,     0,    39,    40,    68,     0,
       0,    38,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,   -75,   120,   -75,   -75,   -75,    -3,   -75,   -75,
     -75,   -75,   -75,    20,     7,   -75,   -75,   -51,   -64,   -44,
     -31,   -74,    45,    40,    46,   -41,   -75,   -75,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    20,    50,    32,    79,
     113,    33,    89,    51,    52,    14,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    97,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      72,    96,    80,    73,    91,    72,    11,    10,    77,   101,
      70,    71,    10,     1,     2,    27,    26,     3,    17,    18,
       9,    28,    21,    19,    35,     9,    13,   107,     1,     2,
      15,    72,     3,    23,    16,    36,    90,   118,    92,    72,
      22,    72,    72,    72,    72,    99,    24,   105,    24,    75,
      25,    29,    34,    76,    86,   114,    87,   116,    30,    81,
      82,    83,    31,    38,   -20,    39,    40,    72,   121,   122,
       1,     2,    81,    82,     3,    41,   115,    64,    65,    42,
      37,    24,    66,    67,    42,    43,    68,    69,    44,    45,
      43,    74,    78,    44,    42,    46,    47,    48,    84,    49,
      46,    47,    48,    44,    49,    85,    88,    93,    94,    95,
      46,    47,    48,    16,    49,   100,   106,   108,   109,   110,
     111,   119,    86,   120,   112,    12,   117,   104,     0,     0,
     102,     0,   103
};

static const yytype_int8 yycheck[] =
{
      44,    75,    53,    44,    68,    49,     0,     0,    49,    83,
      41,    42,     5,    10,    11,    20,    19,    14,    25,    26,
       0,    26,    15,    20,    27,     5,    35,    91,    10,    11,
      19,    75,    14,    35,    23,    28,    67,   111,    69,    83,
      36,    85,    86,    87,    88,    76,    21,    88,    21,    19,
      25,    35,    25,    23,    39,   106,    41,   108,    24,    31,
      32,    33,    23,     3,    22,     5,     6,   111,   119,   120,
      10,    11,    31,    32,    14,    15,   107,    22,    35,    19,
      36,    21,    24,    19,    19,    25,    19,    19,    28,    29,
      25,    19,    35,    28,    19,    35,    36,    37,    25,    39,
      35,    36,    37,    28,    39,    42,    40,    25,    20,    35,
      35,    36,    37,    23,    39,    22,    20,    20,    20,    20,
      26,     4,    39,    20,    24,     5,    25,    87,    -1,    -1,
      85,    -1,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    14,    45,    46,    47,    48,    49,    57,
      58,     0,    47,    35,    59,    19,    23,    25,    26,    20,
      50,    58,    36,    35,    21,    25,    51,    20,    26,    35,
      24,    23,    52,    55,    25,    51,    58,    36,     3,     5,
       6,    15,    19,    25,    28,    29,    35,    36,    37,    39,
      51,    57,    58,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    22,    35,    24,    19,    19,    19,
      64,    64,    63,    69,    19,    19,    23,    69,    35,    53,
      61,    31,    32,    33,    25,    42,    39,    41,    40,    56,
      64,    62,    64,    25,    20,    35,    65,    71,    72,    64,
      22,    65,    66,    68,    67,    69,    20,    62,    20,    20,
      20,    26,    24,    54,    61,    64,    61,    25,    65,     4,
      20,    61,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    48,    48,
      49,    49,    50,    50,    50,    50,    52,    53,    54,    51,
      55,    56,    51,    57,    58,    58,    58,    59,    59,    59,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    69,    70,
      70,    70,    70,    70,    70,    70,    71,    71,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     5,     4,     3,     2,     1,     0,     0,     0,     6,
       0,     0,     4,     3,     1,     1,     1,     3,     6,     1,
       4,     1,     2,     1,     1,     1,     7,     5,     7,     5,
       5,     3,     1,     2,     1,     4,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     2,     2,     1,     1,
       4,     3,     1,     1,     2,     2,     1,     0,     3,     1
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
#line 97 "1505088_Offline4.y" /* yacc.c:1646  */
    {
		//write your code in this block in all the similar blocks below
		fprintf(logout,"\nAt line no. %d start : program\n",line_count);
		//$$ = $1;
		fprintf(codeFile,".MODEL SMALL\n\n.STACK 100H\n\n.DATA\n\n.CODE\n\n");
		for(int i=0 ; i<idVect.size();i++){
			fprintf(codeFile,"%s",idVect[i].c_str());
			fprintf(codeFile," dw ? \n");
		}
		for(int i=0 ; i<arrayVect.size();i++){
			fprintf(codeFile,"%s",arrayVect[i].c_str());
			fprintf(codeFile," dw %d DUP(?)\n",arrayVectIndex[i]);
		}
		fprintf(codeFile,"\n%s",(yyvsp[0].symbol)->code.c_str());
		string outdec = "\nOUTDEC PROC\n\tPUSH AX\n\tPUSH BX\n\tPUSH CX\n\tPUSH DX\n\n\tOR AX,AX\n\tJGE NEXT\n\n\tPUSH AX\n\tMOV AH,2\n\tMOV DL,'-'\n\tINT 21h\n\tPOP AX\n\tNEG AX\n\nNEXT:\n\tXOR CX,CX\n\tMOV BX,10D\n\nASIF:\n\tXOR DX,DX\n\tDIV BX\n\tPUSH DX\n\tINC CX\n\tOR AX,AX\n\tJNE ASIF\n\n\tMOV AH,2\nPRINT_LOOP:\n\tPOP DX\n\tOR DL,30H\n\tINT 21h\n\tLOOP PRINT_LOOP\n\n\tMOV DL,' '\n\tINT 21h\n\n\tPOP DX\n\tPOP CX\n\tPOP BX\n\tPOP AX\n\tRET\nOUTDEC ENDP\nEND MAIN\n";
		fprintf(codeFile,"%s",outdec.c_str());
	}
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 117 "1505088_Offline4.y" /* yacc.c:1646  */
    {
		fprintf(logout,"\nAt line no. %d program : program unit\n",line_count);
		(yyval.symbol)->symboPrint = (yyvsp[-1].symbol)->symboPrint +"\n"+ (yyvsp[0].symbol)->symboPrint ;
		(yyval.symbol) = (yyvsp[-1].symbol);
		(yyval.symbol)->code += (yyvsp[0].symbol)->code;
		fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
	}
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 126 "1505088_Offline4.y" /* yacc.c:1646  */
    {
		(yyval.symbol) = (yyvsp[0].symbol);
		//cout<<"\n\n\n\n\n"<<$$->code;
		fprintf(logout,"\nAt line no. %d program : unit\n",line_count);
		fprintf(logout,"%s\n\n",(yyval.symbol)->symboPrint.c_str());
	}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 135 "1505088_Offline4.y" /* yacc.c:1646  */
    {
		(yyval.symbol) = (yyvsp[0].symbol);
		fprintf(logout,"\nAt line no. %d unit : var_declaration\n",line_count);
	}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 140 "1505088_Offline4.y" /* yacc.c:1646  */
    {
		(yyval.symbol) = (yyvsp[0].symbol);
		fprintf(logout,"\nAt line no. %d unit : func_declaration\n",line_count);
	}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 145 "1505088_Offline4.y" /* yacc.c:1646  */
    {
		(yyval.symbol) = (yyvsp[0].symbol);
		fprintf(logout,"\nAt line no. %d unit : func_definition\n",line_count);
	}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 152 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				fprintf(logout,"\nAt line no. %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n",line_count);
				//fprintf(logout,"\n%s %s( %s);\n",($1->getName()).c_str(),($2->getName()).c_str(),$4->getName().c_str());
				symboInfo *st1 = table.LookUpSymbol((yyvsp[-4].symbol)->getName(),"FUNC");
				//int st1 = table.LookUpSymbol($2->getName());
				if(st1 != NULL)
				{
					fprintf(errorFile,"Error at line %d : multiple declaration of %s \n",line_count,(yyvsp[-4].symbol)->getName().c_str());
					error_count++;		
				}
				else
				{		
					symboInfo* tmp = table.InsertSymbol((yyvsp[-4].symbol)->getName(),"FUNC");
					tmp->setTypeSpecifier((yyvsp[-5].symbol)->getName());
					(yyval.symbol)->symboPrint = (yyvsp[-5].symbol)->getName() + " " +(yyvsp[-4].symbol)->getName() + "("+(yyvsp[-2].symbol)->symboPrint+")"+";" + "\n";
					fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
					printf("\n%s\n",tmp->getTypeSpecifier().c_str());
				} 
			}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 173 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				fprintf(logout,"\nAt line no. %d func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n",line_count);
				symboInfo *st1 = table.LookUpSymbol((yyvsp[-3].symbol)->getName(),"FUNC");
				//int st1 = table.LookUpSymbol($2->getName());
				if(st1 != NULL)
				{
					fprintf(errorFile,"Error at line %d : multiple declaration of \n",line_count);
					error_count++;		
				}
				else
				{		
					symboInfo* temp = table.InsertSymbol((yyvsp[-3].symbol)->getName(),"FUNC");
					temp->setTypeSpecifier((yyvsp[-4].symbol)->getName());
					(yyval.symbol)->symboPrint = (yyvsp[-4].symbol)->getName() + " " +(yyvsp[-3].symbol)->getName() + "(" + ")" + ";";
					fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
					printf("Success1");
				} 
			}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 194 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d : func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n",line_count);
			symboInfo *st1 = table.LookUpSymbol((yyvsp[-4].symbol)->getName(),"FUNC");
			//cout<<st1->getTypeSpecifier()<<"--hello";
				//int st1 = table.LookUpSymbol($2->getName());
			if(st1 != NULL)
			{
				if(st1->getFuncDefined())
				{					
					fprintf(errorFile,"Error at line %d : Function already defined\n",line_count);
					error_count++;
				}
				else if(st1->getTypeSpecifier() != (yyvsp[-5].symbol)->getName())
				{
					fprintf(errorFile,"\nError at line no. %d: Return type does not match\n",line_count);
					error_count++;	
				}
				else
				{
					st1->setFuncDefined();
					(yyval.symbol)->symboPrint = (yyvsp[-5].symbol)->getName() + " " +(yyvsp[-4].symbol)->getName() + "("+(yyvsp[-2].symbol)->symboPrint+")"+ (yyvsp[0].symbol)->symboPrint;
					fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
					(yyval.symbol)->code = (yyvsp[-4].symbol)->getName() + " PROC\n";
					(yyval.symbol)->code += (yyvsp[0].symbol)->code;
					(yyval.symbol)->code += "\tRET\n";
					(yyval.symbol)->code += (yyvsp[-4].symbol)->getName() + " ENDP\n";
				}		
			}
			else
			{		
				symboInfo* temp = table.InsertSymbol((yyvsp[-4].symbol)->getName(),"FUNC");
				temp->setFuncDefined();
				temp->setTypeSpecifier((yyvsp[-5].symbol)->getName());
				(yyval.symbol)->symboPrint = (yyvsp[-5].symbol)->getName() + " " + (yyvsp[-4].symbol)->getName() + "(" + (yyvsp[-2].symbol)->symboPrint + ")" + (yyvsp[0].symbol)->symboPrint;
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
				(yyval.symbol)->code = (yyvsp[-4].symbol)->getName() + " PROC\n";
				(yyval.symbol)->code += (yyvsp[0].symbol)->code;
				(yyval.symbol)->code += "\tRET\n";
				(yyval.symbol)->code += (yyvsp[-4].symbol)->getName() + " ENDP\n";
			} 
		}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 236 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: func_definition : type_specifier ID LPAREN RPAREN compound_statement\n",line_count);
			symboInfo *st1 = table.LookUpSymbol((yyvsp[-3].symbol)->getName(),"FUNC");
				//int st1 = table.LookUpSymbol($2->getName());
			if(st1 != NULL)
			{
				if(st1->getFuncDefined())
				{					
					fprintf(errorFile,"Error at line %d : Function already defined\n",line_count);
					error_count++;
				}
				else if(st1->getTypeSpecifier()!= (yyvsp[-4].symbol)->getName())
				{
					fprintf(errorFile,"\nError at line no. %d: Return type does not match\n",line_count);
					error_count++;	
				}
				else
				{
					st1->setFuncDefined();
					(yyval.symbol)->symboPrint = (yyvsp[-4].symbol)->getName() + " " +(yyvsp[-3].symbol)->getName() + "("+")"+ (yyvsp[0].symbol)->symboPrint;
					fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
					(yyval.symbol)->code += (yyvsp[0].symbol)->code;
				}		
			}
			else
			{		
				symboInfo* temp = table.InsertSymbol((yyvsp[-3].symbol)->getName(),"FUNC");
				temp->setFuncDefined();
				temp->setTypeSpecifier((yyvsp[-4].symbol)->getName());
				(yyval.symbol)->symboPrint = (yyvsp[-4].symbol)->getName() + " " +(yyvsp[-3].symbol)->getName() + "("+")"+ (yyvsp[0].symbol)->symboPrint;
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
				printf("Success2");
				(yyval.symbol)->code = (yyvsp[-3].symbol)->getName() + " PROC\n";
				(yyval.symbol)->code += (yyvsp[0].symbol)->code;
				if((yyvsp[-3].symbol)->getName() == "main")
				{
					(yyval.symbol)->code += "\tMOV AH,4CH\n\tINT 21h\n";
				}
				else
				{
					(yyval.symbol)->code += "\tRET\n";
				}
				(yyval.symbol)->code += (yyvsp[-3].symbol)->getName() + " ENDP\n";
			} 
			
		}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 286 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: parameter_list : parameter_list COMMA type_specifier ID\n",line_count);
			symboInfo *st1 = table.LookUpSymbol((yyvsp[0].symbol)->getName(),"PARAM");
				//int st1 = table.LookUpSymbol($2->getName());
			if(st1 != NULL)
			{
				fprintf(errorFile,"Error at line %d : multiple declaration of %s\n",line_count,(yyvsp[0].symbol)->getName().c_str());
				error_count++;		
			}
			else
			{		
				symboInfo* temp = table.InsertSymbol((yyvsp[0].symbol)->getName(),"PARAM");
				temp->setTypeSpecifier((yyvsp[-1].symbol)->getName());
				(yyval.symbol)->symboPrint = (yyvsp[-3].symbol)->symboPrint + "," + (yyvsp[-1].symbol)->getName()+" " +(yyvsp[0].symbol)->getName();
				printf("Success3 \n");
				cout<<(yyval.symbol)->symboPrint;
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
			} 
		}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 307 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(errorFile,"Error at line %d : Wrong declaration\n",line_count);
			error_count++;
		}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 312 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: parameter_list : type_specifier ID\n",line_count);
			symboInfo *temp = table.LookUpSymbol((yyvsp[0].symbol)->getName(),"PARAM");
			if(temp == NULL)
			{
				symboInfo *temp = table.InsertSymbol((yyvsp[0].symbol)->getName(),"PARAM");
				temp->setTypeSpecifier((yyvsp[-1].symbol)->getName());
				(yyval.symbol)->symboPrint = (yyvsp[-1].symbol)->getName() +" " +(yyvsp[0].symbol)->getName(); 
				printf("Success somewhere! ");
				cout<<(yyval.symbol)->symboPrint;
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
			}
			else
			{
				fprintf(errorFile,"Error at line no. %d: Multiple declaration of %s\n",line_count,(yyvsp[0].symbol)->getName().c_str());
				error_count++;
			}
		}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 331 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(errorFile,"Error at line %d : Wrong declaration\n",line_count);
			error_count++;
		}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 338 "1505088_Offline4.y" /* yacc.c:1646  */
    {table.EnterScope();}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 338 "1505088_Offline4.y" /* yacc.c:1646  */
    {table.allScope();}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 338 "1505088_Offline4.y" /* yacc.c:1646  */
    {table.ExitScope();}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 339 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				fprintf(logout,"\nAt line no. %d : compound_statement : LCURL statements RCURL\n",line_count);
				(yyval.symbol) = (yyvsp[-3].symbol);
				(yyval.symbol)->symboPrint ="\n{\n"+(yyvsp[-3].symbol)->symboPrint+"\n}\n";
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
				cout<<"\ncompound\n"; 
			}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 346 "1505088_Offline4.y" /* yacc.c:1646  */
    {table.EnterScope();}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 346 "1505088_Offline4.y" /* yacc.c:1646  */
    {table.allScope();table.ExitScope();}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 347 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				fprintf(logout,"\nAt line no. %d : compound_statement : LCURL RCURL\n",line_count);
				(yyval.symbol)->symboPrint ="{\n}\n";
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
			}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 355 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d : var_declaration : type_specifier declaration_list SEMICOLON\n",line_count);
			(yyval.symbol)->symboPrint = (yyvsp[-2].symbol)->getName() + " " + (yyvsp[-1].symbol)->symboPrint + ";" + "\n";
			fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
		  }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 363 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: type_specifier : INT\n",line_count);
			fprintf(logout,"%s\n\n","int");
			symboInfo *tmp = new symboInfo("int","INT");
			typeInfo = "INT";
			(yyval.symbol) = tmp;
		}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 371 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: type_specifier : FLOAT\n",line_count);
			fprintf(logout,"float\n\n");
			symboInfo *tmp = new symboInfo("float","FLOAT");
			typeInfo = "FLOAT";
			(yyval.symbol) = tmp;
		}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 379 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: type_specifier : VOID\n",line_count);
			fprintf(logout,"void\n\n");
			symboInfo *tmp = new symboInfo("void","VOID");
			typeInfo = "VOID";
			(yyval.symbol) = tmp;
		}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 389 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				fprintf(logout,"\nAt line no. %d: declaration_list : declaration_list COMMA ID\n",line_count);
				if(typeInfo.compare("VOID") == 0)
				{
					fprintf(errorFile,"Error at line no. %d: variable type cannot be void\n",line_count);
					error_count++;	
				}
				else
				{
					symboInfo *temp = table.LookUpSymbol((yyvsp[0].symbol)->getName(),"ID");
					if(temp != NULL)
					{
						fprintf(errorFile,"Error at line no. %d: Multiple declaration of %s\n",line_count,(yyvsp[0].symbol)->getName().c_str());
						error_count++;
					}
					else
					{
						symboInfo *ins = table.InsertSymbol(((yyvsp[0].symbol)->getName()),"ID");
						ins->setTypeSpecifier(typeInfo);
						(yyval.symbol)->symboPrint = (yyvsp[-2].symbol)->symboPrint + " , " + (yyvsp[0].symbol)->getName();
						fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
						idVect.push_back((yyvsp[0].symbol)->getName() + to_string(table.getScopeNum()));
						ins->setString((yyvsp[0].symbol)->getName() + to_string(table.getScopeNum()));
						table.allScope();
					}
				}
			}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 417 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				fprintf(logout,"\nAt line no.%d : declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",line_count);
				if(typeInfo.compare("VOID") == 0)
				{
					fprintf(errorFile,"Error at line no. %d: variable type cannot be void\n",line_count);
					error_count++;	
				}
				else
				{
					string name = (yyvsp[-3].symbol)->getName()+to_string(table.getScopeNum());
					symboInfo *temp = table.LookUpSymbol((yyvsp[-3].symbol)->getName(),"ARRAY");
					if(temp != NULL)
					{
						fprintf(errorFile,"Error at line no. %d: Multiple declaration of %s\n",line_count,(yyvsp[-3].symbol)->getName().c_str());
						error_count++;
					}
					else
					{
						symboInfo *ins = table.InsertSymbol((yyvsp[-3].symbol)->getName(),"ARRAY");
						int araLen = atoi((yyvsp[-1].symbol)->getName().c_str());
						ins->setArrayLen(araLen);
						ins->setTypeSpecifier(typeInfo);
						if(typeInfo.compare("INT") == 0)
						{
							for(int i=ins->symboInt.size() ; i<ins->getArrayLen() ; i++)
							{
								ins->symboInt.push_back(0);
							}
						}
						else if(typeInfo.compare("FLOAT") == 0)
						{
							for(int i=ins->symboFloat.size() ; i<ins->getArrayLen() ; i++)
							{
								ins->symboFloat.push_back(0);
							}
						}
						else if(typeInfo.compare("CHAR") == 0)
						{
							for(int i=ins->symboChar.size() ; i<ins->getArrayLen() ; i++)
							{
								ins->symboChar.push_back('\0');
							}
						}
						(yyval.symbol)->symboPrint = (yyvsp[-5].symbol)->symboPrint + " , " + (yyvsp[-3].symbol)->getName() + "["+(yyvsp[-1].symbol)->getName() +"]";
						fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str()); 
						arrayVect.push_back(name);
						arrayVectIndex.push_back(araLen);
						ins->setString(name);
						table.allScope();
					}
				}
			}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 470 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no. %d: declaration_list : ID\n",line_count);
				if(typeInfo.compare("VOID") == 0)
				{
					fprintf(errorFile,"Error at line no. %d: variable type cannot be void\n",line_count);
					error_count++;	
				}
				else
				{
					string name = (yyvsp[0].symbol)->getName()+to_string(table.getScopeNum());
					symboInfo *temp = table.LookUpSymbol((yyvsp[0].symbol)->getName(),"ID");
					if(temp != NULL)
					{
						fprintf(errorFile,"Error at line no. %d: Multiple declaration of %s\n",line_count,(yyvsp[0].symbol)->getName().c_str());
						error_count++;
					}
					else
					{
						symboInfo *ins = table.InsertSymbol((yyvsp[0].symbol)->getName(),"ID");
						ins->setTypeSpecifier(typeInfo);
						(yyval.symbol)->symboPrint = (yyvsp[0].symbol)->getName() ; 
						fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
						idVect.push_back(name);
						ins->setString(name);
						table.allScope();
					}
				}
			}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 499 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				fprintf(logout,"\nAt line no.%d : declaration_list : ID LTHIRD CONST_INT RTHIRD\n",line_count);
				if(typeInfo.compare("VOID") == 0)
				{
					fprintf(errorFile,"Error at line no. %d: variable type cannot be void\n",line_count);
					error_count++;	
				}
				else
				{
					string name = (yyvsp[-3].symbol)->getName()+to_string(table.getScopeNum());
					symboInfo *temp = table.LookUpSymbol((yyvsp[-3].symbol)->getName(),"ARRAY");
					if(temp != NULL)
					{
						fprintf(errorFile,"Error at line no. %d: Multiple declaration of %s\n",line_count,(yyvsp[-3].symbol)->getName().c_str());
						error_count++;
					}
					else
					{
						symboInfo *ins = table.InsertSymbol((yyvsp[-3].symbol)->getName(),"ARRAY");
						int araLen = atoi((yyvsp[-1].symbol)->getName().c_str());
						ins->setArrayLen(araLen);
						ins->setTypeSpecifier(typeInfo);
						if(typeInfo.compare("INT") == 0)
						{
							for(int i=ins->symboInt.size() ; i<ins->getArrayLen() ; i++)
							{
								ins->symboInt.push_back(0);
							}
						}
						else if(typeInfo.compare("FLOAT") == 0)
						{
							for(int i=ins->symboFloat.size() ; i<ins->getArrayLen() ; i++)
							{
								ins->symboFloat.push_back(0);
							}
						}
						else if(typeInfo.compare("CHAR") == 0)
						{
							for(int i=ins->symboChar.size() ; i<ins->getArrayLen() ; i++)
							{
								ins->symboChar.push_back('\0');
							}
						}
						(yyval.symbol)->symboPrint = (yyvsp[-3].symbol)->getName() + "["+(yyvsp[-1].symbol)->getName()+"]";
						fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
						arrayVect.push_back(name);
						arrayVectIndex.push_back(araLen);
						ins->setString(name);
						table.allScope();
					}
				}
			}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 554 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			(yyval.symbol) = (yyvsp[0].symbol);
			fprintf(logout,"\nAt line no. %d: statements : statement\n",line_count);
		}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 560 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			(yyval.symbol) = (yyvsp[-1].symbol);
			fprintf(logout,"\nAt line no. %d: statements : statements statement\n",line_count);
			(yyval.symbol)->symboPrint += (yyvsp[0].symbol)->symboPrint + "\n";
			fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
			(yyval.symbol)->code += (yyvsp[0].symbol)->code;
			cout << (yyval.symbol)->code << endl;	
			delete (yyvsp[0].symbol);
		}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 572 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			(yyval.symbol) = (yyvsp[0].symbol);
			fprintf(logout,"\nAt line no. %d: statement : var_declaration\n",line_count);
		}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 577 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			(yyval.symbol) = (yyvsp[0].symbol);
			fprintf(logout,"\nAt line no. %d: statement : expression_statement\n",line_count);
		}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 582 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			(yyval.symbol) = (yyvsp[0].symbol);
			fprintf(logout,"\nAt line no. %d: statement : compound_statement\n",line_count);
		}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 587 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n",line_count);
			(yyval.symbol) = (yyvsp[-4].symbol);
			(yyval.symbol)->symboPrint ="for( " + (yyvsp[-4].symbol)->symboPrint + (yyvsp[-3].symbol)->symboPrint + (yyvsp[-2].symbol)->symboPrint + ")" + (yyvsp[0].symbol)->symboPrint; 
			fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
			
			char *label = newLable();
			char *label2 = newLable();
			(yyval.symbol)->code += string(label) + ":\n";
			(yyval.symbol)->code += (yyvsp[-3].symbol)->code;
			(yyval.symbol)->code += "\tMOV AX, " + (yyvsp[-3].symbol)->getString() + "\n";
			(yyval.symbol)->code += "\tCMP AX, 0\n";
			(yyval.symbol)->code += "\tJE " + string(label2) + "\n";
			(yyval.symbol)->code += (yyvsp[-2].symbol)->code ;
			(yyval.symbol)->code += (yyvsp[0].symbol)->code ;
			(yyval.symbol)->code += "\tJMP " + string(label) + "\n";
			(yyval.symbol)->code += string(label2) + ":\n"; 
		}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 606 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: statement : IF LPAREN expression RPAREN statement\n",line_count);
			(yyval.symbol) = (yyvsp[-2].symbol);
			(yyval.symbol)->symboPrint ="if( " + (yyvsp[-2].symbol)->symboPrint + ")" + (yyvsp[0].symbol)->symboPrint; 
			fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
			
			char *label=newLable();
			(yyval.symbol)->code+="\tMOV AX, "+(yyvsp[-2].symbol)->getString()+"\n";
			(yyval.symbol)->code+="\tCMP AX, 0\n";
			(yyval.symbol)->code+="\tJE "+string(label)+"\n";
			(yyval.symbol)->code+=(yyvsp[0].symbol)->code;
			
			(yyval.symbol)->code+=string(label)+":\n";
		}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 621 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: statement : IF LPAREN expression RPAREN statement ELSE statement\n",line_count);
			(yyval.symbol) = (yyvsp[-4].symbol);			
			(yyval.symbol)->symboPrint ="if( " + (yyvsp[-4].symbol)->symboPrint + ")" +(yyvsp[-2].symbol)->symboPrint +"else"+ (yyvsp[0].symbol)->symboPrint; 
			fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
			
			char *label = newLable();
			char *label2 = newLable();
			(yyval.symbol)->code += "\tMOV AX, " + (yyvsp[-4].symbol)->getString() + "\n";
			(yyval.symbol)->code += "\tCMP AX, 0\n";
			(yyval.symbol)->code += "\tJE "+string(label)+"\n";
			(yyval.symbol)->code += (yyvsp[-2].symbol)->code;
			(yyval.symbol)->code += "\tJMP " + string(label2) + "\n";
			(yyval.symbol)->code += string(label) + ":\n";
			(yyval.symbol)->code += (yyvsp[0].symbol)->code;
			(yyval.symbol)->code += string(label2) + ":\n";
			
		}
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 640 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: statement : WHILE LPAREN expression RPAREN statement\n",line_count);
			(yyval.symbol) = (yyvsp[-2].symbol);
			(yyval.symbol)->symboPrint ="while( " + (yyvsp[-2].symbol)->symboPrint + ")" + (yyvsp[0].symbol)->symboPrint; 
			fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());

			char *label = newLable();
			char *label2 = newLable();
			(yyval.symbol)->code += string(label) + ":\n";
			(yyval.symbol)->code += "\tMOV AX, " + (yyvsp[-2].symbol)->getString() + "\n";
			(yyval.symbol)->code += "\tCMP AX, 0\n";
			(yyval.symbol)->code += "\tJE " + string(label2) + "\n";
			(yyval.symbol)->code += (yyvsp[0].symbol)->code;
			(yyval.symbol)->code += "\tJMP " + string(label) + "\n";
			(yyval.symbol)->code += string(label2) + ":\n";
			
		}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 658 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			symboInfo *id = table.LookUpSymbol((yyvsp[-2].symbol)->getName(), "ID");
			if(id != NULL){
				fprintf(logout,"\nAt line no. %d: statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n",line_count);
				(yyval.symbol) = (yyvsp[-2].symbol);
				(yyval.symbol)->symboPrint ="println( " + (yyvsp[-2].symbol)->getName() + ")" + ";\n"; 
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
				(yyval.symbol)->code = "\tMOV AX, " + id->getString() + "\n";
				(yyval.symbol)->code += "\tCALL OUTDEC\n";
			}
			else
			{
				fprintf(errorFile,"Error at line no. %d: %s does not exist!\n",line_count,(yyvsp[-2].symbol)->getName().c_str());
				error_count++;
			}
		}
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 675 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: statement : RETURN expression SEMICOLON\n",line_count);
			(yyval.symbol) = (yyvsp[-1].symbol);
			(yyval.symbol)->symboPrint ="return " + (yyvsp[-1].symbol)->symboPrint + ";\n"; 
			fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
			//something maybe!!!
			

		}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 687 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				fprintf(logout,"\nAt line no. %d: expression_statement : SEMICOLON\n",line_count);
				(yyval.symbol)->symboPrint = ";";
				(yyval.symbol)->code = "";
			}
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 693 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				fprintf(logout,"\nAt line no. %d: expression_statement : expression SEMICOLON\n",line_count);
				//$$->symboPrint = $1->symboPrint + ";";
				//$$->code += $1->code + "\n";
				(yyval.symbol) = (yyvsp[-1].symbol);
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
				table.allScope();
			}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 704 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			
			//cout<<"\nhow are you?";
			fprintf(logout,"\nAt line no. %d: variable : ID\n",line_count);
			string name = (yyvsp[0].symbol)->getName()+to_string(table.getScopeNum());
			symboInfo *var = table.LookUpSymbol((yyvsp[0].symbol)->getName(),"ID");
			if(var == NULL)
			{
				fprintf(errorFile,"Error at line no. %d: %s does not exist!\n",line_count,(yyvsp[0].symbol)->getName().c_str());
				error_count++;
			}
			else
			{
				//table.InsertSymbo($1->getName(),"ID");
				//$$ = var;
				(yyval.symbol) = new symboInfo((yyvsp[0].symbol)->getName(),(yyvsp[0].symbol)->getType());
				//$$ = tem;
				(yyval.symbol)->symboPrint = (yyvsp[0].symbol)->getName();
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
				if(std::find(idVect.begin(), idVect.end(), name) != idVect.end())
				{
					cout<<"\nNothing to do\n";
				}
				else
				{
					idVect.push_back((yyvsp[0].symbol)->getName()+to_string(table.getScopeNum()));
					//$$->setString($1->getName()+to_string(table.getScopeNum()));
					table.allScope();
				}
				(yyval.symbol)->setString((yyvsp[0].symbol)->getName()+to_string(table.getScopeNum()));
			}
		}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 737 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: variable : ID LTHIRD expression RTHIRD\n",line_count);
			string name = (yyvsp[-3].symbol)->getName()+to_string(table.getScopeNum());
			symboInfo *ara = table.LookUpSymbol((yyvsp[-3].symbol)->getName(),"ARRAY");
			if(ara == NULL)
			{
				fprintf(errorFile,"Error at line %d: %s does not exists\n",line_count,(yyvsp[-3].symbol)->getName().c_str());	
				error_count++;
			}
			else{
				int araIndex = (yyvsp[-1].symbol)->integer;
				ara->symboIndex = araIndex;
				if(ara->getTypeSpecifier() == "FLOAT")
				{
					fprintf(errorFile,"Error at line no. %d: Array index cannot be float\n",line_count);
					error_count++;	
				}
			
				//$$ = ara;
				(yyval.symbol) = new symboInfo((yyvsp[-3].symbol)->getName(),(yyvsp[-3].symbol)->getType());
				(yyval.symbol)->symboPrint = (yyvsp[-3].symbol)->getName() + "[" + (yyvsp[-1].symbol)->symboPrint + "]";
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
				if(std::find(arrayVect.begin(), arrayVect.end(), name) != arrayVect.end())
				{
					cout<<"\nNothing to do\n";
				}
				else
				{
					arrayVect.push_back((yyvsp[-3].symbol)->getName()+to_string(table.getScopeNum()));
					arrayVectIndex.push_back(ara->getArrayLen());
					(yyval.symbol)->setString((yyvsp[-3].symbol)->getName()+to_string(table.getScopeNum()));
					//table.allScope();
					(yyval.symbol)->code=(yyvsp[-1].symbol)->code+"\tMOV BX, " +(yyvsp[-1].symbol)->getName() +"\n\tADD BX, BX\n";
				
					delete (yyvsp[-1].symbol);
				}
			}
		}
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 778 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			(yyval.symbol) = (yyvsp[0].symbol);
			fprintf(logout,"\nAt line no. %d : expression : logic_expression\n",line_count);
		}
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 783 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d : expression : variable ASSIGNOP logic_expression\n",line_count);
			(yyval.symbol)->code = (yyvsp[0].symbol)->code + (yyvsp[-2].symbol)->code;
			(yyval.symbol)->code += "\tMOV AX, " + (yyvsp[0].symbol)->getString() + "\n";
			cout<<(yyvsp[-2].symbol)->getType()<<"\n";
			if((yyvsp[-2].symbol)->getType() == "ARRAY")
			{
				//cout<<"\n\nhi";
				(yyval.symbol)->code += "\tMOV " + (yyvsp[-2].symbol)->getString() + "[BX], AX\n";
			}
			else
			{
				(yyval.symbol)->code += "\tMOV " + (yyvsp[-2].symbol)->getString()+ ", AX\n";
			}
			(yyval.symbol)->symboPrint = (yyvsp[-2].symbol)->symboPrint + " = " + (yyvsp[0].symbol)->symboPrint;
			fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
			delete (yyvsp[0].symbol);
			table.allScope();
		}
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 805 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				(yyval.symbol) = (yyvsp[0].symbol);
				fprintf(logout,"\nAt line no. %d : expression : logic_expression\n",line_count);
			}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 810 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				fprintf(logout,"\nAt line no. %d : expression : rel_expression LOGICOP rel_expression\n",line_count);
				(yyval.symbol)->code += (yyvsp[0].symbol)->code;
				cout<<"\n\n"<<(yyvsp[-2].symbol)->getString()<<"\n";
				if((yyvsp[-1].symbol)->getName() == "&&"){
					/* 
						Check whether both operands value is 1. If both are one set value of a temporary variable to 1
						otherwise 0
					*/
					char *lable = newLable();
					char *lable2 = newLable();
					char *temp = newTemp();
					(yyval.symbol)->code += "\tMOV AX, " + (yyvsp[-2].symbol)->getString() + "\n";
					(yyval.symbol)->code += "\tCMP AX, 0\n";
					(yyval.symbol)->code += "\tJE " + string(lable) + "\n";
					(yyval.symbol)->code += "\tMOV BX, " + (yyvsp[0].symbol)->getString() + "\n";
					(yyval.symbol)->code += "\tCMP BX, 0\n";
					(yyval.symbol)->code += "\tJE " + string(lable) + "\n";
					(yyval.symbol)->code += "\tMOV " + string(temp) + ", 1\n";
					(yyval.symbol)->code += "\tJMP " + string(lable2) + "\n";
					(yyval.symbol)->code += string(lable) + ":\n";
					(yyval.symbol)->code += "\tMOV " + string(temp) + ", 0\n";
					(yyval.symbol)->code += string(lable2) + ":\n";
					(yyval.symbol)->setString(string(temp));
					idVect.push_back(temp);
					//$$->setType("ID");
				}
				else if((yyvsp[-1].symbol)->getName() == "||")
				{
					char *lable = newLable();
					char *lable2 = newLable();
					char *temp = newTemp();
					(yyval.symbol)->code += "\tMOV AX, " + (yyvsp[-2].symbol)->getString() + "\n";
					(yyval.symbol)->code += "\tCMP AX, 1\n";
					(yyval.symbol)->code += "\tJE " + string(lable) + "\n";
					(yyval.symbol)->code += "\tMOV BX, " + (yyvsp[0].symbol)->getString() + "\n";
					(yyval.symbol)->code += "\tCMP BX, 1\n";
					(yyval.symbol)->code += "\tJE " + string(lable) + "\n";
					(yyval.symbol)->code += "\tMOV " + string(temp) + ", 0\n";
					(yyval.symbol)->code += "\tJMP " + string(lable2) + "\n";
					(yyval.symbol)->code += string(lable) + ":\n";
					(yyval.symbol)->code += "\tMOV " + string(temp) + ", 1\n";
					(yyval.symbol)->code += string(lable2) + ":\n";
					(yyval.symbol)->setString(string(temp));
					idVect.push_back(temp);
					//$$->setType("ID");
				}
				(yyval.symbol)->symboPrint = (yyvsp[-2].symbol)->symboPrint + (yyvsp[-1].symbol)->getName() + (yyvsp[0].symbol)->symboPrint;
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
				table.allScope();
				delete (yyvsp[0].symbol);
			}
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 865 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			(yyval.symbol) = (yyvsp[0].symbol);
			fprintf(logout,"\nAt line no. %d : rel_expression : simple_expression\n",line_count);
		}
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 870 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d : rel_expression : simple_expression RELOP simple_expression\n",line_count);
			(yyval.symbol)->code += (yyvsp[0].symbol)->code;
			(yyval.symbol)->code += "\tMOV AX, " + (yyvsp[-2].symbol)->getString() + "\n";
			(yyval.symbol)->code += "\tCMP AX, " + (yyvsp[0].symbol)->getString() + "\n";
			
			char *lable  =newLable();
			char *lable2 = newLable();
			char *temp = newTemp();
			if((yyvsp[-1].symbol)->getName() == "<")
			{
				(yyval.symbol)->code += "\tJL " + string(lable) + "\n";
			}
			else if((yyvsp[-1].symbol)->getName() == "<=")
			{
				(yyval.symbol)->code += "\tJLE " + string(lable) + "\n";
			}
			else if((yyvsp[-1].symbol)->getName() == ">")
			{
				(yyval.symbol)->code += "\tJG " + string(lable) + "\n";
			}
			else if((yyvsp[-1].symbol)->getName() == ">=")
			{
				(yyval.symbol)->code += "\tJGE " + string(lable) + "\n";
			}
			else if((yyvsp[-1].symbol)->getName() == "==")
			{
				(yyval.symbol)->code += "\tJE " + string(lable) + "\n";
			}
			else if((yyvsp[-1].symbol)->getName() == "!=")
			{
				(yyval.symbol)->code += "\tJNE " + string(lable) + "\n";
			}
			(yyval.symbol)->code += "\tMOV " + string(temp) + ", 0\n";
			(yyval.symbol)->code += "\tJMP " + string(lable2) + "\n";
			(yyval.symbol)->code += string(lable) + ":\n";
			(yyval.symbol)->code += "\tMOV " + string(temp) + ", 1\n";
			(yyval.symbol)->code += string(lable2) + ":\n";
			(yyval.symbol)->setString(temp);
			(yyval.symbol)->symboPrint = (yyvsp[-2].symbol)->symboPrint + (yyvsp[-1].symbol)->getName() + (yyvsp[0].symbol)->symboPrint;
			fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
			idVect.push_back(temp);
			//$$->setType("ID");
			delete (yyvsp[0].symbol);
		}
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 918 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				(yyval.symbol) = (yyvsp[0].symbol);
				fprintf(logout,"\nAt line no. %d: simple_expression : term\n",line_count);
			}
#line 2433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 923 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				fprintf(logout,"\nAt line no. %d: simple_expression : simple_expression ADDOP term\n",line_count);
				(yyval.symbol)->code += (yyvsp[0].symbol)->code;
				char *temp = newTemp();
				if((yyvsp[-1].symbol)->getName() == "+")
				{
					(yyval.symbol)->code += "\tMOV AX, " + (yyvsp[-2].symbol)->getString() +"\n";
					(yyval.symbol)->code += "\tADD AX, " + (yyvsp[0].symbol)->getString() + "\n";
					(yyval.symbol)->code += "\tMOV " + string(temp) + ",AX\n"; 
				}
				else if((yyvsp[-1].symbol)->getName() == "-")
				{
					(yyval.symbol)->code += "\tMOV AX, " + (yyvsp[-2].symbol)->getString() +"\n";
					(yyval.symbol)->code += "\tSUB AX, " + (yyvsp[0].symbol)->getString() + "\n";
					(yyval.symbol)->code += "\tMOV " + string(temp) + ",AX\n";
				}
				(yyval.symbol)->setString(temp);
				//$$->setType("ID");
				(yyval.symbol)->symboPrint = (yyvsp[-2].symbol)->symboPrint + (yyvsp[-1].symbol)->getName() + (yyvsp[0].symbol)->symboPrint;
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
				idVect.push_back(temp);
				delete (yyvsp[0].symbol);
			}
#line 2461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 950 "1505088_Offline4.y" /* yacc.c:1646  */
    {
		(yyval.symbol) = (yyvsp[0].symbol);
		fprintf(logout,"\n At line no. %d: term : unary_expression\n",line_count);
	}
#line 2470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 955 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\n At line no. %d: term : term MULOP unary_expression\n",line_count);
			(yyval.symbol)->code += (yyvsp[0].symbol)->code;
				(yyval.symbol)->code += "\tMOV AX, " + (yyvsp[-2].symbol)->getString() + "\n";
				(yyval.symbol)->code += "\tMOV BX, " + (yyvsp[0].symbol)->getString() + "\n";
				char *temp = newTemp();
				if((yyvsp[-1].symbol)->getName() == "*")
				{
					//$$->code += "\tMOV AX, " + $1->getName() +"\n";
					(yyval.symbol)->code += "\tMUL BX\n";
					(yyval.symbol)->code += "\tMOV " + string(temp) + ",AX\n"; 
				}
				else if((yyvsp[-1].symbol)->getName() == "/")
				{
					(yyval.symbol)->code += "\tXOR DX, DX\n";
					(yyval.symbol)->code += "\tDIV BX\n";
					(yyval.symbol)->code += "\tMOV " + string(temp) + ",AX\n";
				}
				else if((yyvsp[-1].symbol)->getName() == "%")
				{
					(yyval.symbol)->code += "\tXOR DX, DX\n";
					(yyval.symbol)->code += "\tDIV BX\n";
					(yyval.symbol)->code += "\tMOV " + string(temp) + " ,DX\n";
				}
				(yyval.symbol)->setString(temp);
				//$$->setType("ID");
				(yyval.symbol)->symboPrint = (yyvsp[-2].symbol)->symboPrint + (yyvsp[-1].symbol)->getName() + (yyvsp[0].symbol)->symboPrint;
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
				idVect.push_back(temp);
				delete (yyvsp[0].symbol);	
			}
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 989 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: unary_expression : ADDOP unary_expression\n",line_count);
			(yyval.symbol) = (yyvsp[0].symbol);
			if((yyvsp[-1].symbol)->getName() == "-"){
				(yyval.symbol)->symboPrint = (yyvsp[-1].symbol)->getName() + (yyvsp[0].symbol)->symboPrint;
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
				(yyval.symbol)->code += "\tMOV AX, " + (yyvsp[0].symbol)->getString() + "\n";
				(yyval.symbol)->code += "\tNEG AX\n";
				(yyval.symbol)->code += "\tMOV " + (yyvsp[0].symbol)->getString() + ", AX\n";
			}
		}
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1001 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				fprintf(logout,"At line no. %d: unary_expression : NOT unary_expression\n",line_count);
				(yyval.symbol) = (yyvsp[0].symbol);
				(yyval.symbol)->symboPrint = "^" + (yyvsp[0].symbol)->symboPrint;
				fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
				(yyval.symbol)->code += "\tMOV AX, " + (yyvsp[0].symbol)->getString() + "\n";
				(yyval.symbol)->code += "\tNOT AX\n";
				(yyval.symbol)->code += "\tMOV " + (yyvsp[0].symbol)->getString() + ", AX\n";
			}
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1011 "1505088_Offline4.y" /* yacc.c:1646  */
    {
				(yyval.symbol) = (yyvsp[0].symbol);
				fprintf(logout,"\nAt line no. %d: unary_expression : factor\n",line_count);
			}
#line 2545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1018 "1505088_Offline4.y" /* yacc.c:1646  */
    {
		(yyval.symbol) = (yyvsp[0].symbol);
		fprintf(logout,"\nAt line no. %d: factor : variable\n",line_count);
		if((yyvsp[0].symbol)->getName() == "ID"){
		
		}
		else if((yyvsp[0].symbol)->getType() == "ARRAY"){
			char *temp= newTemp();
			(yyval.symbol)->code+="\tMOV AX, " + (yyvsp[0].symbol)->getString() + "[bx]\n";
			(yyval.symbol)->code+= "\tMOV " + string(temp) + ", AX\n";
			(yyval.symbol)->setString(temp);
			idVect.push_back(temp);
		}
		
	}
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1034 "1505088_Offline4.y" /* yacc.c:1646  */
    {
		fprintf(logout,"nAt line no. %d: factor : ID LPAREN argument_list RPAREN\n",line_count);
		symboInfo *temp = table.LookUpSymbol((yyvsp[-3].symbol)->getName(),"FUNC");
		if(temp == NULL)
		{
			fprintf(errorFile,"Error at line no. %d: Function does not exist\n",line_count);
			error_count++;
		}
		else
		{
			if(temp->getTypeSpecifier() == "VOID")
			{
				fprintf(errorFile,"Error at line no. %d: Function returns void\n",line_count);
				error_count++;	
			}
			else
			{
				if(temp->getTypeSpecifier() == "INT")
				{
					(yyval.symbol)->setTypeSpecifier("INT");
					//$$->symboPrint = $1->getName() +"(" + $3->symboPrint + ")";
					//fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
				}
				else if(temp->getTypeSpecifier() == "FLOAT")
				{
					(yyval.symbol)->setTypeSpecifier("FLOAT");
					//$$->symboPrint = $1->getName() + "(" + $3->symboPrint + ")";
					//fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
				}
				//$$->symboPrint = $1->getName() +"(" + $3->symboPrint + ")";
				//fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
				//$$->code = $3->code;
				(yyval.symbol)->code = "\tCALL " + (yyvsp[-3].symbol)->getName() + "\n";
			}
		}
	}
#line 2606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1071 "1505088_Offline4.y" /* yacc.c:1646  */
    {
		fprintf(logout,"\nAt line no. %d: factor : LPAREN expression RPAREN\n",line_count);
		(yyval.symbol) = (yyvsp[-1].symbol);
		(yyval.symbol)->symboPrint = "(" + (yyvsp[-1].symbol)->symboPrint + ")"; 
		fprintf(logout,"\n%s\n\n",(yyval.symbol)->symboPrint.c_str());
	}
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1078 "1505088_Offline4.y" /* yacc.c:1646  */
    {
		(yyval.symbol) = (yyvsp[0].symbol);
		fprintf(logout,"\nAt line no. %d: factor : CONST_INT\n",line_count);
		(yyvsp[0].symbol)->setTypeSpecifier("INT");
		//$1->symboInt[0] = atoi($1->getName().c_str());
		(yyvsp[0].symbol)->integer = atoi((yyvsp[0].symbol)->getName().c_str());
		cout<<(yyvsp[0].symbol)->getType();
		(yyval.symbol)->symboPrint = (yyvsp[0].symbol)->getName();
		//$$->code = $1->getName();
	}
#line 2632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1089 "1505088_Offline4.y" /* yacc.c:1646  */
    {
		(yyval.symbol) = (yyvsp[0].symbol);
		fprintf(logout,"\nAt line no. %d: factor : CONST_FLOAT\n",line_count);
		(yyvsp[0].symbol)->setTypeSpecifier("FLOAT");
		(yyvsp[0].symbol)->floating = atof((yyvsp[0].symbol)->getName().c_str());
		(yyval.symbol)->symboPrint = (yyvsp[0].symbol)->getName();
	}
#line 2644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1097 "1505088_Offline4.y" /* yacc.c:1646  */
    {
		fprintf(logout,"\nAt line no. %d: factor : variable INCOP\n",line_count);
		(yyval.symbol)->code += "\tMOV AX, " + (yyvsp[-1].symbol)->getString() + "\n";
		(yyval.symbol)->code += "\tADD AX, 1\n";
		(yyval.symbol)->code += "\tMOV "+ (yyvsp[-1].symbol)->getString() + ", AX\n";
	}
#line 2655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1104 "1505088_Offline4.y" /* yacc.c:1646  */
    {
		fprintf(logout,"\nAt line no. %d: factor : variable DECOP\n",line_count);
		(yyval.symbol)->code += "\tMOV AX, " + (yyvsp[-1].symbol)->getString() + "\n";
		(yyval.symbol)->code += "\tSUB AX, 1\n";
		(yyval.symbol)->code += "\tMOV "+ (yyvsp[-1].symbol)->getString() + ", AX\n";
	}
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1113 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no %d: argument_list : arguments\n",line_count);
		}
#line 2674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1120 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: arguments : arguments COMMA logic_expression\n",line_count);
		}
#line 2682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1124 "1505088_Offline4.y" /* yacc.c:1646  */
    {
			fprintf(logout,"\nAt line no. %d: arguments : logic_expression\n",line_count);
		}
#line 2690 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2694 "y.tab.c" /* yacc.c:1646  */
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
#line 1129 "1505088_Offline4.y" /* yacc.c:1906  */

int main(int argc,char *argv[])
{
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	if((yyin=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}
		

	logout= fopen("log.txt","w");
	errorFile= fopen("error.txt","w");
	codeFile = fopen("assembly.asm","w");
	
	yyparse();
	
	fprintf(logout,"\n Symbol Table: \n");
	table.allScope();

	fprintf(logout,"\n\nTotal Line: %d\n",line_count);
	fprintf(logout,"Total Error: %d\n",error_count);
	fclose(logout);
	fclose(errorFile);
	fclose(codeFile);
	
	return 0;

}
