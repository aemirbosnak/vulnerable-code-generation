//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct medicine {
    char name[50];
    char manufacturer[50];
    char expiry_date[11];
    int quantity;
    float price;
} medicine;

// Define the structure of a node in the linked list
typedef struct node {
    medicine data;
    struct node *next;
} node;

// Define the head of the linked list
node *head = NULL;

// Function to add a medicine to the linked list
void add_medicine(medicine m) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));

    // Copy the data into the new node
    new_node->data = m;

    // Insert the new node at the beginning of the linked list
    new_node->next = head;
    head = new_node;
}

// Function to search for a medicine in the linked list
medicine *search_medicine(char *name) {
    // Traverse the linked list
    node *current = head;
    while (current != NULL) {
        // Check if the name of the medicine matches the given name
        if (strcmp(current->data.name, name) == 0) {
            // Return the medicine
            return &current->data;
        }

        // Move to the next node
        current = current->next;
    }

    // Medicine not found
    return NULL;
}

// Function to update the quantity of a medicine in the linked list
void update_quantity(char *name, int quantity) {
    // Search for the medicine
    medicine *m = search_medicine(name);

    // If the medicine was found, update the quantity
    if (m != NULL) {
        m->quantity = quantity;
    }
}

// Function to delete a medicine from the linked list
void delete_medicine(char *name) {
    // Search for the medicine
    node *current = head;
    node *previous = NULL;
    while (current != NULL) {
        // Check if the name of the medicine matches the given name
        if (strcmp(current->data.name, name) == 0) {
            // If the medicine is the first node in the linked list, update the head
            if (previous == NULL) {
                head = current->next;
            } else {
                // Otherwise, update the next pointer of the previous node
                previous->next = current->next;
            }

            // Free the memory allocated for the node
            free(current);

            // Medicine deleted
            return;
        }

        // Move to the next node
        previous = current;
        current = current->next;
    }

    // Medicine not found
    printf("Medicine not found\n");
}

// Function to print the linked list
void print_list() {
    // Traverse the linked list
    node *current = head;
    while (current != NULL) {
        // Print the data of the medicine
        printf("Name: %s\n", current->data.name);
        printf("Manufacturer: %s\n", current->data.manufacturer);
        printf("Expiry Date: %s\n", current->data.expiry_date);
        printf("Quantity: %d\n", current->data.quantity);
        printf("Price: %f\n\n", current->data.price);

        // Move to the next node
        current = current->next;
    }
}

// Main function
int main() {
    // Add some medicines to the linked list
    medicine m1 = {"Paracetamol", "GlaxoSmithKline", "2023-03-01", 100, 10.0};
    add_medicine(m1);
    medicine m2 = {"Ibuprofen", "Pfizer", "2023-06-01", 50, 15.0};
    add_medicine(m2);
    medicine m3 = {"Aspirin", "Bayer", "2023-09-01", 25, 5.0};
    add_medicine(m3);

    // Print the linked list
    printf("Initial list:\n");
    print_list();

    // Search for a medicine
    medicine *m = search_medicine("Ibuprofen");
    if (m != NULL) {
        printf("Medicine found:\n");
        printf("Name: %s\n", m->name);
        printf("Manufacturer: %s\n", m->manufacturer);
        printf("Expiry Date: %s\n", m->expiry_date);
        printf("Quantity: %d\n", m->quantity);
        printf("Price: %f\n\n", m->price);
    } else {
        printf("Medicine not found\n");
    }

    // Update the quantity of a medicine
    update_quantity("Paracetamol", 75);

    // Print the linked list
    printf("Updated list:\n");
    print_list();

    // Delete a medicine
    delete_medicine("Aspirin");

    // Print the linked list
    printf("Deleted list:\n");
    print_list();

    return 0;
}