//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the queue
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define the structure of the queue
typedef struct queue {
    node_t *front;
    node_t *rear;
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

// Free the memory allocated for the queue
void destroy_queue(queue_t *queue) {
    node_t *current = queue->front;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}

// Check if the queue is empty
int is_empty(queue_t *queue) {
    return queue->size == 0;
}

// Get the size of the queue
int get_size(queue_t *queue) {
    return queue->size;
}

// Enqueue an element into the queue
void enqueue(queue_t *queue, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
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
    if (is_empty(queue)) {
        return -1;
    }
    node_t *current = queue->front;
    int data = current->data;
    queue->front = current->next;
    free(current);
    queue->size--;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}

// Print the elements of the queue
void print_queue(queue_t *queue) {
    node_t *current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new queue
    queue_t *queue = create_queue();

    // Enqueue some elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the elements of the queue
    printf("Elements of the queue: ");
    print_queue(queue);

    // Dequeue some elements from the queue
    printf("Dequeue: %d\n", dequeue(queue));
    printf("Dequeue: %d\n", dequeue(queue));
    printf("Dequeue: %d\n", dequeue(queue));

    // Print the elements of the queue
    printf("Elements of the queue: ");
    print_queue(queue);

    // Destroy the queue
    destroy_queue(queue);

    return 0;
}