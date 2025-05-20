//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int num;
    struct node *next;
} Node;

// Function declarations
void addNode(Node **head, int data);
void printList(Node *head);
void deleteNode(Node **head, int data);
void reverseList(Node **head);

int main() {
    Node *head = NULL;

    // Adding nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Printing the original list
    printf("Original list:\n");
    printList(head);

    // Reversing the list
    reverseList(&head);

    // Printing the reversed list
    printf("\nReversed list:\n");
    printList(head);

    // Deleting a node from the list
    deleteNode(&head, 3);

    // Printing the updated list
    printf("\nUpdated list after deleting node with value 3:\n");
    printList(head);

    return 0;
}

// Function to add a node to the list
void addNode(Node **head, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->num = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the list
void printList(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->num);
        temp = temp->next;
    }
}

// Function to delete a node from the list
void deleteNode(Node **head, int data) {
    Node *temp = *head, *prev;

    if (temp!= NULL && temp->num == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->num!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

// Function to reverse the list
void reverseList(Node **head) {
    Node *prev, *current, *next;
    prev = NULL;
    current = *head;

    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}