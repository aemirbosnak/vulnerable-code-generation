//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

// Define the structure of the queue
typedef struct {
    int data;
    struct node* next;
} node;

// Create a new node with the given data
node* createNode(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Add a new node to the end of the queue
void enqueue(node** head, int data) {
    node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Remove the first node from the queue
void dequeue(node** head) {
    if (*head == NULL) {
        printf("Error: Queue is empty.\n");
        return;
    }
    node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Display the contents of the queue
void displayQueue(node* head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Check if the queue is empty
bool isEmpty(node* head) {
    return head == NULL;
}

int main() {
    node* head = NULL;

    // Add some nodes to the queue
    enqueue(&head, 10);
    enqueue(&head, 20);
    enqueue(&head, 30);

    // Display the contents of the queue
    printf("Queue after adding 3 nodes:\n");
    displayQueue(head);

    // Remove the first node from the queue
    dequeue(&head);

    // Display the contents of the queue again
    printf("Queue after removing 1 node:\n");
    displayQueue(head);

    // Check if the queue is empty
    if (isEmpty(head)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    return 0;
}