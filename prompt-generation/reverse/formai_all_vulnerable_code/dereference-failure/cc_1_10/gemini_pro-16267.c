//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Defines a futuristic Queue structure
typedef struct Queue {
    int *data;          // Array to store the elements of the queue
    int front, rear;    // Indices to track the front and rear of the queue
    int capacity;       // Maximum capacity of the queue
} Queue;

// Function to create a new Queue
Queue* createQueue(int size) {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->data = (int*) malloc(sizeof(int) * size);
    q->front = q->rear = -1;
    q->capacity = size;
    return q;
}

// Function to check if the Queue is full
int isFull(Queue* q) {
    return q->rear == q->capacity - 1;
}

// Function to check if the Queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to enqueue an element into the Queue
void enqueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->data[q->rear] = data;
}

// Function to dequeue an element from the Queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int data = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return data;
}

// Function to print the elements of the Queue
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

// Main function to test the Queue implementation
int main() {
    Queue* q = createQueue(5);

    // Enqueue some elements into the Queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Print the elements of the Queue
    printQueue(q);

    // Dequeue some elements from the Queue
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));

    // Print the elements of the Queue
    printQueue(q);

    return 0;
}