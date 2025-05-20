//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: peaceful
// This is a serene C program that implements a queue in a tranquil manner.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// A node in the queue, holding a value and a pointer to the next node.
struct node {
    int value;
    struct node *next;
};

// The queue itself, consisting of a head and a tail pointer.
struct queue {
    struct node *head;
    struct node *tail;
};

// Create a new queue.
struct queue *create_queue() {
    struct queue *queue = malloc(sizeof(struct queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

// Add an element to the tail of the queue.
void enqueue(struct queue *queue, int value) {
    struct node *node = malloc(sizeof(struct node));
    node->value = value;
    node->next = NULL;

    if (queue->tail == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
}

// Remove and return the element at the head of the queue.
int dequeue(struct queue *queue) {
    assert(queue->head != NULL);

    int value = queue->head->value;
    struct node *next = queue->head->next;
    free(queue->head);

    queue->head = next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    return value;
}

// Print the elements of the queue from head to tail.
void print_queue(struct queue *queue) {
    struct node *current = queue->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a new queue.
    struct queue *queue = create_queue();

    // Enqueue some elements.
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue.
    printf("Queue: ");
    print_queue(queue);

    // Dequeue some elements.
    printf("Dequeue: %d\n", dequeue(queue));
    printf("Dequeue: %d\n", dequeue(queue));
    printf("Dequeue: %d\n", dequeue(queue));

    // Print the queue again.
    printf("Queue: ");
    print_queue(queue);

    // Free the memory used by the queue.
    while (queue->head != NULL) {
        struct node *next = queue->head->next;
        free(queue->head);
        queue->head = next;
    }
    free(queue);

    return 0;
}