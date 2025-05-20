//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// A node in the queue
typedef struct node {
    int data;
    struct node *next;
} node;

// The queue itself
typedef struct queue {
    struct node *head;
    struct node *tail;
} queue;

// Create a new queue
queue *create_queue() {
    queue *q = malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

// Add an item to the queue
void enqueue(queue *q, int data) {
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

// Remove an item from the queue
int dequeue(queue *q) {
    if (q->head == NULL) {
        return -1; // Queue is empty
    }

    struct node *temp = q->head;
    int data = temp->data;

    q->head = temp->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(temp);
    return data;
}

// Check if the queue is empty
int is_empty(queue *q) {
    return q->head == NULL;
}

// Print the queue
void print_queue(queue *q) {
    struct node *temp = q->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main() {
    queue *q = create_queue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    print_queue(q);

    dequeue(q);
    print_queue(q);

    dequeue(q);
    print_queue(q);

    dequeue(q);
    print_queue(q);

    return 0;
}