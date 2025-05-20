//FormAI DATASET v1.0 Category: Queue ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

// Queue implementation using circular array
typedef struct {
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
} Queue;

// Initializes an empty queue
Queue* create_queue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    return q;
}

// Checks if queue is empty
int is_empty(Queue* q) {
    return (q->front == q->rear);
}

// Checks if queue is full
int is_full(Queue* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// Enqueues data onto the rear of the queue
void enqueue(Queue* q, int value) {
    if (is_full(q)) {
        printf("Error: Queue is full\n");
        return;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

// Dequeues the item at the front of the queue and returns its value
int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return value;
}

// Displays the queue contents from front to rear
void print_queue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}

int main() {
    Queue* q = create_queue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    print_queue(q); // Queue contents: 10 20 30 
    dequeue(q);
    print_queue(q); // Queue contents: 20 30
    enqueue(q, 40);
    enqueue(q, 50);
    print_queue(q); // Queue contents: 20 30 40 50
    enqueue(q, 60); // Error: Queue is full
    dequeue(q);
    dequeue(q);
    dequeue(q);
    print_queue(q); // Queue is empty
    return 0;
}