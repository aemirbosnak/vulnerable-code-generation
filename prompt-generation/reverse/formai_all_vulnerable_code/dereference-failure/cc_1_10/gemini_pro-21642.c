//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct Medicine {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
} Medicine;

// Define the structure of a node in the linked list
typedef struct Node {
    Medicine medicine;
    struct Node *next;
} Node;

// Define the head of the linked list
Node *head = NULL;

// Function to add a medicine to the linked list
void addMedicine(Medicine medicine) {
    // Create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));

    // Copy the medicine data to the new node
    newNode->medicine = medicine;

    // Set the next pointer of the new node to the head of the linked list
    newNode->next = head;

    // Update the head of the linked list to point to the new node
    head = newNode;
}

// Function to search for a medicine in the linked list
Node *searchMedicine(char *name) {
    // Traverse the linked list
    Node *currentNode = head;
    while (currentNode != NULL) {
        // Check if the name of the medicine matches the search term
        if (strcmp(currentNode->medicine.name, name) == 0) {
            // Return the current node if the medicine is found
            return currentNode;
        }

        // Move to the next node in the linked list
        currentNode = currentNode->next;
    }

    // Return NULL if the medicine is not found
    return NULL;
}

// Function to delete a medicine from the linked list
void deleteMedicine(char *name) {
    // Search for the medicine in the linked list
    Node *currentNode = searchMedicine(name);

    // Check if the medicine was found
    if (currentNode != NULL) {
        // If the medicine is the head of the linked list, update the head to point to the next node
        if (currentNode == head) {
            head = currentNode->next;
        } else {
            // Find the previous node in the linked list
            Node *previousNode = head;
            while (previousNode->next != currentNode) {
                previousNode = previousNode->next;
            }

            // Update the next pointer of the previous node to skip the current node
            previousNode->next = currentNode->next;
        }

        // Free the memory allocated for the current node
        free(currentNode);
    }
}

// Function to print the linked list
void printLinkedList() {
    // Traverse the linked list
    Node *currentNode = head;
    while (currentNode != NULL) {
        // Print the data of the current node
        printf("Medicine Name: %s\n", currentNode->medicine.name);
        printf("Manufacturer: %s\n", currentNode->medicine.manufacturer);
        printf("Quantity: %d\n", currentNode->medicine.quantity);
        printf("Price: %f\n\n", currentNode->medicine.price);

        // Move to the next node in the linked list
        currentNode = currentNode->next;
    }
}

// Main function
int main() {
    // Create some sample medicines
    Medicine medicine1 = {"Paracetamol", "GlaxoSmithKline", 100, 10.0};
    Medicine medicine2 = {"Ibuprofen", "Reckitt Benckiser", 50, 5.0};
    Medicine medicine3 = {"Aspirin", "Bayer", 25, 2.0};

    // Add the medicines to the linked list
    addMedicine(medicine1);
    addMedicine(medicine2);
    addMedicine(medicine3);

    // Print the linked list
    printLinkedList();

    // Search for a medicine in the linked list
    Node *foundNode = searchMedicine("Ibuprofen");

    // Check if the medicine was found
    if (foundNode != NULL) {
        // Print the data of the found medicine
        printf("Medicine Name: %s\n", foundNode->medicine.name);
        printf("Manufacturer: %s\n", foundNode->medicine.manufacturer);
        printf("Quantity: %d\n", foundNode->medicine.quantity);
        printf("Price: %f\n\n", foundNode->medicine.price);
    } else {
        printf("Medicine not found.\n");
    }

    // Delete a medicine from the linked list
    deleteMedicine("Aspirin");

    // Print the linked list again to show that the medicine has been deleted
    printLinkedList();

    return 0;
}