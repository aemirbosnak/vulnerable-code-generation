//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100 // Maximum size of the Queue

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a Queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the Queue is full
bool isFull(Queue* q) {
    return (q->rear == MAX - 1);
}

// Check if the Queue is empty
bool isEmpty(Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

// Enqueue an element in the Queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) 
        q->front = 0; // Initialize front
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue an element from the Queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1; // Reset the queue
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Display the Queue elements
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Mathematical operations
int sumQueue(Queue* q) {
    int sum = 0;
    for (int i = q->front; i <= q->rear; i++) {
        sum += q->items[i];
    }
    return sum;
}

float meanQueue(Queue* q) {
    if (isEmpty(q)) return 0;
    return (float)sumQueue(q) / (q->rear - q->front + 1);
}

// Main function to demonstrate Queue operations
int main() {
    Queue* q = createQueue();

    // Enqueue some mathematical values
    for (int i = 1; i <= 10; i++) {
        enqueue(q, i * i);  // Enqueue squares of numbers
    }
    
    // Display the queue
    display(q);
    
    // Calculate the sum and mean
    printf("Sum of Queue elements: %d\n", sumQueue(q));
    printf("Mean of Queue elements: %.2f\n", meanQueue(q));
    
    // Dequeue some elements
    for (int i = 0; i < 3; i++) {
        dequeue(q);
    }
    
    // Display the queue again
    display(q);
    
    // Enqueue more values
    for (int i = 11; i <= 15; i++) {
        enqueue(q, i * i * i);  // Enqueue cubes of numbers
    }
    
    // Final display of the queue
    display(q);
    printf("Sum of Queue elements: %d\n", sumQueue(q));
    printf("Mean of Queue elements: %.2f\n", meanQueue(q));
    
    // Clean up
    free(q);
    return 0;
}