//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
    int size;
} Queue;

// Function to create a queue and initialize its properties
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue) {
        queue->front = -1;
        queue->rear = -1;
        queue->size = 0;
    }
    return queue;
}

// Check if the queue is full
bool isFull(Queue* queue) {
    return queue->size == MAX;
}

// Check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Enqueue an element to the queue
bool enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return false;
    }
    
    if (queue->rear == MAX - 1) {
        queue->rear = -1;  // Wrap around
    }
    
    queue->items[++queue->rear] = value;
    queue->size++;
    
    if (queue->front == -1) {  // First element added
        queue->front = 0;
    }
    
    printf("Enqueued %d into the queue\n", value);
    return true;
}

// Dequeue an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;  // Indicate that the queue is empty
    }
    
    int value = queue->items[queue->front++];
    if (queue->front == MAX) {
        queue->front = 0;  // Wrap around
    }
    
    queue->size--;
    if (isEmpty(queue)) {  // Reset front and rear
        queue->front = -1;
        queue->rear = -1;
    }
    
    printf("Dequeued %d from the queue\n", value);
    return value;
}

// Peek at the front element of the queue
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Nothing to peek\n");
        return -1;  // Indicate that the queue is empty
    }
    return queue->items[queue->front];
}

// Display the queue contents
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue contents: ");
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % MAX;
        printf("%d ", queue->items[index]);
    }
    printf("\n");
}

void freeQueue(Queue* queue) {
    free(queue);
}

// Main program to demonstrate the queue implementation
int main() {
    Queue* queue = createQueue();
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    displayQueue(queue);
    
    printf("Front element is: %d\n", peek(queue));
    
    dequeue(queue);
    displayQueue(queue);
    
    enqueue(queue, 40);
    enqueue(queue, 50);
    displayQueue(queue);
    
    printf("Front element is: %d\n", peek(queue));
    
    dequeue(queue);
    dequeue(queue);
    displayQueue(queue);

    freeQueue(queue);
    return 0;
}