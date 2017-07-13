#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "ast/all.h"  // all.h is automatically generated

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
      if(node->node(i) != nullptr)
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
if(function)
  _pf.INT(node->value()); // push an integer
else
  _pf.CONST(node->value());
}

void xpl::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  int lbl1;

  /* generate the string */
  _pf.RODATA(); // strings are DATA readonly
  _pf.ALIGN(); // make sure we are aligned
  _pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name
  _pf.STR(node->value()); // output string characters

  if(function){
  /* leave the address on the stack */
  _pf.TEXT(); // return to the TEXT segment
  _pf.ADDR(mklbl(lbl1)); // the string to be printed
  }
  else{
      _pf.DATA();
      _pf.ID(mklbl(lbl1));
  }
    
}


//---------------------------------------------------------------------------

void xpl::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  if(node->type()->name() == basic_type::TYPE_INT)
    _pf.NEG(); // 2-complement
  if(node->type()->name() == basic_type::TYPE_DOUBLE)
    _pf.DNEG();  
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  if (node->type()->name() == basic_type::TYPE_DOUBLE){
    node->left()->accept(this, lvl);
    if (node->left()->type()->name() == basic_type::TYPE_INT)
        _pf.I2D(); //conversao para double
    node->right()->accept(this, lvl);
    if (node->right()->type()->name() == basic_type::TYPE_INT)
        _pf.I2D(); //conversao para double
    _pf.DADD();
    }
  else if(node->type()->name() == basic_type::TYPE_INT || node->type()->name() == basic_type::TYPE_POINTER ){
      node->left()->accept(this,lvl);
      node->right()->accept(this,lvl);
      _pf.ADD();
  }
}
   
void xpl::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.SUB();
}
void xpl::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MUL();
}
void xpl::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.DIV();
}
void xpl::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MOD();
}
void xpl::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LT();
}
void xpl::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LE();
}
void xpl::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GE();
}
void xpl::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GT();
}
void xpl::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.NE();
}
void xpl::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.EQ();
}

void xpl::postfix_writer::do_and_node(cdk::and_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int i;

  node->left()->accept(this,lvl);
  _pf.INT(0);
  _pf.EQ();
  _pf.JNZ(mklbl(i = ++_lbl));

  node->right()->accept(this,lvl);
  _pf.INT(0);
  _pf.EQ();
  _pf.ALIGN();
  _pf.LABEL(mklbl(i));
}

void xpl::postfix_writer::do_or_node(cdk::or_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int i;

  node->left()->accept(this,lvl);
  _pf.INT(0);
  _pf.GT();
  _pf.JNZ(mklbl(i = ++_lbl));

  node->right()->accept(this,lvl);
  _pf.INT(0);
  _pf.GT();
  _pf.ALIGN();
  _pf.LABEL(mklbl(i));
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_identifier_node(cdk::identifier_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  // simplified generation: all variables are global
  _pf.ADDR(node->name());
}

void xpl::postfix_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->lvalue()->accept(this, lvl);
  _pf.LOAD(); // depends on type size
}

void xpl::postfix_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->rvalue()->accept(this, lvl); // determine the new value
  _pf.DUP();
  if (new_symbol() == nullptr) {
    node->lvalue()->accept(this, lvl); // where to store the value
  } else {
    _pf.DATA(); // variables are all global and live in DATA
    _pf.ALIGN(); // make sure we are aligned
    _pf.LABEL(new_symbol()->name()); // name variable location
    _pf.CONST(0); // initialize it to 0 (zero)
    _pf.TEXT(); // return to the TEXT segment
    node->lvalue()->accept(this, lvl);  //DAVID: bah!
  }
  _pf.STORE(); // store the value at address
}

//---------------------------------------------------------------------------

/*void xpl::postfix_writer::do_program_node(xpl::program_node * const node, int lvl) {
  // The ProgramNode (representing the whole program) is the
  // main function node.

  // generate the main function (RTS mandates that its name be "_main")
  _pf.TEXT();
  _pf.ALIGN();
  _pf.GLOBAL("_main", _pf.FUNC());
  _pf.LABEL("_main");
  _pf.ENTER(0);  // XPL doesn't implement local variables

  node->statements()->accept(this, lvl);

  // end the main function
  _pf.INT(0);
  _pf.POP();
  _pf.LEAVE();
  _pf.RET();

  // these are just a few library function imports
  _pf.EXTERN("readi");
  _pf.EXTERN("printi");
  _pf.EXTERN("prints");
  _pf.EXTERN("println");
}
*/
//---------------------------------------------------------------------------


void xpl::postfix_writer::do_function_declaration_node(xpl::function_declaration_node * const node, int lvl){
    ASSERT_SAFE_EXPRESSIONS;
    function = true;
    
    _pf.TEXT();
    _pf.ALIGN();
    _pf.LABEL(*(node->name()));
    
    std::shared_ptr<xpl::symbol> symbol = _symtab.find(*node->name());

    if(symbol==nullptr){
        symbol = std::make_shared<xpl::symbol>(node->type(), *node->name(), 0);        
        _symtab.insert(symbol->name(),  symbol);
    }
    
    function = false;
}

