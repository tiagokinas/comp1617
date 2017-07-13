%{
// $Id: xpl_parser.y,v 1.14 2017/05/21 23:44:50 ist168199 Exp $
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
//-- don't change *any* of these --- END!
%}

%union {
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
};

%token <i> tINTEGER 
%token <d> tDOUBLE 
%token <s> tIDENTIFIER tSTRING
%token <b> tPUBLIC tUSE tPROCEDURE
%token tINT tREAL tIF tELSIF tELSE tWHILE tSWEEP tNEXT tNULL tSTOP tRETURN tREAD tPRINT tPRINTLN tAND tOR

%nonassoc tIFX
%nonassoc tSTRINGX
%nonassoc tELSIF
%nonassoc tELSE tSTRING 


%nonassoc tNOVAR

%nonassoc tNOBLOCK
%nonassoc tHALFBLOCK
%nonassoc tEMPTYBLOCK


%nonassoc '~'
%left '+' '-'
%right '='
%left tOR
%left tAND
%right '[' '('
%left tGE tLE tEQ tNE '>' '<'
%left '*' '/' '%' '{' '}'
%nonassoc tUNARY

%type <node> stmt file declaration var  functionarg elsif 
%type <sequence> list functionargs declarations argscall calls 
%type <expression> expr literal
%type <lvalue> lval
%type <_type> type type_void
%type <_func> function
%type <_block> block
%type <s> string

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file : declarations { compiler -> ast($1); }
     |              { compiler -> ast(new cdk::sequence_node(LINE, nullptr)); }
     ;

declarations : declaration { $$ = new cdk::sequence_node(LINE, $1); }
             | declarations declaration { $$ = new cdk::sequence_node(LINE,$2, $1); }
             ;
             
declaration : var ';' { $$ = $1; }
            | function    { $$ = $1; }
            ;
            
var : type tIDENTIFIER                              { $$ = new xpl::variable_declaration_node(LINE, $1, $2,false,false); }    
    | tPUBLIC type tIDENTIFIER                              { $$ = new xpl::variable_declaration_node(LINE, $2, $3, true,false); } 
    | tUSE type tIDENTIFIER                              { $$ = new xpl::variable_declaration_node(LINE, $2, $3, true,false); }  
    | type tIDENTIFIER '=' expr %prec tNOVAR        { $$ = new xpl::variable_initialization_node(LINE, $1, $2, $4,false, false); }
    | tPUBLIC type tIDENTIFIER '=' expr %prec tNOVAR        { $$ = new xpl::variable_initialization_node(LINE, $2, $3, $5, true, false); }
    | tUSE type tIDENTIFIER '=' expr %prec tNOVAR        { $$ = new xpl::variable_initialization_node(LINE, $2, $3, $5, false, true); }
    ;
    
