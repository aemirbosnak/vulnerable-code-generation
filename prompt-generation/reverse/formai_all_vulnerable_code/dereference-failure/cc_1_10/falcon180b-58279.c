//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to add a node at the end of the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the list
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to search for a node in the list
Node* searchNode(Node* head, int data) {
    Node* temp = head;

    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    return temp;
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;

    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print the list
    printf("Original list:\n");
    printList(head);

    // Search for a node
    Node* foundNode = searchNode(head, 3);
    if (foundNode!= NULL) {
        printf("Found node with data: %d\n", foundNode->data);
    } else {
        printf("Node not found.\n");
    }

    // Delete a node
    deleteNode(&head, 4);

    // Print the updated list
    printf("Updated list:\n");
    printList(head);

    return 0;
}