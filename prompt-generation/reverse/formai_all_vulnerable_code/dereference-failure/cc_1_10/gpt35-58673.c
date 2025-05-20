//FormAI DATASET v1.0 Category: Linked list operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Main function
int main() {

    // Create three Nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Allocate memory to each Node 
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to each Node
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Add another Node to the end of the list
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 4;
    newNode->next = NULL;

    // Traverse the list and print out each element
    printf("The List is: \n");
    struct Node* current = head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }

    // Insert the new node at the beginning of the list
    newNode->next = head;
    head = newNode;

    // Traverse the list again
    printf("\nThe List after inserting a new Node at the beginning: \n");
    current = head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    return 0;
}