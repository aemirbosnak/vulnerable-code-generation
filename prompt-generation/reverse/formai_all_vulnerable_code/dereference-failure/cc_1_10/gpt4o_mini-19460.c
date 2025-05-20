//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of Queue

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Function to create a queue and initialize its members
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to add an item to the queue
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Unable to enqueue %d\n", value);
        return;
    }
    // If queue is empty, initialize the front and rear
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an item from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Unable to dequeue.\n");
        return -1; // Indicates queue is empty
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        // Queue has only one element, reset it to empty
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued: %d\n", item);
    return item;
}

// Function to display the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < MAX; i++) {
        if (!isEmpty(q) && (q->front <= q->rear ? (i >= q->front && i <= q->rear) : (i >= q->front || i <= q->rear))) {
            printf("%d ", q->items[i]);
        }
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    struct Queue* q = createQueue();

    // Enqueue some elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    
    // Attempt to enqueue when full
    enqueue(q, 60);

    // Display the queue
    display(q);

    // Dequeue elements
    dequeue(q);
    dequeue(q);
    
    // Display the queue after some dequeues
    display(q);

    // Enqueue more elements
    enqueue(q, 60);
    enqueue(q, 70);

    // Finally display the queue
    display(q);

    // Free the queue memory
    free(q);

    return 0;
}