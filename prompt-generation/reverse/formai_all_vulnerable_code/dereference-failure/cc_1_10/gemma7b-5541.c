//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOKENS 100

typedef struct Token {
  char *name;
  struct Token *next;
} Token;

Token *insertToken(Token *head, char *name) {
  Token *newToken = malloc(sizeof(Token));
  newToken->name = strdup(name);
  newToken->next = NULL;

  if (head == NULL) {
    head = newToken;
  } else {
    head->next = insertToken(head->next, name);
  }

  return head;
}

int main() {
  Token *head = NULL;
  char **tokens = malloc(MAX_TOKENS * sizeof(char *));

  // Extract tokens from some text
  tokens[0] = "The";
  tokens[1] = "quick";
  tokens[2] = "brown";
  tokens[3] = "fox";
  tokens[4] = "jumps";
  tokens[5] = "over";
  tokens[6] = "the";
  tokens[7] = "lazy";
  tokens[8] = "dog";

  for (int i = 0; tokens[i] != NULL; i++) {
    insertToken(head, tokens[i]);
  }

  // Print the extracted tokens
  Token *current = head;
  while (current) {
    printf("%s ", current->name);
    current = current->next;
  }

  printf("\n");

  return 0;
}