//FormAI DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

// Defining queue structure
typedef struct Queue {
    int front, rear, size;
    unsigned int capacity;
    int *array;
} Queue;

// Queue creation function
Queue *createQueue(unsigned int capacity) {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full function
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty function
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Add an element to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size += 1;
}

// Remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size -= 1;
    return item;
}

// Get the front element of the queue
int front(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->front];
}

// Get the rear element of the queue
int rear(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->rear];
}

// Main function
int main() {
    Queue *queue = createQueue(10);

    // Enqueue some elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Dequeue some elements
    dequeue(queue);

    // Enqueue some more elements
    enqueue(queue, 50);
    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);

    // Print front and rear elements of the queue
    printf("Front element is: %d\n", front(queue));
    printf("Rear element is: %d\n", rear(queue));

    // Dequeue all elements and print them
    printf("Elements in the queue are: ");
    while(!isEmpty(queue)) {
        printf("%d ", dequeue(queue));
    }

    return 0;
}