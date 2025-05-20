//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a medical store item
typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

// Create a linked list of items
typedef struct Node {
    Item item;
    struct Node* next;
} Node;

// Function to insert an item into the linked list
void insertItem(Node** head, Item item) {
    Node* newNode = malloc(sizeof(Node));
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

// Function to update the quantity of an item in the linked list
void updateQuantity(Node* head, char* name, int quantity) {
    Item* item = searchItem(head, name);
    if (item) {
        item->quantity = quantity;
    }
}

// Function to remove an item from the linked list
void removeItem(Node** head, char* name) {
    Node* previousNode = NULL;
    Node* currentNode = *head;

    while (currentNode) {
        if (strcmp(currentNode->item.name, name) == 0) {
            if (previousNode) {
                previousNode->next = currentNode->next;
            } else {
                *head = currentNode->next;
            }
            free(currentNode);
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    return;
}

int main() {
    Node* head = NULL;

    // Create some items
    Item item1 = {"Paracetamol", 10, 20.0};
    Item item2 = {"Ibuprofen", 5, 15.0};
    Item item3 = {"Acetaminophen", 7, 12.0};

    // Insert items into the linked list
    insertItem(&head, item1);
    insertItem(&head, item2);
    insertItem(&head, item3);

    // Search for an item
    Item* item = searchItem(head, "Paracetamol");
    if (item) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", item->name, item->quantity, item->price);
    }

    // Update the quantity of an item
    updateQuantity(head, "Ibuprofen", 12);
    item = searchItem(head, "Ibuprofen");
    if (item) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", item->name, item->quantity, item->price);
    }

    // Remove an item
    removeItem(&head, "Acetaminophen");
    item = searchItem(head, "Acetaminophen");
    if (item) {
        printf("Error: item not found.\n");
    }

    return 0;
}