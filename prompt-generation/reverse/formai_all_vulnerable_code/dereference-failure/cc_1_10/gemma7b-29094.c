//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store warehouse item information
typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

// Create a linked list to store warehouse items
typedef struct Node {
    Item item;
    struct Node* next;
} Node;

// Function to insert an item into the linked list
void insertItem(Node** head, Item item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
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
    // Create a linked list to store warehouse items
    Node* head = NULL;

    // Insert some items into the list
    Item item1 = {"Item 1", 10, 20.0};
    insertItem(&head, item1);

    Item item2 = {"Item 2", 20, 30.0};
    insertItem(&head, item2);

    Item item3 = {"Item 3", 30, 40.0};
    insertItem(&head, item3);

    // Search for an item in the list
    Item* item = searchItem(head, "Item 2");

    // Print the item information
    if (item) {
        printf("Name: %s\n", item->name);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
    } else {
        printf("Item not found.\n");
    }

    return 0;
}