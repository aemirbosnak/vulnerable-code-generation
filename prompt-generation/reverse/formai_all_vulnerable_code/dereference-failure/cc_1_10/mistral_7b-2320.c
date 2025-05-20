//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int front, rear;
    int capacity;
    char* queue;
} TuringQueue;

void createQueue(TuringQueue* q, int size) {
    q->queue = (char*)calloc(size, sizeof(char));
    q->front = q->rear = -1;
    q->capacity = size;
}

void enqueue(TuringQueue* q, char data) {
    if (q->rear == q->capacity - 1) {
        printf("\nQueue Overflow. Cannot enqueue %c\n", data);
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear++;
    q->queue[q->rear] = data;
}

char dequeue(TuringQueue* q) {
    if (q->front == -1) {
        printf("\nQueue Underflow. Cannot dequeue\n");
        return '\0';
    }

    char data = q->queue[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }

    return data;
}

int main() {
    TuringQueue q;
    int size = 10;
    createQueue(&q, size);

    printf("\nInitial State: Front = %d, Rear = %d\n", q.front, q.rear);

    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');
    enqueue(&q, 'D');

    printf("\nAfter enqueuing A, B, C, D: Front = %d, Rear = %d\n", q.front, q.rear);

    char dequeued;
    for (int i = 0; i < 4; i++) {
        dequeued = dequeue(&q);
        printf("\nDequeued: %c", dequeued);
    }

    printf("\nAfter dequeuing A, B, C, D: Front = %d, Rear = %d\n", q.front, q.rear);

    enqueue(&q, 'E');
    printf("\nAfter enqueuing E: Front = %d, Rear = %d\n", q.front, q.rear);

    return 0;
}