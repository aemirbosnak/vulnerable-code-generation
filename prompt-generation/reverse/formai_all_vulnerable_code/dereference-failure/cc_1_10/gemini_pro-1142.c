//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct Product {
    int id;
    char *name;
    int quantity;
    float price;
} Product;

// Node structure for linked list
typedef struct Node {
    Product product;
    struct Node *next;
} Node;

// Head of the linked list
Node *head = NULL;

// Function to create a new node
Node *create_node(Product product) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->product = product;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the end of the linked list
void insert_node(Product product) {
    Node *new_node = create_node(product);
    if (head == NULL) {
        head = new_node;
        return;
    }
    Node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

// Function to search for a product by ID
Product *search_product(int id) {
    Node *current_node = head;
    while (current_node != NULL) {
        if (current_node->product.id == id) {
            return &current_node->product;
        }
        current_node = current_node->next;
    }
    return NULL;
}

// Function to update the quantity of a product
void update_quantity(int id, int quantity) {
    Product *product = search_product(id);
    if (product != NULL) {
        product->quantity = quantity;
    }
}

// Function to delete a product from the linked list
void delete_product(int id) {
    Node *current_node = head;
    Node *previous_node = NULL;
    while (current_node != NULL) {
        if (current_node->product.id == id) {
            if (previous_node == NULL) {
                head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
}

// Function to print the inventory
void print_inventory() {
    Node *current_node = head;
    while (current_node != NULL) {
        printf("Product ID: %d\n", current_node->product.id);
        printf("Product Name: %s\n", current_node->product.name);
        printf("Product Quantity: %d\n", current_node->product.quantity);
        printf("Product Price: %.2f\n\n", current_node->product.price);
        current_node = current_node->next;
    }
}

// Main function
int main() {
    // Create some products
    Product product1 = {1, "Apple", 10, 1.00};
    Product product2 = {2, "Orange", 15, 1.20};
    Product product3 = {3, "Banana", 20, 1.50};

    // Insert the products into the linked list
    insert_node(product1);
    insert_node(product2);
    insert_node(product3);

    // Search for a product by ID
    Product *product = search_product(2);
    if (product != NULL) {
        printf("Product found:\n");
        printf("Product ID: %d\n", product->id);
        printf("Product Name: %s\n", product->name);
        printf("Product Quantity: %d\n", product->quantity);
        printf("Product Price: %.2f\n\n", product->price);
    } else {
        printf("Product not found.\n");
    }

    // Update the quantity of a product
    update_quantity(1, 15);

    // Delete a product from the linked list
    delete_product(3);

    // Print the inventory
    print_inventory();

    return 0;
}