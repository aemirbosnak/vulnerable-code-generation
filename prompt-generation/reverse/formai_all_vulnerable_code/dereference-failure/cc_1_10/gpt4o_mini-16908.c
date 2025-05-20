//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_CAPACITY 10

typedef struct Queue {
    int* array;            // Pointer to the queue array
    int front;            // Index of the front element
    int rear;             // Index of the last element
    int count;            // Current count of elements in queue
} Queue;

// Function to create a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->array = (int*)malloc(QUEUE_CAPACITY * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return (queue->count == 0);
}

// Function to check if the queue is full
bool isFull(Queue* queue) {
    return (queue->count == QUEUE_CAPACITY);
}

// Function to enqueue an element
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
    queue->array[queue->rear] = item;
    queue->count++;
    printf("Enqueued %d\n", item);
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1; // Indicating an error
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % QUEUE_CAPACITY;
    queue->count--;
    printf("Dequeued %d\n", item);
    return item;
}

// Function to get the front element
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! No front element\n");
        return -1; // Indicating an error
    }
    return queue->array[queue->front];
}

// Function to get the size of the queue
int size(Queue* queue) {
    return queue->count;
}

// Function to delete the queue
void deleteQueue(Queue* queue) {
    free(queue->array);
    free(queue);
    printf("Queue deleted successfully.\n");
}

// Function to display the queue elements
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < queue->count; i++) {
        printf("%d ", queue->array[(queue->front + i) % QUEUE_CAPACITY]);
    }
    printf("\n");
}

// Main function for testing the queue implementation
int main() {
    Queue* queue = createQueue();
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    displayQueue(queue);

    dequeue(queue);
    displayQueue(queue);

    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);
    enqueue(queue, 90);
    enqueue(queue, 100);
    displayQueue(queue);

    printf("Front element is: %d\n", front(queue));
    printf("Queue size is: %d\n", size(queue));

    while (!isEmpty(queue)) {
        dequeue(queue);
    }

    displayQueue(queue);
    
    deleteQueue(queue);
    
    return 0;
}