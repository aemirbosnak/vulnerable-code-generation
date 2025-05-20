//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
// Romeo and Juliet Queue Implementation

#include <stdio.h>
#include <stdlib.h>

// Define the structure of the queue
typedef struct {
    int *arr;   // array to store queue elements
    int front;  // front element of the queue
    int rear;   // rear element of the queue
    int size;   // size of the queue
} Queue;

// function to create an empty queue
Queue* createQueue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (int *)malloc(sizeof(int)*size);
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

// function to check if the queue is full
int isFull(Queue *q) {
    return (q->rear == q->size-1);
}

// function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// function to add an element to the queue
void enqueue(Queue *q, int element) {
    if (isFull(q)) {
        printf("Oh Romeo, thy queue is full! Thou canst not add more elements.\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->arr[q->rear] = element;
    printf("Oh Romeo, thou hast added %d to thy queue with grace and ease.\n", element);
}

// function to remove an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Oh Juliet, thy queue is empty! Thou canst not remove an element.\n");
        return -1;
    }
    int element = q->arr[q->front];
    q->front++;
    printf("Oh Juliet, thou hast removed %d from thy queue with gentle touch.\n", element);
    return element;
}

// function to print the queue
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Oh Romeo, thy queue is empty! Thou canst not print it.\n");
        return;
    }
    printf("Oh Romeo, thy queue is: ");
    for (int i=q->front; i<=q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

// function to get the front element of the queue
int front(Queue *q) {
    if (isEmpty(q)) {
        printf("Oh Juliet, thy queue is empty! Thou canst not get the front element.\n");
        return -1;
    }
    return q->arr[q->front];
}

// function to get the rear element of the queue
int rear(Queue *q) {
    if (isEmpty(q)) {
        printf("Oh Juliet, thy queue is empty! Thou canst not get the rear element.\n");
        return -1;
    }
    return q->arr[q->rear];
}

int main() {
    Queue *q = createQueue(5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printQueue(q);
    printf("Front element: %d\n", front(q));
    printf("Rear element: %d\n", rear(q));
    dequeue(q);
    printQueue(q);
    printf("Front element: %d\n", front(q));
    printf("Rear element: %d\n", rear(q));
    enqueue(q, 4);
    enqueue(q, 5);
    printQueue(q);
    enqueue(q, 6);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    return 0;
}