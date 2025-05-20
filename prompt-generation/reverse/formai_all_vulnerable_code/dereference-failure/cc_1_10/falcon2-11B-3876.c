//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

// Function to initialize head node
struct node* initHead(int val) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtHead(struct node** headRef, int val) {
    struct node* newNode = initHead(val);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct node** headRef, int val) {
    struct node* newNode = initHead(val);
    struct node* current = *headRef;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct node** headRef, int val) {
    struct node* current = *headRef;
    struct node* previous = NULL;
    while (current!= NULL) {
        if (current->data == val) {
            if (previous!= NULL) {
                previous->next = current->next;
            } else {
                *headRef = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Node not found\n");
}

// Function to display the linked list
void display(struct node* head) {
    struct node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    insertAtHead(&head, 1);
    insertAtHead(&head, 2);
    insertAtHead(&head, 3);
    insertAtHead(&head, 4);
    insertAtHead(&head, 5);
    display(head);
    printf("Deleting node with value 4\n");
    deleteNode(&head, 4);
    display(head);
    return 0;
}