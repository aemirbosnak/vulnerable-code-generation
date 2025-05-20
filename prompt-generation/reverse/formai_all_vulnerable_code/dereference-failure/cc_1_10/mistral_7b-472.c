//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

// Struct definition for queue elements
typedef struct {
    char data[MAX_SIZE];
    int front;
    int rear;
} queue;

// Function to initialize the queue
void initQueue(queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(queue *q) {
    return q->front == -1 && q->rear == -1;
}

// Function to add an element to the queue
void enqueue(queue *q, char x) {
    if ((q->rear + 1) % MAX_SIZE == q->front) {
        printf("Queue is full\n");
        return;
    }

    strncpy(q->data + q->rear, &x, sizeof(x) + 1);

    if (q->front == -1) {
        q->front = q->rear;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
}

// Function to remove an element from the queue
char dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return '\0';
    }

    char x = q->data[q->front];

    q->front = (q->front + 1) % MAX_SIZE;

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }

    return x;
}

// Function to print the queue
void printQueue(queue q) {
    if (isEmpty(&q)) {
        printf("Queue is empty\n");
        return;
    }

    int i = q.front;

    do {
        printf("%c", q.data[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != q.rear);

    printf("\n");
}

int main() {
    queue q;
    initQueue(&q);

    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');
    enqueue(&q, 'D');
    enqueue(&q, 'E');

    printQueue(q);

    dequeue(&q);
    printQueue(q);

    dequeue(&q);
    printQueue(q);

    return 0;
}