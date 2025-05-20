//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
  char *name;
  struct Token *next;
} Token;

Token *tokenize(char *str) {
  Token *head = NULL;
  char *p = str;
  char **tokens = NULL;
  int n = 0;

  while (*p) {
    tokens = realloc(tokens, (n + 1) * sizeof(char *));
    tokens[n++] = p;

    while (*p && !isalnum(*p)) {
      p++;
    }

    if (head == NULL) {
      head = malloc(sizeof(Token));
      head->name = strdup(tokens[0]);
      head->next = NULL;
    } else {
      Token *tail = malloc(sizeof(Token));
      tail->name = strdup(tokens[0]);
      tail->next = NULL;
      head->next = tail;
      head = tail;
    }
  }

  free(tokens);
  return head;
}

int main() {
  char str[] = "This is a string with some metadata, including a key-value pair: foo=bar, and a list of items: apple, banana, orange.";
  Token *tokens = tokenize(str);

  for (Token *token = tokens; token; token = token->next) {
    printf("Token: %s\n", token->name);
  }

  free(tokens);
  return 0;
}