//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the product structure
typedef struct product {
    int id;
    char *name;
    float price;
    int quantity;
} product;

// Declare the linked list node structure
typedef struct node {
    product *data;
    struct node *next;
} node;

// Declare the linked list head and tail pointers
node *head = NULL;
node *tail = NULL;

// Function to create a new product
product *createProduct(int id, char *name, float price, int quantity) {
    // Allocate memory for the new product
    product *newProduct = (product *)malloc(sizeof(product));

    // Set the product's properties
    newProduct->id = id;
    newProduct->name = strdup(name);
    newProduct->price = price;
    newProduct->quantity = quantity;

    // Return the new product
    return newProduct;
}

// Function to add a product to the linked list
void addProduct(product *newProduct) {
    // Create a new linked list node
    node *newNode = (node *)malloc(sizeof(node));

    // Set the node's data and next pointers
    newNode->data = newProduct;
    newNode->next = NULL;

    // If the linked list is empty, set the head and tail pointers to the new node
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    // Otherwise, add the new node to the end of the linked list
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to search for a product by ID
product *searchProductById(int id) {
    // Traverse the linked list and search for the product with the given ID
    node *current = head;
    while (current != NULL) {
        if (current->data->id == id) {
            return current->data;
        }
        current = current->next;
    }

    // If the product is not found, return NULL
    return NULL;
}

// Function to delete a product from the linked list
void deleteProductById(int id) {
    // Traverse the linked list and search for the product with the given ID
    node *current = head;
    node *previous = NULL;
    while (current != NULL) {
        if (current->data->id == id) {
            // If the product is found, remove it from the linked list
            if (current == head) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            // Free the memory allocated for the product and the linked list node
            free(current->data);
            free(current);

            // Exit the loop
            break;
        }

        // Move to the next node
        previous = current;
        current = current->next;
    }
}

// Function to print the products in the linked list
void printProducts() {
    // Traverse the linked list and print the products
    node *current = head;
    while (current != NULL) {
        printf("Product ID: %d\n", current->data->id);
        printf("Product Name: %s\n", current->data->name);
        printf("Product Price: %.2f\n", current->data->price);
        printf("Product Quantity: %d\n\n", current->data->quantity);
        current = current->next;
    }
}

// Main function
int main() {
    // Create some test products
    product *product1 = createProduct(1, "Apple", 1.00, 10);
    product *product2 = createProduct(2, "Banana", 1.50, 15);
    product *product3 = createProduct(3, "Orange", 2.00, 20);

    // Add the products to the linked list
    addProduct(product1);
    addProduct(product2);
    addProduct(product3);

    // Print the products in the linked list
    printf("Products in the inventory:\n");
    printProducts();

    // Search for a product by ID
    int id = 2;
    product *product = searchProductById(id);
    if (product != NULL) {
        printf("Product found:\n");
        printf("Product ID: %d\n", product->id);
        printf("Product Name: %s\n", product->name);
        printf("Product Price: %.2f\n", product->price);
        printf("Product Quantity: %d\n", product->quantity);
    } else {
        printf("Product not found.\n");
    }

    // Delete a product from the linked list
    id = 3;
    deleteProductById(id);

    // Print the products in the linked list
    printf("Products in the inventory after deletion:\n");
    printProducts();

    // Free the memory allocated for the products and the linked list nodes
    free(product1);
    free(product2);
    free(product3);

    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    return 0;
}