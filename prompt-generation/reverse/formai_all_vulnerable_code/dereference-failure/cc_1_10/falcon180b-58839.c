//Falcon-180B DATASET v1.0 Category: Memory management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the list
void addNode(struct node** head, int data) {
    struct node* node = newNode(data);
    struct node* temp = *head;

    if (*head == NULL) {
        node->next = NULL;
        *head = node;
        return;
    }

    while (temp->next!= NULL)
        temp = temp->next;

    temp->next = node;
    node->next = NULL;
}

// Function to delete a node with given data
void deleteNode(struct node** head, int data) {
    struct node* temp = *head;
    struct node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

// Function to search for a node with given data
struct node* searchNode(struct node* head, int data) {
    struct node* temp = head;

    while (temp!= NULL) {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

// Function to print the list
void printList(struct node* node) {
    while (node!= NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;

    // Adding nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);

    // Printing the list
    printf("Original List:\n");
    printList(head);

    // Deleting a node
    deleteNode(&head, 3);

    // Printing the updated list
    printf("\nList after deleting 3:\n");
    printList(head);

    // Searching for a node
    struct node* foundNode = searchNode(head, 4);

    if (foundNode!= NULL)
        printf("\nNode with data %d found!\n", foundNode->data);
    else
        printf("\nNode with data %d not found!\n", 5);

    return 0;
}