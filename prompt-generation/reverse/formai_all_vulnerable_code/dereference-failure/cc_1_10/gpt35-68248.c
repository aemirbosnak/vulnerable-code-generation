//FormAI DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

This program creates a surrealist representation of a traditional linked list.
Each element of the list is represented by a random number of potted plants.

*/

// Define the structure of each node
typedef struct node {
    int data; // The number of potted plants at this position in the list
    struct node* next; // Pointer to the next node in the list
} Node;

// Function to generate a random number of plants for a node
int generateRandomNumber() {
    return rand() % 10 + 1; // Return a random number between 1 and 10
}

// Function to add a new node to the list
void addNode(Node** head, int newData) {
    Node* newNode = (Node*) malloc(sizeof(Node)); // Allocate memory for the new node
    newNode->data = newData; // Set the data value of the new node
    newNode->next = *head; // Set the next pointer of the new node to the head of the list
    *head = newNode; // Set the head pointer to the new node
}

// Function to print out the list in a surrealist style
void printList(Node* node) {
    while (node != NULL) { // Iterate over all nodes in the list
        int i;
        for (i = 0; i < node->data; i++) { // Print out a number of potted plants equal to the data value of the node
            printf("^"); // Print the symbol '^' for each plant
        }
        printf("\n"); // Move to the next line for the next node
        node = node->next; // Progress to the next node in the list
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    Node* head = NULL; // Initialize the head of the linked list to NULL

    // Add 10 nodes to the list with random numbers of plants
    int i;
    for (i = 0; i < 10; i++) {
        addNode(&head, generateRandomNumber());
    }

    // Print out the linked list in a surrealist style
    printList(head);

    return 0;
}