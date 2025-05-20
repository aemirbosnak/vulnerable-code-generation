//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5  // Maximum size of the queue

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
bool isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to add an item to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Unable to enqueue %d.\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;  // First element being added
        }
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Function to remove an item from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Unable to dequeue.\n");
        return -1; // Return -1 to indicate the queue is empty
    } else {
        int item = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1; // Queue is now empty
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        printf("Dequeued: %d\n", item);
        return item;
    }
}

// Function to display the elements in the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        while (1) {
            printf("%d ", q->items[i]);
            if (i == q->rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

// Function to get the front item of the queue
int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No front element.\n");
        return -1; // Indicate error
    }
    return q->items[q->front];
}

// Main function to demonstrate the queue implementation
int main() {
    Queue* myQueue = createQueue();
    
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    enqueue(myQueue, 40);
    enqueue(myQueue, 50); // This will fill the queue
    displayQueue(myQueue);

    // Try to add another element to the full queue
    enqueue(myQueue, 60);  

    // Dequeue elements
    dequeue(myQueue);
    dequeue(myQueue);
    displayQueue(myQueue);

    // Enqueue more elements
    enqueue(myQueue, 60);
    enqueue(myQueue, 70); // Add some more
    displayQueue(myQueue);

    // Display the front element
    int frontElement = front(myQueue);
    if (frontElement != -1) {
        printf("Front element: %d\n", frontElement);
    }

    // Clean up
    free(myQueue);
    return 0;
}