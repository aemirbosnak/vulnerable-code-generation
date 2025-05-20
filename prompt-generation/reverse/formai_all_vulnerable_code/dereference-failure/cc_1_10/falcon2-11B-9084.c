//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elements;
    int front;
    int rear;
} Queue;

void enqueue(Queue *q, int data) {
    if (q->rear == q->front) {
        q->rear = 0;
        q->elements = (int *)realloc(q->elements, (q->rear + 1) * sizeof(int));
    }
    q->elements[q->rear++] = data;
}

int dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = q->elements[q->front++];
    if (q->front == q->rear) {
        q->rear = 0;
        q->front = 0;
    }
    return data;
}

void display_queue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->elements[i]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    queue.front = 0;
    queue.rear = 0;
    queue.elements = (int *)malloc(10 * sizeof(int));

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);

    display_queue(&queue);

    printf("Dequeue: %d\n", dequeue(&queue));

    display_queue(&queue);

    return 0;
}