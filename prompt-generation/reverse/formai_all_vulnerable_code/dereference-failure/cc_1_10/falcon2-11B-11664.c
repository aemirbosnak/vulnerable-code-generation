//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the queue
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an element to the queue
void enqueue(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to remove an element from the queue
int dequeue(Node **head) {
    if (*head == NULL) {
        return -1; // Queue is empty
    }
    int data = (*head)->data;
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return data;
}

// Function to display the elements in the queue
void display(Node *head) {
    Node *current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    enqueue(&head, 5);
    enqueue(&head, 10);
    enqueue(&head, 15);
    enqueue(&head, 20);
    display(head);
    printf("%d\n", dequeue(&head));
    display(head);
    printf("%d\n", dequeue(&head));
    display(head);
    return 0;
}