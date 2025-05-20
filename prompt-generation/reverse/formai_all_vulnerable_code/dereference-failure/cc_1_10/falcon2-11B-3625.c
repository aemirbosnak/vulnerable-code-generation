//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the queue
typedef struct {
    int front;
    int rear;
    int capacity;
    int *queue;
} Queue;

// Initialize a new queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->queue = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// Add an element to the end of the queue
void enqueue(Queue* queue, int element) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full. Cannot enqueue more elements.\n");
        return;
    }
    queue->rear++;
    queue->queue[queue->rear] = element;
    printf("Enqueued %d\n", element);
}

// Remove the first element from the queue
int dequeue(Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty. Cannot dequeue any elements.\n");
        return -1;
    }
    int element = queue->queue[queue->front];
    queue->front++;
    printf("Dequeued %d\n", element);
    return element;
}

// Print the elements in the queue
void printQueue(Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    int i;
    printf("Queue elements: ");
    for (i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->queue[i]);
    }
    printf("\n");
}

int main() {
    // Create a queue with capacity 5
    Queue* queue = createQueue(5);

    // Enqueue elements to the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Print the queue
    printQueue(queue);

    // Dequeue elements from the queue
    int element = dequeue(queue);
    printf("Dequeued %d\n", element);
    element = dequeue(queue);
    printf("Dequeued %d\n", element);
    element = dequeue(queue);
    printf("Dequeued %d\n", element);

    // Print the queue again
    printQueue(queue);

    // Free the memory
    free(queue->queue);
    free(queue);

    return 0;
}