//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

typedef struct Token {
  char *lexeme;
  int type;
  struct Token *next;
} Token;

void yy_scan(char **input);

int main() {
  char **input = malloc(10 * sizeof(char *));
  input[0] = "yy_scan(\"abc\");";
  input[1] = "int main() {};";
  input[2] = "return 0;";

  yy_scan(input);

  return 0;
}

void yy_scan(char **input) {
  Token *head = NULL;
  Token *curr = NULL;

  for (int i = 0; input[i] != NULL; i++) {
    char *lexeme = malloc(10 * sizeof(char));
    lexeme = strcpy(lexeme, input[i]);

    Token *token = malloc(sizeof(Token));
    token->lexeme = lexeme;
    token->type = 0;
    token->next = NULL;

    if (head == NULL) {
      head = token;
      curr = token;
    } else {
      curr->next = token;
      curr = token;
    }
  }

  // Print the tokens
  Token *token = head;
  while (token) {
    printf("%s (%d)\n", token->lexeme, token->type);
    token = token->next;
  }
}