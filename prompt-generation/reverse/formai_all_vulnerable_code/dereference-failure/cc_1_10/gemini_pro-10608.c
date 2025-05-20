//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
  int id;
  char *name;
  int quantity;
  float price;
};

struct Node {
  struct Item *item;
  struct Node *next;
};

struct LinkedList {
  struct Node *head;
  struct Node *tail;
  int size;
};

struct LinkedList *create_linked_list() {
  struct LinkedList *list = malloc(sizeof(struct LinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

void add_item(struct LinkedList *list, struct Item *item) {
  struct Node *node = malloc(sizeof(struct Node));
  node->item = item;
  node->next = NULL;

  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }

  list->size++;
}

struct Item *get_item(struct LinkedList *list, int id) {
  struct Node *node = list->head;

  while (node != NULL) {
    if (node->item->id == id) {
      return node->item;
    }

    node = node->next;
  }

  return NULL;
}

void remove_item(struct LinkedList *list, int id) {
  struct Node *node = list->head;
  struct Node *prev = NULL;

  while (node != NULL) {
    if (node->item->id == id) {
      if (prev == NULL) {
        list->head = node->next;
      } else {
        prev->next = node->next;
      }

      if (node == list->tail) {
        list->tail = prev;
      }

      free(node->item);
      free(node);
      list->size--;

      return;
    }

    prev = node;
    node = node->next;
  }
}

void print_list(struct LinkedList *list) {
  struct Node *node = list->head;

  while (node != NULL) {
    printf("%d %s %d %.2f\n", node->item->id, node->item->name, node->item->quantity, node->item->price);
    node = node->next;
  }
}

void free_list(struct LinkedList *list) {
  struct Node *node = list->head;
  struct Node *next;

  while (node != NULL) {
    next = node->next;
    free(node->item->name);
    free(node->item);
    free(node);
    node = next;
  }

  free(list);
}

int main() {
  struct LinkedList *list = create_linked_list();

  struct Item *item1 = malloc(sizeof(struct Item));
  item1->id = 1;
  item1->name = strdup("Apple");
  item1->quantity = 10;
  item1->price = 1.00;

  struct Item *item2 = malloc(sizeof(struct Item));
  item2->id = 2;
  item2->name = strdup("Orange");
  item2->quantity = 15;
  item2->price = 1.25;

  struct Item *item3 = malloc(sizeof(struct Item));
  item3->id = 3;
  item3->name = strdup("Banana");
  item3->quantity = 20;
  item3->price = 1.50;

  add_item(list, item1);
  add_item(list, item2);
  add_item(list, item3);

  print_list(list);

  printf("\n");

  struct Item *item = get_item(list, 2);
  printf("Item found: %d %s %d %.2f\n", item->id, item->name, item->quantity, item->price);

  printf("\n");

  remove_item(list, 1);
  print_list(list);

  printf("\n");

  free_list(list);

  return 0;
}