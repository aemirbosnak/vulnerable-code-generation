//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct queue {
    struct node *front;
    struct node *rear;
} queue;

queue *create_queue() {
    // Initialize the queue.
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(queue *q, int data) {
    // Create a new node.
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    // If the queue is empty, the new node is the first and last node.
    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    }
    // Otherwise, the new node is only the last node.
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(queue *q) {
    // Check if the queue is empty.
    if (q->front == NULL) {
        return -1;
    }
    // Get the data from the front node.
    int data = q->front->data;
    // If the queue has only one node, the queue is empty.
    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    }
    // Otherwise, the front node is deleted.
    else {
        q->front = q->front->next;
    }
    return data;
}

void print_queue(queue *q) {
    // Check if the queue is empty.
    if (q->front == NULL) {
        printf("The queue is empty.\n");
    }
    // Otherwise, print the data from each node.
    else {
        node *current_node = q->front;
        while (current_node != NULL) {
            printf("%d ", current_node->data);
            current_node = current_node->next;
        }
        printf("\n");
    }
}

int main() {
    // Create a queue.
    queue *q = create_queue();
    // Enqueue some data.
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    // Print the queue.
    print_queue(q);
    // Dequeue some data.
    dequeue(q);
    dequeue(q);
    // Print the queue.
    print_queue(q);
    // Dequeue the last data.
    dequeue(q);
    // Print the queue.
    print_queue(q);
    // Free the queue.
    free(q);
    return 0;
}