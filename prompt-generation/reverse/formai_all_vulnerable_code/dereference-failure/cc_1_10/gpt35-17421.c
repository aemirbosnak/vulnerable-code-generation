//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct item {
  char *name;
  int quantity;
} Item;

typedef struct warehouse {
  Item *items[MAX_ITEMS];
  int count;
} Warehouse;

void add_item(Warehouse *w, char *name, int quantity) {
  if (w->count >= MAX_ITEMS) {
    printf("Warehouse is full!\n");
    return;
  }
  Item *item = (Item *)malloc(sizeof(Item));
  item->name = name;
  item->quantity = quantity;
  w->items[w->count] = item;
  w->count++;
}

void remove_item(Warehouse *w, char *name) {
  for (int i = 0; i < w->count; i++) {
    if (strcmp(w->items[i]->name, name) == 0) {
      free(w->items[i]);
      w->items[i] = w->items[w->count-1];
      w->count--;
      printf("Item removed from warehouse.\n");
      return;
    }
  }
  printf("Item not found in warehouse.\n");
}

void print_items(Warehouse *w) {
  printf("%-10s %s\n", "Quantity", "Item");
  for (int i = 0; i < w->count; i++) {
    printf("%-10d %s\n", w->items[i]->quantity, w->items[i]->name);
  }
}

int main() {
  Warehouse w;
  w.count = 0;

  add_item(&w, "apples", 50);
  add_item(&w, "oranges", 25);
  print_items(&w);

  remove_item(&w, "apples");
  print_items(&w);

  add_item(&w, "bananas", 40);
  print_items(&w);

  return 0;
}