 
#ifndef __XPL_FUNCTIONCALLNODE_H__
#define __XPL_FUNCTIONCALLNODE_H__ 

#include <cdk/ast/basic_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/basic_type.h>

namespace xpl {

  
  class function_call_node: public cdk::expression_node {
    
      std::string *_name;
      cdk::sequence_node *_input;
      
      

  public:
      
    inline function_call_node(int lineno, std::string *name, cdk::sequence_node *input) :
        expression_node(lineno), _name(name), _input(input){
    }

  public:
   
    
    inline std::string *name() {
        return _name;
    }
    
    
    inline cdk::sequence_node *input() {
      return _input;
    }
    


    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_call_node(this, level);
    }

  };

} // xpl

#endif
 
