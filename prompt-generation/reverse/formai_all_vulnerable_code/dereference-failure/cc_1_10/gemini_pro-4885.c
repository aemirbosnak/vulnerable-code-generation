//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the data structures
typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct queue {
    node_t *front;
    node_t *rear;
} queue_t;

// Create a new queue
queue_t *create_queue() {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Enqueue an element into the queue
void enqueue(queue_t *queue, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

// Dequeue an element from the queue
int dequeue(queue_t *queue) {
    if (queue->front == NULL) {
        return -1;
    } else {
        node_t *temp = queue->front;
        int data = temp->data;
        queue->front = temp->next;
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        free(temp);
        return data;
    }
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

    // Print the queue
    printf("Queue: ");
    print_queue(queue);

    // Dequeue some elements from the queue
    dequeue(queue);
    dequeue(queue);

    // Print the queue
    printf("Queue: ");
    print_queue(queue);

    return 0;
}