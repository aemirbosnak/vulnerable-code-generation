//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define the structure of a queue node
typedef struct queue_node {
    int data;
    struct queue_node *next;
} queue_node_t;

// Define the structure of a queue
typedef struct queue {
    queue_node_t *front;
    queue_node_t *rear;
    int size;
} queue_t;

// Create a new queue
queue_t *create_queue() {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Enqueue an element to the queue
void enqueue(queue_t *queue, int data) {
    queue_node_t *new_node = (queue_node_t *)malloc(sizeof(queue_node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    queue->size++;
}

// Dequeue an element from the queue
int dequeue(queue_t *queue) {
    if (queue->front == NULL) {
        return -1;
    }

    int data = queue->front->data;
    queue_node_t *temp = queue->front;
    queue->front = queue->front->next;

    free(temp);
    queue->size--;
    return data;
}

// Check if the queue is empty
int is_empty(queue_t *queue) {
    return queue->size == 0;
}

// Get the size of the queue
int size(queue_t *queue) {
    return queue->size;
}

// Print the queue
void print_queue(queue_t *queue) {
    queue_node_t *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Destroy the queue
void destroy_queue(queue_t *queue) {
    while (queue->front != NULL) {
        queue_node_t *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}

// Main function
int main() {
    // Create a queue
    queue_t *queue = create_queue();

    // Enqueue some elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    print_queue(queue);

    // Dequeue some elements
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    // Print the queue
    print_queue(queue);

    // Destroy the queue
    destroy_queue(queue);

    return 0;
}