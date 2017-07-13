#ifndef __XPL_FUNCTIONDECLARATIONNODE_H__
#define __XPL_FUNCTIONDECLARATIONNODE_H__ 

#include <cdk/ast/basic_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/basic_type.h>

namespace xpl {

  
  class function_declaration_node: public cdk::basic_node {
    
      basic_type *_type;
      std::string *_name;
      cdk::sequence_node *_input;
      bool _isUse;
      bool _isPublic;
      bool _isProcedure;
      
      

  public:
      
    inline function_declaration_node(int lineno, basic_type *type,std::string *name, cdk::sequence_node *input, bool isUse, bool isPublic, bool isProcedure) :
        cdk::basic_node(lineno), _type(type), _name(name), _input(input), _isUse(isUse), _isPublic(isPublic), _isProcedure(isProcedure) {
    }

  public:
   
    inline basic_type *type() {
        return _type;
    }
    
    inline std::string *name() {
        return _name;
    }
    
    
    inline cdk::sequence_node *input() {
      return _input;
    }
    
    inline bool isUse(){
        return _isUse;
    }
    
    inline bool isPublic(){
        return _isPublic;
    }

    inline bool isProcedure(){
        return _isProcedure;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_declaration_node(this, level);
    }

  };

} // xpl

#endif
 
