//FormAI DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>

#define MAX 5

// C Queue Implementation using arrays
struct queue {
    int items[MAX];
    int front, rear;
};

// Function to create an empty queue
struct queue* createQueue() {
    struct queue* newQueue = (struct queue*)malloc(sizeof(struct queue));
    newQueue->front = -1;
    newQueue->rear = -1;
    return newQueue;
}

// Function to check if the queue is full
int isFull(struct queue* myQueue) {
    if (myQueue->rear == MAX - 1) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(struct queue* myQueue) {
    if (myQueue->front == -1 && myQueue->rear == -1) {
        return 1;
    }
    return 0;
}

// Function to add an item to the queue
void enqueue(struct queue* myQueue, int value) {
    if (isFull(myQueue)) {
        printf("Queue is full, cannot add item.\n");
    } else {
        if (isEmpty(myQueue)) {
            myQueue->front = 0;
            myQueue->rear = 0;
        } else {
            myQueue->rear++;
        }
        myQueue->items[myQueue->rear] = value;
        printf("Item successfully added to queue: %d\n", value);
    }
}

// Function to remove an item from the queue
void dequeue(struct queue* myQueue) {
    if (isEmpty(myQueue)) {
        printf("Queue is empty, cannot remove item.\n");
    } else {
        printf("Item successfully removed from queue: %d\n", myQueue->items[myQueue->front]);
        if (myQueue->front == myQueue->rear) {
            myQueue->front = -1;
            myQueue->rear = -1;
        } else {
            myQueue->front++;
        }
    }
}

// Function to display the items in the queue
void display(struct queue* myQueue) {
    if (isEmpty(myQueue)) {
        printf("Queue is empty, nothing to display.\n");
    } else {
        printf("Items currently in the queue: ");
        for (int i = myQueue->front; i <= myQueue->rear; i++) {
            printf("%d ", myQueue->items[i]);
        }
        printf("\n");
    }
}

// Driver program to test the C Queue Implementation
int main() {
    struct queue* myQueue = createQueue();

    printf("Adding items to the queue...\n");
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    enqueue(myQueue, 40);
    enqueue(myQueue, 50);
    enqueue(myQueue, 60); // should give an error message

    display(myQueue);

    printf("Removing items from the queue...\n");
    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue); // should give an error message

    display(myQueue);

    return 0;
}