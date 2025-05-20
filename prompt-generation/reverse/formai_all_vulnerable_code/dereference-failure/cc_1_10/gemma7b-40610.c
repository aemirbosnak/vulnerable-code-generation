//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char data;
  struct Node* next;
};

typedef struct Node Node;

Node* parse_syntax(char* str) {
  Node* head = NULL;
  Node* tail = NULL;
  char* ptr = str;

  while (*ptr) {
    switch (*ptr) {
      case '(':
        ptr++;
        Node* newNode = malloc(sizeof(Node));
        newNode->data = '(';
        newNode->next = NULL;
        if (head == NULL) {
          head = newNode;
          tail = newNode;
        } else {
          tail->next = newNode;
          tail = newNode;
        }
        break;
      case ')':
        ptr++;
        tail->next = NULL;
        break;
      default:
        ptr++;
    }
  }

  return head;
}

int main() {
  char* str = "((()))";
  Node* head = parse_syntax(str);

  while (head) {
    printf("%c ", head->data);
    head = head->next;
  }

  return 0;
}