%option c++ yyclass="xpl_scanner" outfile="xpl_scanner.cpp"
%option stack noyywrap yylineno 8bit 
%{ 
/* $Id: xpl_scanner.l,v 1.8 2017/05/22 13:31:07 ist168199 Exp $ */
// make relevant includes before including the parser's tab file
#include <string>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include "xpl_scanner.h"
#include "xpl_parser.tab.h"
#include <climits>

// don't change this
#define yyerror LexerError
%}

EXP ([eE][+-]?[0-9]+)?

%x X_STRING X_STRING_SPECIAL
%x X_COMENT_E X_COMENT_O

%%

"//"                   yy_push_state(X_COMENT_E);
<X_COMENT_E>\n         yy_pop_state();
<X_COMENT_E>.          ; /*ignore comment content*/

<INITIAL,X_COMENT_O>"/*"  yy_push_state(X_COMENT_O);
<X_COMENT_O>"*/"          yy_pop_state();
<X_COMENT_O>.|\n          ; /*ignore comment content*/


">="                   return tGE; 
"<="                   return tLE; 
"=="                   return tEQ; 
"!="                   return tNE; 


"int"                  return tINT;
"real"                 return tREAL;
"string"               return tSTRING;
"procedure"            return tPROCEDURE;
"public"               return tPUBLIC;
"use"                  return tUSE;


"while"                return tWHILE;
"sweep"                return tSWEEP;
"if"                   return tIF;
"elsif"                return tELSIF;
"else"                 return tELSE;

"!"                    return tPRINT;
"!!"                   return tPRINTLN;
"@"                    return tREAD;


"next"                 return tNEXT;
"stop"                 return tSTOP;
"null"                 return tNULL;
"return"               return tRETURN;

"&"                    return tAND;
"|"                    return tOR;


[A-Za-z_][A-Za-z0-9_]*  yylval.s = new std::string(yytext); return tIDENTIFIER;

\"                     yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>\"           yy_pop_state(); return tSTRING;

<X_STRING>\\            yy_push_state(X_STRING_SPECIAL);
<X_STRING>.|\n            *yylval.s += yytext;

<X_STRING_SPECIAL>n    {*yylval.s += "\n"; yy_pop_state();}
<X_STRING_SPECIAL>t    {*yylval.s += "\t"; yy_pop_state();}
<X_STRING_SPECIAL>r    {*yylval.s += "\t"; yy_pop_state();}
<X_STRING_SPECIAL>[1-9a-fA-F][0-9a-fA-F]?       {*yylval.s += (char) strtol(yytext, nullptr, 16); yy_pop_state();}
<X_STRING_SPECIAL>[0][0-9a-fA-F]*    {*yylval.s += "\0"; yy_pop_state();}

<X_STRING_SPECIAL>.|\n            yyerror("Invalid Special character");

0                      yylval.i=0; return tINTEGER;
0[0-9]+                yyerror("Zero is always zero");
[1-9][0-9]*            yylval.i = strtol(yytext, nullptr, 10); return tINTEGER;

0x0[0-9a-fA-F]*            yyerror("Zero is always zero");
0x[1-9a-fA-F][0-9a-fA-F]*  {yylval.i = strtol(yytext, nullptr, 16);
                            if (yylval.i == INT_MAX) 
                            yyerror("Overflow in hexa");
                            return tINTEGER;}

0(\.)?{EXP}              yyerror("Not a zero representation");
0[0-9]+(\.)?[0-9]*{EXP}   yyerror("Zero is always zero");
[0-9]+(\.)?[0-9]*{EXP}    yylval.d = strtod(yytext, nullptr); return tDOUBLE;

[-()<>=#+?*/%;,{}~!:]       return *yytext;

[ \t\n]+               ; /* ignore whitespace */

.                      yyerror("Unknown character");

%%
// Very, very dirty hack: flex is a mess generating C++ scanners.
int xpl_scanner::yywrap() { return 1; }
