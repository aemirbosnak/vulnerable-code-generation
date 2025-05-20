//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the queue

typedef struct {
    int *items;
    int front;
    int rear;
    int size;
} Queue;

// Function to create a new queue
Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->items = (int*)malloc(q->size * sizeof(int));
    return q;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return (q->rear + 1) % q->size == q->front;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to add an item to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("\nQueue is full! Cannot enqueue %d\n", value);
        return;
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % q->size;
        q->items[q->rear] = value;
        printf("\nEnqueued: %d\n", value);
    }
}

// Function to remove an item from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty! Cannot dequeue.\n");
        return -1;
    } else {
        int item = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % q->size;
        }
        printf("\nDequeued: %d\n", item);
        return item;
    }
}

// Function to display the queue elements
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty!\n");
        return;
    }
    printf("\nQueue Elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    printf("\nWelcome to the Circular Queue Implementation!\n");
    Queue* myQueue = createQueue(MAX);

    int choice, value;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(myQueue, value);
                break;
            case 2:
                dequeue(myQueue);
                break;
            case 3:
                display(myQueue);
                break;
            case 4:
                printf("Exiting the program. Bye!\n");
                free(myQueue->items);
                free(myQueue);
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
}