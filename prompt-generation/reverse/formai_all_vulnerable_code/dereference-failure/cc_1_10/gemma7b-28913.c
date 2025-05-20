//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
  char *name;
  char *value;
  struct Token *next;
} Token;

Token *extract_metadata(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char line[MAX_TOKENS];
  Token *head = NULL;

  while (fgets(line, MAX_TOKENS, fp) != NULL) {
    char *key = strchr(line, ':');
    if (key) {
      char *value = strchr(key, ';');
      if (value) {
        value = malloc(strlen(value) + 1);
        memcpy(value, key + 1, value - key - 1);
        value[value - key - 1] = '\0';

        Token *new_token = malloc(sizeof(Token));
        new_token->name = malloc(strlen(key) + 1);
        memcpy(new_token->name, key, strlen(key) + 1);
        new_token->value = value;
        new_token->next = head;
        head = new_token;
      }
    }
  }

  fclose(fp);
  return head;
}

int main() {
  Token *tokens = extract_metadata("example.txt");

  for (Token *token = tokens; token; token = token->next) {
    printf("%s: %s\n", token->name, token->value);
  }

  return 0;
}