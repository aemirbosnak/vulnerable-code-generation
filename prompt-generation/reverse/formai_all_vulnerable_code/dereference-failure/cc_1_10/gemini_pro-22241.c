//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// A node in the queue
typedef struct node {
    int data;
    struct node *next;
} node;

// The queue itself
typedef struct queue {
    node *head;
    node *tail;
} queue;

// Create a new queue
queue *create_queue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = q->tail = NULL;
    return q;
}

// Check if the queue is empty
int is_empty(queue *q) {
    return q->head == NULL;
}

// Enqueue an item into the queue
void enqueue(queue *q, int item) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = item;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->head = q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

// Dequeue an item from the queue
int dequeue(queue *q) {
    if (is_empty(q)) {
        return -1;  // Queue is empty
    }

    int item = q->head->data;
    node *old_head = q->head;

    q->head = q->head->next;
    if (q->head == NULL) {  // Queue is now empty
        q->tail = NULL;
    }

    free(old_head);
    return item;
}

// Print the queue
void print_queue(queue *q) {
    node *current = q->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Free the queue
void free_queue(queue *q) {
    node *current = q->head;

    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }

    free(q);
}

// Example usage
int main() {
    queue *q = create_queue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    print_queue(q);  // Output: 1 2 3 4 5

    int item = dequeue(q);  // item = 1
    printf("%d\n", item);  // Output: 1

    print_queue(q);  // Output: 2 3 4 5

    free_queue(q);

    return 0;
}