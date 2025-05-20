//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ITEMS 100

typedef struct item {
  char name[50];
  int quantity;
  struct item* next;
} item_t;

item_t* insert_item(item_t* head, char* name, int quantity) {
  item_t* new_item = malloc(sizeof(item_t));
  strcpy(new_item->name, name);
  new_item->quantity = quantity;
  new_item->next = NULL;

  if (head == NULL) {
    return new_item;
  }

  head->next = insert_item(head->next, name, quantity);
  return head;
}

item_t* search_item(item_t* head, char* name) {
  item_t* current = head;

  while (current) {
    if (strcmp(current->name, name) == 0) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}

int main() {
  item_t* head = NULL;

  insert_item(&head, "Apple", 10);
  insert_item(&head, "Banana", 5);
  insert_item(&head, "Orange", 7);

  item_t* item = search_item(head, "Banana");

  if (item) {
    printf("%s has %d units.\n", item->name, item->quantity);
  } else {
    printf("Item not found.\n");
  }

  return 0;
}