//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of the Queue ADT
typedef struct {
    int size;
    int front;
    int rear;
    int *arr;
} Queue;

// Function to create a new queue with a specified size
Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = size;
    queue->front = 0;
    queue->rear = -1;
    queue->arr = (int *)malloc(size * sizeof(int));
    return queue;
}

// Function to add an element to the rear of the queue
void enqueue(Queue *queue, int data) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full, cannot add data.\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = data;
}

// Function to remove an element from the front of the queue
int dequeue(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty, cannot remove data.\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    queue->front++;
    return data;
}

// Function to check if the queue is empty
bool isEmpty(Queue *queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
bool isFull(Queue *queue) {
    return (queue->rear == queue->size - 1);
}

// Function to print the elements of the queue
void printQueue(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    int i;
    for (i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    int size = 5;
    Queue *queue = createQueue(size);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Queue: ");
    printQueue(queue);

    int data = dequeue(queue);
    printf("Dequeued: %d\n", data);

    data = dequeue(queue);
    printf("Dequeued: %d\n", data);

    data = dequeue(queue);
    printf("Dequeued: %d\n", data);

    data = dequeue(queue);
    printf("Dequeued: %d\n", data);

    data = dequeue(queue);
    printf("Dequeued: %d\n", data);

    data = dequeue(queue);
    printf("Dequeued: %d\n", data);

    data = dequeue(queue);
    printf("Dequeued: %d\n", data);

    printf("Queue is empty: %s\n", isEmpty(queue)? "True" : "False");
    printf("Queue is full: %s\n", isFull(queue)? "True" : "False");

    free(queue->arr);
    free(queue);

    return 0;
}