//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medical store items
struct item {
    char name[50];
    int quantity;
    float price;
    struct item* next;
};

// Define a function to insert a new item into the linked list
void insertItem(struct item** head, char name, int quantity, float price) {
    struct item* newNode = (struct item*)malloc(sizeof(struct item));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->price = price;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Define a function to search for an item in the linked list
struct item* searchItem(struct item* head, char name) {
    struct item* currentItem = head;

    while (currentItem) {
        if (strcmp(currentItem->name, name) == 0) {
            return currentItem;
        }
        currentItem = currentItem->next;
    }

    return NULL;
}

int main() {
    struct item* head = NULL;

    // Insert some items into the linked list
    insertItem(&head, "Acetaminophen", 100, 5.0);
    insertItem(&head, "Ibuprofen", 50, 6.0);
    insertItem(&head, "Tylenol", 75, 4.5);

    // Search for an item in the linked list
    struct item* item = searchItem(head, "Tylenol");

    // Print the item information
    if (item) {
        printf("Name: %s\n", item->name);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
    } else {
        printf("Item not found.\n");
    }

    return 0;
}