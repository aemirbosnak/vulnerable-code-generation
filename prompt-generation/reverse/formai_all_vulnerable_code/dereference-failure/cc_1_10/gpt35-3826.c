//FormAI DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

/* Define the maximum size of the circular queue */
#define MAX_SIZE 5

/* Define the struct Circular Queue that will hold our data */
typedef struct {
    int arr[MAX_SIZE];
    int front;  // Index of the front of the queue
    int rear;   // Index of the rear of the queue
    int size;   // Number of elements in the queue
} CircularQueue;

/* Create a new Circular Queue and return a pointer to it */
CircularQueue* newCircularQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

/* Checks if a queue is empty */
int isEmpty(CircularQueue* queue) {
    return (queue->size == 0);
}

/* Checks if a queue is full */
int isFull(CircularQueue* queue) {
    return (queue->size == MAX_SIZE);
}

/* Enqueues an element to the rear of the queue */
void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Circular Queue is full.\n");
        return;
    }

    queue->rear = (queue->rear+1) % MAX_SIZE;
    queue->arr[queue->rear] = value;
    queue->size++;
}

/* Dequeues an element from the front of the queue */
void dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty.\n");
        return;
    }

    printf("Dequeued %d\n", queue->arr[queue->front]);
    queue->front = (queue->front+1) % MAX_SIZE;
    queue->size--;
}

/* Prints the contents of the queue */
void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty.\n");
        return;
    }

    printf("Circular Queue (front to rear):\n");
    for (int i=0; i<queue->size; i++) {
        int index = (queue->front+i) % MAX_SIZE;
        printf("%d ", queue->arr[index]);
    }
    printf("\n");
}

/* Test the Circular Queue implementation */
int main() {
    CircularQueue* queue = newCircularQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    enqueue(queue, 40);
    enqueue(queue, 50);
    display(queue);
    enqueue(queue, 60);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    free(queue);
    return 0;
}