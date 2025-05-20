//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 100

// Define the structure of the queue
typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

// Function to initialize an empty queue
Queue *initQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1 && q->rear == -1;
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

// Function to enqueue an element into the queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Error: Queue is full.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear] = value;
    q->size++;
}

// Function to dequeue an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    q->size--;
    return value;
}

// Function to display the elements in the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue *q = initQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}