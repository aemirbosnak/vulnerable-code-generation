//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Create a function to print our linked list
void printList(Node* head) {
    printf("Our linked list contains: ");
    Node* curr = head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Create a function to add a node to the end of our linked list
void addNode(Node** headRef, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
    }
    else {
        Node* curr = *headRef;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// Create a function to remove a node from our linked list
void removeNode(Node** headRef, int data) {
    Node* curr = *headRef;
    Node* prev = NULL;

    if (curr!= NULL && curr->data == data) {
        *headRef = curr->next;
        free(curr);
        return;
    }

    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        return;
    }

    prev->next = curr->next;
    free(curr);
}

// Create a function to reverse our linked list
void reverseList(Node** headRef) {
    Node* curr = *headRef;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr!= NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *headRef = prev;
}

int main() {
    Node* head = NULL;

    // Add some nodes to our linked list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print our linked list
    printList(head);

    // Remove a node from our linked list
    removeNode(&head, 3);

    // Print our linked list again
    printList(head);

    // Reverse our linked list
    reverseList(&head);

    // Print our linked list one last time
    printList(head);

    return 0;
}