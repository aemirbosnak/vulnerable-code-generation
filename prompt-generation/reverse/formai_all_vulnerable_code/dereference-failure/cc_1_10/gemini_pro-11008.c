//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Node structure for linked list
typedef struct node {
    product data;
    struct node *next;
} node;

// Head and tail pointers for linked list
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

// Function to delete a node from the linked list
void delete_node(char *name) {
    node *current = head;
    node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            if (current == head) {
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

// Function to search for a product in the linked list
node* search_node(char *name) {
    node *current = head;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print the linked list
void print_list() {
    node *current = head;
    while (current != NULL) {
        printf("%s %d %.2f\n", current->data.name, current->data.quantity, current->data.price);
        current = current->next;
    }
}

// Main function
int main() {
    // Create some products
    product product1 = {"Apple", 10, 1.0};
    product product2 = {"Banana", 15, 1.5};
    product product3 = {"Orange", 20, 2.0};

    // Insert the products into the linked list
    insert_node(product1);
    insert_node(product2);
    insert_node(product3);

    // Print the linked list
    printf("Initial list:\n");
    print_list();

    // Search for a product
    node *found_node = search_node("Banana");
    if (found_node != NULL) {
        printf("\nFound product: %s %d %.2f\n", found_node->data.name, found_node->data.quantity, found_node->data.price);
    } else {
        printf("\nProduct not found.\n");
    }

    // Delete a product
    delete_node("Orange");

    // Print the linked list
    printf("\nUpdated list:\n");
    print_list();

    return 0;
}