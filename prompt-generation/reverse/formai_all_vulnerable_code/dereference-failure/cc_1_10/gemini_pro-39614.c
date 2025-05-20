//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a product struct
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Create a linked list node
typedef struct node {
    product data;
    struct node *next;
} node;

// Create a linked list head
node *head = NULL;

// Add a product to the inventory
void add_product(product product) {
    // Create a new node
    node *new_node = malloc(sizeof(node));
    new_node->data = product;
    new_node->next = NULL;

    // Add the new node to the beginning of the list
    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
}

// Remove a product from the inventory
void remove_product(int id) {
    // Find the node with the specified ID
    node *current_node = head;
    while (current_node != NULL) {
        if (current_node->data.id == id) {
            break;
        }
        current_node = current_node->next;
    }

    // If the node was found, remove it from the list
    if (current_node != NULL) {
        if (current_node == head) {
            head = current_node->next;
        } else {
            node *previous_node = head;
            while (previous_node->next != current_node) {
                previous_node = previous_node->next;
            }
            previous_node->next = current_node->next;
        }
        free(current_node);
    }
}

// Update the quantity of a product
void update_quantity(int id, int quantity) {
    // Find the node with the specified ID
    node *current_node = head;
    while (current_node != NULL) {
        if (current_node->data.id == id) {
            break;
        }
        current_node = current_node->next;
    }

    // If the node was found, update the quantity
    if (current_node != NULL) {
        current_node->data.quantity = quantity;
    }
}

// Print the inventory
void print_inventory() {
    // Iterate over the linked list and print each product
    node *current_node = head;
    while (current_node != NULL) {
        printf("ID: %d\n", current_node->data.id);
        printf("Name: %s\n", current_node->data.name);
        printf("Quantity: %d\n", current_node->data.quantity);
        printf("Price: %.2f\n", current_node->data.price);
        printf("\n");
        current_node = current_node->next;
    }
}

// Get the total value of the inventory
float get_total_value() {
    // Iterate over the linked list and calculate the total value
    node *current_node = head;
    float total_value = 0;
    while (current_node != NULL) {
        total_value += current_node->data.quantity * current_node->data.price;
        current_node = current_node->next;
    }
    return total_value;
}

// Main function
int main() {
    // Add some products to the inventory
    product product1 = {1, "iPhone 14", 10, 999.99};
    add_product(product1);
    product product2 = {2, "MacBook Pro", 5, 1299.99};
    add_product(product2);
    product product3 = {3, "iPad Air", 7, 599.99};
    add_product(product3);

    // Print the inventory
    print_inventory();

    // Remove a product from the inventory
    remove_product(2);

    // Print the inventory again
    print_inventory();

    // Update the quantity of a product
    update_quantity(1, 15);

    // Print the inventory again
    print_inventory();

    // Get the total value of the inventory
    float total_value = get_total_value();
    printf("Total value of the inventory: %.2f\n", total_value);

    return 0;
}