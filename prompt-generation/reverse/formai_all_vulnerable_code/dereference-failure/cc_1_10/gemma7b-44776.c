//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
  char name[50];
  int quantity;
  double price;
  struct item* next;
};

struct warehouse {
  struct item* head;
  struct item* tail;
  int items_count;
  double total_value;
};

void insert_item(struct warehouse* w, char* name, int quantity, double price) {
  struct item* new_item = malloc(sizeof(struct item));
  strcpy(new_item->name, name);
  new_item->quantity = quantity;
  new_item->price = price;
  new_item->next = NULL;

  if (w->head == NULL) {
    w->head = new_item;
    w->tail = new_item;
  } else {
    w->tail->next = new_item;
    w->tail = new_item;
  }

  w->items_count++;
  w->total_value += quantity * price;
}

void remove_item(struct warehouse* w, char* name) {
  struct item* current = w->head;
  struct item* previous = NULL;

  while (current) {
    if (strcmp(current->name, name) == 0) {
      if (previous) {
        previous->next = current->next;
        w->tail = previous;
      } else {
        w->head = current->next;
        w->tail = w->head;
      }

      w->items_count--;
      w->total_value -= current->quantity * current->price;
      free(current);
      return;
    }

    previous = current;
    current = current->next;
  }

  printf("Item not found.\n");
}

int main() {
  struct warehouse w;
  w.head = NULL;
  w.tail = NULL;
  w.items_count = 0;
  w.total_value = 0.0;

  insert_item(&w, "Apple", 10, 1.2);
  insert_item(&w, "Banana", 20, 0.8);
  insert_item(&w, "Orange", 15, 0.9);

  remove_item(&w, "Banana");

  printf("Items: %d\n", w.items_count);
  printf("Total value: %.2lf\n", w.total_value);

  return 0;
}