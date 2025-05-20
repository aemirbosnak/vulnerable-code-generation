//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the warehouse items
typedef struct Item {
  char itemName[20];
  int quantity;
  float price;
  struct Item *next;
} Item;

// Function to add a new item to the warehouse inventory
void addItem(Item **head) {
  Item *cur = *head;
  Item *newItem = malloc(sizeof(Item));
  
  printf("\nEnter Name of Item: ");
  scanf("%s", newItem->itemName);
  printf("Enter Quantity: ");
  scanf("%d", &newItem->quantity);
  printf("Enter Price: ");
  scanf("%f", &newItem->price);

  newItem->next = NULL;

  if (*head == NULL) {
    *head = newItem;
  } else {
    while (cur->next != NULL) {
      cur = cur->next;
    }
    cur->next = newItem;
  }
  printf("\nItem Added Successfully\n");
}

// Function to display the warehouse inventory
void displayItems(Item *head) {
  Item *cur = head;
  if (cur == NULL) {
    printf("\nWarehouse is Empty\n");
  } else {
    printf("\n%-20s | %-10s | %-10s\n", "Item Name", "Quantity", "Price");
    printf("------------------------------------------\n");
    while (cur != NULL) {
      printf("%-20s | %-10d | $%-10.2f\n", cur->itemName, cur->quantity, cur->price);
      cur = cur->next;
    }
  }
}

// Function to search for an item in the warehouse inventory
void searchItem(Item *head) {
  Item *cur = head;
  char name[20];
  int found = 0;
  
  printf("\nEnter Name of Item to Search: ");
  scanf("%s", name);

  while (cur != NULL) {
    if (strcmp(cur->itemName, name) == 0) {
      printf("\n%-20s | %-10s | %-10s\n", "Item Name", "Quantity", "Price");
      printf("------------------------------------------\n");
      printf("%-20s | %-10d | $%-10.2f\n", cur->itemName, cur->quantity, cur->price);
      found++;
      break;
    }
    cur = cur->next;
  }
  if (!found) {
    printf("Item not found!\n");
  }
}

// Function to remove an item from the warehouse inventory
void removeItem(Item **head) {
  Item *cur = *head;
  Item *prev = NULL;
  char name[20];
  int found = 0;
  
  printf("\nEnter Name of Item to Remove: ");
  scanf("%s", name);

  if (cur != NULL && strcmp(cur->itemName, name) == 0) {
    *head = cur->next;
    printf("\nItem Removed Successfully\n");
    free(cur);
    return;
  }

  while (cur != NULL && strcmp(cur->itemName, name) != 0) {
    prev = cur;
    cur = cur->next;
  }

  if (cur == NULL) {
    printf("\nItem not found!\n");
    return;
  }

  prev->next = cur->next;
  printf("\nItem Removed Successfully\n");
  free(cur);
}

int main() {
  Item *head = NULL;
  int choice;

  while(1) {
    printf("\n\n---- Warehouse Management System ----\n\n");
    printf("\t1. Add Item to Warehouse\n");
    printf("\t2. Display Inventory\n");
    printf("\t3. Search for an Item\n");
    printf("\t4. Remove an Item\n");
    printf("\t5. Exit\n");
    printf("\n\tEnter your choice: ");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        addItem(&head);
        break;
      case 2:
        displayItems(head);
        break;
      case 3:
        searchItem(head);
        break;
      case 4:
        removeItem(&head);
        break;
      case 5:
        exit(0);
      default:
        printf("\nInvalid Choice! Try Again.\n");
    }
  }
  return 0;
}