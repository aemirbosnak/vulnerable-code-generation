//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 1000 // maximum size of the queue

typedef struct {
    int *data; // pointer to the data in the queue
    int front; // front of the queue
    int rear; // rear of the queue
    int count; // number of elements in the queue
} Queue;

// create a new queue
Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = (int *)malloc(MAX_QUEUE_SIZE * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->count = 0;
    return queue;
}

// add an element to the rear of the queue
void enqueue(Queue *queue, int value) {
    if (queue->count == MAX_QUEUE_SIZE) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->data[++queue->rear] = value;
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->count++;
}

// remove an element from the front of the queue
int dequeue(Queue *queue) {
    if (queue->count == 0) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = queue->data[queue->front];
    if (queue->front == MAX_QUEUE_SIZE - 1) {
        queue->front = 0;
    } else {
        queue->front++;
    }
    queue->count--;
    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    return value;
}

// display the elements in the queue
void display(Queue *queue) {
    if (queue->count == 0) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Elements in the queue:\n");
    if (queue->rear >= queue->front) {
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->data[i]);
        }
    } else {
        for (int i = queue->front; i < MAX_QUEUE_SIZE; i++) {
            printf("%d ", queue->data[i]);
        }
        for (int i = 0; i <= queue->rear; i++) {
            printf("%d ", queue->data[i]);
        }
    }
    printf("\n");
}

// main function
int main() {
    Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    display(queue);
    int value = dequeue(queue);
    printf("Dequeued value: %d\n", value);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    return 0;
}