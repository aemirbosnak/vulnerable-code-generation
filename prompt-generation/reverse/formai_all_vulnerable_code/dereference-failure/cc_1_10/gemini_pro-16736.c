//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: recursive
// Warehouse Management System in Recursive Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a warehouse item
typedef struct Item {
    char name[50];
    int quantity;
    float price;
    struct Item *next;
} Item;

// Function to create a new item
Item *createItem(char *name, int quantity, float price) {
    Item *newItem = malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    newItem->next = NULL;
    return newItem;
}

// Function to add an item to the warehouse
void addItem(Item **head, Item *newItem) {
    if (*head == NULL) {
        *head = newItem;
    } else {
        addItem(&(*head)->next, newItem);
    }
}

// Function to remove an item from the warehouse
void removeItem(Item **head, char *name) {
    if (*head == NULL) {
        printf("Item not found\n");
    } else if (strcmp((*head)->name, name) == 0) {
        Item *temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        removeItem(&(*head)->next, name);
    }
}

// Function to search for an item in the warehouse
Item *searchItem(Item *head, char *name) {
    if (head == NULL) {
        return NULL;
    } else if (strcmp(head->name, name) == 0) {
        return head;
    } else {
        return searchItem(head->next, name);
    }
}

// Function to print the contents of the warehouse
void printWarehouse(Item *head) {
    if (head == NULL) {
        printf("Warehouse is empty\n");
    } else {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", head->name, head->quantity, head->price);
        printWarehouse(head->next);
    }
}

// Function to calculate the total value of the warehouse
float calculateTotalValue(Item *head) {
    if (head == NULL) {
        return 0;
    } else {
        return head->price * head->quantity + calculateTotalValue(head->next);
    }
}

// Main function
int main() {
    // Create a new warehouse
    Item *warehouse = NULL;

    // Add some items to the warehouse
    addItem(&warehouse, createItem("Apple", 10, 1.0));
    addItem(&warehouse, createItem("Orange", 5, 2.0));
    addItem(&warehouse, createItem("Banana", 15, 3.0));

    // Print the contents of the warehouse
    printf("Warehouse contents:\n");
    printWarehouse(warehouse);

    // Search for an item in the warehouse
    Item *item = searchItem(warehouse, "Orange");
    if (item != NULL) {
        printf("Found item: %s, Quantity: %d, Price: %.2f\n", item->name, item->quantity, item->price);
    } else {
        printf("Item not found\n");
    }

    // Remove an item from the warehouse
    removeItem(&warehouse, "Banana");

    // Print the contents of the warehouse again
    printf("Warehouse contents after removing Banana:\n");
    printWarehouse(warehouse);

    // Calculate the total value of the warehouse
    float totalValue = calculateTotalValue(warehouse);
    printf("Total value of the warehouse: %.2f\n", totalValue);

    return 0;
}