//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// A node in the queue
typedef struct node {
    int data;
    struct node *next;
} node_t;

// The queue itself
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
    }
    int data = queue->front->data;
    node_t *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// Print the queue
void print_queue(queue_t *queue) {
    node_t *current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Destroy the queue
void destroy_queue(queue_t *queue) {
    node_t *current = queue->front;
    while (current != NULL) {
        node_t *temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}

int main() {
    queue_t *queue = create_queue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    print_queue(queue);

    dequeue(queue);
    dequeue(queue);

    print_queue(queue);

    destroy_queue(queue);

    return 0;
}