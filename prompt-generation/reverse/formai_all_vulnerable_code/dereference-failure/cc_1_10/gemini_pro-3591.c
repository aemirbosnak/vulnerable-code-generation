//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct Queue {
    int *items;
    int front;
    int rear;
    int size;
};

// Create a new queue
struct Queue* createQueue(int size) {
    struct Queue *queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->items = (int*) malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Check if the queue is full
int isFull(struct Queue *queue) {
    if (queue->rear == queue->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
    if (queue->front == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Add an element to the queue
void enqueue(struct Queue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = element;
        printf("%d inserted to the queue\n", element);
    }
}

// Remove an element from the queue
int dequeue(struct Queue *queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return(-1);
    } else {
        element = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("%d deleted from the queue\n", element);
        return(element);
    }
}

// Print the queue
void printQueue(struct Queue *queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

// Destroy the queue
void destroyQueue(struct Queue *queue) {
    free(queue->items);
    free(queue);
}

// Main function to test the queue
int main() {
    // Create a queue of size 5
    struct Queue *queue = createQueue(5);

    // Enqueue elements to the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Print the queue
    printQueue(queue);

    // Dequeue elements from the queue
    dequeue(queue);
    dequeue(queue);

    // Print the queue
    printQueue(queue);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}