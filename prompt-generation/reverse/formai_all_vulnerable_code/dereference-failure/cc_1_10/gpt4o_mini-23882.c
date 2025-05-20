//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Structure to represent a Queue
typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

// Function to create a Queue of given capacity
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // This is important, see the enqueue
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes equal to the capacity
bool isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue. It changes rear and size
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity; // Circular increment
    queue->array[queue->rear] = item;
    queue->size++;
    printf("Enqueued %d to the queue\n", item);
}

// Function to remove an item from the queue. It changes front and size
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return a sentinel value in case of error
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity; // Circular increment
    queue->size--;
    printf("Dequeued %d from the queue\n", item);
    return item;
}

// Function to return the front item from the queue without removing it
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! No front item.\n");
        return -1; // Return a sentinel value
    }
    return queue->array[queue->front];
}

// Function to return the rear item from the queue without removing it
int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! No rear item.\n");
        return -1; // Return a sentinel value
    }
    return queue->array[queue->rear];
}

// Function to display the queue elements
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

// Main function to test the queue operations
int main() {
    Queue* queue = createQueue(MAX);
    
    // Test enqueue operation
    for (int i = 0; i < 5; i++) {
        enqueue(queue, i + 1); // Enqueue 1 to 5
    }
    
    displayQueue(queue); // Display current queue
    
    // Test dequeue operation
    dequeue(queue);
    displayQueue(queue); // Display queue after dequeue
    
    // Test front and rear operations
    printf("Front item is: %d\n", front(queue));
    printf("Rear item is: %d\n", rear(queue));
    
    // Test enqueue when full
    for (int i = 5; i < 105; i++) { // Try enqueueing beyond queue limit
        enqueue(queue, i + 1);
    }

    // Final state of queue
    displayQueue(queue);

    // Clean up memory
    free(queue->array);
    free(queue);
    
    return 0;
}