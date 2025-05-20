//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a queue node
typedef struct queue_node {
    int data;
    struct queue_node *next;
} queue_node;

// Define the structure of a queue
typedef struct queue {
    queue_node *front;
    queue_node *rear;
} queue;

// Create a new queue
queue *create_queue() {
    queue *q = (queue *) malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Check if the queue is empty
int is_empty(queue *q) {
    return (q->front == NULL);
}

// Enqueue an element into the queue
void enqueue(queue *q, int data) {
    queue_node *new_node = (queue_node *) malloc(sizeof(queue_node));
    new_node->data = data;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Dequeue an element from the queue
int dequeue(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        queue_node *temp = q->front;
        int data = temp->data;
        q->front = temp->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
        return data;
    }
}

// Print the queue
void print_queue(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
    } else {
        queue_node *temp = q->front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Destroy the queue
void destroy_queue(queue *q) {
    while (!is_empty(q)) {
        dequeue(q);
    }
    free(q);
}

// Main function
int main() {
    // Create a new queue
    queue *q = create_queue();

    // Enqueue some elements into the queue
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Print the queue
    print_queue(q);

    // Dequeue some elements from the queue
    dequeue(q);
    dequeue(q);

    // Print the queue
    print_queue(q);

    // Destroy the queue
    destroy_queue(q);

    return 0;
}