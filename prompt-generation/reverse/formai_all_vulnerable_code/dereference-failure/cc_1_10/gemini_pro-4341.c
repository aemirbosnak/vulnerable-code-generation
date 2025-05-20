//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct medicine {
    char name[50];
    char brand[50];
    float price;
    int quantity;
} medicine;

// Define the structure of a node in the linked list
typedef struct node {
    medicine data;
    struct node *next;
} node;

// Define the head of the linked list
node *head = NULL;

// Function to add a medicine to the linked list
void add_medicine(char *name, char *brand, float price, int quantity) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));

    // Copy the data into the new node
    strcpy(new_node->data.name, name);
    strcpy(new_node->data.brand, brand);
    new_node->data.price = price;
    new_node->data.quantity = quantity;

    // Insert the new node at the beginning of the linked list
    new_node->next = head;
    head = new_node;
}

// Function to search for a medicine in the linked list
node *search_medicine(char *name) {
    // Traverse the linked list
    node *current = head;
    while (current != NULL) {
        // Check if the name of the medicine matches the search term
        if (strcmp(current->data.name, name) == 0) {
            // Return the node if the medicine is found
            return current;
        }

        // Move to the next node
        current = current->next;
    }

    // Return NULL if the medicine is not found
    return NULL;
}

// Function to delete a medicine from the linked list
void delete_medicine(char *name) {
    // Search for the medicine in the linked list
    node *to_delete = search_medicine(name);

    // Check if the medicine was found
    if (to_delete == NULL) {
        printf("Medicine not found.\n");
        return;
    }

    // If the medicine is the first node in the linked list
    if (to_delete == head) {
        head = head->next;
    } else {
        // Find the node before the node to be deleted
        node *prev = head;
        while (prev->next != to_delete) {
            prev = prev->next;
        }

        // Skip the node to be deleted
        prev->next = to_delete->next;
    }

    // Free the memory allocated to the node
    free(to_delete);
}

// Function to print the linked list
void print_list() {
    // Traverse the linked list
    node *current = head;
    while (current != NULL) {
        // Print the data in the node
        printf("%s %s %f %d\n", current->data.name, current->data.brand, current->data.price, current->data.quantity);

        // Move to the next node
        current = current->next;
    }
}

// Main function
int main() {
    // Add some medicines to the linked list
    add_medicine("Paracetamol", "Crocin", 10.0, 100);
    add_medicine("Ibuprofen", "Advil", 15.0, 50);
    add_medicine("Aspirin", "Bayer", 5.0, 200);

    // Print the linked list
    print_list();

    // Search for a medicine in the linked list
    node *found = search_medicine("Ibuprofen");
    if (found != NULL) {
        printf("Medicine found: %s %s %f %d\n", found->data.name, found->data.brand, found->data.price, found->data.quantity);
    } else {
        printf("Medicine not found.\n");
    }

    // Delete a medicine from the linked list
    delete_medicine("Aspirin");

    // Print the linked list
    print_list();

    return 0;
}