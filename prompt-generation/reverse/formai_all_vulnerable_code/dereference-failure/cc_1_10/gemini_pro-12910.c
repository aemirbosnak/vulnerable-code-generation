//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Queue node
struct QueueNode {
    int data;
    struct QueueNode *next;
};

// Queue
struct Queue {
    struct QueueNode *front, *rear;
};

// Create a new queue
struct Queue* createQueue() {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Check if the queue is empty
int isEmptyQueue(struct Queue *queue) {
    return (queue->front == NULL);
}

// Enqueue an element into the queue
void enQueue(struct Queue *queue, int data) {
    struct QueueNode *newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue an element from the queue
int deQueue(struct Queue *queue) {
    if (isEmptyQueue(queue)) {
        return -1;
    }
    struct QueueNode *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// Print the queue
void printQueue(struct Queue *queue) {
    struct QueueNode *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Destroy the queue
void destroyQueue(struct Queue *queue) {
    struct QueueNode *temp;
    while (queue->front != NULL) {
        temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}

int main() {
    // Create a queue
    struct Queue *queue = createQueue();

    // Enqueue some elements into the queue
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);

    // Print the queue
    printf("Queue: ");
    printQueue(queue);

    // Dequeue some elements from the queue
    printf("Dequeued: %d\n", deQueue(queue));
    printf("Dequeued: %d\n", deQueue(queue));

    // Print the queue
    printf("Queue: ");
    printQueue(queue);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}