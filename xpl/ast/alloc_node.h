
#ifndef __XPL_ALLOCNODE_H__
#define __XPL_ALLOCNODE_H__

#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing return-cycle nodes.
   */
  class alloc_node: public cdk::expression_node {
      
    expression_node *_size;
      
  public:
      
    inline alloc_node(int lineno, expression_node *size) :
        expression_node(lineno),_size(size) {
    }
    
    inline expression_node *size() {
      return _size;
    }
    
    
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_alloc_node(this, level);
    }

  };

} // xpl

#endif 
