//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store warehouse item information
struct Item {
    char name[20];
    int quantity;
    float price;
    struct Item* next;
};

// Function to insert an item into the warehouse
void insertItem(struct Item* head, char* name, int quantity, float price) {
    struct Item* newNode = (struct Item*)malloc(sizeof(struct Item));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->price = price;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Item* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for an item in the warehouse
struct Item* searchItem(struct Item* head, char* name) {
    struct Item* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to update the quantity of an item in the warehouse
void updateQuantity(struct Item* head, char* name, int newQuantity) {
    struct Item* item = searchItem(head, name);
    if (item) {
        item->quantity = newQuantity;
    }
}

// Function to delete an item from the warehouse
void deleteItem(struct Item* head, char* name) {
    struct Item* item = searchItem(head, name);
    if (item) {
        struct Item* prev = NULL;
        struct Item* temp = head;
        while (temp) {
            if (item == temp) {
                if (prev) {
                    prev->next = item->next;
                } else {
                    head = item->next;
                }
                free(item);
                item = NULL;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
    }
}

int main() {
    struct Item* head = NULL;

    // Insert some items into the warehouse
    insertItem(head, "Apple", 10, 1.20);
    insertItem(head, "Orange", 20, 1.50);
    insertItem(head, "Banana", 30, 1.80);

    // Search for an item in the warehouse
    struct Item* item = searchItem(head, "Orange");
    if (item) {
        printf("Item name: %s\n", item->name);
        printf("Item quantity: %d\n", item->quantity);
        printf("Item price: %.2f\n", item->price);
    }

    // Update the quantity of an item in the warehouse
    updateQuantity(head, "Apple", 20);

    // Search for the updated item in the warehouse
    item = searchItem(head, "Apple");
    if (item) {
        printf("Updated item name: %s\n", item->name);
        printf("Updated item quantity: %d\n", item->quantity);
    }

    // Delete an item from the warehouse
    deleteItem(head, "Banana");

    // Search for the deleted item in the warehouse
    item = searchItem(head, "Banana");
    if (item) {
        printf("Error: Item not found.\n");
    } else {
        printf("Item deleted successfully.\n");
    }

    return 0;
}