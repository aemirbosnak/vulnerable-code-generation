//FormAI DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Basic structure of node in linked list
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Function to add a node at the end of linked list
void addToEnd(struct node** headRef, int data) {
    struct node* newNode = createNode(data);
    struct node* current = *headRef;

    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }
}

// Function to display linked list
void displayList(struct node* head) {
    struct node* current = head;

    printf("List: ");

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Function to delete a node with given data from linked list
void deleteNode(struct node** headRef, int data) {
    struct node* temp = *headRef;
    struct node* prev;

    if (temp != NULL && temp->data == data) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found!\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to reverse a linked list
void reverseList(struct node** headRef) {
    struct node* prev = NULL;
    struct node* current = *headRef;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *headRef = prev;
}

int main() {
    struct node* head = NULL;

    addToEnd(&head, 10);
    addToEnd(&head, 20);
    addToEnd(&head, 30);
    addToEnd(&head, 40);

    displayList(head);

    deleteNode(&head, 30);

    displayList(head);

    reverseList(&head);

    displayList(head);

    return 0;
}