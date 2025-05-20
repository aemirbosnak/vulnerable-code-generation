//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

// Structure to represent the queue
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Function to create a queue and initialize it
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
        printf("Queue is full! Cannot enqueue %d.\n", value);
    } else {
        if (isEmpty(q)) {
            q->front = 0; // Reset front position when adding first element
        }
        q->rear = (q->rear + 1) % MAX; // Circular increment
        q->items[q->rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}

// Function to remove an item from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    } else {
        int value = q->items[q->front];
        if (q->front == q->rear) { // Single element case
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX; // Circular increment
        }
        printf("%d dequeued from queue.\n", value);
        return value;
    }
}

// Function to display the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    } else {
        printf("Queue elements: ");
        int i = q->front;
        while (1) {
            printf("%d ", q->items[i]);
            if (i == q->rear) break;
            i = (i + 1) % MAX; // Circular increment
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct Queue* q = createQueue();
    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                free(q); // Free allocated memory
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}