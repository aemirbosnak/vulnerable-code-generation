//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the queue
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define the structure of the queue
typedef struct queue {
    node_t *head;
    node_t *tail;
} queue_t;

// Create a new queue
queue_t *create_queue() {
    queue_t *queue = malloc(sizeof(queue_t));
    if (queue == NULL) {
        return NULL;
    }
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

// Destroy the queue
void destroy_queue(queue_t *queue) {
    node_t *current = queue->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}

// Enqueue an item into the queue
void enqueue(queue_t *queue, int item) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
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
int dequeue(queue_t *queue) {
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

// Print the queue
void print_queue(queue_t *queue) {
    node_t *current = queue->head;
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

    // Enqueue some items into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    print_queue(queue);

    // Dequeue some items from the queue
    dequeue(queue);
    dequeue(queue);

    // Print the queue
    print_queue(queue);

    // Destroy the queue
    destroy_queue(queue);

    return 0;
}