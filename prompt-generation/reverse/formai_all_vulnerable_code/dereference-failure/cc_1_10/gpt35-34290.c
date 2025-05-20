//FormAI DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

// Create Queue structure
typedef struct queue {
    int items[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Create methods for Queue
Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->rear == -1;
}

int isFull(Queue* queue) {
    return queue->rear == QUEUE_SIZE - 1;
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("Inserted %d\n", value);
    }
}

int dequeue(Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        printf("Deleted %d\n", item);
        queue->front++;
        if (queue->front > queue->rear) {
            printf("Resetting queue!\n");
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Front -> ");
        for (int i = queue->front; i < queue->rear + 1; i++) {
            printf("%d -> ", queue->items[i]);
        }
        printf("Rear\n");
    }
}

int main() {
    Queue* queue = createQueue();
    
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
    
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    
    display(queue);
    
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    
    display(queue);
    
    enqueue(queue, 11);
    enqueue(queue, 12);
    enqueue(queue, 13);
    
    display(queue);
    
    return 0;
}