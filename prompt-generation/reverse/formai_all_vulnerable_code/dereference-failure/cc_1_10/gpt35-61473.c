//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for items in warehouse
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

// Define struct for nodes in linked list
typedef struct Node {
    Item item;
    struct Node* next;
} Node;

// Declare global variable for warehouse inventory
Node* inventory = NULL;

// Define function to add item to warehouse inventory
void addItem(char name[50], int quantity, float price) {
    // Allocate memory for new node
    Node* newNode = (Node*) malloc(sizeof(Node));
    
    // Set item values
    strcpy(newNode->item.name, name);
    newNode->item.quantity = quantity;
    newNode->item.price = price;
    
    // Set next to NULL for first node added
    newNode->next = NULL;
    
    // If inventory not empty, add new node to end
    if (inventory != NULL) {
        Node* current = inventory;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    } 
    // Else, set inventory to new node
    else {
        inventory = newNode;
    }
}

// Define function to remove item from warehouse inventory
void removeItem(char name[50]) {
    // If inventory is empty, return
    if (inventory == NULL) {
        return;
    }
    
    // If first node is item to remove, remove first node
    if (strcmp(inventory->item.name, name) == 0) {
        Node* temp = inventory;
        inventory = inventory->next;
        free(temp);
        return;
    }
    
    // If item to remove is not in first node, iterate through inventory
    Node* current = inventory;
    while (current->next != NULL) {
        if (strcmp(current->next->item.name, name) == 0) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

// Define function to display all items in inventory
void displayInventory() {
    // If inventory is empty, print message and return
    if (inventory == NULL) {
        printf("Inventory is empty.\n");
        return;
    }
    
    // Iterate through inventory and print each item's details
    Node* current = inventory;
    while (current != NULL) {
        printf("Name: %s\n", current->item.name);
        printf("Quantity: %d\n", current->item.quantity);
        printf("Price: $%.2f\n", current->item.price);
        printf("--------------------\n");
        current = current->next;
    }
}

int main() {
    // Add initial items to inventory
    addItem("Box of pens", 50, 7.99);
    addItem("Laptop", 10, 899.99);
    addItem("Printer", 5, 249.99);
    
    // Print initial inventory
    printf("Initial inventory:\n");
    displayInventory();
    
    // Remove printer and add new item to inventory
    removeItem("Printer");
    addItem("Paper", 100, 12.99);
    
    // Print updated inventory
    printf("Updated inventory:\n");
    displayInventory();
    
    return 0;
}