//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Syntax_Node {
  char *lexeme;
  struct Syntax_Node *next;
} Syntax_Node;

Syntax_Node *parse_syntax(char *sentence) {
  Syntax_Node *head = NULL;
  Syntax_Node *tail = NULL;
  char *token = NULL;

  // Break the sentence into tokens
  token = strtok(sentence, " ");

  // Traverse the tokens and create syntax nodes
  while (token) {
    Syntax_Node *node = malloc(sizeof(Syntax_Node));
    node->lexeme = strdup(token);
    node->next = NULL;

    if (head == NULL) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }

    token = strtok(NULL, " ");
  }

  return head;
}

int main() {
  char *sentence = "The quick brown fox jumps over the lazy dog.";
  Syntax_Node *head = parse_syntax(sentence);

  // Print the syntax nodes
  Syntax_Node *node = head;
  while (node) {
    printf("%s ", node->lexeme);
    node = node->next;
  }

  return 0;
}