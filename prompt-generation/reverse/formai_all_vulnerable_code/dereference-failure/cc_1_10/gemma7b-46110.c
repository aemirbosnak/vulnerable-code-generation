//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store inventory items
typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

// Define a linked list to store inventory items
typedef struct Node {
    Item item;
    struct Node* next;
} Node;

// Create a function to insert a new item into the linked list
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

// Create a function to search for an item in the linked list
Item* searchItem(Node* head, char* name) {
    while (head) {
        if (strcmp(head->item.name, name) == 0) {
            return &head->item;
        }
        head = head->next;
    }
    return NULL;
}

// Create a function to update the quantity of an item in the linked list
void updateQuantity(Node* head, char* name, int quantity) {
    Item* item = searchItem(head, name);
    if (item) {
        item->quantity = quantity;
    }
}

// Create a function to remove an item from the linked list
void removeItem(Node* head, char* name) {
    Item* item = searchItem(head, name);
    if (item) {
        Node* previous = NULL;
        Node* current = head;
        while (current) {
            if (strcmp(current->item.name, name) == 0) {
                if (previous) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                free(current);
                return;
            }
            previous = current;
            current = current->next;
        }
    }
    return;
}

int main() {
    // Create a linked list to store inventory items
    Node* head = NULL;

    // Create some inventory items
    Item item1 = {"Item 1", 10, 10.0};
    Item item2 = {"Item 2", 5, 20.0};
    Item item3 = {"Item 3", 7, 30.0};

    // Insert the items into the linked list
    insertItem(head, item1);
    insertItem(head, item2);
    insertItem(head, item3);

    // Search for an item
    Item* item = searchItem(head, "Item 2");
    if (item) {
        printf("Item: %s, Quantity: %d, Price: %.2f\n", item->name, item->quantity, item->price);
    }

    // Update the quantity of an item
    updateQuantity(head, "Item 1", 15);
    item = searchItem(head, "Item 1");
    if (item) {
        printf("Item: %s, Quantity: %d, Price: %.2f\n", item->name, item->quantity, item->price);
    }

    // Remove an item
    removeItem(head, "Item 3");
    item = searchItem(head, "Item 3");
    if (item) {
        printf("Item: %s, Quantity: %d, Price: %.2f\n", item->name, item->quantity, item->price);
    }

    return 0;
}