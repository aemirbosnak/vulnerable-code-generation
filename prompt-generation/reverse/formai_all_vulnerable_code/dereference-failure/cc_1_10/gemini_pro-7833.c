//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue and the data type of the elements
#define MAX_QUEUE_SIZE 100
typedef int element_t;

// Create a struct to represent a queue
typedef struct queue {
    element_t data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} queue_t;

// Create a new queue
queue_t *create_queue() {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->front = queue->rear = -1;
    return queue;
}

// Check if the queue is empty
int is_empty(queue_t *queue) {
    return queue->front == -1;
}

// Check if the queue is full
int is_full(queue_t *queue) {
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

// Get the size of the queue
int size(queue_t *queue) {
    return (queue->rear - queue->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

// Enqueue an element into the queue
void enqueue(queue_t *queue, element_t element) {
    if (is_full(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }
    queue->data[queue->rear] = element;
}

// Dequeue an element from the queue
element_t dequeue(queue_t *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    element_t element = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }
    return element;
}

// Print the queue
void print_queue(queue_t *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("%d\n", queue->data[i]);
}

// Free the queue
void free_queue(queue_t *queue) {
    free(queue);
}

int main() {
    // Create a new queue
    queue_t *queue = create_queue();

    // Enqueue some elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    print_queue(queue);

    // Dequeue some elements from the queue
    dequeue(queue);
    dequeue(queue);

    // Print the queue again
    print_queue(queue);

    // Free the queue
    free_queue(queue);

    return 0;
}