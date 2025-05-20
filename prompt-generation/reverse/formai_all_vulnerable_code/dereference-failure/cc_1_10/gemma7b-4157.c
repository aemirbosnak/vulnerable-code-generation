//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char data;
  struct Node* next;
} Node;

void parse_syntax(char* str) {
  Node* head = NULL;
  Node* tail = NULL;

  for (int i = 0; str[i] != '\0'; i++) {
    switch (str[i]) {
      case '(':
        tail = malloc(sizeof(Node));
        tail->data = str[i];
        tail->next = NULL;

        if (head == NULL) {
          head = tail;
        } else {
          head->next = tail;
          head = tail;
        }
        break;
      case ')':
        tail = head;
        while (tail->data != '(') {
          tail = tail->next;
        }
        free(tail);
        break;
      default:
        tail = malloc(sizeof(Node));
        tail->data = str[i];
        tail->next = NULL;

        if (head == NULL) {
          head = tail;
        } else {
          head->next = tail;
          head = tail;
        }
    }
  }

  free(head);
}

int main() {
  char* str = "((a)b)c)";
  parse_syntax(str);

  return 0;
}