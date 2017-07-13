 
#ifndef __XPL_VARIABLEDECLARATIONNODE_H__
#define __XPL_VARIABLEDECLARATIONNODE_H__ 

#include <cdk/ast/expression_node.h>
#include <cdk/ast/basic_node.h>

namespace xpl {

  
  class variable_declaration_node: public cdk::basic_node {
    
      basic_type *_varType;
      std::string *_varName;
      bool _isUse;
      bool _isPublic;
      
      

  public:
      
    inline variable_declaration_node(int lineno, basic_type *varType,std::string *varName, bool isUse, bool isPublic) :
        basic_node(lineno), _varType(varType), _varName(varName), _isUse(isUse), _isPublic(isPublic){
    }

  public:
   
    inline basic_type *varType() {
        return _varType;
    }
    
    inline std::string *varName() {
        return _varName;
    }
    
    
    inline bool isUse(){
        return _isUse;
    }
    
    inline bool isPublic(){
        return _isPublic;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_declaration_node(this, level);
    }

  };

} // xpl

#endif
 
