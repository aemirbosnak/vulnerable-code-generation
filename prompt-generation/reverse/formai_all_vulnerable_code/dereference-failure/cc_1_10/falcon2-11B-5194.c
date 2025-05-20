//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the structure for the queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new element at the beginning of the queue
void enqueue(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

// Function to delete a node from the beginning of the queue
void deleteFromFront(Node** head_ref) {
    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

// Function to display all elements in the queue
void displayQueue(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    enqueue(&head, 4);
    enqueue(&head, 5);

    printf("Queue: ");
    displayQueue(head);

    deleteFromFront(&head);

    printf("\nQueue after deleting from front: ");
    displayQueue(head);

    return 0;
}