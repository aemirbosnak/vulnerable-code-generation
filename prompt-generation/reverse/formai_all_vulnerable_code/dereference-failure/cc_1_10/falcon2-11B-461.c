//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue {
    int* data;
    int front;
    int rear;
    int size;
} queue;

// Function to create a new queue
queue* createQueue(int size) {
    queue* q = (queue*) malloc(sizeof(queue));
    q->data = (int*) malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

// Function to add an element to the queue
void enqueue(queue* q, int data) {
    if (q->rear == q->size - 1) {
        printf("Queue is full.\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = data;
    printf("Element %d added to the queue.\n", data);
}

// Function to remove an element from the queue
int dequeue(queue* q) {
    if (q->front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = q->data[q->front];
    q->front++;
    printf("Element %d removed from the queue.\n", data);
    return data;
}

// Function to check if the queue is empty
int isEmpty(queue* q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(queue* q) {
    return q->rear == q->size - 1;
}

int main() {
    queue* q = createQueue(10);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    printf("Front element: %d\n", dequeue(q));
    printf("Rear element: %d\n", dequeue(q));
    printf("Front element: %d\n", dequeue(q));
    printf("Rear element: %d\n", dequeue(q));
    printf("Queue is empty: %s\n", isEmpty(q)? "true" : "false");
    printf("Queue is full: %s\n", isFull(q)? "true" : "false");
    return 0;
}