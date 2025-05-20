//FormAI DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Structure for Queue
struct queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Function to create a Queue
struct queue* createQueue(unsigned capacity) {
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->array = (int*) malloc(q->capacity * sizeof(int));
    return q;
}

// Function to check if Queue is full
int isFull(struct queue* q) {
    return (q->size == q->capacity);
}

// Function to check if Queue is empty
int isEmpty(struct queue* q) {
    return (q->size == 0);
}

// Function to add an element to the Queue
void enqueue(struct queue* q, int item) {
    if (isFull(q))
        return;
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
    q->size = q->size + 1;
    printf("%d enqueued to queue\n", item);
}

// Function to remove an element from the Queue
int dequeue(struct queue* q) {
    if (isEmpty(q))
        return -1;
    int item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    return item;
}

// Main Function
int main() {
    struct queue* q = createQueue(5);

    // Adding elements to Queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    // Removing elements from Queue
    printf("%d dequeued from queue\n", dequeue(q));
    printf("%d dequeued from queue\n", dequeue(q));

    // Adding more elements to Queue
    enqueue(q, 50);
    enqueue(q, 60);

    // Removing remaining elements from Queue
    while (!isEmpty(q))
        printf("%d dequeued from queue\n", dequeue(q));

    // Freeing the allocated memory
    free(q->array);
    free(q);

    return 0;
}