function : tPROCEDURE tIDENTIFIER '(' functionargs ')' %prec tNOBLOCK         { $$ = new xpl::function_declaration_node(LINE, nullptr, $2, $4, false, false, true); }
     | tPROCEDURE tUSE type_void tIDENTIFIER  '(' functionargs ')' %prec tNOBLOCK       { $$ = new xpl::function_declaration_node(LINE, $3, $4, $6, true, false, true); }
     | tPROCEDURE tPUBLIC type_void tIDENTIFIER  '(' functionargs ')' %prec tNOBLOCK    { $$ = new xpl::function_declaration_node(LINE, $3, $4, $6, false, true, true); }
     | type tIDENTIFIER '(' functionargs ')' %prec tNOBLOCK                             { $$ = new xpl::function_declaration_node(LINE, $1, $2, $4, false, false, false); }
     | tUSE type tIDENTIFIER  '(' functionargs ')' %prec tNOBLOCK                       { $$ = new xpl::function_declaration_node(LINE, $2, $3, $5, true, false, false); }
     | tPUBLIC type tIDENTIFIER '(' functionargs ')' %prec tNOBLOCK                     { $$ = new xpl::function_declaration_node(LINE, $2, $3, $5, false, true, false); }
     | type tIDENTIFIER  '(' functionargs ')' '=' literal %prec tNOBLOCK                { $$ = new xpl::function_definition_node(LINE, $1, $2, $4, false, false, false, nullptr, $7); }
     | tPUBLIC type tIDENTIFIER '(' functionargs ')' '=' literal %prec tNOBLOCK         { $$ = new xpl::function_definition_node(LINE, $2, $3, $5, false, true, false, nullptr, $8); }
     | tPROCEDURE type_void tIDENTIFIER '(' functionargs ')' block                      { $$ = new xpl::function_definition_node(LINE, $2, $3, $5, false, false, true, $7, nullptr); }
     | tPROCEDURE tPUBLIC type_void tIDENTIFIER '(' functionargs ')' block              { $$ = new xpl::function_definition_node(LINE, $3, $4, $6, false, true, true, $8, nullptr); }
     | type tIDENTIFIER  '(' functionargs ')' block                                     { $$ = new xpl::function_definition_node(LINE, $1, $2, $4, false, false, false, $6, nullptr); }
     | tPUBLIC type tIDENTIFIER  '(' functionargs ')' block                             { $$ = new xpl::function_definition_node(LINE, $2, $3, $5, false, true, false, $7, nullptr); }
     | tPROCEDURE tIDENTIFIER  '(' functionargs ')' block         { $$ = new xpl::function_definition_node(LINE, nullptr, $2, $4, false, false, true, $6, nullptr); }
     | tPROCEDURE tPUBLIC type_void tIDENTIFIER  '(' functionargs ')' '=' literal block { $$ = new xpl::function_definition_node(LINE, $3, $4, $6, false, true, true, $10, $9); }
     | type tIDENTIFIER  '(' functionargs ')' '=' literal block                         { $$ = new xpl::function_definition_node(LINE, $1, $2, $4, false, false, false, $8, $7); }
     | tPUBLIC type tIDENTIFIER  '(' functionargs ')' '=' literal block                 { $$ = new xpl::function_definition_node(LINE, $2, $3, $5, false, true, false, $9, $8); }
     ;

functionarg: type tIDENTIFIER { $$ = new xpl::variable_declaration_node(LINE, $1, $2, 0, 0); }
           ;
           
functionargs:                               { $$ = new cdk::sequence_node(LINE, nullptr); }
            | functionarg                   { $$ = new cdk::sequence_node(LINE, $1); }
            | functionargs ',' functionarg  { $$ = new cdk::sequence_node(LINE, $3, $1); }
            ;
        
type : tINT           { $$ = new basic_type(4, basic_type::TYPE_INT); }
     | tREAL          { $$ = new basic_type(8, basic_type::TYPE_DOUBLE); } 
     | tSTRING        { $$ = new basic_type(4, basic_type::TYPE_STRING); }
     | '[' type ']'  { $$ = new basic_type(4, basic_type::TYPE_POINTER); $$->_subtype = $2; }
     ;
     
type_void : '!'           { $$ = new basic_type(4, basic_type::TYPE_VOID); }
          ;
          
     
block : '{' '}' %prec tEMPTYBLOCK                { $$ = new xpl::block_node(LINE, nullptr, nullptr); }
      | '{' declarations '}' %prec tHALFBLOCK    { $$ = new xpl::block_node(LINE, $2, nullptr); }
      | '{' list '}' %prec tHALFBLOCK            { $$ = new xpl::block_node(LINE, nullptr, $2); }
      | '{' declarations list '}'                { $$ = new xpl::block_node(LINE, $2, $3); }
      ;

    
list : stmt      { $$ = new cdk::sequence_node(LINE, $1); }
     | list stmt { $$ = new cdk::sequence_node(LINE, $2, $1); }
     ;

stmt : expr ';'                         { $$ = new xpl::evaluation_node(LINE, $1); }
     | tWHILE '(' expr ')' stmt         { $$ = new xpl::while_node(LINE, $3, $5); }
     | tIF '(' expr ')' stmt %prec tIFX { $$ = new xpl::if_node(LINE, $3, $5); }
     | tIF '(' expr ')' stmt tELSE stmt    { $$ = new xpl::if_else_node(LINE, $3, $5, $7); }
     | tIF '(' expr ')' stmt tELSIF elsif    { $$ = new xpl::if_else_node(LINE, $3, $5, $7); }
     | expr tPRINT                      { $$ = new xpl::print_node(LINE, $1); }
     | expr tPRINTLN                    { $$ = new xpl::print_node(LINE, $1, true); }
     | tNEXT                     { $$ = new xpl::next_node(LINE); }
     | tSTOP                     { $$ = new xpl::stop_node(LINE); }
     | tRETURN                   { $$ = new xpl::return_node(LINE); }
     | block                     { $$ = $1 ;}
     | tSWEEP '+' '(' lval ':' expr ':' expr ')' stmt  { $$ = new xpl::sweep_plus_node(LINE, $4, $6, $8, $10); }
     | tSWEEP '+' '(' lval ':' expr ':' expr ':' expr ')' stmt { $$ = new xpl::sweep_plus_node(LINE, $4, $6, $8, $10, $12); }  
     | tSWEEP '-' '(' lval ':' expr ':' expr ':' expr ')' stmt   { $$ = new xpl::sweep_less_node(LINE, $4, $6, $8, $10, $12); }
     | tSWEEP '-' '(' lval ':' expr ':' expr ')' stmt  { $$ = new xpl::sweep_less_node(LINE, $4, $6, $8, $10); }         
     ;
     
