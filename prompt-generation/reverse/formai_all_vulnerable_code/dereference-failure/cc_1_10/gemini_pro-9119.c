//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define a node for a linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define a queue
typedef struct queue {
    node_t *head;
    node_t *tail;
} queue_t;

// Create a new queue
queue_t *create_queue() {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

// Enqueue an element into the queue
void enqueue(queue_t *queue, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (queue->head == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

// Dequeue an element from the queue
int dequeue(queue_t *queue) {
    if (queue->head == NULL) {
        return -1;
    }
    node_t *temp = queue->head;
    int data = temp->data;
    queue->head = queue->head->next;
    free(temp);
    return data;
}

// Print the queue
void print_queue(queue_t *queue) {
    node_t *temp = queue->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create a queue
    queue_t *queue = create_queue();

    // Enqueue some elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);

    // Print the queue
    printf("Queue: ");
    print_queue(queue);

    // Dequeue some elements from the queue
    int data = dequeue(queue);
    printf("Dequeued: %d\n", data);
    data = dequeue(queue);
    printf("Dequeued: %d\n", data);

    // Print the queue
    printf("Queue: ");
    print_queue(queue);

    return 0;
}