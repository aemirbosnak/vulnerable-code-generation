//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function prototypes
Queue* createQueue();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void displayQueue(Queue* q);

int main() {
    Queue* queue = createQueue();
    int choice, value;

    printf("🎉 Welcome to the Enthusiastic Queue Program! 🎉\n");
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter a number to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Exiting... Thanks for using the Queue Program! 🎈\n");
                break;
            default:
                printf("Invalid choice! Please select from the menu.\n");
        }
    } while (choice != 4);

    free(queue); // Always good to free up memory!
    return 0;
}

// Create a new Queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is full
bool isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to add an element to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("🚫 Queue is full! Could not enqueue %d.\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0; // First element inserted into the queue
        }
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
        printf("✅ Enqueued: %d\n", value);
    }
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("🚫 Queue is empty! Nothing to dequeue.\n");
        return -1;
    } else {
        int value = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1; // Queue becomes empty
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        return value;
    }
}

// Function to display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("🚫 The queue is empty! Nothing to display.\n");
    } else {
        printf("Current Queue: ");
        int i = q->front;

        while (1) {
            printf("%d ", q->items[i]);
            if (i == q->rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}