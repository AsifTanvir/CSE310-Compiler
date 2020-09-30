/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 30 "1505088_Offline3.y" /* yacc.c:1909  */

symboInfo* symbol;

#line 144 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
