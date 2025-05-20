//FormAI DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue* create_queue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void print_queue(Queue* q);

int main() {
    // Create new queue
    Queue* q = create_queue();

    // Enqueue some values
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    // Print the queue
    printf("Queue: ");
    print_queue(q);

    // Dequeue some values
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    // Print the queue again
    printf("Queue: ");
    print_queue(q);

    // Enqueue some more values
    enqueue(q, 5);
    enqueue(q, 6);

    // Print the queue again
    printf("Queue: ");
    print_queue(q);

    // Free the queue
    free(q);

    return 0;
}

/*
 * Creates a new empty queue
 */
Queue* create_queue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

/*
 * Adds an element to the back of the queue
 */
void enqueue(Queue* q, int value) {
    // Check if the queue is full
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Error: Queue is full\n");
        return;
    }

    // Update rear and add new element
    if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = value;
}

/*
 * Removes an element from the front of the queue and returns it
 */
int dequeue(Queue* q) {
    // Check if the queue is empty
    if (q->front == -1) {
        printf("Error: Queue is empty\n");
        return -1;
    }

    // Remove front element and update front
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

/*
 * Prints all elements of the queue
 */
void print_queue(Queue* q) {
    // Check if the queue is empty
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }

    // Loop through all elements and print them
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}