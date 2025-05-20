//FormAI DATASET v1.0 Category: Data structures visualization ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to add an item to the linked list
void addToList(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to delete an item from the linked list
void deleteFromList(Node** head, int value) {
    Node* currNode = *head;
    Node* prevNode = NULL;
    while (currNode != NULL) {
        if (currNode->data == value) {
            if (prevNode == NULL) {
                *head = currNode->next;
                free(currNode);
                return;
            } else {
                prevNode->next = currNode->next;
                free(currNode);
                return;
            }
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Function to print the linked list
void printList(Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create an empty linked list
    Node* head = NULL;
    
    // Add some items to the list
    addToList(&head, 10);
    addToList(&head, 20);
    addToList(&head, 30);
    
    // Print the list
    printList(head);
    
    // Delete an item from the list
    deleteFromList(&head, 20);
    
    // Print the list again
    printList(head);
    
    return 0;
}