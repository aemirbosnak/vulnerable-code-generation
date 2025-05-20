//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

Node* insert_at_tail(Node* head, char data) {
  Node* new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  if (head == NULL) {
    return new_node;
  }

  head->next = new_node;
  return new_node;
}

void compress(Node* head) {
  Node* current = head;
  Node* previous = NULL;
  int count = 1;

  while (current) {
    if (previous && current->data == previous->data) {
      count++;
    } else {
      if (previous) {
        insert_at_tail(previous, count);
      }

      previous = current;
      count = 1;
    }

    current = current->next;
  }

  insert_at_tail(previous, count);

  // Print the compressed list
  current = head;
  while (current) {
    printf("%c", current->data);
    if (current->next) {
      printf(",");
    }
    current = current->next;
  }

  printf("\n");
}

int main() {
  Node* head = insert_at_tail(NULL, 'a');
  insert_at_tail(head, 'a');
  insert_at_tail(head, 'b');
  insert_at_tail(head, 'b');
  insert_at_tail(head, 'c');
  insert_at_tail(head, 'c');

  compress(head);

  return 0;
}