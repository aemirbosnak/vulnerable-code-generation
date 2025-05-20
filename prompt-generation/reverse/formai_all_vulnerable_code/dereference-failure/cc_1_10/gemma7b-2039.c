//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medical store items
typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

// Create a linked list of medical store items
typedef struct Node {
    Item item;
    struct Node* next;
} Node;

// Function to insert a new item into the linked list
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
void removeItem(Node* head, char* name) {
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

    return;
}

int main() {
    // Create a linked list of medical store items
    Node* head = NULL;

    // Insert some items into the linked list
    Item item1 = {"Paracetamol", 100, 20.0};
    insertItem(&head, item1);

    Item item2 = {"Ibuprofen", 50, 15.0};
    insertItem(&head, item2);

    Item item3 = {"Acetaminophen", 20, 12.0};
    insertItem(&head, item3);

    // Search for an item in the linked list
    Item* item = searchItem(head, "Paracetamol");

    if (item) {
        printf("Item name: %s\n", item->name);
        printf("Item quantity: %d\n", item->quantity);
        printf("Item price: %.2f\n", item->price);
    }

    // Update the quantity of an item in the linked list
    updateQuantity(head, "Ibuprofen", 75);

    item = searchItem(head, "Ibuprofen");

    if (item) {
        printf("Item name: %s\n", item->name);
        printf("Item quantity: %d\n", item->quantity);
        printf("Item price: %.2f\n", item->price);
    }

    // Remove an item from the linked list
    removeItem(head, "Acetaminophen");

    item = searchItem(head, "Acetaminophen");

    if (item) {
        printf("Item name: %s\n", item->name);
        printf("Item quantity: %d\n", item->quantity);
        printf("Item price: %.2f\n", item->price);
    }

    return 0;
}