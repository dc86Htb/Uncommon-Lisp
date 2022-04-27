#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
#include <editline/history.h>

int main(int argc, char** argv) {

  puts("Unlisp Version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");
  
  while(1) {

    /* char* input = readline("Unlisp>>> "); */

    /* add_history(input); */
	char a;
	printf(">>>");
	scanf("%c",&a);

	printf("your name in ascii is %d \n",a);

	/* free(input); */

  }

  return 0;
}
