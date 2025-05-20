//FormAI DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10 // setting the maximum size of the queue to 10

// Defining the queue structure
typedef struct {
    int front, rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

Queue* createQueue() { // Function to create a new queue
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->front = -1; // Initializing front and rear of the queue
    newQueue->rear = -1;
    return newQueue;
}

void enqueue(Queue* q, int val) { // Function to enqueue a value into the queue
    if (q->rear == MAX_QUEUE_SIZE-1) { // Checking if the queue is already full
        printf("Overflow! Queue is already full.\n");
        return;
    }
    else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = val;
        printf("Enqueued value: %d\n", val);
    }
}

int dequeue(Queue* q) { // Function to dequeue a value from the queue
    if (q->front == -1) { // Checking if the queue is already empty
        printf("Underflow! Queue is already empty.\n");
        return -99999; // return some random value
    }
    else {
        int val = q->items[q->front];
        q->front++;
        if (q->front > q->rear) { // Resetting front and rear if the queue becomes empty
            q->front = -1;
            q->rear = -1;
        }
        printf("Dequeued value: %d\n", val);
        return val;
    }
}

int main() {
    Queue* queue = createQueue(); // Creating a new queue
    printf("Welcome to the Queue Program!\n");
    while (1) {
        printf("\nPlease choose an option:\n1. Enqueue a value\n2. Dequeue a value\n3. Exit the program\n"); // Options menu
        int option;
        scanf("%d", &option);

        switch (option) { // Implementing the menu options
            case 1: {
                printf("Please enter a value: ");
                int val;
                scanf("%d", &val);
                enqueue(queue, val);
                break;
            }
            case 2: {
                int val = dequeue(queue);
                break;
            }
            case 3: {
                printf("Thank you for using the program!\n");
                exit(0);
            }
            default: {
                printf("Invalid option! Please try again.\n");
                break;
            }
        }
    }
    return 0;
}