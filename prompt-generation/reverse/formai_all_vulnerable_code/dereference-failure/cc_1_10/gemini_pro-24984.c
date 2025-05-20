//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
typedef struct Queue {
    int *items;
    int front;
    int rear;
    int capacity;
} Queue;

// Create a new Queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->items = (int*) malloc(sizeof(int) * capacity);
    return queue;
}

// Check if the Queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Check if the Queue is full
int isFull(Queue* queue) {
    return queue->rear == queue->capacity - 1;
}

// Add an item to the rear of the Queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = item;
    printf("%d inserted to the queue\n", item);
}

// Remove an item from the front of the Queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    printf("%d removed from the queue\n", item);
    return item;
}

// Get the front item from the Queue
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->items[queue->front];
}

// Get the rear item from the Queue
int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->items[queue->rear];
}

// Print the Queue
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

// Destroy the Queue
void destroyQueue(Queue* queue) {
    free(queue->items);
    free(queue);
}
int main() {
    // Create a Queue of capacity 5
    Queue* queue = createQueue(5);

    // Check if the Queue is empty
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    // Enqueue some items into the Queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Print the Queue
    printQueue(queue);

    // Check if the Queue is full
    if (isFull(queue)) {
        printf("Queue is full\n");
    } else {
        printf("Queue is not full\n");
    }

    // Dequeue an item from the Queue
    int item = dequeue(queue);
    printf("Dequeued item: %d\n", item);

    // Get the front item from the Queue
    item = front(queue);
    printf("Front item: %d\n", item);

    // Get the rear item from the Queue
    item = rear(queue);
    printf("Rear item: %d\n", item);

    // Destroy the Queue
    destroyQueue(queue);

    return 0;
}