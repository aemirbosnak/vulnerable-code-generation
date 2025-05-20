//FormAI DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Maximum size of queue

// Structure definition for Queue
struct Queue {
    int front;
    int rear;
    int count;
    int array[MAX_SIZE];
};

// Function to initialize a queue
struct Queue* initQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
    return queue;
}

// Function to check if queue is empty
int isQueueEmpty(struct Queue* queue) {
    return queue->count == 0;
}

// Function to check if queue is full
int isQueueFull(struct Queue* queue) {
    return queue->count == MAX_SIZE;
}

// Function to insert an element in queue
void enqueue(struct Queue* queue, int value) {
    if (isQueueFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = value;
    queue->count++;
}

// Function to delete an element from queue
void dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow\n");
        return;
    }
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->count--;
}

// Function to get the front element of queue
int front(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue->array[queue->front];
}

// Function to get the rear element of queue
int rear(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue->array[queue->rear];
}

// Function to display elements of queue
void display(struct Queue* queue) {
    int i;
    if (isQueueEmpty(queue)) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue Elements: ");
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue->array[i]);
    }
    printf("%d\n", queue->array[i]);
}

// Main function
int main() {
    struct Queue* queue = initQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue); // Output: Queue Elements: 10 20 30

    dequeue(queue);
    display(queue); // Output: Queue Elements: 20 30

    enqueue(queue, 40);
    enqueue(queue, 50);
    display(queue); // Output: Queue Elements: 20 30 40 50

    dequeue(queue);
    display(queue); // Output: Queue Elements: 30 40 50

    printf("Front Element: %d\n", front(queue)); // Output: Front Element: 30
    printf("Rear Element: %d\n", rear(queue)); // Output: Rear Element: 50

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue); // Output: Queue is Empty

    free(queue); // Deallocate memory

    return 0;
}