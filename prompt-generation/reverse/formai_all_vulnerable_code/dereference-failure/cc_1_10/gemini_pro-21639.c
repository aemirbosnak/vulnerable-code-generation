//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Alan Turing
/*
 * Alan Turing's Automated Product Inventory System
 *
 * This program simulates a simple product inventory system using a linked list data structure.
 * The system allows users to add, remove, and search for products in the inventory.
 *
 * The program is written in a style reminiscent of Alan Turing's early work on computing machines.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a product node.
struct product_node {
    int product_id;
    char *product_name;
    int product_quantity;
    struct product_node *next;
};

// Define the head of the linked list.
struct product_node *head = NULL;

// Add a product to the inventory.
void add_product(int product_id, char *product_name, int product_quantity) {
    // Create a new product node.
    struct product_node *new_node = malloc(sizeof(struct product_node));

    // Set the product ID, name, and quantity.
    new_node->product_id = product_id;
    new_node->product_name = product_name;
    new_node->product_quantity = product_quantity;

    // Set the next pointer to NULL.
    new_node->next = NULL;

    // If the inventory is empty, set the head to the new node.
    if (head == NULL) {
        head = new_node;
    } else {
        // Otherwise, append the new node to the end of the list.
        struct product_node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Remove a product from the inventory.
void remove_product(int product_id) {
    // If the inventory is empty, do nothing.
    if (head == NULL) {
        return;
    }

    // If the product is the first in the list, set the head to the next node.
    if (head->product_id == product_id) {
        head = head->next;
    } else {
        // Otherwise, search for the product in the list.
        struct product_node *current_node = head;
        while (current_node->next != NULL) {
            if (current_node->next->product_id == product_id) {
                // If the product is found, remove it from the list.
                current_node->next = current_node->next->next;
                break;
            }
            current_node = current_node->next;
        }
    }
}

// Search for a product in the inventory.
struct product_node *search_product(int product_id) {
    // If the inventory is empty, return NULL.
    if (head == NULL) {
        return NULL;
    }

    // Search for the product in the list.
    struct product_node *current_node = head;
    while (current_node != NULL) {
        if (current_node->product_id == product_id) {
            // If the product is found, return it.
            return current_node;
        }
        current_node = current_node->next;
    }

    // If the product is not found, return NULL.
    return NULL;
}

// Print the inventory.
void print_inventory() {
    // If the inventory is empty, do nothing.
    if (head == NULL) {
        return;
    }

    // Print the products in the list.
    struct product_node *current_node = head;
    while (current_node != NULL) {
        printf("Product ID: %d\n", current_node->product_id);
        printf("Product Name: %s\n", current_node->product_name);
        printf("Product Quantity: %d\n", current_node->product_quantity);
        printf("\n");
        current_node = current_node->next;
    }
}

// Get the number of products in the inventory.
int get_inventory_count() {
    // If the inventory is empty, return 0.
    if (head == NULL) {
        return 0;
    }

    // Count the number of products in the list.
    int count = 0;
    struct product_node *current_node = head;
    while (current_node != NULL) {
        count++;
        current_node = current_node->next;
    }

    return count;
}

// Main function.
int main() {
    // Add some products to the inventory.
    add_product(1, "Apple", 10);
    add_product(2, "Banana", 20);
    add_product(3, "Orange", 30);

    // Print the inventory.
    print_inventory();

    // Search for a product in the inventory.
    struct product_node *product = search_product(2);
    if (product != NULL) {
        printf("Product found: %s\n", product->product_name);
    } else {
        printf("Product not found.\n");
    }

    // Remove a product from the inventory.
    remove_product(2);

    // Print the inventory again.
    print_inventory();

    // Get the number of products in the inventory.
    int count = get_inventory_count();
    printf("Number of products in inventory: %d\n", count);

    return 0;
}