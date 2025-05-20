//FormAI DATASET v1.0 Category: Queue ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Define the queue struct
typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is full
int isFull(Queue *queue) {
    if (queue->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    return 0;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    if (queue->front == -1)
        return 1;
    return 0;
}

// Add an item to the queue
void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
    } else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Remove an item from the queue
int dequeue(Queue *queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// Display the queue
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue contains the following elements:\n");
        for (int i = queue->front; i <= queue->rear; i++)
            printf("%d ", queue->items[i]);
        printf("\n");
    }
}

int main() {
    Queue *queue = malloc(sizeof(Queue));

    initQueue(queue);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("Dequeuing: %d\n", dequeue(queue));
    printf("Dequeuing: %d\n", dequeue(queue));

    display(queue);

    free(queue);
    return 0;
}