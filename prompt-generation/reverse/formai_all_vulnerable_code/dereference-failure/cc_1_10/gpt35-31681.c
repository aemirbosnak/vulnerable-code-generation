//FormAI DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define a Queue data structure
typedef struct Queue {
    int front;
    int rear;
    int size;
    int* arr;
} Queue;

// Create a function to enqueue a new element to the queue
void enqueue(Queue* q, int val) {
    // If the queue is full
    if (q->rear == q->size - 1) {
        printf("Queue overflow!\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = val;
}

// Create a function to dequeue the first element from the queue
int dequeue(Queue* q) {
    // If the queue is empty
    if (q->front > q->rear) {
        printf("Queue underflow!\n");
        return -1;
    }
    int val = q->arr[q->front];
    q->front++;
    return val;
}

// Create a function to display the queue elements
void display(Queue* q) {
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    // Create a queue object
    Queue* q = (Queue*) malloc(sizeof(Queue));

    // Initialize the queue values
    q->front = 0;
    q->rear = -1;
    q->size = 5;
    q->arr = (int*) malloc(q->size * sizeof(int));

    // Enqueue elements into the queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    // Display the queue elements
    display(q);

    // Dequeue the first element from the queue
    int val = dequeue(q);
    printf("Dequeued value: %d\n", val);

    // Display the queue elements after the dequeue operation
    display(q);

    // Enqueue another element into the queue
    enqueue(q, 50);

    // Display the queue elements after the enqueue operation
    display(q);

    // Dequeue remaining elements from the queue
    for (int i = 0; i < q->size; i++) {
        dequeue(q);
    }

    // Display the queue elements after the dequeue operation
    display(q);

    // Free the memory allocated for the queue
    free(q->arr);
    free(q);

    return 0;
}