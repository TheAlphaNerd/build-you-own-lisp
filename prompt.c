#include <stdio.h>
#include<stdlib.h>

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

//  Fake readline
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer) + 1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy) - 1] = [\0];
  return cpy;
}

// fake add_history
void add_history(char* unused) {}

#else
#include <editline/readline.h>
#endif

int main(int argc, char** argv) {

  /* Print Version and Exit Information */
  puts("Lispy Version 0.0.0.0.2");
  puts("Press Ctrl+c to Exit\n");

  /* In a never ending loop */
  while (1) {

    char * input = readline("> ");
    add_history(input);

    /* Echo input back to user */
    printf("~> %s <~\n", input);
    free(input);
  }

  return 0;
}