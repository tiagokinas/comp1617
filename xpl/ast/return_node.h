
#ifndef __XPL_RETURNNODE_H__
#define __XPL_RETURNNODE_H__

#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing return-cycle nodes.
   */
  class return_node: public cdk::basic_node {

  public:
    inline return_node(int lineno) :
        basic_node(lineno){
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_return_node(this, level);
    }

  };

} // xpl

#endif
