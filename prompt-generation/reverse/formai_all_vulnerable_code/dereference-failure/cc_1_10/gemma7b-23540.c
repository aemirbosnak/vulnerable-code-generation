//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int item_id;
  char item_name[20];
  int quantity;
  struct Node* next;
};

typedef struct Node Node;

void insert_at_tail(Node** head, int item_id, char item_name[], int quantity) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->item_id = item_id;
  strcpy(newNode->item_name, item_name);
  newNode->quantity = quantity;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void search_item(Node* head, int item_id) {
  while (head) {
    if (head->item_id == item_id) {
      printf("Item name: %s, Quantity: %d\n", head->item_name, head->quantity);
      break;
    } else {
      head = head->next;
    }
  }

  if (head == NULL) {
    printf("Item not found.\n");
  }
}

int main() {
  Node* head = NULL;

  insert_at_tail(&head, 1, "Apple", 10);
  insert_at_tail(&head, 2, "Banana", 15);
  insert_at_tail(&head, 3, "Orange", 20);

  search_item(head, 2);

  return 0;
}