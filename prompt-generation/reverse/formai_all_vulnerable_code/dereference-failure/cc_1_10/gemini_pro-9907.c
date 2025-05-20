//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int data;
    struct Queue *next;
} Queue;

// Create a new queue
Queue *createQueue() {
    return NULL;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return queue == NULL;
}

// Enqueue an element into the queue
void enqueue(Queue **queue, int data) {
    Queue *newElement = (Queue *)malloc(sizeof(Queue));
    newElement->data = data;
    newElement->next = NULL;

    if (*queue == NULL) {
        *queue = newElement;
    } else {
        enqueue(&(*queue)->next, data);
    }
}

// Dequeue an element from the queue
int dequeue(Queue **queue) {
    if (*queue == NULL) {
        return -1;
    }

    int data = (*queue)->data;
    Queue *temp = *queue;
    *queue = (*queue)->next;
    free(temp);

    return data;
}

// Get the front element of the queue
int front(Queue *queue) {
    if (queue == NULL) {
        return -1;
    }

    return queue->data;
}

// Print the queue
void printQueue(Queue *queue) {
    if (queue == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("%d ", queue->data);
    printQueue(queue->next);
}

// Free the queue
void freeQueue(Queue *queue) {
    if (queue == NULL) {
        return;
    }

    freeQueue(queue->next);
    free(queue);
}

// Test the queue
int main() {
    Queue *queue = createQueue();
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);

    printf("Queue: ");
    printQueue(queue);
    printf("\n");

    printf("Front element: %d\n", front(queue));

    dequeue(&queue);
    dequeue(&queue);

    printf("Queue after dequeue: ");
    printQueue(queue);
    printf("\n");

    freeQueue(queue);
    return 0;
}