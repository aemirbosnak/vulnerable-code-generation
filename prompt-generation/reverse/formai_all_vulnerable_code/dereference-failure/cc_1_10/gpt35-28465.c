//FormAI DATASET v1.0 Category: Queue Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum capacity of the queue

// Define Queue structure
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Initialize Queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if Queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->rear == -1)
        return 1;
    return 0;
}

// Check if Queue is full
int isFull(struct Queue* queue) {
    if (queue->rear == MAX_SIZE - 1)
        return 1;
    return 0;
}

// Add elements to the Queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Oops! The queue is full!\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->rear++;
    queue->items[queue->rear] = item;
    printf("%d enqueued successfully!\n", item);
}

// Remove elements from the Queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Oops! The queue is empty!\n");
        return -1;
    }
    item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    printf("%d dequeued successfully!\n", item);
    return item;
}

// Display the Queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Oops! The queue is empty!\n");
        return;
    }
    printf("The queue is: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    // Enqueue elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Display Queue
    display(queue);

    // Dequeue elements
    dequeue(queue);
    dequeue(queue);

    // Display Queue
    display(queue);

    return 0;
}