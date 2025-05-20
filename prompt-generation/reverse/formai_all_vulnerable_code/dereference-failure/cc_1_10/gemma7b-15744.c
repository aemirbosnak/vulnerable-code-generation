//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store warehouse item information
typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

// Define a linked list to store warehouse items
typedef struct Node {
    Item item;
    struct Node* next;
} Node;

// Create a linked list of items
Node* head = NULL;

// Function to add an item to the linked list
void addItem(Item item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for an item in the linked list
Item* searchItem(char* name) {
    Node* temp = head;
    while (temp) {
        if (strcmp(temp->item.name, name) == 0) {
            return &temp->item;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to update the quantity of an item
void updateQuantity(char* name, int quantity) {
    Item* item = searchItem(name);
    if (item) {
        item->quantity = quantity;
    }
}

// Function to remove an item from the linked list
void removeItem(char* name) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp) {
        if (strcmp(temp->item.name, name) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    return;
}

int main() {
    Item item1 = {"Item 1", 10, 10.0};
    addItem(item1);

    Item item2 = {"Item 2", 5, 20.0};
    addItem(item2);

    Item item3 = {"Item 3", 7, 30.0};
    addItem(item3);

    updateQuantity("Item 2", 12);

    removeItem("Item 3");

    Node* temp = head;
    while (temp) {
        printf("%s, %d, %f\n", temp->item.name, temp->item.quantity, temp->item.price);
        temp = temp->next;
    }

    return 0;
}