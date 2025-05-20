//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue node
typedef struct {
    int data;
    struct queue *next;
} queue_node;

// Structure to represent a queue
typedef struct {
    queue_node *front;
    queue_node *rear;
    int size;
} queue;

// Function to initialize a new queue
void queue_init(queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Function to insert an element at the end of the queue
void queue_enqueue(queue *q, int data) {
    queue_node *new_node = (queue_node *)malloc(sizeof(queue_node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }

    q->size++;
}

// Function to remove and return the element at the front of the queue
int queue_dequeue(queue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = q->front->data;
    queue_node *temp = q->front;

    q->front = q->front->next;
    free(temp);

    q->size--;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return data;
}

// Function to print the elements of the queue
void queue_print(queue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return;
    }

    queue_node *node = q->front;

    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }

    printf("\n");
}

// Main function
int main() {
    queue q;
    queue_init(&q);

    queue_enqueue(&q, 1);
    queue_enqueue(&q, 2);
    queue_enqueue(&q, 3);

    queue_print(&q); // Output: 1 2 3

    printf("Front element: %d\n", queue_dequeue(&q)); // Output: 1

    queue_print(&q); // Output: 2 3

    printf("Rear element: %d\n", queue_dequeue(&q)); // Output: 2

    queue_print(&q); // Output: 3

    printf("Front element: %d\n", queue_dequeue(&q)); // Output: 3

    queue_print(&q); // Output: Queue is empty

    return 0;
}