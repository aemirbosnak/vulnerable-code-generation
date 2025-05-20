//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to parse a C statement and print its type
void parse_stmt(char *stmt) {
  // Tokenize the statement into individual words
  char *words[10];
  int i = 0;
  while (stmt[i] != '\0') {
    words[i] = stmt + i;
    if (isspace(stmt[i])) {
      i++;
    } else {
      break;
    }
  }

  // Print the type of the statement
  if (strcmp(words[0], "if") == 0) {
    printf("IF\n");
  } else if (strcmp(words[0], "while") == 0) {
    printf("WHILE\n");
  } else if (strcmp(words[0], "for") == 0) {
    printf("FOR\n");
  } else if (strcmp(words[0], "switch") == 0) {
    printf("SWITCH\n");
  } else if (strcmp(words[0], "case") == 0) {
    printf("CASE\n");
  } else if (strcmp(words[0], "break") == 0) {
    printf("BREAK\n");
  } else if (strcmp(words[0], "continue") == 0) {
    printf("CONTINUE\n");
  } else if (strcmp(words[0], "return") == 0) {
    printf("RETURN\n");
  } else if (strcmp(words[0], "int") == 0) {
    printf("INT\n");
  } else if (strcmp(words[0], "float") == 0) {
    printf("FLOAT\n");
  } else if (strcmp(words[0], "double") == 0) {
    printf("DOUBLE\n");
  } else if (strcmp(words[0], "char") == 0) {
    printf("CHAR\n");
  } else if (strcmp(words[0], "void") == 0) {
    printf("VOID\n");
  } else {
    printf("UNKNOWN\n");
  }

  // Free the memory allocated for the words array
  for (int j = 0; j < i; j++) {
    free(words[j]);
  }
  free(words);
}

int main() {
  // Parse a series of C statements
  char *stmt1 = "if (x > 0) { print(\"x is positive\"); }";
  char *stmt2 = "while (x > 0) { print(\"x is positive\"); }";
  char *stmt3 = "for (int i = 0; i < 10; i++) { print(\"i is less than 10\"); }";
  char *stmt4 = "switch (x) { case 0: print(\"x is zero\"); break; case 1: print(\"x is one\"); break; }";
  char *stmt5 = "if (x > 0) { return 1; }";

  parse_stmt(stmt1);
  parse_stmt(stmt2);
  parse_stmt(stmt3);
  parse_stmt(stmt4);
  parse_stmt(stmt5);

  return 0;
}