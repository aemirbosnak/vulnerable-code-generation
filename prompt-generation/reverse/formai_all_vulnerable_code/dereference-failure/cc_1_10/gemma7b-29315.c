//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
  char *name;
  int value;
  struct Token *next;
} Token;

Token *tokenize(char *str) {
  char *p = str;
  Token *head = NULL;
  Token *tail = NULL;

  while (p) {
    char *token = strchr(p, '=');
    if (token) {
      *token = '\0';
      Token *newToken = malloc(sizeof(Token));
      newToken->name = strdup(p);
      newToken->value = atoi(token + 1);
      newToken->next = NULL;

      if (head) {
        tail->next = newToken;
        tail = newToken;
      } else {
        head = tail = newToken;
      }
    } else {
      break;
    }

    p = token + 1;
  }

  return head;
}

int main() {
  char *str = "foo = 10, bar = 20, baz = 30";
  Token *tokens = tokenize(str);

  for (Token *token = tokens; token; token = token->next) {
    printf("%s = %d\n", token->name, token->value);
  }

  return 0;
}