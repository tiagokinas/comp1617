
#ifndef __XPL_STOPNODE_H__
#define __XPL_STOPNODE_H__

#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing stop-cycle nodes.
   */
  class stop_node: public cdk::basic_node {

  public:
    inline stop_node(int lineno) :
        basic_node(lineno){
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_stop_node(this, level);
    }

  };

} // xpl

#endif
