//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store warehouse item information
typedef struct item {
    char name[20];
    int quantity;
    float price;
} item_t;

// Create a linked list to store warehouse items
typedef struct node {
    item_t item;
    struct node* next;
} node_t;

// Function to insert a new item into the linked list
void insert_item(node_t** head, item_t item) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->item = item;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

// Function to search for an item in the linked list
node_t* search_item(node_t* head, char* item_name) {
    while (head) {
        if (strcmp(head->item.name, item_name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of an item in the linked list
void update_item_quantity(node_t* head, char* item_name, int new_quantity) {
    node_t* item = search_item(head, item_name);

    if (item) {
        item->item.quantity = new_quantity;
    }
}

// Function to remove an item from the linked list
void remove_item(node_t** head, char* item_name) {
    node_t* item = search_item(head, item_name);

    if (item) {
        node_t* prev = NULL;

        if (item == *head) {
            *head = item->next;
        } else {
            prev = item->next;
            prev->next = item->next;
        }

        free(item);
    }
}

int main() {
    node_t* head = NULL;

    item_t item1 = {"Item 1", 10, 10.0};
    insert_item(&head, item1);

    item_t item2 = {"Item 2", 20, 20.0};
    insert_item(&head, item2);

    item_t item3 = {"Item 3", 30, 30.0};
    insert_item(&head, item3);

    update_item_quantity(head, "Item 2", 30);

    remove_item(&head, "Item 3");

    node_t* item = search_item(head, "Item 1");

    if (item) {
        printf("Item name: %s\n", item->item.name);
        printf("Item quantity: %d\n", item->item.quantity);
        printf("Item price: %f\n", item->item.price);
    }

    return 0;
}