//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
  char name[50];
  int quantity;
  int id;
  struct item *next;
};

struct node {
  char id[50];
  int quantity;
  struct node *next;
};

struct warehouse {
  struct item *items;
  struct node *nodes;
};

void add_item(struct warehouse *warehouse, char *name, int quantity, int id) {
  struct item *new_item = malloc(sizeof(struct item));
  strcpy(new_item->name, name);
  new_item->quantity = quantity;
  new_item->id = id;
  new_item->next = NULL;

  if (warehouse->items == NULL) {
    warehouse->items = new_item;
  } else {
    struct item *current_item = warehouse->items;
    while (current_item->next != NULL) {
      current_item = current_item->next;
    }
    current_item->next = new_item;
  }
}

void add_node(struct warehouse *warehouse, char *id, int quantity) {
  struct node *new_node = malloc(sizeof(struct node));
  strcpy(new_node->id, id);
  new_node->quantity = quantity;
  new_node->next = NULL;

  if (warehouse->nodes == NULL) {
    warehouse->nodes = new_node;
  } else {
    struct node *current_node = warehouse->nodes;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }
}

void remove_item(struct warehouse *warehouse, char *name) {
  struct item *current_item = warehouse->items;
  struct item *previous_item = NULL;

  while (current_item != NULL) {
    if (strcmp(current_item->name, name) == 0) {
      if (previous_item == NULL) {
        warehouse->items = current_item->next;
      } else {
        previous_item->next = current_item->next;
      }
      free(current_item);
      return;
    }
    previous_item = current_item;
    current_item = current_item->next;
  }
}

void remove_node(struct warehouse *warehouse, char *id) {
  struct node *current_node = warehouse->nodes;
  struct node *previous_node = NULL;

  while (current_node != NULL) {
    if (strcmp(current_node->id, id) == 0) {
      if (previous_node == NULL) {
        warehouse->nodes = current_node->next;
      } else {
        previous_node->next = current_node->next;
      }
      free(current_node);
      return;
    }
    previous_node = current_node;
    current_node = current_node->next;
  }
}

void print_items(struct warehouse *warehouse) {
  struct item *current_item = warehouse->items;

  while (current_item != NULL) {
    printf("%s (%d)\n", current_item->name, current_item->quantity);
    current_item = current_item->next;
  }
}

void print_nodes(struct warehouse *warehouse) {
  struct node *current_node = warehouse->nodes;

  while (current_node != NULL) {
    printf("%s (%d)\n", current_node->id, current_node->quantity);
    current_node = current_node->next;
  }
}

int main() {
  struct warehouse warehouse;
  warehouse.items = NULL;
  warehouse.nodes = NULL;

  add_item(&warehouse, "Apples", 10, 1);
  add_item(&warehouse, "Bananas", 20, 2);
  add_item(&warehouse, "Oranges", 30, 3);

  add_node(&warehouse, "Node 1", 100);
  add_node(&warehouse, "Node 2", 200);
  add_node(&warehouse, "Node 3", 300);

  print_items(&warehouse);
  printf("\n");
  print_nodes(&warehouse);

  remove_item(&warehouse, "Bananas");
  remove_node(&warehouse, "Node 2");

  print_items(&warehouse);
  printf("\n");
  print_nodes(&warehouse);

  return 0;
}