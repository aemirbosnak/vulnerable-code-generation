//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>

// A node in the queue
typedef struct node {
    int data;
    struct node *next;
} node_t;

// The queue itself
typedef struct queue {
    node_t *head;
    node_t *tail;
} queue_t;

// Create a new queue
queue_t *queue_new() {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

// Destroy a queue
void queue_destroy(queue_t *queue) {
    node_t *current = queue->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}

// Enqueue an item onto the queue
void queue_enqueue(queue_t *queue, int item) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = item;
    new_node->next = NULL;
    if (queue->tail == NULL) {
        queue->head = new_node;
    } else {
        queue->tail->next = new_node;
    }
    queue->tail = new_node;
}

// Dequeue an item from the queue
int queue_dequeue(queue_t *queue) {
    if (queue->head == NULL) {
        return -1;
    }
    int item = queue->head->data;
    node_t *old_head = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(old_head);
    return item;
}

// Peek at the next item in the queue
int queue_peek(queue_t *queue) {
    if (queue->head == NULL) {
        return -1;
    }
    return queue->head->data;
}

// Check if the queue is empty
int queue_is_empty(queue_t *queue) {
    return queue->head == NULL;
}

// Print the queue
void queue_print(queue_t *queue) {
    node_t *current = queue->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Test the queue
int main() {
    queue_t *queue = queue_new();
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 3);
    queue_print(queue);
    printf("Dequeue: %d\n", queue_dequeue(queue));
    queue_print(queue);
    printf("Peek: %d\n", queue_peek(queue));
    printf("Is empty: %d\n", queue_is_empty(queue));
    queue_destroy(queue);
    return 0;
}