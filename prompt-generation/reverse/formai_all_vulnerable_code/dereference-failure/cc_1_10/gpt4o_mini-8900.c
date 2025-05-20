//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

// Define a structure for the Queue
typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a Queue and initialize its values
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the Queue is empty
bool isEmpty(Queue* q) {
    return (q->front == -1);
}

// Function to check if the Queue is full
bool isFull(Queue* q) {
    return (q->rear == MAX - 1);
}

// Function to add an element to the Queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
    } else {
        if (isEmpty(q)) {
            q->front = 0; // When first element is added
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Function to remove an element from the Queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1; // Indicate that the queue is empty
    } else {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            // Reset the queue if it is now empty
            q->front = q->rear = -1;
        }
        printf("Dequeued: %d\n", item);
        return item;
    }
}

// Function to peek at the front element of the Queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty! Cannot peek\n");
        return -1; // Indicate that the queue is empty
    }
    return q->items[q->front];
}

// Function to display the contents of the Queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue contents: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Main function to demonstrate the Queue operations
int main() {
    Queue* q = createQueue();
    
    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                if(scanf("%d", &value) != 1) {
                    printf("Invalid input! Please enter a valid integer.\n");
                    while(getchar() != '\n'); // Clear invalid input
                    continue;
                }
                enqueue(q, value);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                value = peek(q);
                if (value != -1) {
                    printf("Front element is: %d\n", value);
                }
                break;

            case 4:
                displayQueue(q);
                break;

            case 5:
                free(q);
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice! Please select from 1 to 5.\n");
        }
    }

    return 0;
}