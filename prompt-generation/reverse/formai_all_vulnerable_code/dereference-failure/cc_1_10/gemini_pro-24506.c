//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

// Define the queue structure
struct Queue {
    int *elements;
    size_t head;
    size_t tail;
    size_t capacity;
};

// Create a new queue with the specified capacity
struct Queue *queue_create(size_t capacity) {
    // Allocate memory for the queue and its elements
    struct Queue *queue = malloc(sizeof(struct Queue));
    queue->elements = malloc(capacity * sizeof(int));

    // Initialize the queue's metadata
    queue->head = 0;
    queue->tail = 0;
    queue->capacity = capacity;

    return queue;
}

// Destroy the specified queue, freeing its associated memory
void queue_destroy(struct Queue *queue) {
    // Free the memory allocated for the queue's elements
    free(queue->elements);

    // Free the memory allocated for the queue itself
    free(queue);
}

// Enqueue an element onto the specified queue
void queue_enqueue(struct Queue *queue, int element) {
    // Check if the queue is full
    if ((queue->tail + 1) % queue->capacity == queue->head) {
        // The queue is full, so we need to reallocate its elements
        size_t new_capacity = queue->capacity * 2;
        int *new_elements = malloc(new_capacity * sizeof(int));

        // Copy the elements from the old array to the new array
        for (size_t i = 0; i < queue->capacity; i++) {
            new_elements[i] = queue->elements[(queue->head + i) % queue->capacity];
        }

        // Free the memory allocated for the old array
        free(queue->elements);

        // Update the queue's metadata
        queue->elements = new_elements;
        queue->head = 0;
        queue->tail = queue->capacity - 1;
        queue->capacity = new_capacity;
    }

    // Enqueue the element onto the queue
    queue->elements[queue->tail] = element;
    queue->tail = (queue->tail + 1) % queue->capacity;
}

// Dequeue an element from the specified queue
int queue_dequeue(struct Queue *queue) {
    // Check if the queue is empty
    if (queue->head == queue->tail) {
        // The queue is empty, so we cannot dequeue an element
        return -1;
    }

    // Dequeue the element from the queue
    int element = queue->elements[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;

    return element;
}

// Get the size of the specified queue
size_t queue_size(struct Queue *queue) {
    return (queue->tail - queue->head + queue->capacity) % queue->capacity;
}

// Check if the specified queue is empty
bool queue_is_empty(struct Queue *queue) {
    return queue->head == queue->tail;
}

// Print the elements of the specified queue to the console
void queue_print(struct Queue *queue) {
    if (queue->head == queue->tail) {
        // The queue is empty, so there are no elements to print
        printf("The queue is empty.\n");
    } else {
        // The queue is not empty, so we can print its elements
        printf("The elements of the queue are: ");
        for (size_t i = 0; i < queue_size(queue); i++) {
            printf("%d ", queue->elements[(queue->head + i) % queue->capacity]);
        }
        printf("\n");
    }
}

// Test the queue implementation
int main() {
    // Create a new queue with a capacity of 5
    struct Queue *queue = queue_create(5);

    // Enqueue some elements onto the queue
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 3);
    queue_enqueue(queue, 4);

    // Print the elements of the queue
    queue_print(queue);

    // Dequeue an element from the queue
    int element = queue_dequeue(queue);

    // Print the elements of the queue
    queue_print(queue);

    // Free the memory associated with the queue
    queue_destroy(queue);

    return 0;
}