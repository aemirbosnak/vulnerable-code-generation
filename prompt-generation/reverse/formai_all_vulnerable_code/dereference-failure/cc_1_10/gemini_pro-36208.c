//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

struct Queue {
    int items[QUEUE_SIZE];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is full
int isFull(struct Queue* queue) {
    if (queue->rear == QUEUE_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->front == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Add an element to the queue
void enQueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
        printf("%d inserted to the queue\n", item);
    }
}

// Remove an element from the queue
int deQueue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return(-1);
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("%d deleted from the queue\n", item);
        return(item);
    }
}

// Print the queue
void printQueue(struct Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d  ", queue->items[i]);
        }
        printf("\n");
    }
}

int main() {
    // Create a queue
    struct Queue* queue = createQueue();

    // Add elements to the queue
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);

    // Print the queue
    printQueue(queue);

    // Remove elements from the queue
    deQueue(queue);
    deQueue(queue);

    // Print the queue
    printQueue(queue);

    return 0;
}