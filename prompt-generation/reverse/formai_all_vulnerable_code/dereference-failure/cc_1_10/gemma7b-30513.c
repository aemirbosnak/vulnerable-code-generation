//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data;
  struct Node* next;
} Node;

void parse_syntax(char* str) {
  Node* head = NULL;
  Node* tail = NULL;

  // Lexical analysis
  char* ptr = str;
  while (*ptr) {
    // Identifier
    if (*ptr >= 'a' && *ptr <= 'z') {
      Node* newNode = malloc(sizeof(Node));
      newNode->data = *ptr;
      newNode->next = NULL;

      if (head == NULL) {
        head = tail = newNode;
      } else {
        tail->next = newNode;
        tail = newNode;
      }
    }

    // Operator
    else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') {
      Node* newNode = malloc(sizeof(Node));
      newNode->data = *ptr;
      newNode->next = NULL;

      tail->next = newNode;
      tail = newNode;
    }

    ptr++;
  }

  // Syntax tree construction
  // (Left as an exercise)

  // Free memory
  free(head);
}

int main() {
  char str[] = "identifier + operator identifier * operator";
  parse_syntax(str);

  return 0;
}