//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 1024

typedef struct Token {
  char *name;
  char *value;
  struct Token *next;
} Token;

Token *parse_metadata(char *data) {
  Token *head = NULL;
  char *token_start = data;
  char *token_end;
  char *key_start;
  char *key_end;
  char *value_start;
  char *value_end;

  while (token_start) {
    token_end = strchr(token_start, ':');
    key_start = token_start;
    key_end = strchr(key_start, ',');
    value_start = token_end + 1;
    value_end = strchr(value_start, ',');

    if (key_start && key_end && value_start) {
      Token *new_token = malloc(sizeof(Token));
      new_token->name = strdup(key_start);
      new_token->value = strdup(value_start);
      new_token->next = head;
      head = new_token;
    }

    token_start = strchr(token_end, ':');
  }

  return head;
}

int main() {
  char data[] = "key1: value1, key2: value2, key3: value3";
  Token *tokens = parse_metadata(data);

  for (Token *token = tokens; token; token = token->next) {
    printf("%s: %s\n", token->name, token->value);
  }

  return 0;
}