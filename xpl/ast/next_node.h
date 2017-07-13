
#ifndef __XPL_NEXTNODE_H__
#define __XPL_NEXTNODE_H__

#include <cdk/ast/basic_node.h>
#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing next-cycle nodes.
   */
  class next_node: public cdk::basic_node {

  public:
    inline next_node(int lineno) :
        basic_node(lineno){
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_next_node(this, level);
    }

  };

} // xpl

#endif
