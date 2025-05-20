//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Baggage constants
#define MAX_BAGS 100
#define MAX_WEIGHT 50

// Queue structure
typedef struct queue {
    int front, rear;
    int size;
    int *array;
} Queue;

// Function to create a queue
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(queue->size * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear == queue->size - 1);
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

// Function to add an element to the queue
void enQueue(Queue* queue, int item) {
    if (isFull(queue)) {
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
}

// Function to remove an element from the queue
int deQueue(Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return item;
}

// Function to simulate the baggage handling system
void simulateBaggageHandling(int numBags) {
    // Create a queue to store the bags
    Queue* queue = createQueue(MAX_BAGS);

    // Generate random weights for the bags
    int weights[MAX_BAGS];
    srand(time(NULL));
    for (int i = 0; i < numBags; i++) {
        weights[i] = rand() % MAX_WEIGHT;
    }

    // Add the bags to the queue
    for (int i = 0; i < numBags; i++) {
        enQueue(queue, weights[i]);
    }

    // Simulate the baggage handling process
    int totalWeight = 0;
    while (!isEmpty(queue)) {
        int weight = deQueue(queue);
        totalWeight += weight;
    }

    // Print the total weight of the bags
    printf("Total weight of the bags: %d\n", totalWeight);
}

int main() {
    // Simulate the baggage handling system with 100 bags
    simulateBaggageHandling(100);
    return 0;
}