//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medical store items
typedef struct Item {
    char name[50];
    int quantity;
    double price;
} Item;

// Create a linked list of medical store items
typedef struct Node {
    Item item;
    struct Node* next;
} Node;

// Function to insert a new item into the linked list
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
Node* searchItem(Node* head, char* name) {
    while (head) {
        if (strcmp(head->item.name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of an item in the linked list
void updateQuantity(Node* head, char* name, int quantity) {
    Node* item = searchItem(head, name);

    if (item) {
        item->item.quantity = quantity;
    }
}

// Function to calculate the total cost of an item
double calculateTotalCost(Node* head, char* name) {
    Node* item = searchItem(head, name);

    if (item) {
        return item->item.quantity * item->item.price;
    }

    return 0;
}

// Main function
int main() {
    // Create a linked list of medical store items
    Node* head = NULL;

    // Insert some items into the linked list
    Item item1 = {"Paracetamol", 10, 2.5};
    insertItem(&head, item1);

    Item item2 = {"Ibuprofen", 5, 3.0};
    insertItem(&head, item2);

    Item item3 = {"Acetaminophen", 7, 2.0};
    insertItem(&head, item3);

    // Search for an item in the linked list
    Node* item = searchItem(head, "Paracetamol");

    // If the item is found, update its quantity
    if (item) {
        updateQuantity(head, "Paracetamol", 15);
    }

    // Calculate the total cost of an item
    double totalCost = calculateTotalCost(head, "Ibuprofen");

    // Print the total cost
    printf("Total cost of Ibuprofen: %.2lf", totalCost);

    return 0;
}