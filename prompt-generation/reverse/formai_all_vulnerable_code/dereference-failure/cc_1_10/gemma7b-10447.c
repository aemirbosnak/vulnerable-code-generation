//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the inventory
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct Item {
    char name[50];
    int quantity;
    double price;
    struct Item* next;
} Item;

// Function to insert an item into the inventory
void insertItem(Item** head, char* name, int quantity, double price) {
    // Allocate memory for the new item
    Item* newNode = malloc(sizeof(Item));

    // Copy the item name, quantity, and price
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->price = price;

    // Insert the new item into the head of the list
    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to search for an item in the inventory
Item* searchItem(Item* head, char* name) {
    // Iterate over the inventory
    while (head) {
        // Compare the item name to the search name
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    // Item not found
    return NULL;
}

// Function to update the quantity of an item in the inventory
void updateQuantity(Item* item, int newQuantity) {
    // Update the item quantity
    item->quantity = newQuantity;
}

// Function to remove an item from the inventory
void removeItem(Item* head, char* name) {
    // Search for the item to remove
    Item* item = searchItem(head, name);

    // If the item is found, remove it from the inventory
    if (item) {
        Item* previousItem = NULL;
        while (item->next) {
            previousItem = item;
            item = item->next;
        }

        // If the item is the first item in the inventory, update the head of the list
        if (previousItem == NULL) {
            head = item->next;
        } else {
            previousItem->next = item->next;
        }

        // Free the memory allocated for the item
        free(item);
    }
}

int main() {
    // Create the inventory head
    Item* head = NULL;

    // Insert some items into the inventory
    insertItem(&head, "Apple", 10, 1.20);
    insertItem(&head, "Banana", 5, 0.80);
    insertItem(&head, "Orange", 7, 0.90);

    // Search for an item in the inventory
    Item* item = searchItem(head, "Banana");

    // If the item is found, update its quantity
    if (item) {
        updateQuantity(item, 12);
    }

    // Remove an item from the inventory
    removeItem(head, "Orange");

    // Print the items in the inventory
    for (item = head; item; item = item->next) {
        printf("%s: %d, $%.2lf\n", item->name, item->quantity, item->price);
    }

    return 0;
}