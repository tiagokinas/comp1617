/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20150711

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "xpl_parser.y"
/* $Id: xpl_parser.y,v 1.14 2017/05/21 23:44:50 ist168199 Exp $*/
/*-- don't change *any* of these: if you do, you'll break the compiler.*/
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
/*-- don't change *any* of these --- END!*/
#line 14 "xpl_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int                   i;	/* integer value */
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  
  double               d;
  bool                 b;
  basic_type           *_type;
  xpl::block_node      *_block;
  xpl::function_declaration_node *_func;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 68 "xpl_parser.y"
/*-- The rules below will be included in yyparse, the main parsing function.*/
#line 56 "xpl_parser.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define tINTEGER 257
#define tDOUBLE 258
#define tIDENTIFIER 259
#define tSTRING 260
#define tPUBLIC 261
#define tUSE 262
#define tPROCEDURE 263
#define tINT 264
#define tREAL 265
#define tIF 266
#define tELSIF 267
#define tELSE 268
#define tWHILE 269
#define tSWEEP 270
#define tNEXT 271
#define tNULL 272
#define tSTOP 273
#define tRETURN 274
#define tREAD 275
#define tPRINT 276
#define tPRINTLN 277
#define tAND 278
#define tOR 279
#define tIFX 280
#define tSTRINGX 281
#define tNOVAR 282
#define tNOBLOCK 283
#define tHALFBLOCK 284
#define tEMPTYBLOCK 285
#define tGE 286
#define tLE 287
#define tEQ 288
#define tNE 289
#define tUNARY 290
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    8,    8,    2,    2,    3,    3,    3,    3,
    3,    3,   16,   16,   16,   16,   16,   16,   16,   16,
   16,   16,   16,   16,   16,   16,   16,   16,    4,    7,
    7,    7,   14,   14,   14,   14,   15,   17,   17,   17,
   17,    6,    6,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    5,    5,
    5,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   12,   12,   12,   18,   18,
    9,    9,   10,   10,   13,   13,
};
static const YYINT yylen[] = {                            2,
    1,    0,    1,    2,    2,    1,    2,    3,    3,    4,
    5,    5,    5,    7,    7,    5,    6,    6,    7,    8,
    7,    8,    6,    7,    6,   10,    8,    9,    2,    0,
    1,    3,    1,    1,    1,    3,    1,    2,    3,    3,
    4,    1,    2,    2,    5,    5,    7,    7,    2,    2,
    1,    1,    1,    1,   10,   12,   12,   10,    4,    6,
    6,    1,    1,    2,    2,    2,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    1,    1,    3,    2,    4,    1,    1,    1,    2,    1,
    0,    1,    1,    3,    1,    4,
};
static const YYINT yydefred[] = {                         0,
   35,    0,    0,    0,   33,   34,    0,    0,    3,    0,
    0,    0,    6,    0,    0,    0,    0,    0,   37,    0,
    0,    5,    4,    0,    0,    0,    0,    0,    0,    0,
   36,    0,    0,    0,    0,    0,    0,   31,    0,    0,
    0,    0,    0,   86,   87,    0,   90,   63,   81,    0,
    0,    0,    0,    0,   62,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   29,    0,    0,    0,    0,   66,
   64,   65,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   84,   89,
    0,    0,   17,    0,   25,   32,    0,    0,    0,    0,
    0,    0,   80,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   69,   70,   71,    0,    0,   23,
    0,   24,    0,    0,    0,    0,   51,   52,   53,   38,
   42,    0,    0,    0,   54,    0,   14,   21,   85,    0,
   96,    0,    0,    0,    0,    0,    0,   40,   43,   39,
    0,   49,   50,   44,    0,   22,    0,   27,   28,    0,
    0,    0,    0,   41,    0,    0,    0,    0,    0,    0,
   26,    0,   45,    0,    0,    0,    0,    0,    0,    0,
   48,   47,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   55,    0,   58,    0,    0,    0,    0,
    0,   61,   60,   56,   57,
};
static const YYINT yydgoto[] = {                          8,
  131,    9,   10,   38,  181,  132,   39,   11,  100,  101,
  134,   55,   56,   40,   20,   13,  135,   57,
};
static const YYINT yysindex[] = {                       409,
    0,  -89,  -89,  157,    0,    0,  -89,    0,    0,  -56,
  409, -244,    0, -240, -224,   -1,   22,   22,    0, -197,
  -26,    0,    0,  -28,   -3,   17,  -89, -184, -178,   46,
    0, 1062,  -89, 1062,  -89, 1062,  -89,    0,  -24, -169,
   57,   61,  -89,    0,    0,   80,    0,    0,    0, 1062,
 1062, 1062, 1062,  562,    0,   19, -132,   89,  562,   97,
  562,  104,    9,  -89,    0,  -89,  -89,  113, 1062,    0,
    0,    0,  146, 1062, 1062, 1062, 1062, 1062, 1062, 1062,
 1062, 1062, 1062, 1062, 1062, 1062, 1062, 1062,    0,    0,
  -52,  -50,    0,  764,    0,    0,  124,  126,    9,  106,
  108,  562,    0,  831,  822,  588,  588,  460,   58,   58,
   58,   58,   58,   58,    0,    0,    0,  588, -230,    0,
 -230,    0,    0,  118,  133,   71,    0,    0,    0,    0,
    0,  972,  952,  410,    0,  -47,    0,    0,    0, 1062,
    0,    9,    9, 1062, 1062,  154,  156,    0,    0,    0,
 1001,    0,    0,    0, -230,    0,  562,    0,    0,  472,
  486, 1062, 1062,    0,    9, 1113, 1113,  562,   88,  103,
    0, -128,    0, 1062, 1062,  160, 1113,  498,  512, 1062,
    0,    0, 1062, 1062,  524,  434,  446, 1113, 1113, 1062,
 1113, 1062,  -82,    0,  538,    0,  550,  160, 1113, 1113,
 1113,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                       212,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  213,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  155,  159,  164,  136,    0,    0,    0,
    0,    0,  136,    0,  136,    0,  136,    0,    0,    0,
    0,    0,  136,    0,    0,  -37,    0,    0,    0,    0,
    0,    0,    0,  166,    0,  368,    1,    0,  167,    0,
  168,    0,   34,    0,    0,  136,  136,    0,  174,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   53,   72,    0,    0,    0,    0,    0,    0,    0,    0,
  178,  140,    0,    6,  188,   25,   44,    0,  618,  623,
  873,  893,  898,  918,    0,    0,    0,   63,    0,    0,
    0,    0,  162,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   91,    0,    0,    0,    0,
    0,  110,  129,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  151,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  574,  574,
    0, 1020,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1040,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  915,    2,    0,  170,   30,  105,   76,  149,    0,    0,
 1324, -103,   40,   29,  193,    0,  627,    0,
};
#define YYTABLESIZE 1516
static const YYINT yytable[] = {                         95,
   88,    7,   22,   95,   95,   95,   95,   95,  119,   95,
  121,   33,   23,  155,   24,  142,   63,  143,   25,   64,
   95,   95,   95,   95,   95,   95,   44,   45,   12,   47,
   14,   15,   32,   13,   26,   21,   35,   88,   27,   12,
   88,   88,   88,   88,   88,   88,   78,   88,   78,   78,
   78,  165,   16,   95,   19,   95,   37,   34,   88,   88,
   88,   30,   88,   78,   78,   67,   31,   67,   67,   67,
   94,   18,   94,   13,   41,   94,   13,   36,   13,   88,
   42,   89,   67,   67,   68,   43,   68,   68,   68,   65,
   15,   88,   16,   88,   87,   16,   66,   16,   78,   85,
   67,   68,   68,   83,   86,   83,   83,   83,   58,   19,
   60,   18,   62,  146,   18,  147,   18,   67,   68,   69,
   83,   83,   12,   88,   13,   88,   88,   90,   20,   91,
   15,   94,   64,   15,   23,   15,   68,   92,  176,  177,
   64,   97,   98,   16,   93,  174,  139,   64,   88,   19,
   89,  140,   19,   99,   19,   83,   64,  144,   13,   13,
  175,   12,   18,   88,  136,   89,  137,   64,   20,   64,
    1,   20,  145,   20,    5,    6,   30,   16,   16,   30,
   93,   15,   87,   93,  198,  199,  103,   85,   76,   19,
   77,   94,   86,  162,   94,  163,   18,   18,   90,  180,
   19,  169,  170,   90,   90,   84,   90,   83,   90,   28,
   29,    2,    1,    7,   91,   15,   15,    8,   92,   20,
   90,   90,    9,   90,   10,   11,   12,  202,   79,    0,
   79,   79,   79,   96,   19,   19,   78,  151,   95,   95,
   95,   95,  133,    0,    0,   79,   79,    0,   95,   95,
   95,   95,   90,   20,   20,    0,    0,   88,   88,   88,
    0,   88,   88,   88,   88,   88,   88,    0,    0,   88,
   88,   88,   88,   88,   88,   88,   88,   88,   88,   88,
   79,   78,   78,   78,   78,    0,   88,   88,   88,   88,
   13,   13,   13,   13,   13,   13,   13,   13,   13,   13,
   67,   67,   13,   13,   13,   13,   13,   13,   13,   16,
   16,   16,   16,   16,   16,   16,   16,   16,   16,   68,
   68,   16,   16,   16,   16,   16,   16,   16,   18,   18,
   18,   18,   18,   18,   18,   18,   18,   18,   83,   83,
   18,   18,   18,   18,   18,   18,   18,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   15,    0,    0,   15,
   15,   15,   15,   15,   15,   15,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,    0,    0,   19,   19,
   19,   19,   19,   19,   19,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,    0,    0,   20,   20,   20,
   20,   20,   20,   20,   82,    0,    0,    0,   82,   82,
   82,   82,   82,    0,   82,   16,    0,   17,   18,    0,
   35,   90,    0,   74,   75,   82,   82,   82,    0,   82,
    0,   79,   80,   81,   82,    0,    0,   90,   90,   90,
   90,    0,    0,    0,    0,    0,   87,   90,   90,   90,
   90,   85,   76,    0,   77,    0,   86,    0,   82,    0,
   82,    0,    0,   79,   79,    0,   79,    0,  154,   84,
   87,   83,    0,    0,  189,   85,   76,    0,   77,    0,
   86,    0,   87,    0,    0,    0,  191,   85,   76,    0,
   77,  190,   86,   84,    0,   83,   87,    0,    0,    7,
   78,   85,   76,  192,   77,   84,   86,   83,   87,    0,
    0,    0,  166,   85,   76,    0,   77,    0,   86,   84,
    0,   83,   87,    0,   78,    0,  167,   85,   76,    0,
   77,   84,   86,   83,   87,    0,   78,    0,    0,   85,
   76,    0,   77,    0,   86,   84,    0,   83,   87,    0,
   78,    0,  141,   85,   76,  183,   77,   84,   86,   83,
   87,    0,   78,    0,  188,   85,   76,    0,   77,  184,
   86,   84,    0,   83,   87,    0,   78,    0,  200,   85,
   76,    0,   77,   84,   86,   83,   87,    0,   78,    0,
  201,   85,   76,    0,   77,    0,   86,   84,   87,   83,
    0,    0,   78,   85,   76,    0,   77,    0,   86,   84,
   82,   83,    0,    0,   78,   82,   82,    0,   82,    0,
   82,   84,    0,   83,   87,    0,    0,    0,   78,   85,
    0,    0,    0,   82,   86,   82,    0,    0,    0,    0,
   78,    0,    0,   82,   82,   82,   82,   84,    0,   83,
    0,    0,   78,   82,   82,   82,   82,    0,   74,    0,
   74,   74,   74,   75,   82,   75,   75,   75,    1,    2,
    3,    4,    5,    6,    0,   74,   74,   74,   78,   74,
   75,   75,   75,    0,   75,  152,  153,   74,   75,   95,
    0,    0,    0,    0,    0,   79,   80,   81,   82,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   74,    0,
   74,   74,   75,   75,    0,   75,    0,  120,  122,   79,
   80,   81,   82,   74,   75,  138,    0,    0,    0,    0,
    0,   79,   80,   81,   82,    0,    0,   74,   75,    0,
    0,    0,    0,    0,    0,   79,   80,   81,   82,   74,
   75,    0,    0,    0,    0,    0,    0,   79,   80,   81,
   82,    0,  156,   74,   75,    0,    0,    0,  158,  159,
    0,   79,   80,   81,   82,   74,   75,    0,    0,    0,
    0,    0,    0,   79,   80,   81,   82,    0,    0,   74,
   75,  171,    0,    0,    0,    0,    0,   79,   80,   81,
   82,   74,   75,   53,    0,    0,   51,    0,   52,   79,
   80,   81,   82,    0,    0,   74,   75,    0,    0,    0,
    0,    0,    0,   79,   80,   81,   82,   74,   75,    0,
    0,    0,    0,    0,    0,   79,   80,   81,   82,   74,
   75,    0,    0,    0,    0,    0,    0,   79,   80,   81,
   82,   82,   82,    0,    7,    0,    0,    0,   87,   82,
   82,   82,   82,   85,    0,   74,   75,   87,   86,    0,
    0,    0,   85,   79,   80,   81,   82,   86,    0,    0,
    0,   84,    0,   83,    0,    0,   94,    0,  130,   50,
   84,    0,   83,   74,   74,   74,   74,    0,   75,   75,
   75,   75,    0,   74,   74,   74,   74,    0,   75,   75,
   75,   75,   78,   77,    0,   77,   77,   77,    0,    0,
    0,   78,    0,    0,    0,    0,    0,    0,    0,    0,
   77,   77,   77,   76,   77,   76,   76,   76,   73,    0,
   73,   73,   73,    0,    0,    0,    0,    0,    0,    0,
   76,   76,   76,    0,   76,   73,   73,   73,   72,   73,
   72,   72,   72,   77,    0,   77,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   72,   72,   72,    0,   72,
    0,    0,    0,   76,    0,   76,    0,    0,   73,    0,
   73,   53,    0,    0,   51,    0,   52,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   72,    0,
   72,   53,    0,    0,   51,    0,   52,    0,    0,    0,
   44,   45,   46,  123,    2,    3,    4,    5,    6,  124,
    0,    0,  125,  126,  127,   48,  128,  129,   49,    0,
   53,    0,    7,   51,    0,   52,  149,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   46,
    0,    0,   46,    0,   46,  149,    0,    0,    0,    0,
    0,    0,    0,    0,   94,    0,  150,   50,    0,   59,
  172,  173,   59,    0,   59,    0,    0,    0,    0,    0,
    0,  182,    0,    0,   94,    0,  148,   50,    0,   74,
    0,   53,  193,  194,   51,  196,   52,   79,   80,   81,
   82,    0,    0,  203,  204,  205,   79,   80,   81,   82,
    0,    0,    0,   94,    0,  164,   50,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   46,    0,   46,   46,    0,    0,   77,   77,
   77,   77,   53,    0,    0,   51,    0,   52,   77,   77,
   77,   77,   59,    0,   59,   59,    0,    0,   76,   76,
   76,   76,    0,   73,   73,   73,   73,    0,   76,   76,
   76,   76,    0,   73,   73,   73,   73,   50,    0,    0,
    0,    0,    0,   72,   72,   72,   72,    0,    0,    0,
    0,    0,    0,   72,   72,   72,   72,    0,   44,   45,
   46,  123,    2,    3,    4,    5,    6,  124,    0,    0,
  125,  126,  127,   48,  128,  129,   49,    0,   44,   45,
   46,   47,    0,    0,    0,   94,    0,  124,   50,    0,
  125,  126,  127,   48,  128,  129,   49,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   44,   45,   46,
   47,    0,    0,    0,    0,    0,  124,    0,    0,  125,
  126,  127,   48,  128,  129,   49,   46,   46,   46,   46,
    0,    0,    0,    0,    0,   46,    0,    0,   46,   46,
   46,   46,   46,   46,   46,    0,   59,   59,   59,   59,
    0,    0,    0,    0,    0,   59,    0,    0,   59,   59,
   59,   59,   59,   59,   59,    0,    0,    0,   44,   45,
   46,   47,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   48,    0,    0,   49,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   54,    0,   59,    0,   61,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   44,
   45,   46,   47,   70,   71,   72,   73,    0,  124,    0,
    0,  125,  126,  127,   48,  128,  129,   49,    0,    0,
    0,    0,  102,    0,    0,    0,    0,  104,  105,  106,
  107,  108,  109,  110,  111,  112,  113,  114,  115,  116,
  117,  118,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  157,    0,    0,    0,  160,  161,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  168,  168,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  178,  179,    0,
    0,    0,    0,  185,    0,    0,  186,  187,    0,    0,
    0,    0,    0,  195,    0,  197,
};
static const YYINT yycheck[] = {                         37,
    0,   91,   59,   41,   42,   43,   44,   45,   61,   47,
   61,   40,   11,   61,  259,  119,   41,  121,  259,   44,
   58,   59,   60,   61,   62,   63,  257,  258,    0,  260,
    2,    3,   61,    0,  259,    7,   40,   37,   40,   11,
   40,   41,   42,   43,   44,   45,   41,   47,   43,   44,
   45,  155,    0,   91,   33,   93,   40,   61,   58,   59,
   60,  259,   62,   58,   59,   41,   93,   43,   44,   45,
  123,    0,  123,   40,  259,  123,   43,   61,   45,   61,
  259,   63,   58,   59,   41,   40,   43,   44,   45,  259,
    0,   91,   40,   93,   37,   43,   40,   45,   93,   42,
   40,   58,   59,   41,   47,   43,   44,   45,   33,    0,
   35,   40,   37,   43,   43,   45,   45,   93,   43,   40,
   58,   59,   94,  123,   91,  125,  126,  260,    0,   41,
   40,  123,   44,   43,  133,   45,   93,   41,  267,  268,
   44,   66,   67,   91,   41,   58,   41,   44,   61,   40,
   63,   44,   43,   41,   45,   93,   44,   40,  125,  126,
   58,  133,   91,   61,   41,   63,   41,   44,   40,   44,
  260,   43,   40,   45,  264,  265,   41,  125,  126,   44,
   41,   91,   37,   44,  267,  268,   41,   42,   43,   33,
   45,   41,   47,   40,   44,   40,  125,  126,   37,   40,
   91,  162,  163,   42,   43,   60,   45,   62,   47,   17,
   18,    0,    0,   59,   41,  125,  126,   59,   41,   91,
   59,   60,   59,   62,   59,   59,   59,  198,   41,   -1,
   43,   44,   45,   64,  125,  126,   91,  133,  276,  277,
  278,  279,   94,   -1,   -1,   58,   59,   -1,  286,  287,
  288,  289,   91,  125,  126,   -1,   -1,  257,  258,  259,
   -1,  261,  262,  263,  264,  265,  266,   -1,   -1,  269,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
   93,  276,  277,  278,  279,   -1,  286,  287,  288,  289,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
  276,  277,  269,  270,  271,  272,  273,  274,  275,  257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  276,
  277,  269,  270,  271,  272,  273,  274,  275,  257,  258,
  259,  260,  261,  262,  263,  264,  265,  266,  276,  277,
  269,  270,  271,  272,  273,  274,  275,  257,  258,  259,
  260,  261,  262,  263,  264,  265,  266,   -1,   -1,  269,
  270,  271,  272,  273,  274,  275,  257,  258,  259,  260,
  261,  262,  263,  264,  265,  266,   -1,   -1,  269,  270,
  271,  272,  273,  274,  275,  257,  258,  259,  260,  261,
  262,  263,  264,  265,  266,   -1,   -1,  269,  270,  271,
  272,  273,  274,  275,   37,   -1,   -1,   -1,   41,   42,
   43,   44,   45,   -1,   47,  259,   -1,  261,  262,   -1,
  259,  260,   -1,  278,  279,   58,   59,   60,   -1,   62,
   -1,  286,  287,  288,  289,   -1,   -1,  276,  277,  278,
  279,   -1,   -1,   -1,   -1,   -1,   37,  286,  287,  288,
  289,   42,   43,   -1,   45,   -1,   47,   -1,   91,   -1,
   93,   -1,   -1,  276,  277,   -1,  279,   -1,   59,   60,
   37,   62,   -1,   -1,   41,   42,   43,   -1,   45,   -1,
   47,   -1,   37,   -1,   -1,   -1,   41,   42,   43,   -1,
   45,   58,   47,   60,   -1,   62,   37,   -1,   -1,   91,
   91,   42,   43,   58,   45,   60,   47,   62,   37,   -1,
   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,   60,
   -1,   62,   37,   -1,   91,   -1,   41,   42,   43,   -1,
   45,   60,   47,   62,   37,   -1,   91,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   60,   -1,   62,   37,   -1,
   91,   -1,   93,   42,   43,   58,   45,   60,   47,   62,
   37,   -1,   91,   -1,   41,   42,   43,   -1,   45,   58,
   47,   60,   -1,   62,   37,   -1,   91,   -1,   41,   42,
   43,   -1,   45,   60,   47,   62,   37,   -1,   91,   -1,
   41,   42,   43,   -1,   45,   -1,   47,   60,   37,   62,
   -1,   -1,   91,   42,   43,   -1,   45,   -1,   47,   60,
   37,   62,   -1,   -1,   91,   42,   43,   -1,   45,   -1,
   47,   60,   -1,   62,   37,   -1,   -1,   -1,   91,   42,
   -1,   -1,   -1,   60,   47,   62,   -1,   -1,   -1,   -1,
   91,   -1,   -1,  276,  277,  278,  279,   60,   -1,   62,
   -1,   -1,   91,  286,  287,  288,  289,   -1,   41,   -1,
   43,   44,   45,   41,   91,   43,   44,   45,  260,  261,
  262,  263,  264,  265,   -1,   58,   59,   60,   91,   62,
   58,   59,   60,   -1,   62,  276,  277,  278,  279,   63,
   -1,   -1,   -1,   -1,   -1,  286,  287,  288,  289,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   91,   -1,
   93,  278,  279,   91,   -1,   93,   -1,   91,   92,  286,
  287,  288,  289,  278,  279,   99,   -1,   -1,   -1,   -1,
   -1,  286,  287,  288,  289,   -1,   -1,  278,  279,   -1,
   -1,   -1,   -1,   -1,   -1,  286,  287,  288,  289,  278,
  279,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,  288,
  289,   -1,  136,  278,  279,   -1,   -1,   -1,  142,  143,
   -1,  286,  287,  288,  289,  278,  279,   -1,   -1,   -1,
   -1,   -1,   -1,  286,  287,  288,  289,   -1,   -1,  278,
  279,  165,   -1,   -1,   -1,   -1,   -1,  286,  287,  288,
  289,  278,  279,   40,   -1,   -1,   43,   -1,   45,  286,
  287,  288,  289,   -1,   -1,  278,  279,   -1,   -1,   -1,
   -1,   -1,   -1,  286,  287,  288,  289,  278,  279,   -1,
   -1,   -1,   -1,   -1,   -1,  286,  287,  288,  289,  278,
  279,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,  288,
  289,  278,  279,   -1,   91,   -1,   -1,   -1,   37,  286,
  287,  288,  289,   42,   -1,  278,  279,   37,   47,   -1,
   -1,   -1,   42,  286,  287,  288,  289,   47,   -1,   -1,
   -1,   60,   -1,   62,   -1,   -1,  123,   -1,  125,  126,
   60,   -1,   62,  276,  277,  278,  279,   -1,  276,  277,
  278,  279,   -1,  286,  287,  288,  289,   -1,  286,  287,
  288,  289,   91,   41,   -1,   43,   44,   45,   -1,   -1,
   -1,   91,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   58,   59,   60,   41,   62,   43,   44,   45,   41,   -1,
   43,   44,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   58,   59,   60,   -1,   62,   58,   59,   60,   41,   62,
   43,   44,   45,   91,   -1,   93,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   58,   59,   60,   -1,   62,
   -1,   -1,   -1,   91,   -1,   93,   -1,   -1,   91,   -1,
   93,   40,   -1,   -1,   43,   -1,   45,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   91,   -1,
   93,   40,   -1,   -1,   43,   -1,   45,   -1,   -1,   -1,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
   -1,   -1,  269,  270,  271,  272,  273,  274,  275,   -1,
   40,   -1,   91,   43,   -1,   45,  132,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,
   -1,   -1,   43,   -1,   45,  151,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  123,   -1,  125,  126,   -1,   40,
  166,  167,   43,   -1,   45,   -1,   -1,   -1,   -1,   -1,
   -1,  177,   -1,   -1,  123,   -1,  125,  126,   -1,  278,
   -1,   40,  188,  189,   43,  191,   45,  286,  287,  288,
  289,   -1,   -1,  199,  200,  201,  286,  287,  288,  289,
   -1,   -1,   -1,  123,   -1,  125,  126,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  123,   -1,  125,  126,   -1,   -1,  276,  277,
  278,  279,   40,   -1,   -1,   43,   -1,   45,  286,  287,
  288,  289,  123,   -1,  125,  126,   -1,   -1,  276,  277,
  278,  279,   -1,  276,  277,  278,  279,   -1,  286,  287,
  288,  289,   -1,  286,  287,  288,  289,  126,   -1,   -1,
   -1,   -1,   -1,  276,  277,  278,  279,   -1,   -1,   -1,
   -1,   -1,   -1,  286,  287,  288,  289,   -1,  257,  258,
  259,  260,  261,  262,  263,  264,  265,  266,   -1,   -1,
  269,  270,  271,  272,  273,  274,  275,   -1,  257,  258,
  259,  260,   -1,   -1,   -1,  123,   -1,  266,  126,   -1,
  269,  270,  271,  272,  273,  274,  275,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,   -1,   -1,   -1,   -1,   -1,  266,   -1,   -1,  269,
  270,  271,  272,  273,  274,  275,  257,  258,  259,  260,
   -1,   -1,   -1,   -1,   -1,  266,   -1,   -1,  269,  270,
  271,  272,  273,  274,  275,   -1,  257,  258,  259,  260,
   -1,   -1,   -1,   -1,   -1,  266,   -1,   -1,  269,  270,
  271,  272,  273,  274,  275,   -1,   -1,   -1,  257,  258,
  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  272,   -1,   -1,  275,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   32,   -1,   34,   -1,   36,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,   50,   51,   52,   53,   -1,  266,   -1,
   -1,  269,  270,  271,  272,  273,  274,  275,   -1,   -1,
   -1,   -1,   69,   -1,   -1,   -1,   -1,   74,   75,   76,
   77,   78,   79,   80,   81,   82,   83,   84,   85,   86,
   87,   88,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  140,   -1,   -1,   -1,  144,  145,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  162,  163,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  174,  175,   -1,
   -1,   -1,   -1,  180,   -1,   -1,  183,  184,   -1,   -1,
   -1,   -1,   -1,  190,   -1,  192,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 311
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,"':'","';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'{'",0,"'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tINTEGER","tDOUBLE",
"tIDENTIFIER","tSTRING","tPUBLIC","tUSE","tPROCEDURE","tINT","tREAL","tIF",
"tELSIF","tELSE","tWHILE","tSWEEP","tNEXT","tNULL","tSTOP","tRETURN","tREAD",
"tPRINT","tPRINTLN","tAND","tOR","tIFX","tSTRINGX","tNOVAR","tNOBLOCK",
"tHALFBLOCK","tEMPTYBLOCK","tGE","tLE","tEQ","tNE","tUNARY",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : declarations",
"file :",
"declarations : declaration",
"declarations : declarations declaration",
"declaration : var ';'",
"declaration : function",
"var : type tIDENTIFIER",
"var : tPUBLIC type tIDENTIFIER",
"var : tUSE type tIDENTIFIER",
"var : type tIDENTIFIER '=' expr",
"var : tPUBLIC type tIDENTIFIER '=' expr",
"var : tUSE type tIDENTIFIER '=' expr",
"function : tPROCEDURE tIDENTIFIER '(' functionargs ')'",
"function : tPROCEDURE tUSE type_void tIDENTIFIER '(' functionargs ')'",
"function : tPROCEDURE tPUBLIC type_void tIDENTIFIER '(' functionargs ')'",
"function : type tIDENTIFIER '(' functionargs ')'",
"function : tUSE type tIDENTIFIER '(' functionargs ')'",
"function : tPUBLIC type tIDENTIFIER '(' functionargs ')'",
"function : type tIDENTIFIER '(' functionargs ')' '=' literal",
"function : tPUBLIC type tIDENTIFIER '(' functionargs ')' '=' literal",
"function : tPROCEDURE type_void tIDENTIFIER '(' functionargs ')' block",
"function : tPROCEDURE tPUBLIC type_void tIDENTIFIER '(' functionargs ')' block",
"function : type tIDENTIFIER '(' functionargs ')' block",
"function : tPUBLIC type tIDENTIFIER '(' functionargs ')' block",
"function : tPROCEDURE tIDENTIFIER '(' functionargs ')' block",
"function : tPROCEDURE tPUBLIC type_void tIDENTIFIER '(' functionargs ')' '=' literal block",
"function : type tIDENTIFIER '(' functionargs ')' '=' literal block",
"function : tPUBLIC type tIDENTIFIER '(' functionargs ')' '=' literal block",
"functionarg : type tIDENTIFIER",
"functionargs :",
"functionargs : functionarg",
"functionargs : functionargs ',' functionarg",
"type : tINT",
"type : tREAL",
"type : tSTRING",
"type : '[' type ']'",
"type_void : '!'",
"block : '{' '}'",
"block : '{' declarations '}'",
"block : '{' list '}'",
"block : '{' declarations list '}'",
"list : stmt",
"list : list stmt",
"stmt : expr ';'",
"stmt : tWHILE '(' expr ')' stmt",
"stmt : tIF '(' expr ')' stmt",
"stmt : tIF '(' expr ')' stmt tELSE stmt",
"stmt : tIF '(' expr ')' stmt tELSIF elsif",
"stmt : expr tPRINT",
"stmt : expr tPRINTLN",
"stmt : tNEXT",
"stmt : tSTOP",
"stmt : tRETURN",
"stmt : block",
"stmt : tSWEEP '+' '(' lval ':' expr ':' expr ')' stmt",
"stmt : tSWEEP '+' '(' lval ':' expr ':' expr ':' expr ')' stmt",
"stmt : tSWEEP '-' '(' lval ':' expr ':' expr ':' expr ')' stmt",
"stmt : tSWEEP '-' '(' lval ':' expr ':' expr ')' stmt",
"elsif : '(' expr ')' stmt",
"elsif : '(' expr ')' stmt tELSE stmt",
"elsif : '(' expr ')' stmt tELSIF elsif",
"expr : literal",
"expr : tNULL",
"expr : '+' expr",
"expr : '-' expr",
"expr : '~' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr tGE expr",
"expr : expr tLE expr",
"expr : expr tNE expr",
"expr : expr tEQ expr",
"expr : expr tAND expr",
"expr : expr tOR expr",
"expr : '(' expr ')'",
"expr : tREAD",
"expr : lval",
"expr : lval '=' expr",
"expr : lval '?'",
"expr : tIDENTIFIER '(' argscall ')'",
"literal : tINTEGER",
"literal : tDOUBLE",
"literal : string",
"string : string tSTRING",
"string : tSTRING",
"argscall :",
"argscall : calls",
"calls : expr",
"calls : calls ',' expr",
"lval : tIDENTIFIER",
"lval : expr '[' expr ']'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 72 "xpl_parser.y"
	{ compiler -> ast(yystack.l_mark[0].sequence); }
break;
case 2:
#line 73 "xpl_parser.y"
	{ compiler -> ast(new cdk::sequence_node(LINE, nullptr)); }
break;
case 3:
#line 76 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 4:
#line 77 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 5:
#line 80 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 6:
#line 81 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[0]._func; }
break;
case 7:
#line 84 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE, yystack.l_mark[-1]._type, yystack.l_mark[0].s,false,false); }
break;
case 8:
#line 85 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE, yystack.l_mark[-1]._type, yystack.l_mark[0].s, true,false); }
break;
case 9:
#line 86 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE, yystack.l_mark[-1]._type, yystack.l_mark[0].s, true,false); }
break;
case 10:
#line 87 "xpl_parser.y"
	{ yyval.node = new xpl::variable_initialization_node(LINE, yystack.l_mark[-3]._type, yystack.l_mark[-2].s, yystack.l_mark[0].expression,false, false); }
break;
case 11:
#line 88 "xpl_parser.y"
	{ yyval.node = new xpl::variable_initialization_node(LINE, yystack.l_mark[-3]._type, yystack.l_mark[-2].s, yystack.l_mark[0].expression, true, false); }
break;
case 12:
#line 89 "xpl_parser.y"
	{ yyval.node = new xpl::variable_initialization_node(LINE, yystack.l_mark[-3]._type, yystack.l_mark[-2].s, yystack.l_mark[0].expression, false, true); }
break;
case 13:
#line 92 "xpl_parser.y"
	{ yyval._func = new xpl::function_declaration_node(LINE, nullptr, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, false, false, true); }
break;
case 14:
#line 93 "xpl_parser.y"
	{ yyval._func = new xpl::function_declaration_node(LINE, yystack.l_mark[-4]._type, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, true, false, true); }
break;
case 15:
#line 94 "xpl_parser.y"
	{ yyval._func = new xpl::function_declaration_node(LINE, yystack.l_mark[-4]._type, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, false, true, true); }
break;
case 16:
#line 95 "xpl_parser.y"
	{ yyval._func = new xpl::function_declaration_node(LINE, yystack.l_mark[-4]._type, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, false, false, false); }
break;
case 17:
#line 96 "xpl_parser.y"
	{ yyval._func = new xpl::function_declaration_node(LINE, yystack.l_mark[-4]._type, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, true, false, false); }
break;
case 18:
#line 97 "xpl_parser.y"
	{ yyval._func = new xpl::function_declaration_node(LINE, yystack.l_mark[-4]._type, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, false, true, false); }
break;
case 19:
#line 98 "xpl_parser.y"
	{ yyval._func = new xpl::function_definition_node(LINE, yystack.l_mark[-6]._type, yystack.l_mark[-5].s, yystack.l_mark[-3].sequence, false, false, false, nullptr, yystack.l_mark[0].expression); }
break;
case 20:
#line 99 "xpl_parser.y"
	{ yyval._func = new xpl::function_definition_node(LINE, yystack.l_mark[-6]._type, yystack.l_mark[-5].s, yystack.l_mark[-3].sequence, false, true, false, nullptr, yystack.l_mark[0].expression); }
break;
case 21:
#line 100 "xpl_parser.y"
	{ yyval._func = new xpl::function_definition_node(LINE, yystack.l_mark[-5]._type, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, false, false, true, yystack.l_mark[0]._block, nullptr); }
break;
case 22:
#line 101 "xpl_parser.y"
	{ yyval._func = new xpl::function_definition_node(LINE, yystack.l_mark[-5]._type, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, false, true, true, yystack.l_mark[0]._block, nullptr); }
break;
case 23:
#line 102 "xpl_parser.y"
	{ yyval._func = new xpl::function_definition_node(LINE, yystack.l_mark[-5]._type, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, false, false, false, yystack.l_mark[0]._block, nullptr); }
break;
case 24:
#line 103 "xpl_parser.y"
	{ yyval._func = new xpl::function_definition_node(LINE, yystack.l_mark[-5]._type, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, false, true, false, yystack.l_mark[0]._block, nullptr); }
break;
case 25:
#line 104 "xpl_parser.y"
	{ yyval._func = new xpl::function_definition_node(LINE, nullptr, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, false, false, true, yystack.l_mark[0]._block, nullptr); }
break;
case 26:
#line 105 "xpl_parser.y"
	{ yyval._func = new xpl::function_definition_node(LINE, yystack.l_mark[-7]._type, yystack.l_mark[-6].s, yystack.l_mark[-4].sequence, false, true, true, yystack.l_mark[0]._block, yystack.l_mark[-1].expression); }
break;
case 27:
#line 106 "xpl_parser.y"
	{ yyval._func = new xpl::function_definition_node(LINE, yystack.l_mark[-7]._type, yystack.l_mark[-6].s, yystack.l_mark[-4].sequence, false, false, false, yystack.l_mark[0]._block, yystack.l_mark[-1].expression); }
break;
case 28:
#line 107 "xpl_parser.y"
	{ yyval._func = new xpl::function_definition_node(LINE, yystack.l_mark[-7]._type, yystack.l_mark[-6].s, yystack.l_mark[-4].sequence, false, true, false, yystack.l_mark[0]._block, yystack.l_mark[-1].expression); }
break;
case 29:
#line 110 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE, yystack.l_mark[-1]._type, yystack.l_mark[0].s, 0, 0); }
break;
case 30:
#line 113 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, nullptr); }
break;
case 31:
#line 114 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 32:
#line 115 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-2].sequence); }
break;
case 33:
#line 118 "xpl_parser.y"
	{ yyval._type = new basic_type(4, basic_type::TYPE_INT); }
break;
case 34:
#line 119 "xpl_parser.y"
	{ yyval._type = new basic_type(8, basic_type::TYPE_DOUBLE); }
break;
case 35:
#line 120 "xpl_parser.y"
	{ yyval._type = new basic_type(4, basic_type::TYPE_STRING); }
break;
case 36:
#line 121 "xpl_parser.y"
	{ yyval._type = new basic_type(4, basic_type::TYPE_POINTER); yyval._type->_subtype = yystack.l_mark[-1]._type; }
break;
case 37:
#line 124 "xpl_parser.y"
	{ yyval._type = new basic_type(4, basic_type::TYPE_VOID); }
break;
case 38:
#line 128 "xpl_parser.y"
	{ yyval._block = new xpl::block_node(LINE, nullptr, nullptr); }
break;
case 39:
#line 129 "xpl_parser.y"
	{ yyval._block = new xpl::block_node(LINE, yystack.l_mark[-1].sequence, nullptr); }
break;
case 40:
#line 130 "xpl_parser.y"
	{ yyval._block = new xpl::block_node(LINE, nullptr, yystack.l_mark[-1].sequence); }
break;
case 41:
#line 131 "xpl_parser.y"
	{ yyval._block = new xpl::block_node(LINE, yystack.l_mark[-2].sequence, yystack.l_mark[-1].sequence); }
break;
case 42:
#line 135 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 43:
#line 136 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 44:
#line 139 "xpl_parser.y"
	{ yyval.node = new xpl::evaluation_node(LINE, yystack.l_mark[-1].expression); }
break;
case 45:
#line 140 "xpl_parser.y"
	{ yyval.node = new xpl::while_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 46:
#line 141 "xpl_parser.y"
	{ yyval.node = new xpl::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 47:
#line 142 "xpl_parser.y"
	{ yyval.node = new xpl::if_else_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 48:
#line 143 "xpl_parser.y"
	{ yyval.node = new xpl::if_else_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 49:
#line 144 "xpl_parser.y"
	{ yyval.node = new xpl::print_node(LINE, yystack.l_mark[-1].expression); }
break;
case 50:
#line 145 "xpl_parser.y"
	{ yyval.node = new xpl::print_node(LINE, yystack.l_mark[-1].expression, true); }
break;
case 51:
#line 146 "xpl_parser.y"
	{ yyval.node = new xpl::next_node(LINE); }
break;
case 52:
#line 147 "xpl_parser.y"
	{ yyval.node = new xpl::stop_node(LINE); }
break;
case 53:
#line 148 "xpl_parser.y"
	{ yyval.node = new xpl::return_node(LINE); }
break;
case 54:
#line 149 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[0]._block ;}
break;
case 55:
#line 150 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_plus_node(LINE, yystack.l_mark[-6].lvalue, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 56:
#line 151 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_plus_node(LINE, yystack.l_mark[-8].lvalue, yystack.l_mark[-6].expression, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 57:
#line 152 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_less_node(LINE, yystack.l_mark[-8].lvalue, yystack.l_mark[-6].expression, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 58:
#line 153 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_less_node(LINE, yystack.l_mark[-6].lvalue, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 59:
#line 156 "xpl_parser.y"
	{ yyval.node = new xpl::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 60:
#line 157 "xpl_parser.y"
	{ yyval.node = new xpl::if_else_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 61:
#line 158 "xpl_parser.y"
	{ yyval.node = new xpl::if_else_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 62:
#line 162 "xpl_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 63:
#line 163 "xpl_parser.y"
	{ yyval.expression = new xpl::null_node(LINE); }
break;
case 64:
#line 164 "xpl_parser.y"
	{ yyval.expression = new xpl::identity_node(LINE, yystack.l_mark[0].expression); }
break;
case 65:
#line 165 "xpl_parser.y"
	{ yyval.expression = new cdk::neg_node(LINE, yystack.l_mark[0].expression); }
break;
case 66:
#line 166 "xpl_parser.y"
	{ yyval.expression = new cdk::not_node(LINE, yystack.l_mark[0].expression); }
break;
case 67:
#line 167 "xpl_parser.y"
	{ yyval.expression = new cdk::add_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 68:
#line 168 "xpl_parser.y"
	{ yyval.expression = new cdk::sub_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 69:
#line 169 "xpl_parser.y"
	{ yyval.expression = new cdk::mul_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 70:
#line 170 "xpl_parser.y"
	{ yyval.expression = new cdk::div_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 71:
#line 171 "xpl_parser.y"
	{ yyval.expression = new cdk::mod_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 72:
#line 172 "xpl_parser.y"
	{ yyval.expression = new cdk::lt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 73:
#line 173 "xpl_parser.y"
	{ yyval.expression = new cdk::gt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 74:
#line 174 "xpl_parser.y"
	{ yyval.expression = new cdk::ge_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 75:
#line 175 "xpl_parser.y"
	{ yyval.expression = new cdk::le_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 76:
#line 176 "xpl_parser.y"
	{ yyval.expression = new cdk::ne_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 77:
#line 177 "xpl_parser.y"
	{ yyval.expression = new cdk::eq_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 78:
#line 178 "xpl_parser.y"
	{ yyval.expression = new cdk::and_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 79:
#line 179 "xpl_parser.y"
	{ yyval.expression = new cdk::or_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 80:
#line 180 "xpl_parser.y"
	{ yyval.expression = yystack.l_mark[-1].expression; }
break;
case 81:
#line 181 "xpl_parser.y"
	{ yyval.expression = new xpl::read_node(LINE); }
break;
case 82:
#line 182 "xpl_parser.y"
	{ yyval.expression = new cdk::rvalue_node(LINE, yystack.l_mark[0].lvalue); }
break;
case 83:
#line 183 "xpl_parser.y"
	{ yyval.expression = new cdk::assignment_node(LINE, yystack.l_mark[-2].lvalue, yystack.l_mark[0].expression); }
break;
case 84:
#line 184 "xpl_parser.y"
	{ yyval.expression = new xpl::adress_of_node(LINE, yystack.l_mark[-1].lvalue); }
break;
case 85:
#line 185 "xpl_parser.y"
	{ yyval.expression = new xpl::function_call_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence); }
break;
case 86:
#line 188 "xpl_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 87:
#line 189 "xpl_parser.y"
	{ yyval.expression = new cdk::double_node(LINE, yystack.l_mark[0].d); }
break;
case 88:
#line 190 "xpl_parser.y"
	{ yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s); }
break;
case 89:
#line 193 "xpl_parser.y"
	{yyval.s = &(yystack.l_mark[-1].s->append(*yystack.l_mark[0].s)); }
break;
case 90:
#line 194 "xpl_parser.y"
	{yyval.s = yystack.l_mark[0].s; }
break;
case 91:
#line 197 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, nullptr); }
break;
case 92:
#line 198 "xpl_parser.y"
	{ yyval.sequence = yystack.l_mark[0].sequence; }
break;
case 93:
#line 201 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression); }
break;
case 94:
#line 202 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression, yystack.l_mark[-2].sequence); }
break;
case 95:
#line 206 "xpl_parser.y"
	{ yyval.lvalue = new cdk::identifier_node(LINE, yystack.l_mark[0].s); }
break;
case 96:
#line 207 "xpl_parser.y"
	{ yyval.lvalue = new xpl::index_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[-1].expression); }
break;
#line 1279 "xpl_parser.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
