//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 1024

typedef struct Token {
  char *name;
  char *value;
  struct Token *next;
} Token;

Token *parse_metadata(char *metadata) {
  Token *head = NULL;
  char *token_start = metadata;
  char *token_end;

  while (token_start) {
    token_end = strchr(token_start, ':');
    char *token_name = malloc(token_end - token_start);
    memcpy(token_name, token_start, token_end - token_start);

    token_start = token_end + 1;
    token_end = strchr(token_start, ';');
    char *token_value = malloc(token_end - token_start);
    memcpy(token_value, token_start, token_end - token_start);

    Token *new_token = malloc(sizeof(Token));
    new_token->name = token_name;
    new_token->value = token_value;
    new_token->next = head;
    head = new_token;
  }

  return head;
}

int main() {
  char *metadata = "name: John Doe\n"
    "age: 30\n"
    "occupation: Software Engineer\n";

  Token *head = parse_metadata(metadata);

  while (head) {
    printf("Name: %s, Value: %s\n", head->name, head->value);
    head = head->next;
  }

  return 0;
}