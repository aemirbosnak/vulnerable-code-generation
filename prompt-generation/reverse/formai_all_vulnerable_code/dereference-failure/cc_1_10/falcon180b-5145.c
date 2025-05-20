//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the structure for a node in the linked list */
typedef struct node {
    char *data; /* Pointer to the data stored in the node */
    struct node *next; /* Pointer to the next node in the list */
} Node;

/* Function to create a new node with the given data */
Node* createNode(char *data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Function to add a new node to the end of the list */
void addNode(Node **head, char *data) {
    Node *newNode = createNode(data);
    Node *lastNode = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (lastNode->next!= NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

/* Function to print the contents of the linked list */
void printList(Node *head) {
    Node *currentNode = head;
    while (currentNode!= NULL) {
        printf("%s ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

/* Function to free the memory used by the linked list */
void freeList(Node *head) {
    Node *currentNode = head;
    while (currentNode!= NULL) {
        free(currentNode->data);
        Node *tempNode = currentNode;
        currentNode = currentNode->next;
        free(tempNode);
    }
}

int main() {
    Node *head = NULL;

    /* Add some nodes to the list */
    addNode(&head, "Hello");
    addNode(&head, "World");
    addNode(&head, "Dennis");
    addNode(&head, "Ritchie");

    /* Print the contents of the list */
    printf("Linked List Contents:\n");
    printList(head);

    /* Free the memory used by the list */
    freeList(head);

    return 0;
}