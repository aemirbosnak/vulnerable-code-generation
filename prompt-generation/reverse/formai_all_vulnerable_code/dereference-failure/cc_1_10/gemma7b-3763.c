//Gemma-7B DATASET v1.0 Category: Sorting ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
  char data;
  struct Node* next;
} Node;

void insert(Node* head, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
}

void sort(Node* head) {
  // Bubble sort algorithm
  for (int i = 0; i < MAX_SIZE - 1; i++) {
    for (int j = 0; j < MAX_SIZE - i - 1; j++) {
      Node* current = head;
      Node* next = current->next;

      if (current->data > next->data) {
        char temp = current->data;
        current->data = next->data;
        next->data = temp;
      }
    }
  }
}

int main() {
  Node* head = NULL;

  insert(head, 'a');
  insert(head, 'c');
  insert(head, 'e');
  insert(head, 'b');
  insert(head, 'd');

  sort(head);

  Node* current = head;
  while (current) {
    printf("%c ", current->data);
    current = current->next;
  }

  printf("\n");

  return 0;
}