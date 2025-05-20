//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is a Warehouse Management System (WMS) program.
// It allows a warehouse to track inventory and shipping orders.

// Define a data structure for inventory items
struct InventoryItem {
    char name[50];
    int quantity;
    double price;
};

// Define a data structure for orders
struct Order {
    char customerName[50];
    char itemName[50];
    int quantity;
};

// Define a data structure for a linked list node
struct Node {
    struct InventoryItem item;
    struct Node* next;
};

// Define a function to print the contents of an inventory item
void printItem(struct InventoryItem item) {
    printf("%s: %d at $%.2f each\n", item.name, item.quantity, item.price);
}

// Define a function to print the contents of an order
void printOrder(struct Order order) {
    printf("Order for %d of %s for %s\n", order.quantity, order.itemName, order.customerName);
}

// Define a function to add an item to the inventory list
void addItem(struct Node** inventoryList, struct InventoryItem item) {
    // Create a new node for the item
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item = item;
    newNode->next = NULL;

    // If the list is empty, set the head to the new node
    if (*inventoryList == NULL) {
        *inventoryList = newNode;
    } else {
        // Otherwise, find the last node in the list and add the new node
        struct Node* curr = *inventoryList;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// Define a function to remove an item from the inventory list
void removeItem(struct Node** inventoryList, char* itemName) {
    struct Node* curr = *inventoryList;
    struct Node* prev = NULL;

    // Find the node with the matching item name, if it exists
    while (curr != NULL) {
        if (strcmp(curr->item.name, itemName) == 0) {
            // If this is the first node, update the head pointer
            if (prev == NULL) {
                *inventoryList = curr->next;
            } else {
                // Otherwise, update the previous node's next pointer
                prev->next = curr->next;
            }
            // Free the memory for the removed node
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Define a function to find an inventory item by name
struct InventoryItem* findItem(struct Node* inventoryList, char* itemName) {
    struct Node* curr = inventoryList;
    while (curr != NULL) {
        if (strcmp(curr->item.name, itemName) == 0) {
            return &(curr->item);
        }
        curr = curr->next;
    }
    // If the item is not found, return NULL
    return NULL;
}

// Define a function to process an order
void processOrder(struct Node** inventoryList, struct Order order) {
    // Find the item in the inventory
    struct InventoryItem* item = findItem(*inventoryList, order.itemName);

    // If the item is not found, print an error message and return
    if (item == NULL) {
        printf("Error: item not found in inventory\n");
        return;
    }

    // If there are not enough items in inventory, print an error message and return
    if (item->quantity < order.quantity) {
        printf("Error: not enough items in inventory\n");
        return;
    }

    // Update the item quantity in inventory
    item->quantity -= order.quantity;

    // Print a message indicating the order has been shipped
    printf("Order shipped: %d of %s for %s\n", order.quantity, order.itemName, order.customerName);
}

// Define a function to print the complete inventory
void printInventory(struct Node* inventoryList) {
    printf("Inventory:\n");
    struct Node* curr = inventoryList;
    while (curr != NULL) {
        printItem(curr->item);
        curr = curr->next;
    }
}

int main() {
    struct Node* inventoryList = NULL;

    // Add some items to the inventory
    struct InventoryItem item1 = {.name = "Widget", .quantity = 10, .price = 2.99};
    struct InventoryItem item2 = {.name = "Gizmo", .quantity = 5, .price = 3.99};
    addItem(&inventoryList, item1);
    addItem(&inventoryList, item2);

    // Print the initial inventory
    printInventory(inventoryList);

    // Process some orders
    struct Order order1 = {.customerName = "Alice", .itemName = "Widget", .quantity = 2};
    struct Order order2 = {.customerName = "Bob", .itemName = "Gizmo", .quantity = 1};
    processOrder(&inventoryList, order1);
    processOrder(&inventoryList, order2);

    // Print the updated inventory
    printInventory(inventoryList);

    // Remove an item from the inventory
    removeItem(&inventoryList, "Widget");

    // Print the updated inventory
    printInventory(inventoryList);

    return 0;
}