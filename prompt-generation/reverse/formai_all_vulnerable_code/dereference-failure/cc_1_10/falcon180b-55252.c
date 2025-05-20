//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 100

// Node structure for linked list implementation
typedef struct node {
    int item_id;
    char item_name[50];
    int quantity;
    struct node* next;
} Node;

// Function to add an item to the warehouse
void add_item(Node** head, int item_id, char item_name[], int quantity) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    new_node->item_id = item_id;
    strcpy(new_node->item_name, item_name);
    new_node->quantity = quantity;
    new_node->next = *head;
    *head = new_node;

    printf("Item added to the warehouse: %s (%d units)\n", item_name, quantity);
}

// Function to remove an item from the warehouse
void remove_item(Node** head, int item_id) {
    Node* curr_node = *head;
    Node* prev_node = NULL;

    while (curr_node!= NULL && curr_node->item_id!= item_id) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    if (curr_node == NULL) {
        printf("Item not found in the warehouse.\n");
        return;
    }

    if (prev_node == NULL) {
        *head = curr_node->next;
    } else {
        prev_node->next = curr_node->next;
    }

    printf("Item removed from the warehouse: %d\n", item_id);
    free(curr_node);
}

// Function to display the contents of the warehouse
void display_warehouse(Node* head) {
    printf("Warehouse contents:\n");
    while (head!= NULL) {
        printf("Item ID: %d, Name: %s, Quantity: %d\n", head->item_id, head->item_name, head->quantity);
        head = head->next;
    }
}

// Main function
int main() {
    Node* warehouse = NULL;

    // Add some items to the warehouse
    add_item(&warehouse, 1, "Apples", 100);
    add_item(&warehouse, 2, "Oranges", 200);
    add_item(&warehouse, 3, "Bananas", 300);

    // Display the contents of the warehouse
    display_warehouse(warehouse);

    // Remove an item from the warehouse
    remove_item(&warehouse, 2);

    // Display the updated contents of the warehouse
    display_warehouse(warehouse);

    return 0;
}