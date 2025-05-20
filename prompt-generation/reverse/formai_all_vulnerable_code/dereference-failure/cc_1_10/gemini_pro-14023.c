//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Create a new queue node
struct QueueNode {
    int data;
    struct QueueNode *next;
};

// Create a new queue
struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};

// Create a new queue node
struct QueueNode *createQueueNode(int data) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a new queue
struct Queue *createQueue() {
    struct Queue *newQueue = (struct Queue *)malloc(sizeof(struct Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == NULL);
}

// Add an element to the rear of the queue
void enqueue(struct Queue *queue, int data) {
    struct QueueNode *newNode = createQueueNode(data);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Remove an element from the front of the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        struct QueueNode *temp = queue->front;
        int data = temp->data;
        queue->front = queue->front->next;
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        free(temp);
        return data;
    }
}

// Print the queue
void printQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        struct QueueNode *temp = queue->front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
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
    // Create a new queue
    struct Queue *queue = createQueue();

    // Enqueue some elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    printf("Queue elements: ");
    printQueue(queue);

    // Dequeue some elements
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    // Print the queue
    printf("Queue elements: ");
    printQueue(queue);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}