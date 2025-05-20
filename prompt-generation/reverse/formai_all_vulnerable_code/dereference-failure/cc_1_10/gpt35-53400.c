//FormAI DATASET v1.0 Category: Queue Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Defining the maximum size of the queue
#define MAX_QUEUE_SIZE 5

// Defining the queue structure
typedef struct {
    int queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function to check if the queue is full
int isFull(Queue *q) {
    return (q->rear == MAX_QUEUE_SIZE - 1);
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front > q->rear);
}

// Function to add an element to the queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert element.\n");
        return;
    }
    q->queue[++(q->rear)] = value;
    printf("%d enqueued successfully.\n", value);
}

// Function to remove an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot remove element.\n");
        return -1;
    }
    return q->queue[(q->front)++];
}

// Function to display the queue contents
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("The queue contents are:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d\t", q->queue[i]);
    }
    printf("\n");
}

int main() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;

    // Enqueuing elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60); // This will not get inserted as queue is full

    // Displaying the contents of the queue
    display(q);

    // Dequeueing elements
    int val1 = dequeue(q);
    int val2 = dequeue(q);
    int val3 = dequeue(q);

    // Displaying the contents of the queue
    display(q);

    // Enqueuing elements
    enqueue(q, 60);
    enqueue(q, 70);

    // Displaying the contents of the queue
    display(q);

    // Dequeueing elements
    int val4 = dequeue(q);
    int val5 = dequeue(q);

    // Displaying the contents of the queue
    display(q);

    // Dequeueing more elements
    int val6 = dequeue(q);
    int val7 = dequeue(q); // This will not get removed as queue is empty

    // Freeing the dynamically allocated memory
    free(q);

    return 0;
}