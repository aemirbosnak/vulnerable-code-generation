//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Queue structure
typedef struct queue {
    node_t *front, *rear;
    int size;
} queue_t;

// Function to create a new queue
queue_t *create_queue() {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
int is_empty(queue_t *queue) {
    return queue->size == 0;
}

// Function to add an element to the queue
void enqueue(queue_t *queue, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (is_empty(queue)) {
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    queue->size++;
}

// Function to remove an element from the queue
int dequeue(queue_t *queue) {
    if (is_empty(queue)) {
        return -1;
    }

    node_t *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;
    return data;
}

// Function to print the queue
void print_queue(queue_t *queue) {
    node_t *temp = queue->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main() {
    queue_t *queue = create_queue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    print_queue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    print_queue(queue);

    return 0;
}