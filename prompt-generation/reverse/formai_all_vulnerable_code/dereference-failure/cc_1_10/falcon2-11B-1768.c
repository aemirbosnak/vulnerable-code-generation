//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to initialize the head of the linked list
struct Node* initList() {
    struct Node* head = NULL;
    return head;
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node* current = head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int data) {
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found in the linked list\n", data);
    } else {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = initList();
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 10);
    insertAtEnd(head, 15);
    insertAtEnd(head, 20);
    printList(head);
    printf("Deleting node with data 10...\n");
    deleteNode(&head, 10);
    printList(head);
    printf("Deleting node with data 20...\n");
    deleteNode(&head, 20);
    printList(head);
    return 0;
}