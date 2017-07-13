 
#ifndef __XPL_VARIABLEINITIALIZATIONNODE_H__
#define __XPL_VARIABLEINITIALIZATIONNODE_H__ 

#include <cdk/ast/expression_node.h>
#include <cdk/ast/basic_node.h>

namespace xpl {

  
  class variable_initialization_node: public cdk::basic_node {
    
      basic_type *_varType;
      std::string *_varName;
      cdk::expression_node *_value;
      bool _isUse;
      bool _isPublic;
      
      

  public:
      
    inline variable_initialization_node(int lineno, basic_type *varType,std::string *varName,cdk::expression_node *value, bool isUse, bool isPublic) :
        cdk::basic_node(lineno), _varType(varType), _varName(varName),_value(value), _isUse(isUse), _isPublic(isPublic){
    }

  public:
   
    inline basic_type *varType() {
        return _varType;
    }
    
    inline std::string *varName() {
        return _varName;
    }
    
    inline cdk::expression_node *value() {
        return _value;
    }
    
    
    inline bool isUse(){
        return _isUse;
    }
    
    inline bool isPublic(){
        return _isPublic;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_initialization_node(this, level);
    }

  };

} // xpl

#endif
 
