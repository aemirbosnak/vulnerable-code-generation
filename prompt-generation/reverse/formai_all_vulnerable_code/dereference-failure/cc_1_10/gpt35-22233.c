//FormAI DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5 // Maximum size of the queue

// Structure of our queue
typedef struct Queue {
    int items[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function to create a new empty queue
Queue* create_queue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int is_full(Queue* queue) {
    if (queue->rear == QUEUE_SIZE - 1) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int is_empty(Queue* queue) {
    if (queue->front == -1 && queue->rear == -1) {
        return 1;
    }
    return 0;
}

// Function to add an item to the queue
void enqueue(Queue* queue, int item) {
    if (is_full(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (is_empty(queue)) {
        queue->front = 0;
        queue->rear = 0;
        queue->items[0] = item;
    } else {
        queue->rear++;
        queue->items[queue->rear] = item;
    }
    printf("%d enqueued to the queue.\n", item);
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    int item;
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    printf("%d dequeued from the queue.\n", item);
    return item;
}

// Main function
int main() {
    Queue* queue = create_queue();

    // Artistically enqueueing some items
    printf("Enqueuing items to the queue...\n");
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Trying to enqueue an extra item (not enough space in the queue)
    printf("\nTrying to enqueue another item...\n");
    enqueue(queue, 6);

    // Artistically dequeuing some items
    printf("\nDequeuing items from the queue...\n");
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    // Trying to dequeue an extra item (queue is empty)
    printf("\nTrying to dequeue another item...\n");
    dequeue(queue);

    return 0;
}