void xpl::postfix_writer::do_function_definition_node(xpl::function_definition_node * const node, int lvl){
   //CHECK_TYPES(_compiler, _symtab, node);  uncoment after typechecker done
  ASSERT_SAFE_EXPRESSIONS; 
  function = true;
    
  _pf.TEXT();
  _pf.ALIGN();
  
  std::string functionName = *(node->name());
  if(functionName == "xpl"){
      functionName = "_main";
      _pf.GLOBAL(functionName, _pf.FUNC());
  }

  std::shared_ptr<xpl::symbol> symbol = _symtab.find(*node->name());

  if(symbol==nullptr){
      symbol = std::make_shared<xpl::symbol>(node->type(), *node->name(), 0);        
      _symtab.insert(symbol->name(),  symbol);
  }
    
  
  _pf.LABEL(functionName);
  _pf.ENTER(0);  // XPL doesn't implement local variables

  node->body()->accept(this, lvl);

  // end the main function
  _pf.INT(0);
  _pf.POP();
  _pf.LEAVE();
  _pf.RET();

  // these are just a few library function imports
  _pf.EXTERN("readi");
  _pf.EXTERN("printi");
  _pf.EXTERN("prints");
  _pf.EXTERN("printd");
  _pf.EXTERN("println");
  
  function = false;
}

void xpl::postfix_writer::do_function_call_node(xpl::function_call_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  std::shared_ptr<xpl::symbol> symbol = _symtab.find(*node->name());

  if(symbol==nullptr){
      std::cout << "Cannot call function without defining it before." << std::endl;
      return;
  }
  else{
    node->type(symbol->type());
  }
    

  if (*(node->name()) == "xpl")
        _pf.CALL("_main");
    else _pf.CALL(*(node->name()));
}

void xpl::postfix_writer::do_variable_declaration_node(xpl::variable_declaration_node * const node, int lvl){
    ASSERT_SAFE_EXPRESSIONS;
    const std::string *id = node->varName();
    std::shared_ptr<xpl::symbol> symbol = _symtab.find(*id);
    
    
    
    if(symbol==nullptr){
        symbol = std::make_shared<xpl::symbol>(node->varType(), *node->varName(), 0);

        _symtab.insert(symbol->name(),  symbol);
    }
    
    _pf.DATA();
    _pf.ALIGN();
    _pf.LABEL(*id);
    
    symbol->value(0);
    
    switch(node->varType()->name()){
        case basic_type::TYPE_INT:
            _pf.CONST(0);
            break;
        case basic_type::TYPE_DOUBLE:
            _pf.DOUBLE(0.0);
            break;
        case basic_type::TYPE_STRING:
            _pf.STR("");
            break;
        case basic_type::TYPE_POINTER:
            symbol->value(-1);
            break;
        default:
            std::cout << "Var Type Error" << std::endl;
            break;
    }
    _pf.TEXT();
    
    
    symbol->sethasValue(false);
}
    
void xpl::postfix_writer::do_variable_initialization_node(xpl::variable_initialization_node * const node, int lvl){
    ASSERT_SAFE_EXPRESSIONS;

    const std::string *id = node->varName();
    std::shared_ptr<xpl::symbol> symbol = _symtab.find(*id);
    
    
    
    if(symbol==nullptr){
        symbol = std::make_shared<xpl::symbol>(node->varType(), *node->varName(), 0);
                
        _symtab.insert(symbol->name(),  symbol);
    }
    
    _pf.DATA();
    _pf.ALIGN();
    _pf.LABEL(*id);
    
    symbol->value(0);
    
    node->value()->accept(this, lvl+2);
    
    _pf.TEXT();
    
    
    symbol->sethasValue(false);
  
}

    
void xpl::postfix_writer::do_block_node(xpl::block_node * const node, int lvl){
    ASSERT_SAFE_EXPRESSIONS;
    if(node->declarations() != nullptr){
        node->declarations()->accept(this, lvl);
    }
    if(node->instructions() != nullptr){
        node->instructions()->accept(this, lvl);}
}

void xpl::postfix_writer::do_evaluation_node(xpl::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  if(node->argument()->type() == nullptr){

  }else if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.TRASH(4); // delete the evaluated value
  } else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.TRASH(4); // delete the evaluated value's address
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
}

