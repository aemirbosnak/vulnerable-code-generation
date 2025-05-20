//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Cat Language grammar
#define CAT_LANG_GRAMMAR "Expression ::= Term | Expression '+' Term | Expression '-' Term"
#define CAT_LANG_TERM "Term ::= Factor | Term '*' Factor | Term '/' Factor"
#define CAT_LANG_FACTOR "Factor ::= '(' Expression ')' | Number"
#define CAT_LANG_NUMBER "Number ::= [0-9]+"

// Define the Cat Language interpreter
int cat_lang_interpret(char *expression) {
  // Parse the expression
  int result = 0;
  char *p = expression;
  while (*p != '\0') {
    // Skip whitespace
    while (*p == ' ' || *p == '\t' || *p == '\n') {
      p++;
    }

    // Parse a factor
    int factor = 0;
    if (*p == '(') {
      // Parse a parenthesized expression
      p++;
      factor = cat_lang_interpret(p);
      if (*p != ')') {
        fprintf(stderr, "Error: missing closing parenthesis\n");
        return -1;
      }
      p++;
    } else if (*p >= '0' && *p <= '9') {
      // Parse a number
      factor = atoi(p);
      while (*p >= '0' && *p <= '9') {
        p++;
      }
    } else {
      fprintf(stderr, "Error: unexpected character '%c'\n", *p);
      return -1;
    }

    // Apply the operation
    if (*p == '+') {
      result += factor;
      p++;
    } else if (*p == '-') {
      result -= factor;
      p++;
    } else if (*p == '\0') {
      // End of expression
      return result;
    } else {
      fprintf(stderr, "Error: unexpected character '%c'\n", *p);
      return -1;
    }
  }

  return result;
}

// Define the main function
int main(int argc, char **argv) {
  // Check the command line arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <expression>\n", argv[0]);
    return -1;
  }

  // Interpret the expression
  int result = cat_lang_interpret(argv[1]);
  if (result == -1) {
    fprintf(stderr, "Error: could not interpret expression\n");
    return -1;
  }

  // Print the result
  printf("Result: %d\n", result);
  return 0;
}