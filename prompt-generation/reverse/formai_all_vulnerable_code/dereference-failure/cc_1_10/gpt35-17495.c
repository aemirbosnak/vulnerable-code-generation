//FormAI DATASET v1.0 Category: Mailing list manager ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for holding information about a single address
struct node {
    char name[50];
    char email[100];
    struct node* next;
};

// Initialize the head pointer of the list to NULL
struct node* head = NULL;

// Function to add a new address to the list
void addAddress(char name[], char email[]) {
    // Allocate memory for the new node
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    
    // Copy the name and email strings to the new node
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    
    // Initialize the next pointer of the new node to NULL
    newNode->next = NULL;
    
    // If the head of the list is NULL, set the new node as the head
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    // Otherwise, iterate through the list to find the last node
    struct node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    
    // Set the next pointer of the last node to the new node
    curr->next = newNode;
}

// Function to print all the addresses in the list
void printAddresses() {
    // Start iterating from the head of the list
    struct node* curr = head;
    
    // Print each address until the end of the list is reached
    while (curr != NULL) {
        printf("%s <%s>\n", curr->name, curr->email);
        curr = curr->next;
    }
}

// Main function to test the mailing list manager program
int main() {
    // Add some sample addresses to the list
    addAddress("John Smith", "johnsmith@example.com");
    addAddress("Jane Doe", "janedoe@example.com");
    addAddress("Bob Johnson", "bobjohnson@example.com");
    
    // Print all the addresses in the list
    printf("Mailing List:\n");
    printAddresses();
    
    // Exit the program with no errors
    return 0;
}