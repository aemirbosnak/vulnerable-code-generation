//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 1024

typedef struct Token {
  char *name;
  int value;
  struct Token *next;
} Token;

Token *parse_metadata(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char line[MAX_TOKENS];
  Token *head = NULL;
  Token *tail = NULL;

  while (fgets(line, MAX_TOKENS, fp) != NULL) {
    char *key = strchr(line, ':');
    if (key) {
      char *value = key + 1;
      Token *new_token = malloc(sizeof(Token));
      new_token->name = strdup(key);
      new_token->value = atoi(value);
      new_token->next = NULL;

      if (head == NULL) {
        head = new_token;
        tail = new_token;
      } else {
        tail->next = new_token;
        tail = new_token;
      }
    }
  }

  fclose(fp);
  return head;
}

int main() {
  Token *tokens = parse_metadata("metadata.txt");
  for (Token *token = tokens; token; token = token->next) {
    printf("%s: %d\n", token->name, token->value);
  }

  return 0;
}