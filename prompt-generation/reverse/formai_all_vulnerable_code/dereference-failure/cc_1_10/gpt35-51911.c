//FormAI DATASET v1.0 Category: Queue Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

// Create a new Queue
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the Queue is full
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Check if the Queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Add an element to the Queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("\nElement %d added to queue.\n", item);
}

// Remove an element from the Queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    printf("\nElement %d removed from queue.\n", item);
    return item;
}

// Display the current state of the Queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nCurrent state of queue:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

// Program entry point
int main() {

    printf("**********************************\n");
    printf("*** RETRO C QUEUE IMPLEMENTATION ***\n");
    printf("**********************************\n\n");

    // Create a Queue with capacity 5
    Queue* queue = createQueue(5);

    // Add some elements to the Queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Try to add more elements to the full Queue
    enqueue(queue, 60);
    enqueue(queue, 70);

    // Display the current state of the Queue
    display(queue);

    // Remove some elements from the Queue
    dequeue(queue);
    dequeue(queue);

    // Display the current state of the Queue
    display(queue);

    // Add some more elements to the Queue
    enqueue(queue, 60);
    enqueue(queue, 70);

    // Display the current state of the Queue
    display(queue);

    // Remove all elements from the Queue
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    // Display the current state of the Queue
    display(queue);

    return 0;
}