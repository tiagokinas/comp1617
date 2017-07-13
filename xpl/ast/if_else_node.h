// $Id: if_else_node.h,v 1.8 2017/04/19 17:07:12 ist168199 Exp $ -*- c++ -*-
#ifndef __XPL_IFELSENODE_H__
#define __XPL_IFELSENODE_H__

#include <cdk/ast/basic_node.h>
#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing if-then-else nodes.
   */
  class if_else_node: public cdk::basic_node {
    cdk::expression_node *_condition;
    cdk::basic_node *_thenblock;
    cdk::basic_node *_elseblock;

  public:
    
    inline if_else_node(int lineno, cdk::expression_node *condition, cdk::basic_node *thenblock, cdk::basic_node *elseblock) :
        basic_node(lineno), _condition(condition), _thenblock(thenblock), _elseblock(elseblock) {
    }

  public:
    inline cdk::expression_node *condition() {
      return _condition;
    }
    inline cdk::basic_node *thenblock() {
      return _thenblock;
    }


    inline cdk::basic_node *elseblock() {
      return _elseblock;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_if_else_node(this, level);
    }

  };

} // xpl

#endif
