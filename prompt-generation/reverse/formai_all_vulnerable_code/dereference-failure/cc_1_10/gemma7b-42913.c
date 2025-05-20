//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: introspective
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
struct Node {
    Item item;
    struct Node* next;
};

// Function to insert a new item into the linked list
void insertItem(struct Node** head, Item item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item = item;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to search for an item in the linked list
struct Node* searchItem(struct Node* head, char* name) {
    while (head) {
        if (strcmp(head->item.name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

int main() {
    // Create a linked list of medical store items
    struct Node* head = NULL;

    // Insert some items into the linked list
    Item item1 = {"Paracetamol", 100, 20.0};
    insertItem(&head, item1);

    Item item2 = {"Ibuprofen", 50, 15.0};
    insertItem(&head, item2);

    Item item3 = {"Acetaminophen", 75, 12.0};
    insertItem(&head, item3);

    // Search for an item in the linked list
    struct Node* itemNode = searchItem(head, "Paracetamol");

    // Print the item information
    if (itemNode) {
        printf("Name: %s\n", itemNode->item.name);
        printf("Quantity: %d\n", itemNode->item.quantity);
        printf("Price: %.2f\n", itemNode->item.price);
    } else {
        printf("Item not found\n");
    }

    return 0;
}