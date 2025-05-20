//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

struct Node {
  char item_name[20];
  int quantity;
  struct Node* next;
};

struct Node* insert_at_tail(struct Node* head, char item_name, int quantity) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->item_name, item_name);
  newNode->quantity = quantity;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    struct Node* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  return head;
}

struct Node* search_item(struct Node* head, char item_name) {
  struct Node* temp = head;
  while (temp) {
    if (strcmp(temp->item_name, item_name) == 0) {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

void update_item_quantity(struct Node* head, char item_name, int new_quantity) {
  struct Node* item = search_item(head, item_name);
  if (item) {
    item->quantity = new_quantity;
  }
}

void delete_item(struct Node* head, char item_name) {
  struct Node* item = search_item(head, item_name);
  if (item) {
    struct Node* prev = NULL;
    struct Node* temp = head;
    while (temp) {
      if (strcmp(temp->item_name, item_name) == 0) {
        if (prev) {
          prev->next = temp->next;
        } else {
          head = temp->next;
        }
        free(item);
      } else {
        prev = temp;
        temp = temp->next;
      }
    }
  }
}

int main() {
  struct Node* head = NULL;

  insert_at_tail(head, "Apple", 10);
  insert_at_tail(head, "Banana", 20);
  insert_at_tail(head, "Orange", 30);

  update_item_quantity(head, "Banana", 25);

  delete_item(head, "Orange");

  struct Node* item = search_item(head, "Apple");
  if (item) {
    printf("Item: %s, Quantity: %d\n", item->item_name, item->quantity);
  }

  return 0;
}