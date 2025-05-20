//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

// Create a new queue
Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

// Enqueue an element into the queue
void enqueue(Queue *queue, int data) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }

    QueueNode *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Peek the front element of the queue
int peek(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }

    return queue->front->data;
}

// Print the queue
void printQueue(Queue *queue) {
    QueueNode *temp = queue->front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Destroy the queue
void destroyQueue(Queue *queue) {
    QueueNode *temp = queue->front;

    while (temp != NULL) {
        QueueNode *next = temp->next;
        free(temp);
        temp = next;
    }

    free(queue);
}

// Test the queue
int main() {
    Queue *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printQueue(queue);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    printQueue(queue);

    enqueue(queue, 6);
    enqueue(queue, 7);

    printQueue(queue);

    destroyQueue(queue);

    return 0;
}