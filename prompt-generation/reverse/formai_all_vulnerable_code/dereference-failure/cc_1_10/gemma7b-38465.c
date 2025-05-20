//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOKENS 1024

typedef struct Token {
  char *lexeme;
  int lineNumber;
  struct Token *next;
} Token;

Token *tokenize(char *source) {
  Token *head = NULL;
  char *p = source;
  int i = 0;

  while (p && i < MAX_TOKENS) {
    char *token = malloc(256);
    int tokenLen = 0;

    // Skip whitespace
    while (*p == ' ' || *p == '\t' || *p == '\n') {
      p++;
    }

    // Identify token
    while (*p && !isspace(*p) && tokenLen < 255) {
      token[tokenLen++] = *p;
      p++;
    }

    token[tokenLen] = '\0';

    Token *newToken = malloc(sizeof(Token));
    newToken->lexeme = token;
    newToken->lineNumber = i;
    newToken->next = head;
    head = newToken;

    i++;
  }

  return head;
}

int main() {
  char *source = "int main() { return 0; }";
  Token *tokens = tokenize(source);

  for (Token *token = tokens; token; token = token->next) {
    printf("L%d: %s\n", token->lineNumber, token->lexeme);
  }

  return 0;
}