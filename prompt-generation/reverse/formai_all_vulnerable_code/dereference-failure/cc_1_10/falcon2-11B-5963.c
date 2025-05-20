//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct queue {
    int* array;
    int front, rear;
} Queue;

void enqueue(Queue* q, int data) {
    if (q->rear == MAX_SIZE) {
        printf("Queue is full\n");
        return;
    }
    q->array[q->rear] = data;
    q->rear++;
}

int dequeue(Queue* q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->array[q->front];
    q->front++;
    return data;
}

int isEmpty(Queue* q) {
    return (q->front == q->rear);
}

int main() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    q->array = (int*)malloc(MAX_SIZE * sizeof(int));
    if (q->array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    q->front = 0;
    q->rear = -1;

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("Front element: %d\n", dequeue(q));
    printf("Front element: %d\n", dequeue(q));
    printf("Front element: %d\n", dequeue(q));

    printf("Queue is empty: %s\n", isEmpty(q)? "true" : "false");

    free(q->array);
    free(q);

    return 0;
}