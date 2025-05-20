//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_SIZE 100

typedef struct {
  char *text;
  int length;
} Token;

typedef struct {
  Token tokens[MAX_TOKENS];
  int num_tokens;
} TokenList;

TokenList *tokenize(char *input) {
  TokenList *tokens = malloc(sizeof(TokenList));
  tokens->num_tokens = 0;

  char *token_start = input;
  while (*input != '\0') {
    if (*input == ' ' || *input == '\t' || *input == '\n') {
      if (token_start != input) {
        Token token;
        token.text = malloc(input - token_start + 1);
        strncpy(token.text, token_start, input - token_start);
        token.text[input - token_start] = '\0';
        token.length = input - token_start;
        tokens->tokens[tokens->num_tokens++] = token;
      }
      token_start = input + 1;
    }
    input++;
  }

  if (token_start != input) {
    Token token;
    token.text = malloc(input - token_start + 1);
    strncpy(token.text, token_start, input - token_start);
    token.text[input - token_start] = '\0';
    token.length = input - token_start;
    tokens->tokens[tokens->num_tokens++] = token;
  }

  return tokens;
}

void print_tokens(TokenList *tokens) {
  for (int i = 0; i < tokens->num_tokens; i++) {
    printf("%s\n", tokens->tokens[i].text);
  }
}

int main() {
  char *input = "int main() { printf(\"Hello, world!\n\"); }";

  TokenList *tokens = tokenize(input);
  print_tokens(tokens);

  for (int i = 0; i < tokens->num_tokens; i++) {
    free(tokens->tokens[i].text);
  }
  free(tokens);

  return 0;
}