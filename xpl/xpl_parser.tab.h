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
extern YYSTYPE yylval;
