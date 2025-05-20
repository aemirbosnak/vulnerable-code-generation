//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGGAGE 10

// Structure for the baggage
struct Baggage {
    int id;
    int weight;
    char destination[50];
};

// Queue implementation for the baggage handling system
struct BaggageQueue {
    int count;
    int front;
    int rear;
    struct Baggage baggage[MAX_BAGGAGE];
};

// Create a new baggage queue
struct BaggageQueue* createQueue() {
    struct BaggageQueue* queue = (struct BaggageQueue*) malloc(sizeof(struct BaggageQueue));

    queue->count = 0;
    queue->front = 0;
    queue->rear = -1;

    return queue;
}

// Add a baggage to the queue
void enqueue(struct BaggageQueue* queue, struct Baggage item) {
    if (queue->count < MAX_BAGGAGE) {
        queue->rear = (queue->rear + 1) % MAX_BAGGAGE;
        queue->baggage[queue->rear] = item;
        queue->count++;
    }
}

// Remove a baggage from the queue
struct Baggage dequeue(struct BaggageQueue* queue) {
    struct Baggage item = queue->baggage[queue->front];

    queue->front = (queue->front + 1) % MAX_BAGGAGE;
    queue->count--;

    return item;
}

// Check if the queue is empty
bool isQueueEmpty(struct BaggageQueue* queue) {
    return (queue->count == 0);
}

// Print the details of a baggage
void printBaggage(struct Baggage baggage) {
    printf("Baggage ID: %d\nWeight: %d kg\nDestination: %s\n\n", baggage.id, baggage.weight, baggage.destination);
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a queue for the baggage
    struct BaggageQueue* queue = createQueue();

    // Generate 5 baggage with random details and add them to the queue
    for (int i = 0; i < 5; i++) {
        struct Baggage baggage;
        baggage.id = i + 1;
        baggage.weight = rand() % 30 + 1;
        strcpy(baggage.destination, "Unknown");
        enqueue(queue, baggage);
    }

    // Print the details of all the baggage in the queue
    printf("Baggage in Queue:\n");
    while (!isQueueEmpty(queue)) {
        struct Baggage item = dequeue(queue);
        printBaggage(item);
    }

    return 0;
}