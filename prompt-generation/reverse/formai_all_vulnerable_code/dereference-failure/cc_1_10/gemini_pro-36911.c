//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a product
typedef struct product {
    int id;
    char *name;
    int quantity;
    float price;
} product;

// Define the structure of a node in the linked list
typedef struct node {
    product *product;
    struct node *next;
} node;

// Define the head of the linked list
node *head = NULL;

// Add a product to the linked list
void add_product(product *product) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));

    // Set the product pointer in the new node
    new_node->product = product;

    // Set the next pointer in the new node
    new_node->next = head;

    // Set the head pointer to the new node
    head = new_node;
}

// Remove a product from the linked list
void remove_product(int id) {
    // Find the node with the specified ID
    node *current_node = head;
    while (current_node != NULL) {
        if (current_node->product->id == id) {
            break;
        }
        current_node = current_node->next;
    }

    // If the node was not found, return
    if (current_node == NULL) {
        return;
    }

    // Remove the node from the linked list
    if (current_node == head) {
        head = current_node->next;
    } else {
        node *previous_node = head;
        while (previous_node->next != current_node) {
            previous_node = previous_node->next;
        }
        previous_node->next = current_node->next;
    }

    // Free the memory allocated for the node
    free(current_node);
}

// Find a product by its ID
product *find_product(int id) {
    // Find the node with the specified ID
    node *current_node = head;
    while (current_node != NULL) {
        if (current_node->product->id == id) {
            return current_node->product;
        }
        current_node = current_node->next;
    }

    // If the node was not found, return NULL
    return NULL;
}

// Print the linked list
void print_list() {
    // Iterate over the linked list and print each product
    node *current_node = head;
    while (current_node != NULL) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", current_node->product->id, current_node->product->name, current_node->product->quantity, current_node->product->price);
        current_node = current_node->next;
    }
}

// Main function
int main() {
    // Create some products
    product *product1 = (product *)malloc(sizeof(product));
    product1->id = 1;
    product1->name = "iPhone";
    product1->quantity = 10;
    product1->price = 999.99;

    product *product2 = (product *)malloc(sizeof(product));
    product2->id = 2;
    product2->name = "iPad";
    product2->quantity = 5;
    product2->price = 499.99;

    product *product3 = (product *)malloc(sizeof(product));
    product3->id = 3;
    product3->name = "Apple Watch";
    product3->quantity = 3;
    product3->price = 299.99;

    // Add the products to the linked list
    add_product(product1);
    add_product(product2);
    add_product(product3);

    // Print the linked list
    print_list();

    // Find a product by its ID
    product *found_product = find_product(2);
    if (found_product != NULL) {
        printf("Found product: %s\n", found_product->name);
    } else {
        printf("Product not found\n");
    }

    // Remove a product from the linked list
    remove_product(1);

    // Print the linked list
    print_list();

    return 0;
}