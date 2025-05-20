//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

Node* parse_c_syntax(char* str) {
  Node* head = NULL;
  Node* tail = NULL;
  int i = 0;

  while (str[i] != '\0') {
    char token = str[i];

    if (token == '{' || token == '}' || token == '(' || token == ')') {
      Node* newNode = malloc(sizeof(Node));
      newNode->data = token;
      newNode->next = NULL;

      if (head == NULL) {
        head = newNode;
        tail = newNode;
      } else {
        tail->next = newNode;
        tail = newNode;
      }
    }

    i++;
  }

  return head;
}

int main() {
  char str[] = "int main() { return 0; }";
  Node* head = parse_c_syntax(str);

  printf("Parsed syntax:");
  for (Node* node = head; node; node = node->next) {
    printf("%c ", node->data);
  }

  printf("\n");

  return 0;
}