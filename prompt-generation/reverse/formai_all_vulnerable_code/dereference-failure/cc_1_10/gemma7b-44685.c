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

Token *extract_metadata(char *filename) {
  FILE *fp;
  char line[MAX_TOKENS];
  Token *head = NULL;
  Token *tail = NULL;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  while (fgets(line, MAX_TOKENS, fp) != NULL) {
    char *key = strchr(line, ':');
    char *value = strchr(line, ',');

    if (key && value) {
      Token *new_token = malloc(sizeof(Token));
      new_token->name = strdup(key + 1);
      new_token->value = strdup(value);
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
  char *filename = "example.txt";
  Token *tokens = extract_metadata(filename);

  if (tokens) {
    for (Token *token = tokens; token; token = token->next) {
      printf("%s: %s\n", token->name, token->value);
    }
  } else {
    printf("Error extracting metadata.\n");
  }

  return 0;
}