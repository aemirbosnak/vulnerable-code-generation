//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10

typedef struct queue {
    int front;
    int rear;
    int size;
    int *array;
} queue;

queue *createQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = -1;
    q->size = MAX_QUEUE_SIZE;
    q->array = (int *)calloc(q->size, sizeof(int));
    if (!q->array) {
        free(q);
        return NULL;
    }
    return q;
}

bool isFull(queue *q) {
    return (q->rear + 1) % q->size == q->front;
}

bool isEmpty(queue *q) {
    return (q->front == q->rear);
}

void enqueue(queue *q, int data) {
    if (isFull(q)) {
        fprintf(stderr, "Queue Overflow\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = data;
}

int dequeue(queue *q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Queue Underflow\n");
        return -1;
    }
    int data = q->array[q->front];
    q->front++;
    if (q->front >= q->size) {
        q->front = 0;
    }
    return data;
}

void displayQueue(queue *q) {
    int i = q->front;
    printf("Queue: ");
    while (i != q->rear) {
        printf("%d ", q->array[i]);
        i = (i + 1) % q->size;
    }
    printf("%d\n", q->array[i]);
}

int main() {
    queue *q = createQueue();

    if (!q) {
        fprintf(stderr, "Memory Allocation Failed\n");
        return 1;
    }

    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);

    printf("Enqueued Elements: ");
    displayQueue(q);

    int dequeuedData = dequeue(q);
    printf("Dequeued Element: %d\n", dequeuedData);

    enqueue(q, 20);

    printf("Enqueued Element: 20\n");
    printf("Enqueued Elements: ");
    displayQueue(q);

    dequeue(q);
    dequeue(q);

    printf("Dequeued Element: %d\n", dequeuedData);
    printf("Dequeued Element: %d\n", dequeuedData);

    printf("Enqueued Elements: ");
    displayQueue(q);

    enqueue(q, 25); // This will cause queue overflow

    printf("Enqueued Element: 25\n"); // This will result in an error message

    free(q->array);
    free(q);

    return 0;
}