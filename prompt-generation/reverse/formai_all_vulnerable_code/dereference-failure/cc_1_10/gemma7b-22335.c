//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of items in the database
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct Item {
    char name[50];
    int quantity;
    struct Item* next;
} Item;

// Define the head of the database
Item* head = NULL;

// Function to insert an item into the database
void insertItem(char* name, int quantity) {
    // Allocate memory for a new item
    Item* newNode = (Item*)malloc(sizeof(Item));

    // Copy the item name and quantity
    strcpy(newNode->name, name);
    newNode->quantity = quantity;

    // If the database is empty, make the new item the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Traverse the database to the last item
        Item* lastItem = head;
        while (lastItem->next) {
            lastItem = lastItem->next;
        }

        // Insert the new item after the last item
        lastItem->next = newNode;
    }
}

// Function to search for an item in the database
Item* searchItem(char* name) {
    // Traverse the database to find the item
    Item* item = head;
    while (item) {
        if (strcmp(item->name, name) == 0) {
            return item;
        }
        item = item->next;
    }

    // Item not found
    return NULL;
}

// Function to remove an item from the database
void removeItem(char* name) {
    // Find the item to remove
    Item* itemToDelete = searchItem(name);

    // If the item is found, remove it from the database
    if (itemToDelete) {
        // If the item is the head of the database, update the head
        if (itemToDelete == head) {
            head = itemToDelete->next;
        } else {
            // Traverse the database to find the item before the item to remove
            Item* prevItem = head;
            while (prevItem->next != itemToDelete) {
                prevItem = prevItem->next;
            }

            // Remove the item from the database
            prevItem->next = itemToDelete->next;
        }

        // Free the memory of the item
        free(itemToDelete);
    }
}

// Main function
int main() {
    // Insert items into the database
    insertItem("Water", 10);
    insertItem("Food", 5);
    insertItem("Weapons", 2);

    // Search for an item in the database
    Item* item = searchItem("Food");
    if (item) {
        printf("Item name: %s, Quantity: %d\n", item->name, item->quantity);
    }

    // Remove an item from the database
    removeItem("Weapons");

    // Search for the item after removal
    item = searchItem("Weapons");
    if (item) {
        printf("Item name: %s, Quantity: %d\n", item->name, item->quantity);
    } else {
        printf("Item not found\n");
    }

    return 0;
}