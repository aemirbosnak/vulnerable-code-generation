//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct item {
  char name[50];
  int quantity;
  struct item* next;
} item;

item* head = NULL;

void insert_item(char* name, int quantity) {
  item* new_item = (item*)malloc(sizeof(item));
  strcpy(new_item->name, name);
  new_item->quantity = quantity;
  new_item->next = NULL;

  if (head == NULL) {
    head = new_item;
  } else {
    item* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_item;
  }
}

void print_items() {
  item* current = head;
  while (current) {
    printf("%s: %d\n", current->name, current->quantity);
    current = current->next;
  }
}

void update_item(char* name, int new_quantity) {
  item* current = head;
  while (current) {
    if (strcmp(current->name, name) == 0) {
      current->quantity = new_quantity;
      return;
    }
    current = current->next;
  }

  printf("Item not found.\n");
}

void delete_item(char* name) {
  item* current = head;
  item* previous = NULL;

  while (current) {
    if (strcmp(current->name, name) == 0) {
      if (previous) {
        previous->next = current->next;
      } else {
        head = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }

  printf("Item not found.\n");
}

int main() {
  insert_item("Foo", 10);
  insert_item("Bar", 20);
  insert_item("Baz", 30);

  print_items();

  update_item("Bar", 25);

  print_items();

  delete_item("Baz");

  print_items();

  return 0;
}