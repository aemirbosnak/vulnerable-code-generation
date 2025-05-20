//FormAI DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node to the linked list
void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        return;
    }
    
    prev->next = temp->next;
    free(temp);
}

// Function to search for a node in the linked list
void searchNode(struct Node** head, int key) {
    struct Node* temp = *head;
    int found = 0;
    
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Node with key %d found\n", key);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    
    if (!found) {
        printf("Node with key %d not found\n", key);
    }
}

// Function to print out the linked list
void printList(struct Node** head) {
    struct Node* temp = *head;
    
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;
    
    // Add some nodes
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    
    // Print out the linked list
    printf("Linked List: ");
    printList(&head);
    printf("\n");
    
    // Delete a node
    deleteNode(&head, 2);
    
    // Print out the linked list
    printf("Linked List after deleting node with key 2: ");
    printList(&head);
    printf("\n");
    
    // Search for a node
    searchNode(&head, 3);
    
    // Search for a node that is not in the linked list
    searchNode(&head, 5);
    
    return 0;
}