void xpl::postfix_writer::do_print_node(xpl::print_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value to print
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.CALL("printi");
    _pf.TRASH(4); // delete the printed value
  }else if (node->argument()->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.CALL("printd");
    _pf.TRASH(8); // delete the printed value
  } else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.CALL("prints");
    _pf.TRASH(4); // delete the printed value's address
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
  if (node->ln()){
  _pf.CALL("println"); // print a newline
  }
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_read_node(xpl::read_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  _pf.CALL("readi");
  _pf.STORE();
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_while_node(xpl::while_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
 
  /*int lbl1, lbl2;
  int i = 0;

  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl1 = ++_lbl));


  node->condition()->accept(this, lvl);
  i++;
  if( i >= 50)
    _pf.ALIGN();
    _pf.JNZ(mklbl(lbl2 = ++_lbl));
  _pf.ALIGN();
  _pf.JZ(mklbl(lbl2 = ++_lbl));


  node->block()->accept(this, lvl + 2);
  
  _pf.JMP(mklbl(lbl1));
  _pf.LABEL(mklbl(lbl2));*/
}

void xpl::postfix_writer::do_stop_node(xpl::stop_node * const node, int lvl) {
  /*ASSERT_SAFE_EXPRESSIONS;
  _pf.JMP(mklbl(_labelStopCycle[_labelStopCycle.size()]));*/

}

void xpl::postfix_writer::do_next_node(xpl::next_node * const node, int lvl) {
  /*ASSERT_SAFE_EXPRESSIONS;
  _pf.JMP(mklbl(_labelNextCycle[_labelNextCycle.size()]));*/
}
//---------------------------------------------------------------------------

void xpl::postfix_writer::do_if_node(xpl::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1));
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_if_else_node(xpl::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1, lbl2;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl2 = ++_lbl));
  _pf.LABEL(mklbl(lbl1));
  node->elseblock()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1 = lbl2));
}

void xpl::postfix_writer::do_identity_node(xpl::identity_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  
  node->argument()->accept(this, lvl + 2);
}

void xpl::postfix_writer::do_return_node(xpl::return_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  _pf.POP();
  _pf.LEAVE();
  _pf.RET();
}

void xpl::postfix_writer::do_sweep_less_node(xpl::sweep_less_node * const node, int lvl){
    
    int lbl_cond = ++_lbl;
    int lbl_step = ++_lbl;
    int lbl_end = ++_lbl;


    // Make initial assignment
    cdk::assignment_node(node->lineno(), node->lvalue(), node->expression1()).accept(this, lvl+1);

    //xpl::print_node(node->lineno(), new cdk::rvalue_node(node->lineno(), node->lvalue()), true).accept(this, lvl+1);

    // Evaluate condition
    _pf.ALIGN();
    _pf.LABEL(mklbl(lbl_cond));

    // Make condition expression
    cdk::ge_node(node->lineno(), new cdk::rvalue_node(node->lineno(), node->lvalue()), node->expression2()).accept(this, lvl+1);
    //node->make_cond_expression()->accept(this, lvl+1);

    
    // Exit loop if condition is false
    _pf.JZ(mklbl(lbl_end));

    // Evaluate block - block is only ran if passes cond
    node->block()->accept(this, lvl+1);
            
    // Evaluate step
    _pf.ALIGN();
    _pf.LABEL(mklbl(lbl_step)); // Continue jumps here
    if(node->expression3() != nullptr){
      cdk::assignment_node(node->lineno(), node->lvalue(), 
        new cdk::sub_node(node->lineno(), new cdk::rvalue_node(node->lineno(), node->lvalue()), node->expression3())).accept(this, lvl+1);

        
    }
    else{
      cdk::assignment_node(node->lineno(), node->lvalue(), 
        new cdk::sub_node(node->lineno(), new cdk::rvalue_node(node->lineno(), node->lvalue()), new cdk::integer_node(node->lineno(), 1))).accept(this, lvl+1);
        
    }
    

    // Restart loop
    _pf.JMP(mklbl(lbl_cond));

    // Insert label after loop
    _pf.ALIGN();
    _pf.LABEL(mklbl(lbl_end)); // Break jumps here
  
}

void xpl::postfix_writer::do_sweep_plus_node(xpl::sweep_plus_node * const node, int lvl){
    
    int lbl_cond = ++_lbl;
    int lbl_step = ++_lbl;
    int lbl_end = ++_lbl;


    // Make initial assignment
    cdk::assignment_node(node->lineno(), node->lvalue(), node->expression1()).accept(this, lvl+1);
    //node->make_init_assignment()->accept(this, lvl+1);

    

    // Evaluate condition
    _pf.ALIGN();
    _pf.LABEL(mklbl(lbl_cond));

    // Make condition expression
    cdk::le_node(node->lineno(), new cdk::rvalue_node(node->lineno(), node->lvalue()), node->expression2()).accept(this, lvl+1);
    

    
    // Exit loop if condition is false
    _pf.JZ(mklbl(lbl_end));

    // Evaluate block - block is only ran if passes cond
    node->block()->accept(this, lvl+1);
            
    // Evaluate step
    _pf.ALIGN();
    _pf.LABEL(mklbl(lbl_step)); // Continue jumps here
    if(node->expression3() != nullptr){
      cdk::assignment_node(node->lineno(), node->lvalue(), 
        new cdk::add_node(node->lineno(), new cdk::rvalue_node(node->lineno(), node->lvalue()), node->expression3())).accept(this, lvl+1);


    }
    else{
      cdk::assignment_node(node->lineno(), node->lvalue(), 
        new cdk::add_node(node->lineno(), new cdk::rvalue_node(node->lineno(), node->lvalue()), new cdk::integer_node(node->lineno(), 1))).accept(this, lvl+1);
    }

    // Restart loop
    _pf.JMP(mklbl(lbl_cond));

    // Insert label after loop
    _pf.ALIGN();
    _pf.LABEL(mklbl(lbl_end)); // Break jumps here
	
}
