//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of items in the warehouse
int numItems = 10;

// Create an array of items in the warehouse
struct Item {
    char name[20];
    int quantity;
    float price;
    struct Item* next;
};

// Create a linked list of items in the warehouse
struct Item* head = NULL;

// Function to add an item to the warehouse
void addItem(char* name, int quantity, float price) {
    // Allocate memory for a new item
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));

    // Copy the item name, quantity, and price into the new item
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;

    // Add the new item to the end of the linked list
    if (head == NULL) {
        head = newItem;
    } else {
        head->next = newItem;
        head = head->next;
    }
}

// Function to find an item in the warehouse
struct Item* findItem(char* name) {
    // Traverse the linked list of items in the warehouse
    struct Item* currentItem = head;
    while (currentItem) {
        // Check if the item name is equal to the name of the item being searched for
        if (strcmp(currentItem->name, name) == 0) {
            // Return the item
            return currentItem;
        }
        currentItem = currentItem->next;
    }

    // Return NULL if the item is not found
    return NULL;
}

// Function to update the quantity of an item in the warehouse
void updateItemQuantity(char* name, int quantity) {
    // Find the item in the warehouse
    struct Item* item = findItem(name);

    // If the item is found, update its quantity
    if (item) {
        item->quantity = quantity;
    }
}

// Function to remove an item from the warehouse
void removeItem(char* name) {
    // Find the item in the warehouse
    struct Item* item = findItem(name);

    // If the item is found, remove it from the linked list
    if (item) {
        struct Item* previousItem = NULL;
        struct Item* currentItem = head;

        // Traverse the linked list of items in the warehouse
        while (currentItem) {
            // Check if the item name is equal to the name of the item being removed
            if (strcmp(currentItem->name, name) == 0) {
                // If the previous item is not NULL, update the previous item to point to the current item
                if (previousItem) {
                    previousItem->next = currentItem->next;
                } else {
                    head = currentItem->next;
                }

                // Free the memory allocated for the current item
                free(currentItem);
            } else {
                previousItem = currentItem;
                currentItem = currentItem->next;
            }
        }
    }
}

// Main function
int main() {
    // Add items to the warehouse
    addItem("Apple", 10, 1.0);
    addItem("Orange", 15, 1.5);
    addItem("Banana", 20, 2.0);

    // Find an item in the warehouse
    struct Item* item = findItem("Orange");
    if (item) {
        printf("Item name: %s\n", item->name);
        printf("Item quantity: %d\n", item->quantity);
        printf("Item price: %.2f\n", item->price);
    }

    // Update the quantity of an item in the warehouse
    updateItemQuantity("Apple", 12);

    // Remove an item from the warehouse
    removeItem("Banana");

    // Print the items in the warehouse
    struct Item* currentItem = head;
    while (currentItem) {
        printf("Item name: %s\n", currentItem->name);
        printf("Item quantity: %d\n", currentItem->quantity);
        printf("Item price: %.2f\n", currentItem->price);
        printf("\n");
        currentItem = currentItem->next;
    }

    return 0;
}