//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// A node in the queue
typedef struct node {
    int data;
    struct node *next;
} node;

// The queue itself
typedef struct queue {
    node *front;
    node *rear;
    int size;
} queue;

// Create a new queue
queue* create_queue() {
    queue *q = malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Check if the queue is empty
int is_empty(queue *q) {
    return q->size == 0;
}

// Add an element to the rear of the queue
void enqueue(queue *q, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(q)) {
        q->front = new_node;
    } else {
        q->rear->next = new_node;
    }
    q->rear = new_node;
    q->size++;
}

// Remove an element from the front of the queue
int dequeue(queue *q) {
    if (is_empty(q)) {
        return -1;
    }
    int data = q->front->data;
    node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return data;
}

// Print the queue
void print_queue(queue *q) {
    node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Destroy the queue
void destroy_queue(queue *q) {
    while (!is_empty(q)) {
        dequeue(q);
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
    print_queue(q); // 1 2 3 4 5
    dequeue(q);      // 1
    dequeue(q);      // 2
    print_queue(q); // 3 4 5
    enqueue(q, 6);
    enqueue(q, 7);
    print_queue(q); // 3 4 5 6 7
    destroy_queue(q);
    return 0;
}