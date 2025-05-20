//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define the queue node
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define the queue
typedef struct queue {
    node_t *front;
    node_t *rear;
    int size;
} queue_t;

// Create a new queue
queue_t *create_queue() {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    if (queue == NULL) {
        return NULL;
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    return queue;
}

// Check if the queue is empty
int is_empty(queue_t *queue) {
    return (queue->size == 0);
}

// Enqueue an element
void enqueue(queue_t *queue, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }

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

// Dequeue an element
int dequeue(queue_t *queue) {
    if (is_empty(queue)) {
        return -1;
    }

    node_t *temp = queue->front;
    int data = temp->data;

    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;

    return data;
}

// Get the front element
int front(queue_t *queue) {
    if (is_empty(queue)) {
        return -1;
    }

    return queue->front->data;
}

// Get the rear element
int rear(queue_t *queue) {
    if (is_empty(queue)) {
        return -1;
    }

    return queue->rear->data;
}

// Get the size of the queue
int size(queue_t *queue) {
    return queue->size;
}

// Print the queue
void print_queue(queue_t *queue) {
    node_t *temp = queue->front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Destroy the queue
void destroy_queue(queue_t *queue) {
    while (!is_empty(queue)) {
        dequeue(queue);
    }

    free(queue);
}

// Main function
int main() {
    // Create a new queue
    queue_t *queue = create_queue();

    // Enqueue some elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    printf("Queue: ");
    print_queue(queue);

    // Dequeue some elements
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    // Print the queue
    printf("Queue: ");
    print_queue(queue);

    // Get the front and rear elements
    printf("Front: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));

    // Get the size of the queue
    printf("Size: %d\n", size(queue));

    // Destroy the queue
    destroy_queue(queue);

    return 0;
}