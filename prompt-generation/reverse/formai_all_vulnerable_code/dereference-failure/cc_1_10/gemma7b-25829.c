//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
  int item_id;
  struct Node* next;
} Node;

Node* insert_at_tail(Node* head, int item_id) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->item_id = item_id;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
  } else {
    head->next = new_node;
  }

  return head;
}

int search(Node* head, int item_id) {
  while (head) {
    if (head->item_id == item_id) {
      return 1;
    } else {
      head = head->next;
    }
  }

  return 0;
}

int main() {
  Node* head = NULL;
  head = insert_at_tail(head, 10);
  head = insert_at_tail(head, 20);
  head = insert_at_tail(head, 30);
  head = insert_at_tail(head, 40);

  if (search(head, 20) == 1) {
    printf("Item found.\n");
  } else {
    printf("Item not found.\n");
  }

  return 0;
}