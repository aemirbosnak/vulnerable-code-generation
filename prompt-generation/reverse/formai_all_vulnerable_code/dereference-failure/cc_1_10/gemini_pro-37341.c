//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is full
int isFull(Queue* queue) {
    if (queue->rear == MAX_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    if (queue->front == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Add an element to the queue
void enQueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = element;
        printf("%d inserted to the queue\n", element);
    }
}

// Remove an element from the queue
int deQueue(Queue* queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return(-1);
    } else {
        element = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("%d deleted from the queue\n", element);
        return(element);
    }
}

// Print the queue
void display(Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue* queue = createQueue();
    
    enQueue(queue, 10);
    enQueue(queue, 20);
    enQueue(queue, 30);
    enQueue(queue, 40);
    enQueue(queue, 50);
    
    display(queue);
    
    deQueue(queue);
    deQueue(queue);
    
    display(queue);
    
    enQueue(queue, 60);
    enQueue(queue, 70);
    
    display(queue);
    
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
    
    return 0;
}