//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: lively
// This is an example of a queue implementation in C. // We will be using a linked list to implement the queue. // The linked list will have nodes with the following structure:

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of the queue
typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

// Initialize an empty queue
Queue* initQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Enqueue an element to the rear of the queue
void enqueue(Queue* q, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (isEmpty(q)) {
        q->front = node;
        q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}

// Dequeue an element from the front of the queue
int dequeue(Queue* q) {
    int data = -1;
    if (!isEmpty(q)) {
        Node* node = q->front;
        data = node->data;
        q->front = q->front->next;
        free(node);
    }
    return data;
}

// Print the elements in the queue
void printQueue(Queue* q) {
    Node* node = q->front;
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Example usage of the queue implementation
int main() {
    Queue* q = initQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);
    printf("Dequeued element: %d\n", dequeue(q));
    printQueue(q);
    printf("Dequeued element: %d\n", dequeue(q));
    printQueue(q);
    printf("Dequeued element: %d\n", dequeue(q));
    printQueue(q);
    return 0;
}

/*
Sample output:
10 20 30 
Dequeued element: 10
20 30 
Dequeued element: 20
30 
Dequeued element: 30
*/