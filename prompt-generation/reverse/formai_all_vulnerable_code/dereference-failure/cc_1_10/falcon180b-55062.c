//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define our medieval-style queue structure
typedef struct {
    void **data;
    size_t front;
    size_t rear;
    size_t capacity;
} Queue;

// Initialize an empty queue with the given capacity
Queue *create_queue(size_t capacity) {
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL) {
        fprintf(stderr, "Failed to allocate memory for queue.\n");
        exit(EXIT_FAILURE);
    }
    queue->data = malloc(capacity * sizeof(void *));
    if (queue->data == NULL) {
        fprintf(stderr, "Failed to allocate memory for queue data.\n");
        exit(EXIT_FAILURE);
    }
    queue->front = 0;
    queue->rear = 0;
    queue->capacity = capacity;
    return queue;
}

// Enqueue an item onto the rear of the queue
void enqueue(Queue *queue, void *item) {
    if (queue->rear == queue->capacity) {
        fprintf(stderr, "Queue is full. Cannot enqueue item.\n");
        exit(EXIT_FAILURE);
    }
    void **data = queue->data;
    data[queue->rear++] = item;
}

// Dequeue an item from the front of the queue
void *dequeue(Queue *queue) {
    if (queue->front == queue->rear) {
        fprintf(stderr, "Queue is empty. Cannot dequeue item.\n");
        exit(EXIT_FAILURE);
    }
    void **data = queue->data;
    void *item = data[queue->front++];
    return item;
}

// Check if the queue is empty
int is_empty(Queue *queue) {
    return queue->front == queue->rear;
}

// Free the memory allocated for the queue and its data
void destroy_queue(Queue *queue) {
    free(queue->data);
    free(queue);
}

int main() {
    // Create a queue with capacity for 10 items
    Queue *queue = create_queue(10);

    // Enqueue some items onto the queue
    enqueue(queue, "sword");
    enqueue(queue, "shield");
    enqueue(queue, "helmet");

    // Dequeue an item from the front of the queue
    void *item = dequeue(queue);
    printf("Dequeued item: %s\n", (char *)item);

    // Check if the queue is empty
    if (is_empty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    // Destroy the queue and free its memory
    destroy_queue(queue);

    return 0;
}