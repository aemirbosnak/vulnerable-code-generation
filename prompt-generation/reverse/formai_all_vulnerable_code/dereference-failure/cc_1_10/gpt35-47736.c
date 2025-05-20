//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate unique item ID
char* generateID() {
  // Current timestamp as a string
  time_t t = time(NULL);
  char *timestamp = asctime(localtime(&t));
  strtok(timestamp, "\n"); // remove newline character from timestamp

  // Random 3-digit number string
  char *randomNum = malloc(sizeof(char) * 4); // allocate memory for 3 digits and null terminator
  sprintf(randomNum, "%d", rand() % 900 + 100); // generate random number between 100 and 999
  
  // Concatenate timestamp and random number to create unique ID
  char *ID = malloc(strlen(timestamp) + strlen(randomNum) + 1); // allocate memory for ID
  strcpy(ID, timestamp);
  strcat(ID, "-");
  strcat(ID, randomNum);
  
  return ID;
}

// Struct to represent item in warehouse
struct Item {
  char *ID;
  char *name;
  int quantity;
};

// Function to add item to warehouse
void addItem(struct Item **warehouse, int *numItems) {
  struct Item newItem;
  newItem.ID = generateID();

  printf("Name of item:\n");
  char name[50];
  scanf("%s", name);
  newItem.name = malloc(strlen(name) + 1);
  strcpy(newItem.name, name);

  printf("Quantity of item:\n");
  scanf("%d", &newItem.quantity);

  (*warehouse) = realloc((*warehouse), sizeof(struct Item) * (*numItems + 1)); // increase size of warehouse array
  (*warehouse)[*numItems] = newItem; // add item to warehouse
  (*numItems)++;
  printf("Item added to warehouse.\n");
}

// Function to remove item from warehouse
void removeItem(struct Item **warehouse, int *numItems) {
  printf("Enter ID of item to remove:\n");
  char ID[50];
  scanf("%s", ID);

  // Find index of item in warehouse array
  int index = -1;
  for (int i = 0; i < (*numItems); i++) {
    if (strcmp((*warehouse)[i].ID, ID) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Item not found.\n");
  } else {
    // Shift all items after removed item to the left
    for (int i = index; i < (*numItems) - 1; i++) {
      (*warehouse)[i] = (*warehouse)[i+1];
    }
    (*numItems)--;
    (*warehouse) = realloc((*warehouse), sizeof(struct Item) * (*numItems)); // decrease size of warehouse array
    printf("Item removed from warehouse.\n");
  }
}

// Function to print all items in warehouse
void printItems(struct Item *warehouse, int numItems) {
  printf("Items in warehouse:\n");
  for (int i = 0; i < numItems; i++) {
    printf("%s %s %d\n", warehouse[i].ID, warehouse[i].name, warehouse[i].quantity);
  }
}

int main() {
  printf("Welcome to the Futuristic Warehouse Management System!\n");

  struct Item *warehouse = malloc(sizeof(struct Item));
  int numItems = 0;

  while (1) {
    printf("\nOptions:\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Print items\n");
    printf("4. Exit\n");

    int choice;
    scanf("%d", &choice);
    printf("\n");

    switch (choice) {
      case 1:
        addItem(&warehouse, &numItems);
        break;
      case 2:
        removeItem(&warehouse, &numItems);
        break;
      case 3:
        printItems(warehouse, numItems);
        break;
      case 4:
        printf("Exiting program.\n");
        exit(0);
      default:
        printf("Invalid option.\n");
        break;
    }
  }

  return 0;
}