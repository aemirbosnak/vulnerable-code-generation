//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Define the linked list node structure
typedef struct node {
    product data;
    struct node *next;
} node;

// Define the head and tail of the linked list
node *head = NULL;
node *tail = NULL;

// Function to create a new node
node* create_node(product data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the end of the linked list
void insert_node(product data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

// Function to search for a product by ID
node* search_product(int id) {
    node *current = head;
    while (current != NULL) {
        if (current->data.id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a product by ID
void delete_product(int id) {
    node *current = head;
    node *previous = NULL;
    while (current != NULL) {
        if (current->data.id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to print the linked list
void print_list() {
    node *current = head;
    while (current != NULL) {
        printf("Product ID: %d\n", current->data.id);
        printf("Product Name: %s\n", current->data.name);
        printf("Product Quantity: %d\n", current->data.quantity);
        printf("Product Price: %.2f\n\n", current->data.price);
        current = current->next;
    }
}

// Main function
int main() {
    // Create some products
    product product1 = {1, "Product 1", 10, 10.00};
    product product2 = {2, "Product 2", 20, 20.00};
    product product3 = {3, "Product 3", 30, 30.00};

    // Insert the products into the linked list
    insert_node(product1);
    insert_node(product2);
    insert_node(product3);

    // Print the linked list
    printf("Initial Product Inventory:\n\n");
    print_list();

    // Search for a product by ID
    int id = 2;
    node *product_found = search_product(id);
    if (product_found != NULL) {
        printf("\nProduct found:\n\n");
        printf("Product ID: %d\n", product_found->data.id);
        printf("Product Name: %s\n", product_found->data.name);
        printf("Product Quantity: %d\n", product_found->data.quantity);
        printf("Product Price: %.2f\n\n", product_found->data.price);
    } else {
        printf("\nProduct not found.\n\n");
    }

    // Delete a product by ID
    id = 3;
    delete_product(id);

    // Print the linked list
    printf("\nProduct Inventory after deletion:\n\n");
    print_list();

    return 0;
}