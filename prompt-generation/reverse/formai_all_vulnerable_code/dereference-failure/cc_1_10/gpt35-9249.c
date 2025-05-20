//FormAI DATASET v1.0 Category: Queue ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

// Define the Queue struct
typedef struct Queue {
    int *items;
    int front;
    int rear;
} Queue;

// Initialize an empty queue
Queue *createQueue() {
    Queue *q = malloc(sizeof(Queue));
    q->items = malloc(sizeof(int) * MAX_QUEUE_SIZE);
    q->front = -1;
    q->rear = -1;
    return q;
}

// Returns true if queue is full
int isFull(Queue *queue) {
    return queue->rear == MAX_QUEUE_SIZE - 1;
}

// Returns true if queue is empty
int isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Insert new element to queue
void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue element %d\n", value);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = value;
    printf("Enqueued element %d\n", value);
}

// Removes an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue element\n");
        return -1;
    }
    int dequeued = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    printf("Dequeued element %d\n", dequeued);
    return dequeued;
}

// Displays the queue elements
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    Queue *queue = createQueue();

    // Enqueue some elements
    enqueue(queue, 4);
    enqueue(queue, 8);
    enqueue(queue, 12);
    enqueue(queue, 16);
    enqueue(queue, 20);

    // Dequeue some elements
    dequeue(queue);
    dequeue(queue);

    // Add some more elements
    enqueue(queue, 24);
    enqueue(queue, 28);
    enqueue(queue, 32);
    enqueue(queue, 36);

    // Display the final queue elements
    display(queue);

    return 0;
}