//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function to create a new queue
Queue* newQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    if (queue->front == -1 && queue->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to add an item to the queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        if (queue->front >= queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
        printf("Deleted %d\n", item);
    }
    return item;
}

// Function to display the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        int i;
        printf("Queue elements are:\n");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d  ", queue->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue* queue = newQueue();

    // Add elements to the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Display the queue
    display(queue);

    // Remove elements from the queue
    dequeue(queue);
    dequeue(queue);

    // Display the queue after removal
    display(queue);

    return 0;
}