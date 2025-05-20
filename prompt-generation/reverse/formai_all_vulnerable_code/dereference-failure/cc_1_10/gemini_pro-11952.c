//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the stock struct
typedef struct stock {
  char *name;
  float price;
  int volume;
} stock;

// Declare the linked list node struct
typedef struct node {
  stock *data;
  struct node *next;
} node;

// Declare the linked list head
node *head = NULL;

// Create a new stock
stock *create_stock(char *name, float price, int volume) {
  stock *new_stock = malloc(sizeof(stock));
  new_stock->name = strdup(name);
  new_stock->price = price;
  new_stock->volume = volume;
  return new_stock;
}

// Insert a new stock into the linked list
void insert_stock(stock *new_stock) {
  node *new_node = malloc(sizeof(node));
  new_node->data = new_stock;
  new_node->next = head;
  head = new_node;
}

// Search for a stock in the linked list
stock *search_stock(char *name) {
  node *current = head;
  while (current != NULL) {
    if (strcmp(current->data->name, name) == 0) {
      return current->data;
    }
    current = current->next;
  }
  return NULL;
}

// Print the linked list
void print_linked_list() {
  node *current = head;
  while (current != NULL) {
    printf("%s %.2f %d\n", current->data->name, current->data->price, current->data->volume);
    current = current->next;
  }
}

// Free the linked list
void free_linked_list() {
  node *current = head;
  while (current != NULL) {
    node *next = current->next;
    free(current->data->name);
    free(current->data);
    free(current);
    current = next;
  }
}

// Main function
int main() {
  // Create some stocks
  stock *aapl = create_stock("AAPL", 100.00, 1000);
  stock *amzn = create_stock("AMZN", 120.00, 1200);
  stock *goog = create_stock("GOOG", 140.00, 1400);
  stock *msft = create_stock("MSFT", 160.00, 1600);
  stock *tsla = create_stock("TSLA", 180.00, 1800);

  // Insert the stocks into the linked list
  insert_stock(aapl);
  insert_stock(amzn);
  insert_stock(goog);
  insert_stock(msft);
  insert_stock(tsla);

  // Print the linked list
  printf("Here are the stocks in the list:\n");
  print_linked_list();

  // Search for a stock in the linked list
  stock *found_stock = search_stock("GOOG");
  if (found_stock != NULL) {
    printf("\nFound the stock: %s %.2f %d\n", found_stock->name, found_stock->price, found_stock->volume);
  } else {
    printf("\nStock not found.\n");
  }

  // Free the linked list
  free_linked_list();

  return 0;
}