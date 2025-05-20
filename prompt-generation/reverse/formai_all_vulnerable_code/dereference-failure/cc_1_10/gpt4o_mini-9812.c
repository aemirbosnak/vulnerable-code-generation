//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10 // Max size of the queue

// Futuristic definition of a queue node for space command transmissions
typedef struct SpaceTransmission {
    char message[256]; // Message content
    int senderId;      // ID of the sender
} SpaceTransmission;

// Futuristic queue structure to hold space transmissions
typedef struct Queue {
    SpaceTransmission transmissions[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function prototypes
Queue* createQueue();
int isFull(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, SpaceTransmission trans);
SpaceTransmission dequeue(Queue* q);
void displayQueue(Queue* q);
void freeQueue(Queue* q);

int main() {
    Queue* myQueue = createQueue();
    SpaceTransmission trans;

    // Emulating space transmissions
    for (int i = 0; i < 12; i++) {
        sprintf(trans.message, "Transmission %d from Ship %d", i+1, rand() % 100); // Create a message
        trans.senderId = rand() % 100; // Random sender ID

        // Trying to enqueue transmissions
        if (!isFull(myQueue)) {
            enqueue(myQueue, trans);
            printf("Enqueued: %s | Sender ID: %d\n", trans.message, trans.senderId);
        } else {
            printf("Queue is full. Unable to enqueue: %s | Sender ID: %d\n", trans.message, trans.senderId);
        }
    }

    printf("\nCurrent Queue State:\n");
    displayQueue(myQueue);

    // Dequeue all messages
    printf("\nProcessing Queue Transactions:\n");
    while (!isEmpty(myQueue)) {
        SpaceTransmission processed = dequeue(myQueue);
        printf("Dequeued: %s | Sender ID: %d\n", processed.message, processed.senderId);
    }

    // Free the allocated queue
    freeQueue(myQueue);
    return 0;
}

// Function to create the queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return (q->rear + 1) % QUEUE_SIZE == q->front;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to enqueue a transmission to the queue
void enqueue(Queue* q, SpaceTransmission trans) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue transmission.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0; // Initialize front
    }
    q->rear = (q->rear + 1) % QUEUE_SIZE; // Circular increment
    q->transmissions[q->rear] = trans; // Add transmission
}

// Function to dequeue a transmission from the queue
SpaceTransmission dequeue(Queue* q) {
    SpaceTransmission trans = { "", 0 }; // Initialize an empty transmission
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue transmission.\n");
        return trans;
    }
    trans = q->transmissions[q->front]; // Store the front transmission
    if (q->front == q->rear) {
        // Reset queue if it was the last transmission
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % QUEUE_SIZE; // Circular increment
    }
    return trans; // Return dequeued transmission
}

// Function to display the current status of the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is currently empty.\n");
        return;
    }
    int i = q->front;
    printf("Messages in Queue:\n");
    while (1) {
        printf("%s | Sender ID: %d\n", q->transmissions[i].message, q->transmissions[i].senderId);
        if (i == q->rear) break; // Stop if reached the rear
        i = (i + 1) % QUEUE_SIZE; // Circular increment
    }
}

// Function to free the allocated queue
void freeQueue(Queue* q) {
    free(q);
}