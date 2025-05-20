//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
  char *name;
  struct Token *next;
} Token;

Token *createToken(char *name) {
  Token *token = malloc(sizeof(Token));
  token->name = strdup(name);
  token->next = NULL;
  return token;
}

void freeToken(Token *token) {
  free(token->name);
  free(token);
}

void extractMetadata(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    return;
  }

  char line[MAX_TOKENS];
  Token *head = NULL;

  while (fgets(line, MAX_TOKENS, fp) != NULL) {
    char *key = strstr(line, ":");
    char *value = key ? strchr(key, ":") + 1 : "";

    Token *token = createToken(key);
    token->next = head;
    head = token;
  }

  fclose(fp);

  // Print tokens
  for (Token *token = head; token; token = token->next) {
    printf("%s: %s\n", token->name, token->name);
  }
}

int main() {
  extractMetadata("my_file.txt");
  return 0;
}