//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOKENS 10

typedef struct Token {
  char* lexeme;
  int type;
} Token;

Token** parse_c_syntax(char* source) {
  char** tokens = malloc(MAX_TOKENS * sizeof(char*));
  int token_count = 0;

  // Lexical analysis
  char* p = source;
  while (*p) {
    // Identifier
    if (*p >= 'a' && *p <= 'z') {
      tokens[token_count++] = strdup(p);
    }

    // Operator
    else if (*p >= 'a' && *p <= 'z') {
      tokens[token_count++] = strdup(p);
    }

    // Parentheses
    else if (*p == '(' || *p == ')') {
      tokens[token_count++] = strdup(p);
    }

    // Comments
    else if (*p == '/') {
      // Skip comment
    }

    p++;
  }

  return tokens;
}

int main() {
  char* source = "int main() { return 0; }";
  Token** tokens = parse_c_syntax(source);

  for (int i = 0; tokens[i] != NULL; i++) {
    printf("%s\n", tokens[i]->lexeme);
  }

  free(tokens);
  return 0;
}