#include <stdio.h>
#include "mpc.h"
#include <stdlib.h>
#include <string.h>
#include <editline/readline.h>
#include <editline/history.h>
int main(int argc, char** argv) {
  puts("unlisp Version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");
  /* Create Some Parsers */
  mpc_parser_t* Number = mpc_new("number");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expr = mpc_new("expr");
  mpc_parser_t* unlisp = mpc_new("unlisp");
/* Define them with the following Language */
  mpca_lang(MPCA_LANG_DEFAULT,
  "                                                     \
    number   : /-?[0-9]+/ ;                             \
    operator : '+' | '-' | '*' | '/' ;                  \
    expr     : <number> | '(' <operator> <expr>+ ')' ;  \
    unlisp    : /^/ <operator> <expr>+ /$/ ;             \
  ",
  Number, Operator, Expr, unlisp);

  while(1) {
    char* input = readline("unlisp> ");
 	add_history(input);
		/* Attempt to Parse the user Input */
		mpc_result_t r;
		if (mpc_parse("<stdin>", input, unlisp, &r)) {
		/* On Success Print the AST */
		mpc_ast_print(r.output);
		mpc_ast_delete(r.output);
}		else {
		/* Otherwise Print the Error */
		mpc_err_print(r.error);
		mpc_err_delete(r.error);
}
	free(input);
  }
  return 0;
}

