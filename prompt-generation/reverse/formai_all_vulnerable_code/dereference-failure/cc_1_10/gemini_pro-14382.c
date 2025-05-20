//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Node for the linked list
typedef struct node {
    char* name;
    int quantity;
    struct node* next;
} node;

// Global variables
node* head = NULL;
node* tail = NULL;
int num_products = 0;

// Function to add a product to the inventory
void add_product(char* name, int quantity) {
    // Create a new node
    node* new_node = (node*)malloc(sizeof(node));
    new_node->name = strdup(name);
    new_node->quantity = quantity;
    new_node->next = NULL;

    // If the inventory is empty, set the head and tail to the new node
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        // Add the new node to the end of the linked list
        tail->next = new_node;
        tail = new_node;
    }

    // Increment the number of products in the inventory
    num_products++;
}

// Function to remove a product from the inventory
void remove_product(char* name) {
    // Find the node with the given name
    node* current_node = head;
    while (current_node != NULL) {
        if (strcmp(current_node->name, name) == 0) {
            break;
        }
        current_node = current_node->next;
    }

    // If the node was not found, return
    if (current_node == NULL) {
        return;
    }

    // If the node is the head, set the head to the next node
    if (current_node == head) {
        head = current_node->next;
    }
    // If the node is the tail, set the tail to the previous node
    else if (current_node == tail) {
        tail = current_node->next;
    }
    // Otherwise, set the previous node's next pointer to the next node
    else {
        node* previous_node = head;
        while (previous_node->next != current_node) {
            previous_node = previous_node->next;
        }
        previous_node->next = current_node->next;
    }

    // Free the node
    free(current_node->name);
    free(current_node);

    // Decrement the number of products in the inventory
    num_products--;
}

// Function to print the inventory
void print_inventory() {
    // Iterate over the linked list and print each product
    node* current_node = head;
    while (current_node != NULL) {
        printf("%s: %d\n", current_node->name, current_node->quantity);
        current_node = current_node->next;
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Add some products to the inventory
    add_product("Apple", 10);
    add_product("Banana", 15);
    add_product("Orange", 20);
    add_product("Grape", 25);
    add_product("Strawberry", 30);

    // Print the inventory
    printf("Inventory:\n");
    print_inventory();

    // Remove a product from the inventory
    remove_product("Apple");

    // Print the inventory again
    printf("\nInventory after removing Apple:\n");
    print_inventory();

    return 0;
}