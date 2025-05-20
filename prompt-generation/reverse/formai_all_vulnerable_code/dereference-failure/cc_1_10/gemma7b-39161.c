//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store warehouse item information
typedef struct Item {
    char item_name[50];
    int quantity;
    float price;
    struct Item* next;
} Item;

// Function to insert an item into the warehouse
void insertItem(Item** head) {
    Item* newNode = (Item*)malloc(sizeof(Item));

    printf("Enter item name: ");
    scanf("%s", newNode->item_name);

    printf("Enter quantity: ");
    scanf("%d", &newNode->quantity);

    printf("Enter price: ");
    scanf("%f", &newNode->price);

    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to search for an item in the warehouse
Item* searchItem(Item* head, char* item_name) {
    while (head) {
        if (strcmp(item_name, head->item_name) == 0) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

// Function to update the quantity of an item in the warehouse
void updateQuantity(Item* head, char* item_name, int new_quantity) {
    Item* item = searchItem(head, item_name);

    if (item) {
        item->quantity = new_quantity;
    }
}

// Function to delete an item from the warehouse
void deleteItem(Item* head, char* item_name) {
    Item* item = searchItem(head, item_name);

    if (item) {
        Item* prevItem = NULL;

        // If the item is the first item in the list, update the head of the list
        if (prevItem == NULL) {
            head = item->next;
        } else {
            prevItem->next = item->next;
        }

        free(item);
    }
}

// Main function
int main() {
    Item* head = NULL;

    // Insert some items into the warehouse
    insertItem(&head);
    insertItem(&head);
    insertItem(&head);

    // Search for an item in the warehouse
    Item* item = searchItem(head, "Item 2");

    // Update the quantity of an item in the warehouse
    updateQuantity(head, "Item 1", 10);

    // Delete an item from the warehouse
    deleteItem(head, "Item 3");

    // Print the items in the warehouse
    for (item = head; item; item = item->next) {
        printf("%s: %d, $%.2f\n", item->item_name, item->quantity, item->price);
    }

    return 0;
}