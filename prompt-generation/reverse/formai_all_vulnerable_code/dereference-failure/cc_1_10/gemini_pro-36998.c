//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// A node in the queue
struct node {
    int data;
    struct node *next;
};

// The queue itself
struct queue {
    struct node *head;
    struct node *tail;
};

// Create a new queue
struct queue *create_queue() {
    struct queue *q = malloc(sizeof(struct queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

// Enqueue an item
void enqueue(struct queue *q, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->tail == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

// Dequeue an item
int dequeue(struct queue *q) {
    if (q->head == NULL) {
        return -1;
    }
    int data = q->head->data;
    struct node *new_head = q->head->next;
    free(q->head);
    q->head = new_head;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    return data;
}

// Print the queue
void print_queue(struct queue *q) {
    struct node *current = q->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Destroy the queue
void destroy_queue(struct queue *q) {
    while (q->head != NULL) {
        struct node *next_node = q->head->next;
        free(q->head);
        q->head = next_node;
    }
    free(q);
}

int main() {
    // Create a new queue
    struct queue *q = create_queue();

    // Enqueue some items
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Print the queue
    print_queue(q);

    // Dequeue some items
    dequeue(q);
    dequeue(q);

    // Print the queue
    print_queue(q);

    // Destroy the queue
    destroy_queue(q);

    return 0;
}