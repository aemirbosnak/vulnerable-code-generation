//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 10

typedef struct Token {
  char *name;
  struct Token *next;
} Token;

Token *parse_resume(char *resume_text) {
  // Tokenize the resume text
  char **tokens = NULL;
  int num_tokens = 0;
  char *token = strtok(resume_text, " ");
  while (token) {
    tokens = realloc(tokens, (num_tokens + 1) * sizeof(char *));
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Create a linked list of tokens
  Token *head = NULL;
  for (int i = 0; i < num_tokens; i++) {
    Token *new_token = malloc(sizeof(Token));
    new_token->name = strdup(tokens[i]);
    new_token->next = head;
    head = new_token;
  }

  // Free the tokens
  free(tokens);

  return head;
}

int main() {
  char *resume_text = "John Doe\n123 Main St.\nNew York, NY 10001\n(123) 456-7890\n";
  Token *head = parse_resume(resume_text);

  // Print the tokens
  for (Token *token = head; token; token = token->next) {
    printf("%s ", token->name);
  }

  // Free the tokens
  free(head);

  return 0;
}