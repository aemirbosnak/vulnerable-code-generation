//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    struct node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct node** head, int data) {
    struct node* temp = *head;
    struct node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found in the linked list\n");
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
        free(temp);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void displayList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Creating a linked list
    struct node* head = NULL;
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Displaying the linked list
    printf("Linked List: ");
    displayList(head);
    printf("\n");

    // Deleting a node from the linked list
    deleteNode(&head, 3);

    // Displaying the linked list after deletion
    printf("Linked List after Deletion: ");
    displayList(head);
    printf("\n");

    return 0;
}