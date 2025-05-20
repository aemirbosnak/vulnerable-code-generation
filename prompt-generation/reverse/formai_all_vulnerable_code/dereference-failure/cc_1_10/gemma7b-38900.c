//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct Item {
    char name[20];
    int quantity;
    double price;
} Item;

// Create a linked list of items
typedef struct Node {
    Item item;
    struct Node* next;
} Node;

// Function to insert an item into the linked list
void insertItem(Node* head, Item item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Function to search for an item in the linked list
Item* searchItem(Node* head, char* name) {
    while (head) {
        if (strcmp(head->item.name, name) == 0) {
            return &head->item;
        }
        head = head->next;
    }

    return NULL;
}

int main() {
    // Create a linked list of items
    Node* head = NULL;

    // Insert some items into the linked list
    Item item1 = {"Item 1", 10, 10.0};
    insertItem(head, item1);

    Item item2 = {"Item 2", 5, 20.0};
    insertItem(head, item2);

    Item item3 = {"Item 3", 7, 30.0};
    insertItem(head, item3);

    // Search for an item in the linked list
    Item* item = searchItem(head, "Item 2");

    // If the item is found, print its name and quantity
    if (item) {
        printf("Name: %s, Quantity: %d", item->name, item->quantity);
    } else {
        printf("Item not found");
    }

    return 0;
}