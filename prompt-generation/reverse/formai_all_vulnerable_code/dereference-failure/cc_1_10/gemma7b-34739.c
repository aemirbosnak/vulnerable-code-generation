//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a product
typedef struct product {
    char name[50];
    int quantity;
    double price;
} product_t;

// Define a linked list node
typedef struct node {
    product_t product;
    struct node* next;
} node_t;

// Function to insert a product into the linked list
void insert(node_t** head, product_t product) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->product = product;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

// Function to search for a product in the linked list
product_t* search(node_t* head, char* name) {
    while (head) {
        if (strcmp(head->product.name, name) == 0) {
            return &head->product;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of a product in the linked list
void update(node_t* head, char* name, int quantity) {
    product_t* product = search(head, name);

    if (product) {
        product->quantity = quantity;
    }
}

// Function to delete a product from the linked list
void delete(node_t* head, char* name) {
    node_t* previous = NULL;
    node_t* current = head;

    while (current) {
        if (strcmp(current->product.name, name) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            current = NULL;
        } else {
            previous = current;
            current = current->next;
        }
    }
}

int main() {
    node_t* head = NULL;

    // Insert some products into the linked list
    insert(&head, (product_t){.name = "Product A", .quantity = 10, .price = 100.0});
    insert(&head, (product_t){.name = "Product B", .quantity = 20, .price = 200.0});
    insert(&head, (product_t){.name = "Product C", .quantity = 30, .price = 300.0});

    // Search for a product and update its quantity
    update(head, "Product B", 30);

    // Delete a product from the linked list
    delete(head, "Product C");

    // Print the products in the linked list
    for (node_t* current = head; current; current = current->next) {
        printf("%s: %d, %f\n", current->product.name, current->product.quantity, current->product.price);
    }

    return 0;
}