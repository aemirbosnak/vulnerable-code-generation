//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the queue

// Structure to represent the queue
typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a queue and initialize its variables
Queue* createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is full
int isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// Function to add an item to the queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Unable to enqueue %d.\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0;  // Set front to the first element
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("%d enqueued to queue.\n", value);
}

// Function to remove an item from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Unable to dequeue.\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    // Reset front and rear if queue becomes empty
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return item;
}

// Function to display the elements of the queue
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    Queue *q = createQueue();
    int choice, value;

    do {
        printf("\n*** Queue Menu ***\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Check if Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1) {
                    printf("%d dequeued from queue.\n", value);
                }
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                if (isEmpty(q)) {
                    printf("The queue is empty.\n");
                } else {
                    printf("The queue is not empty.\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    free(q); // Free the memory allocated for the queue
    return 0;
}