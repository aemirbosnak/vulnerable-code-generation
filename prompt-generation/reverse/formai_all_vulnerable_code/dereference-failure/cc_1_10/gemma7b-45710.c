//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: calm
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
    item item_data;
    struct node* next;
} node;

// Function to insert an item into the linked list
void insert(node** head, item item) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->item_data = item;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

// Function to search for an item in the linked list
node* search(node* head, char* name) {
    while (head) {
        if (strcmp(head->item_data.name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of an item in the linked list
void update(node* head, char* name, int new_quantity) {
    node* item = search(head, name);

    if (item) {
        item->item_data.quantity = new_quantity;
    }
}

// Function to delete an item from the linked list
void delete(node* head, char* name) {
    node* item = search(head, name);

    if (item) {
        node* prev = NULL;
        node* current = head;

        while (current) {
            if (strcmp(current->item_data.name, name) == 0) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                free(current);
                current = NULL;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
}

int main() {
    // Create a linked list to store medical store items
    node* head = NULL;

    // Insert some items into the linked list
    item item1 = {"Panadol", 10, 20.0};
    insert(&head, item1);

    item item2 = {"Paracetamol", 5, 15.0};
    insert(&head, item2);

    item item3 = {"Ibuprofen", 7, 25.0};
    insert(&head, item3);

    // Search for an item in the linked list
    node* item = search(head, "Panadol");

    if (item) {
        printf("Name: %s\n", item->item_data.name);
        printf("Quantity: %d\n", item->item_data.quantity);
        printf("Price: %.2f\n", item->item_data.price);
    }

    // Update the quantity of an item in the linked list
    update(head, "Paracetamol", 12);

    item = search(head, "Paracetamol");

    if (item) {
        printf("Name: %s\n", item->item_data.name);
        printf("Quantity: %d\n", item->item_data.quantity);
        printf("Price: %.2f\n", item->item_data.price);
    }

    // Delete an item from the linked list
    delete(head, "Ibuprofen");

    item = search(head, "Ibuprofen");

    if (item) {
        printf("Name: %s\n", item->item_data.name);
        printf("Quantity: %d\n", item->item_data.quantity);
        printf("Price: %.2f\n", item->item_data.price);
    }

    return 0;
}