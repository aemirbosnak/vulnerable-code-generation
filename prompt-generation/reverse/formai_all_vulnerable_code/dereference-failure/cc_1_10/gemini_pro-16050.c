//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Queue structure
typedef struct queue {
    node *front;
    node *rear;
    int size;
} queue;

// Create a new queue
queue *createQueue() {
    queue *newQueue = (queue *)malloc(sizeof(queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
    return newQueue;
}

// Check if queue is empty
int isEmpty(queue *q) {
    return q->size == 0;
}

// Add an element to the queue
void enqueue(queue *q, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

// Remove an element from the queue
int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty\n");
        return -1;
    }

    int data = q->front->data;
    node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;

    return data;
}

// Get the size of the queue
int getSize(queue *q) {
    return q->size;
}

// Print the queue
void printQueue(queue *q) {
    node *temp = q->front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Destroy the queue
void destroyQueue(queue *q) {
    node *temp;

    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }

    free(q);
}

// Usage example
int main() {
    queue *q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    printf("Queue: ");
    printQueue(q);

    printf("Size of queue: %d\n", getSize(q));

    printf("Dequeued element: %d\n", dequeue(q));

    printf("Queue after dequeue: ");
    printQueue(q);

    destroyQueue(q);

    return 0;
}