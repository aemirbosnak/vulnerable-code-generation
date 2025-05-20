//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1024

void parse_c_code(const char *src) {
  char buffer[MAX_LEN];
  char *token = buffer;
  char *next;
  int i = 0;

  // Tokenize the input code
  while ((next = strchr(src, ' '))) {
    *next = '\0';
    token = buffer + i;
    i += strlen(token) + 1;
    src = next + 1;
  }
  token = buffer + i;

  // Parse the tokens
  if (strcmp(token, "int") == 0) {
    printf("INT\n");
  } else if (strcmp(token, "main") == 0) {
    printf("MAIN\n");
  } else if (strcmp(token, "void") == 0) {
    printf("VOID\n");
  } else if (strcmp(token, "if") == 0) {
    printf("IF\n");
  } else if (strcmp(token, "else") == 0) {
    printf("ELSE\n");
  } else if (strcmp(token, "for") == 0) {
    printf("FOR\n");
  } else if (strcmp(token, "while") == 0) {
    printf("WHILE\n");
  } else if (strcmp(token, "switch") == 0) {
    printf("SWITCH\n");
  } else if (strcmp(token, "break") == 0) {
    printf("BREAK\n");
  } else if (strcmp(token, "continue") == 0) {
    printf("CONTINUE\n");
  } else if (strcmp(token, "return") == 0) {
    printf("RETURN\n");
  } else if (strcmp(token, "char") == 0) {
    printf("CHAR\n");
  } else if (strcmp(token, "int") == 0) {
    printf("INT\n");
  } else if (strcmp(token, "float") == 0) {
    printf("FLOAT\n");
  } else if (strcmp(token, "double") == 0) {
    printf("DOUBLE\n");
  } else if (strcmp(token, "void") == 0) {
    printf("VOID\n");
  } else {
    printf("UNKNOWN_KEYWORD\n");
  }
}

int main() {
  parse_c_code("int main() { printf(\"Hello, World!\"); return 0; }");
  return 0;
}