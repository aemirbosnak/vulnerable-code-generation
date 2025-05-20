//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the queue data structure
typedef struct Queue {
    int *arr;
    int head;
    int tail;
    int capacity;
} Queue;

// Create a new queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (int*)malloc(sizeof(int) * capacity);
    queue->head = 0;
    queue->tail = 0;
    queue->capacity = capacity;
    return queue;
}

// Destroy a queue
void destroyQueue(Queue* queue) {
    free(queue->arr);
    free(queue);
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->head == queue->tail;
}

// Get the size of the queue
int size(Queue* queue) {
    return (queue->tail - queue->head + queue->capacity) % queue->capacity;
}

// Enqueue an element
void enqueue(Queue* queue, int element) {
    if ((queue->tail + 1) % queue->capacity == queue->head) {
        printf("Queue is full\n");
    } else {
        queue->arr[queue->tail] = element;
        queue->tail = (queue->tail + 1) % queue->capacity;
    }
}

// Dequeue an element
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int element = queue->arr[queue->head];
        queue->head = (queue->head + 1) % queue->capacity;
        return element;
    }
}

// Print the queue
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        for (int i = queue->head; i != queue->tail; i = (i + 1) % queue->capacity) {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}

// Test the queue
int main() {
    Queue* queue = createQueue(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printQueue(queue);

    printf("Size of the queue: %d\n", size(queue));

    int element = dequeue(queue);
    printf("Dequeued element: %d\n", element);

    printQueue(queue);

    destroyQueue(queue);

    return 0;
}