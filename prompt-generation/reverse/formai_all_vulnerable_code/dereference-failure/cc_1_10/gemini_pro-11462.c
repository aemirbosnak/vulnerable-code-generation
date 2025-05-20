//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Queue node
struct node {
    int data;
    struct node *next;
};

// Queue
struct queue {
    struct node *front;
    struct node *rear;
};

// Create a new queue
struct queue *create_queue() {
    struct queue *q = malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Check if queue is empty
int is_empty(struct queue *q) {
    return q->front == NULL;
}

// Enqueue an item
void enqueue(struct queue *q, int item) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = item;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Dequeue an item
int dequeue(struct queue *q) {
    if (is_empty(q)) {
        return -1;
    }

    int item = q->front->data;
    struct node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return item;
}

// Print the queue
void print_queue(struct queue *q) {
    struct node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Destroy the queue
void destroy_queue(struct queue *q) {
    while (!is_empty(q)) {
        dequeue(q);
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