elsif: '(' expr ')' stmt %prec tIFX         { $$ = new xpl::if_node(LINE, $2, $4); }
     | '(' expr ')' stmt tELSE stmt         { $$ = new xpl::if_else_node(LINE, $2, $4, $6); }
     | '(' expr ')' stmt tELSIF elsif       { $$ = new xpl::if_else_node(LINE, $2, $4, $6); }
     ;


expr : literal                   { $$ = $1; }
     | tNULL                     { $$ = new xpl::null_node(LINE); }
     | '+' expr %prec tUNARY     { $$ = new xpl::identity_node(LINE, $2); }
     | '-' expr %prec tUNARY     { $$ = new cdk::neg_node(LINE, $2); }
     | '~' expr %prec tUNARY     { $$ = new cdk::not_node(LINE, $2); }
     | expr '+' expr	         { $$ = new cdk::add_node(LINE, $1, $3); }
     | expr '-' expr	         { $$ = new cdk::sub_node(LINE, $1, $3); }
     | expr '*' expr	         { $$ = new cdk::mul_node(LINE, $1, $3); }
     | expr '/' expr	         { $$ = new cdk::div_node(LINE, $1, $3); }
     | expr '%' expr	         { $$ = new cdk::mod_node(LINE, $1, $3); }
     | expr '<' expr	         { $$ = new cdk::lt_node(LINE, $1, $3); }
     | expr '>' expr	         { $$ = new cdk::gt_node(LINE, $1, $3); }
     | expr tGE expr	         { $$ = new cdk::ge_node(LINE, $1, $3); }
     | expr tLE expr             { $$ = new cdk::le_node(LINE, $1, $3); }
     | expr tNE expr	         { $$ = new cdk::ne_node(LINE, $1, $3); }
     | expr tEQ expr	         { $$ = new cdk::eq_node(LINE, $1, $3); }
     | expr tAND expr	         { $$ = new cdk::and_node(LINE, $1, $3); }
     | expr tOR expr	         { $$ = new cdk::or_node(LINE, $1, $3); }
     | '(' expr ')'              { $$ = $2; }
     | tREAD                     { $$ = new xpl::read_node(LINE); }
     | lval                      { $$ = new cdk::rvalue_node(LINE, $1); }
     | lval '=' expr             { $$ = new cdk::assignment_node(LINE, $1, $3); }
     | lval '?'                  { $$ = new xpl::adress_of_node(LINE, $1); }
     | tIDENTIFIER '(' argscall ')'  { $$ = new xpl::function_call_node(LINE, $1, $3); }
     ;

literal : tINTEGER                  { $$ = new cdk::integer_node(LINE, $1); }
        | tDOUBLE                   { $$ = new cdk::double_node(LINE, $1); }
        | string %prec tSTRINGX     { $$ = new cdk::string_node(LINE, $1); }
        ;

string : string tSTRING {$$ = &($1->append(*$2)); }
       | tSTRING     {$$ = $1; }
       ;
       
argscall :                     { $$ = new cdk::sequence_node(LINE, nullptr); }
         | calls               { $$ = $1; }
         ;
         
calls : expr                   { $$ = new cdk::sequence_node(LINE, $1); }         
      | calls ',' expr   { $$ = new cdk::sequence_node(LINE, $3, $1); }
      ;


lval : tIDENTIFIER             { $$ = new cdk::identifier_node(LINE, $1); }
     | expr '[' expr ']'      { $$ = new xpl::index_node(LINE, $1, $3); }
     ;

%%