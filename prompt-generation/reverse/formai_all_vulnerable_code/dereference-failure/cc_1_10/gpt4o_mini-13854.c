//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_CAPACITY 100

typedef struct Queue {
    int front;
    int rear;
    int size;
    int* items;
} Queue;

// Function prototypes
Queue* createQueue();
bool isFull(Queue* queue);
bool isEmpty(Queue* queue);
void enqueue(Queue* queue, int item);
int dequeue(Queue* queue);
int peek(Queue* queue);
void destroyQueue(Queue* queue);
void displayQueue(Queue* queue);

// Create a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->items = (int*)malloc(QUEUE_CAPACITY * sizeof(int));
    return queue;
}

// Check if the queue is full
bool isFull(Queue* queue) {
    return queue->size == QUEUE_CAPACITY;
}

// Check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Add an element to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d.\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
    queue->items[queue->rear] = item;
    queue->size++;
    printf("Enqueued %d to the queue.\n", item);
}

// Remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return -1 if the queue is empty
    }
    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % QUEUE_CAPACITY;
    queue->size--;
    printf("Dequeued %d from the queue.\n", item);
    return item;
}

// Peek at the front element of the queue without removing it
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot peek.\n");
        return -1; // Return -1 if the queue is empty
    }
    return queue->items[queue->front];
}

// Destroy the queue
void destroyQueue(Queue* queue) {
    free(queue->items);
    free(queue);
    printf("Queue destroyed.\n");
}

// Display current elements of the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Current Queue: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->items[(queue->front + i) % QUEUE_CAPACITY]);
    }
    printf("\n");
}

// Main function for testing the queue implementation
int main() {
    Queue* myQueue = createQueue();

    displayQueue(myQueue);

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    displayQueue(myQueue);

    printf("Front element is: %d\n", peek(myQueue));

    dequeue(myQueue);
    displayQueue(myQueue);
    
    enqueue(myQueue, 40);
    enqueue(myQueue, 50);
    enqueue(myQueue, 60);
    enqueue(myQueue, 70);
    displayQueue(myQueue);

    while (!isEmpty(myQueue)) {
        dequeue(myQueue);
    }

    displayQueue(myQueue);
  
    destroyQueue(myQueue);
    return 0;
}