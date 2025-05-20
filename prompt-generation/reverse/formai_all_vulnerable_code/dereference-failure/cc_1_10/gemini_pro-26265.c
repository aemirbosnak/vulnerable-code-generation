//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the structure of a medicine
typedef struct medicine {
    char name[50];
    char company[50];
    float price;
    int quantity;
} medicine;

// Define the structure of a node in a linked list
typedef struct node {
    medicine data;
    struct node *next;
} node;

// Define the head of the linked list
node *head = NULL;

// Function to add a medicine to the linked list
void addMedicine(medicine m) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));

    // Copy the data into the new node
    new_node->data = m;

    // Set the next pointer of the new node to NULL
    new_node->next = NULL;

    // If the linked list is empty, set the head to the new node
    if (head == NULL) {
        head = new_node;
    } else {
        // Otherwise, find the last node in the linked list and set its next pointer to the new node
        node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Function to search for a medicine in the linked list
node *searchMedicine(char *name) {
    // Traverse the linked list and compare the name of each medicine to the given name
    node *current_node = head;
    while (current_node != NULL) {
        if (strcmp(current_node->data.name, name) == 0) {
            return current_node;
        }
        current_node = current_node->next;
    }

    // If the medicine is not found, return NULL
    return NULL;
}

// Function to delete a medicine from the linked list
void deleteMedicine(char *name) {
    // Search for the medicine in the linked list
    node *node_to_delete = searchMedicine(name);

    // If the medicine is not found, return
    if (node_to_delete == NULL) {
        return;
    }

    // If the node to delete is the head of the linked list, set the head to the next node
    if (node_to_delete == head) {
        head = head->next;
    } else {
        // Otherwise, find the previous node and set its next pointer to the next node of the node to delete
        node *previous_node = head;
        while (previous_node->next != node_to_delete) {
            previous_node = previous_node->next;
        }
        previous_node->next = node_to_delete->next;
    }

    // Free the memory allocated for the node to delete
    free(node_to_delete);
}

// Function to print the linked list
void printLinkedList() {
    // Traverse the linked list and print the data of each medicine
    node *current_node = head;
    while (current_node != NULL) {
        printf("%s %s %f %d\n", current_node->data.name, current_node->data.company, current_node->data.price, current_node->data.quantity);
        current_node = current_node->next;
    }
}

// Main function
int main() {
    // Add some medicines to the linked list
    medicine m1 = {"Paracetamol", "Cipla", 10.0, 50};
    addMedicine(m1);
    medicine m2 = {"Ibuprofen", "Advil", 15.0, 25};
    addMedicine(m2);
    medicine m3 = {"Aspirin", "Bayer", 20.0, 10};
    addMedicine(m3);

    // Print the linked list
    printLinkedList();

    // Search for a medicine in the linked list
    node *result = searchMedicine("Ibuprofen");
    if (result != NULL) {
        printf("Medicine found: %s %s %f %d\n", result->data.name, result->data.company, result->data.price, result->data.quantity);
    } else {
        printf("Medicine not found\n");
    }

    // Delete a medicine from the linked list
    deleteMedicine("Aspirin");

    // Print the linked list
    printLinkedList();

    return 0;
}