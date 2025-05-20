//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
  char name[20];
  int quantity;
  float price;
};

struct node {
  struct item item_data;
  struct node* next;
};

struct warehouse {
  struct node* head;
  int items_count;
  float total_value;
};

void insert_item(struct warehouse* warehouse, char* name, int quantity, float price) {
  struct item new_item;
  strcpy(new_item.name, name);
  new_item.quantity = quantity;
  new_item.price = price;

  struct node* new_node = malloc(sizeof(struct node));
  new_node->item_data = new_item;
  new_node->next = NULL;

  if (warehouse->head == NULL) {
    warehouse->head = new_node;
  } else {
    warehouse->head->next = new_node;
  }

  warehouse->items_count++;
  warehouse->total_value += new_item.price * new_item.quantity;
}

void print_items(struct warehouse* warehouse) {
  struct node* current_node = warehouse->head;

  printf("Items in the warehouse:\n");
  while (current_node) {
    printf("%s - %d - %.2f\n", current_node->item_data.name, current_node->item_data.quantity, current_node->item_data.price);
    current_node = current_node->next;
  }
}

int main() {
  struct warehouse warehouse;
  warehouse.head = NULL;
  warehouse.items_count = 0;
  warehouse.total_value = 0.0f;

  insert_item(&warehouse, "Apple", 10, 1.20);
  insert_item(&warehouse, "Banana", 5, 0.80);
  insert_item(&warehouse, "Orange", 7, 1.00);

  print_items(&warehouse);

  return 0;
}