//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_SIZE 1024

typedef struct {
  char *token;
  int length;
} Token;

typedef struct {
  Token *tokens;
  int num_tokens;
} TokenList;

TokenList *tokenize(char *input) {
  TokenList *tokens = malloc(sizeof(TokenList));
  int num_tokens = 0;
  int start = 0;
  int end = 0;
  while (input[end] != '\0') {
    if (input[end] == ' ' || input[end] == '\t' || input[end] == '\n' || input[end] == ',') {
      if (end > start) {
        Token token;
        token.token = malloc(sizeof(char) * (end - start + 1));
        memcpy(token.token, input + start, end - start);
        token.token[end - start] = '\0';
        token.length = end - start;
        num_tokens++;
      }
      start = end + 1;
    }
    end++;
  }
  if (end > start) {
    Token token;
    token.token = malloc(sizeof(char) * (end - start + 1));
    memcpy(token.token, input + start, end - start);
    token.token[end - start] = '\0';
    token.length = end - start;
    num_tokens++;
  }
  tokens->tokens = malloc(sizeof(Token) * num_tokens);
  tokens->num_tokens = num_tokens;
  int i;
  for (i = 0; i < num_tokens; i++) {
    tokens->tokens[i] = *(tokens->tokens + i);
  }
  return tokens;
}

int main() {
  char *input = "{\"name\":\"John Doe\",\"age\":30,\"city\":\"New York\"}";
  TokenList *tokens = tokenize(input);
  int i;
  for (i = 0; i < tokens->num_tokens; i++) {
    printf("%s\n", tokens->tokens[i].token);
  }
  return 0;
}