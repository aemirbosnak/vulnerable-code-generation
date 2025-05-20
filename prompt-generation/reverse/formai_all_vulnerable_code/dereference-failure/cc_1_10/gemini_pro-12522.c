//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
/* Claude Shannon Medical Store Management System */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Item {
  int id;
  char name[50];
  int quantity;
  float price;
} Item;

typedef struct Node {
  Item item;
  struct Node *next;
} Node;

typedef struct LinkedList {
  struct Node *head;
  struct Node *tail;
  int size;
} LinkedList;

// Initialize a linked list
LinkedList *init_linked_list() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

// Insert an item into a linked list
void insert_item(LinkedList *list, Item item) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->item = item;
  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }

  list->size++;
}

// Search for an item in a linked list
Item *search_item(LinkedList *list, int id) {
  Node *current = list->head;

  while (current != NULL) {
    if (current->item.id == id) {
      return &current->item;
    }
    current = current->next;
  }

  return NULL;
}

// Delete an item from a linked list
void delete_item(LinkedList *list, int id) {
  Node *current = list->head;
  Node *prev = NULL;

  while (current != NULL) {
    if (current->item.id == id) {
      if (prev == NULL) {
        list->head = current->next;
      } else {
        prev->next = current->next;
      }

      free(current);
      list->size--;
      return;
    }

    prev = current;
    current = current->next;
  }
}

// Print a linked list
void print_linked_list(LinkedList *list) {
  Node *current = list->head;

  while (current != NULL) {
    printf("ID: %d\n", current->item.id);
    printf("Name: %s\n", current->item.name);
    printf("Quantity: %d\n", current->item.quantity);
    printf("Price: %.2f\n\n", current->item.price);
    current = current->next;
  }
}

// Main function
int main() {
  // Create a linked list to store the items
  LinkedList *list = init_linked_list();

  // Insert some items into the linked list
  Item item1 = {1, "Paracetamol", 100, 10.0};
  insert_item(list, item1);
  Item item2 = {2, "Ibuprofen", 50, 15.0};
  insert_item(list, item2);
  Item item3 = {3, "Aspirin", 75, 20.0};
  insert_item(list, item3);

  // Print the linked list
  printf("Items in the medical store:\n");
  print_linked_list(list);

  // Search for an item in the linked list
  int id = 2;
  Item *item = search_item(list, id);
  if (item != NULL) {
    printf("Item found:\n");
    printf("ID: %d\n", item->id);
    printf("Name: %s\n", item->name);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: %.2f\n\n", item->price);
  } else {
    printf("Item not found.\n");
  }

  // Delete an item from the linked list
  id = 3;
  delete_item(list, id);

  // Print the linked list
  printf("Items in the medical store after deletion:\n");
  print_linked_list(list);

  // Free the linked list
  while (list->head != NULL) {
    Node *current = list->head;
    list->head = current->next;
    free(current);
  }
  free(list);

  return 0;
}