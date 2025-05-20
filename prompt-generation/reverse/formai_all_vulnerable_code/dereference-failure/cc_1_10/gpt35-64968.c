//FormAI DATASET v1.0 Category: Queue ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

// Creating a structure to implement Queue
struct Queue {
    int items[MAXSIZE];
    int front;
    int rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    if (queue->rear == MAXSIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->front == -1 && queue->rear == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("\nQueue is full. Cannot add any more items.\n");
    }
    else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("\nItem %d has been added to the queue.\n", value);
    }
}

// Function to remove an item from the queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("\nQueue is empty. Cannot remove any more items.\n");
        return -1;
    }
    else {
        item = queue->items[queue->front];
        if (queue->front >= queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        }
        else {
            queue->front++;
        }
        printf("\nItem %d has been removed from the queue.\n", item);
        return item;
    }
}

// Function to display the contents of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nThe queue is empty.\n");
    }
    else {
        printf("\nThe contents of the queue are: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
    }
}

// Driver function to test the queue implementation
int main() {
    struct Queue* queue = createQueue();

    // Adding items to the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    enqueue(queue, 10);
    display(queue);

    // Removing items from the queue
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);

    // Adding items to the queue again
    enqueue(queue, 11);
    enqueue(queue, 12);
    display(queue);

    // Removing items from the queue again
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);

    // Checking if the queue is empty now
    isEmpty(queue);

    return 0;
}