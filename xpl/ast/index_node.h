 
#ifndef __XPL_INDEXNODE_H__
#define __XPL_INDEXNODE_H__ 

#include <cdk/ast/basic_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>

namespace xpl {

  
  class index_node: public cdk::lvalue_node {
    
      cdk::expression_node *_base;
      cdk::expression_node *_offset;

  public:
      
    inline index_node(int lineno, cdk::expression_node *base,cdk::expression_node *offset) :
            lvalue_node(lineno), _base(base), _offset(offset) {
    }

  public:
    
    inline cdk::expression_node *base() {
      return _base;
    }
      
    inline cdk::expression_node *offset() {
      return _offset;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_index_node(this, level);
    }

  };

} // xpl

#endif
