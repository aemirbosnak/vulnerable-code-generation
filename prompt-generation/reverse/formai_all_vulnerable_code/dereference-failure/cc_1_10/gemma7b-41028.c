//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medical store items
typedef struct item {
    char name[50];
    int quantity;
    float price;
} item;

// Create a linked list to store medical store items
typedef struct node {
    item data;
    struct node* next;
} node;

// Insert an item into the linked list
void insert(node** head, item item) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = item;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Search for an item in the linked list
item* search(node* head, char* name) {
    while (head) {
        if (strcmp(head->data.name, name) == 0) {
            return &head->data;
        }
        head = head->next;
    }
    return NULL;
}

// Update the quantity of an item in the linked list
void updateQuantity(node* head, char* name, int quantity) {
    item* item = search(head, name);
    if (item) {
        item->quantity = quantity;
    }
}

// Delete an item from the linked list
void deleteItem(node** head, char* name) {
    node* prev = NULL;
    node* current = *head;

    while (current) {
        if (strcmp(current->data.name, name) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                *head = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    return;
}

// Main function
int main() {
    node* head = NULL;

    // Create a few items
    item item1 = {"Paracetamol", 100, 20.0};
    insert(&head, item1);

    item item2 = {"Ibuprofen", 50, 15.0};
    insert(&head, item2);

    item item3 = {"Cough Syrup", 20, 12.0};
    insert(&head, item3);

    // Search for an item
    item* item = search(head, "Paracetamol");
    if (item) {
        printf("Name: %s\n", item->name);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %f\n", item->price);
    }

    // Update the quantity of an item
    updateQuantity(head, "Ibuprofen", 75);
    item = search(head, "Ibuprofen");
    if (item) {
        printf("Name: %s\n", item->name);
        printf("Quantity: %d\n", item->quantity);
    }

    // Delete an item
    deleteItem(&head, "Cough Syrup");
    item = search(head, "Cough Syrup");
    if (item) {
        printf("Item not found\n");
    }

    return 0;
}