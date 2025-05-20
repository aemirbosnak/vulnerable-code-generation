//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// We'll be using a circular buffer to implement the queue.
struct Queue {
    int *array;
    int size;
    int head;
    int tail;
};

// Create a new queue with a given size.
struct Queue *create_queue(int size) {
    struct Queue *queue = malloc(sizeof(struct Queue));
    if (!queue) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    queue->array = malloc(sizeof(int) * size);
    if (!queue->array) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    queue->size = size;
    queue->head = 0;
    queue->tail = 0;

    return queue;
}

// Destroy the queue and free its resources.
void destroy_queue(struct Queue *queue) {
    free(queue->array);
    free(queue);
}

// Enqueue an item into the queue.
void enqueue(struct Queue *queue, int item) {
    if ((queue->tail + 1) % queue->size == queue->head) {
        printf("Queue is full!\n");
        return;
    }

    queue->array[queue->tail] = item;
    queue->tail = (queue->tail + 1) % queue->size;
}

// Dequeue an item from the queue.
int dequeue(struct Queue *queue) {
    if (queue->head == queue->tail) {
        printf("Queue is empty!\n");
        return -1;
    }

    int item = queue->array[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return item;
}

// Check if the queue is empty.
bool is_empty(struct Queue *queue) {
    return queue->head == queue->tail;
}

// Check if the queue is full.
bool is_full(struct Queue *queue) {
    return (queue->tail + 1) % queue->size == queue->head;
}

// Get the size of the queue.
int get_size(struct Queue *queue) {
    return queue->size;
}

// Print the queue.
void print_queue(struct Queue *queue) {
    printf("Queue: ");
    for (int i = queue->head; i != queue->tail; i = (i + 1) % queue->size) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    // Create a queue of size 5.
    struct Queue *queue = create_queue(5);

    // Enqueue some items into the queue.
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue.
    print_queue(queue);

    // Dequeue some items from the queue.
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    // Print the queue.
    print_queue(queue);

    // Destroy the queue.
    destroy_queue(queue);

    return 0;
}