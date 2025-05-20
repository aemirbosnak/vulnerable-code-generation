//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a queue and initialize its values
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
bool isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

// Function to add an item to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Inserted %d\n", value);
}

// Function to remove an item from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1; // Indicates that the queue is empty
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    printf("Removed %d\n", item);
    return item;
}

// Function to peek at the front item of the queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to peek\n");
        return -1; // Indicates that the queue is empty
    }
    return q->items[q->front];
}

// Function to display the queue contents
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Sample usage of the queue in a realistic scenario
void queueOperations() {
    Queue* q = createQueue();
    int choice, value;
    
    while (true) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                value = peek(q);
                if (value != -1) {
                    printf("Front of the queue is %d\n", value);
                }
                break;
            case 4:
                displayQueue(q);
                break;
            case 5:
                free(q);
                printf("Exiting the program.\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    queueOperations();
    return 0;
}