//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct warehouse {
  char *name;
  int capacity;
  int stock;
  struct warehouse *next;
} warehouse;

warehouse *create_warehouse(char *name, int capacity) {
  warehouse *new_warehouse = malloc(sizeof(warehouse));
  new_warehouse->name = strdup(name);
  new_warehouse->capacity = capacity;
  new_warehouse->stock = 0;
  new_warehouse->next = NULL;
  return new_warehouse;
}

void add_warehouse(warehouse **head, warehouse *new_warehouse) {
  if (*head == NULL) {
    *head = new_warehouse;
  } else {
    add_warehouse(&(*head)->next, new_warehouse);
  }
}

void print_warehouse(warehouse *head) {
  if (head == NULL) {
    return;
  } else {
    printf("%s (%d/%d)\n", head->name, head->stock, head->capacity);
    print_warehouse(head->next);
  }
}

void add_stock(warehouse *head, char *name, int amount) {
  if (head == NULL) {
    return;
  } else if (strcmp(head->name, name) == 0) {
    if (head->stock + amount <= head->capacity) {
      head->stock += amount;
    } else {
      printf("Error: Warehouse %s is full.\n", head->name);
    }
  } else {
    add_stock(head->next, name, amount);
  }
}

void remove_stock(warehouse *head, char *name, int amount) {
  if (head == NULL) {
    return;
  } else if (strcmp(head->name, name) == 0) {
    if (head->stock - amount >= 0) {
      head->stock -= amount;
    } else {
      printf("Error: Warehouse %s does not have enough stock.\n", head->name);
    }
  } else {
    remove_stock(head->next, name, amount);
  }
}

void delete_warehouse(warehouse *head, char *name) {
  if (head == NULL) {
    return;
  } else if (strcmp(head->name, name) == 0) {
    warehouse *temp = head->next;
    free(head->name);
    free(head);
    head = temp;
  } else {
    delete_warehouse(head->next, name);
  }
}

int main() {
  warehouse *head = NULL;
  add_warehouse(&head, create_warehouse("Warehouse A", 100));
  add_warehouse(&head, create_warehouse("Warehouse B", 200));
  add_warehouse(&head, create_warehouse("Warehouse C", 300));

  print_warehouse(head);

  add_stock(head, "Warehouse A", 50);
  add_stock(head, "Warehouse B", 100);
  add_stock(head, "Warehouse C", 150);

  print_warehouse(head);

  remove_stock(head, "Warehouse A", 25);
  remove_stock(head, "Warehouse B", 50);
  remove_stock(head, "Warehouse C", 75);

  print_warehouse(head);

  delete_warehouse(head, "Warehouse B");

  print_warehouse(head);

  return 0;
}