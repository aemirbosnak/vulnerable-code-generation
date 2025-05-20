//FormAI DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to initialize the linked list
void initializeList(Node **head) {
    *head = NULL;
}

// Function to add nodes to the linked list
void addNode(Node **head, int newData) {
    // Allocate memory for a new node
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;
    
    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Otherwise, traverse the list to find the last node and add the new node there
    Node *currentNode = *head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    
    currentNode->next = newNode;
    return;
}

// Function to delete a node from the linked list
void deleteNode(Node **head, int dataToDelete) {
    // If the list is empty, exit the function
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node *temp = *head;
    Node *prev = NULL;

    // If the head node itself holds the data to be deleted
    if (temp != NULL && temp->data == dataToDelete) {
        *head = temp->next;
        free(temp);
        printf("%d deleted successfully\n", dataToDelete);
        return;
    }

    // Search for the data to be deleted, keeping track of the previous node
    while (temp != NULL && temp->data != dataToDelete) {
        prev = temp;
        temp = temp->next;
    }

    // If the data wasn't found in the list, exit the function
    if (temp == NULL) {
        printf("%d not found\n", dataToDelete);
        return;
    } 
    // Otherwise, delete the node and free its memory
    prev->next = temp->next;
    free(temp);
    printf("%d deleted successfully\n", dataToDelete);
}

// Function to search for a node in the linked list
void searchNode(Node *head, int dataToSearch) {
    // Start at the head and traverse the list until the data is found
    Node *currentNode = head;
    while (currentNode != NULL) {
        if (currentNode->data == dataToSearch) {
            printf("%d found in the list\n", dataToSearch);
            return;
        }
        currentNode = currentNode->next;
    }
    printf("%d not found\n", dataToSearch);
    return;
}

// Function to display the linked list
void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node *currentNode = head;
    printf("List contents:\n");
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main () {
    Node *head;
    initializeList(&head);

    // Add nodes to the list
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);

    // Display the list contents
    displayList(head);

    // Search for a node in the list
    searchNode(head, 10);

    // Delete a node from the list
    deleteNode(&head, 10);

    // Display the updated list contents
    displayList(head);

    return 0;
}