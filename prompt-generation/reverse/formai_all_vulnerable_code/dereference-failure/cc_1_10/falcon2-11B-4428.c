//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Structure to define a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node at the beginning of the linked list
void addNode(struct Node** head, int data) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Initialize the new node
    newNode->data = data;
    newNode->next = (*head);
    
    // Update the head pointer to point to the new node
    (*head) = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int key) {
    // Initialize a temporary pointer to the previous node
    struct Node* temp = *head;
    
    // Traverse the linked list until the node to be deleted is found
    while (temp!= NULL && temp->data!= key) {
        temp = temp->next;
    }
    
    // If the node to be deleted is not found, return
    if (temp == NULL) {
        printf("Node not found in the linked list!\n");
        return;
    }
    
    // If the node to be deleted is the head node, update the head pointer
    if (*head == temp) {
        *head = temp->next;
    }
    
    // Otherwise, update the next pointer of the previous node
    else {
        temp->next = temp->next->next;
    }
    
    // Free the memory of the deleted node
    free(temp);
}

// Function to search for a node in the linked list
int searchNode(struct Node* head, int key) {
    while (head!= NULL) {
        if (head->data == key) {
            return 1; // Node found
        }
        head = head->next;
    }
    return 0; // Node not found
}

int main() {
    // Create the head node of the linked list
    struct Node* head = NULL;
    
    // Add nodes to the linked list
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    
    // Print the linked list
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    // Delete a node from the linked list
    deleteNode(&head, 20);
    
    // Print the updated linked list
    temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    // Search for a node in the linked list
    int searchKey = 30;
    if (searchNode(head, searchKey) == 1) {
        printf("Node found: %d\n", searchKey);
    }
    else {
        printf("Node not found\n");
    }
    
    return 0;
}