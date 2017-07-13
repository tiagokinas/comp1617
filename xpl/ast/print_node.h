// $Id: print_node.h,v 1.5 2017/03/24 15:40:51 ist168199 Exp $ -*- c++ -*-
#ifndef __XPL_PRINTNODE_H__
#define __XPL_PRINTNODE_H__

#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing print nodes.
   */
  class print_node: public cdk::basic_node {
    cdk::expression_node *_argument;
    bool _ln;

  public:
    inline print_node(int lineno, cdk::expression_node *argument, bool ln = false) :
        cdk::basic_node(lineno), _argument(argument), _ln(ln) {
    }

  public:
    inline cdk::expression_node *argument() {
      return _argument;
    }
    
    inline bool ln(){
        return _ln;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_print_node(this, level);
    }

  };

} // xpl

#endif
