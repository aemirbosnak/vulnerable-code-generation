//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the warehouse management system structure
typedef struct WarehouseManagementSystem {
  char item_name[256];
  int item_quantity;
  double item_price;
  struct WarehouseManagementSystem* next;
} WarehouseManagementSystem;

// Function to insert an item into the warehouse management system
void insert_item(WarehouseManagementSystem* head) {
  // Allocate memory for the new item
  WarehouseManagementSystem* new_item = (WarehouseManagementSystem*)malloc(sizeof(WarehouseManagementSystem));

  // Get the item name, quantity, and price from the user
  printf("Enter item name: ");
  scanf("%s", new_item->item_name);

  printf("Enter item quantity: ");
  scanf("%d", &new_item->item_quantity);

  printf("Enter item price: ");
  scanf("%lf", &new_item->item_price);

  // Insert the new item into the linked list
  new_item->next = head;
  head = new_item;
}

// Function to search for an item in the warehouse management system
void search_item(WarehouseManagementSystem* head) {
  // Get the item name from the user
  printf("Enter item name: ");
  char item_name[256];
  scanf("%s", item_name);

  // Search for the item in the linked list
  WarehouseManagementSystem* current_item = head;
  while (current_item) {
    if (strcmp(current_item->item_name, item_name) == 0) {
      // Print the item information
      printf("Item name: %s\n", current_item->item_name);
      printf("Item quantity: %d\n", current_item->item_quantity);
      printf("Item price: %.2lf\n", current_item->item_price);
      break;
    }
    current_item = current_item->next;
  }

  // If the item is not found, print an error message
  if (current_item == NULL) {
    printf("Item not found.\n");
  }
}

// Function to update the item quantity in the warehouse management system
void update_item_quantity(WarehouseManagementSystem* head) {
  // Get the item name from the user
  printf("Enter item name: ");
  char item_name[256];
  scanf("%s", item_name);

  // Search for the item in the linked list
  WarehouseManagementSystem* current_item = head;
  while (current_item) {
    if (strcmp(current_item->item_name, item_name) == 0) {
      // Get the new item quantity from the user
      int new_quantity;
      printf("Enter new item quantity: ");
      scanf("%d", &new_quantity);

      // Update the item quantity
      current_item->item_quantity = new_quantity;

      // Print the updated item information
      printf("Item name: %s\n", current_item->item_name);
      printf("Item quantity: %d\n", current_item->item_quantity);
      printf("Item price: %.2lf\n", current_item->item_price);
      break;
    }
    current_item = current_item->next;
  }

  // If the item is not found, print an error message
  if (current_item == NULL) {
    printf("Item not found.\n");
  }
}

// Function to delete an item from the warehouse management system
void delete_item(WarehouseManagementSystem* head) {
  // Get the item name from the user
  printf("Enter item name: ");
  char item_name[256];
  scanf("%s", item_name);

  // Search for the item in the linked list
  WarehouseManagementSystem* current_item = head;
  WarehouseManagementSystem* previous_item = NULL;
  while (current_item) {
    if (strcmp(current_item->item_name, item_name) == 0) {
      // If the item is the first item in the list, update the head of the list
      if (previous_item == NULL) {
        head = current_item->next;
      } else {
        // Otherwise, update the previous item to point to the next item in the list
        previous_item->next = current_item->next;
      }

      // Free the memory allocated for the item
      free(current_item);

      // Print the updated item list
      printf("Items:\n");
      current_item = head;
      while (current_item) {
        printf("Item name: %s\n", current_item->item_name);
        printf("Item quantity: %d\n", current_item->item_quantity);
        printf("Item price: %.2lf\n", current_item->item_price);
        printf("\n");
        current_item = current_item->next;
      }

      break;
    }
    previous_item = current_item;
    current_item = current_item->next;
  }

  // If the item is not found, print an error message
  if (current_item == NULL) {
    printf("Item not found.\n");
  }
}

int main() {
  // Create a head of the warehouse management system
  WarehouseManagementSystem* head = NULL;

  // Insert items into the warehouse management system
  insert_item(head);
  insert_item(head);
  insert_item(head);

  // Search for an item in the warehouse management system
  search_item(head);

  // Update the item quantity in the warehouse management system
  update_item_quantity(head);

  // Delete an item from the warehouse management system
  delete_item(head);

  // Print the updated item list
  printf("Items:\n");
  search_item(head);

  return 0;
}