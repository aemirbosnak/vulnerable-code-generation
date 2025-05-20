//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the queue
#define MAX_SIZE 100

// Define the structure of the queue
typedef struct {
    int front;
    int rear;
    int *arr;
} Queue;

// Create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->arr = (int*)malloc(MAX_SIZE * sizeof(int));
    return q;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1 && q->rear == -1;
}

// Check if the queue is full
int isFull(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Add an element to the rear of the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->arr[q->rear] = value;
}

// Remove an element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

// Display the contents of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    display(q);
    int value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    display(q);
    return 0;
}