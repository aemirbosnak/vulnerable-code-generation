//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the linked list representing a product
struct product_node {
    char *name;
    int quantity;
    struct product_node *next;
};

// The head of the linked list of products
struct product_node *head = NULL;

// Add a new product to the inventory
void add_product(char *name, int quantity) {
    // Create a new product node
    struct product_node *new_node = malloc(sizeof(struct product_node));
    new_node->name = strdup(name);
    new_node->quantity = quantity;
    new_node->next = NULL;

    // Add the new node to the end of the linked list
    if (head == NULL) {
        head = new_node;
    } else {
        struct product_node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Remove a product from the inventory
void remove_product(char *name) {
    // Find the product node to remove
    struct product_node *current_node = head;
    struct product_node *previous_node = NULL;
    while (current_node != NULL && strcmp(current_node->name, name) != 0) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    // If the product node was found, remove it from the linked list
    if (current_node != NULL) {
        if (previous_node == NULL) {
            head = current_node->next;
        } else {
            previous_node->next = current_node->next;
        }
        free(current_node->name);
        free(current_node);
    }
}

// Get the quantity of a product in the inventory
int get_product_quantity(char *name) {
    // Find the product node
    struct product_node *current_node = head;
    while (current_node != NULL && strcmp(current_node->name, name) != 0) {
        current_node = current_node->next;
    }

    // If the product node was found, return its quantity
    if (current_node != NULL) {
        return current_node->quantity;
    } else {
        return 0;
    }
}

// Print the inventory to the console
void print_inventory() {
    struct product_node *current_node = head;
    while (current_node != NULL) {
        printf("%s: %d\n", current_node->name, current_node->quantity);
        current_node = current_node->next;
    }
}

// Free the memory allocated for the inventory
void free_inventory() {
    struct product_node *current_node = head;
    while (current_node != NULL) {
        struct product_node *next_node = current_node->next;
        free(current_node->name);
        free(current_node);
        current_node = next_node;
    }
    head = NULL;
}

// Main function
int main() {
    // Add some products to the inventory
    add_product("Apple", 10);
    add_product("Orange", 5);
    add_product("Banana", 15);

    // Print the inventory
    printf("Initial inventory:\n");
    print_inventory();

    // Remove a product from the inventory
    remove_product("Orange");

    // Print the inventory
    printf("\nInventory after removing Orange:\n");
    print_inventory();

    // Get the quantity of a product in the inventory
    int apple_quantity = get_product_quantity("Apple");
    printf("\nQuantity of Apple in the inventory: %d\n", apple_quantity);

    // Free the memory allocated for the inventory
    free_inventory();

    return 0;
}