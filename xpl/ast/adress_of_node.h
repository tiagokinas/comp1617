
#ifndef __XPL_ADRESSOFNODE_H__
#define __XPL_ADRESSOFNODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/unary_expression_node.h>

namespace xpl {

  /**
   * Class for describing return-cycle nodes.
   */
  class adress_of_node: public cdk::unary_expression_node {
      
    expression_node *_pos;
      
  public:
      
    inline adress_of_node(int lineno, expression_node *pos) :
        unary_expression_node(lineno,pos) {
    }
    
    inline expression_node *pos() {
      return _pos;
    }
    
    
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_adress_of_node(this, level);
    }

  };

} // xpl

#endif 
