//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a Queue and initialize its members
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the Queue is full
int isFull(Queue* q) {
    return (q->rear == MAX - 1);
}

// Function to check if the Queue is empty
int isEmpty(Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

// Function to add an element to the Queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0; // First element
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

// Function to remove an element from the Queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Indicate that the queue is empty
    } else {
        int value = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = -1;
            q->rear = -1;
        }
        printf("%d dequeued from queue\n", value);
        return value;
    }
}

// Function to peek at the front element of the Queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1; // Indicate that the queue is empty
    } else {
        return q->items[q->front];
    }
}

// Function to print the Queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing to display.\n");
    } else {
        printf("Queue contents: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Function to calculate and return the size of the Queue
int size(Queue* q) {
    if (isEmpty(q)) {
        return 0;
    }
    return q->rear - q->front + 1;
}

// Main function to demonstrate Queue operations and showcase statistical analysis
int main() {
    Queue* q = createQueue();
    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Size of Queue\n");
        printf("6. Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enqueue
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2: // Dequeue
                dequeue(q);
                break;
            case 3: // Peek
                value = peek(q);
                if (value != -1) {
                    printf("Front element is: %d\n", value);
                }
                break;
            case 4: // Display Queue
                displayQueue(q);
                break;
            case 5: // Size of Queue
                printf("Size of queue: %d\n", size(q));
                break;
            case 6: // Exit
                printf("Exiting program...\n");
                free(q); // Free allocated queue memory
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}