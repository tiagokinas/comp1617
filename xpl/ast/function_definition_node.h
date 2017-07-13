#ifndef __XPL_FUNCTIONDEFINITIONNODE_H__
#define __XPL_FUNCTIONDEFINITIONNODE_H__ 

#include <cdk/ast/basic_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/basic_type.h>

#include "ast/function_declaration_node.h"
#include "ast/block_node.h"

namespace xpl {

  
  class function_definition_node: public function_declaration_node {
    
      block_node *_body;
      cdk::expression_node *_returnV;
      
      

  public:
      
    inline function_definition_node(int lineno, basic_type *type,std::string *name, cdk::sequence_node *input, bool isUse, bool isPublic, bool isProcedure, block_node *body, cdk::expression_node *returnV) :
        function_declaration_node(lineno,type,name,input,isUse,isPublic,isProcedure),_body(body),_returnV(returnV) {
    }

  public:
   
    inline block_node *body() {
        return _body;
    }
    
    inline cdk::expression_node *returnV() {
        return _returnV;
    }


    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_definition_node(this, level);
    }

  };

} // xpl

#endif
 

