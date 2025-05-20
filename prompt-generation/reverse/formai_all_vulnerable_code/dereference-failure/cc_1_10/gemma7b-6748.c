//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
  char data;
  struct Node* next;
} Node;

Node* parse_c_syntax(char* source) {
  int i = 0;
  Node* head = NULL;
  Node* tail = NULL;

  while (source[i] && !isspace(source[i])) {
    char token = source[i];

    if (head == NULL) {
      head = tail = malloc(sizeof(Node));
      head->data = token;
      head->next = NULL;
    } else {
      tail->next = malloc(sizeof(Node));
      tail = tail->next;
      tail->data = token;
      tail->next = NULL;
    }

    i++;
  }

  return head;
}

int main() {
  char* source = "int main() { return 0; }";
  Node* syntax_tree = parse_c_syntax(source);

  printf("Syntax tree:\n");
  for (Node* node = syntax_tree; node; node = node->next) {
    printf("%c ", node->data);
  }

  printf("\n");

  return 0;
}