//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

// A queue data structure
typedef struct queue {
    int front, rear;
    int size;
    int *array;
} queue;

// Create a new queue
queue *create_queue(int size) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = -1;
    q->size = size;
    q->array = (int *)malloc(q->size * sizeof(int));
    return q;
}

// Check if the queue is empty
int is_empty(queue *q) {
    return q->front == -1;
}

// Check if the queue is full
int is_full(queue *q) {
    return (q->rear + 1) % q->size == q->front;
}

// Add an element to the queue
void enqueue(queue *q, int data) {
    if (is_full(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->array[q->rear] = data;
}

// Remove an element from the queue
int dequeue(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = q->array[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return data;
}

// Print the queue
void print_queue(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->array[i]);
        i = (i + 1) % q->size;
    }
    printf("%d\n", q->array[q->rear]);
}

// Destroy the queue
void destroy_queue(queue *q) {
    free(q->array);
    free(q);
}

// Main function
int main() {
    // Create a queue of size 5
    queue *q = create_queue(5);

    // Enqueue some elements
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Print the queue
    printf("Queue: ");
    print_queue(q);

    // Dequeue some elements
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));

    // Print the queue
    printf("Queue: ");
    print_queue(q);

    // Destroy the queue
    destroy_queue(q);

    return 0;
}