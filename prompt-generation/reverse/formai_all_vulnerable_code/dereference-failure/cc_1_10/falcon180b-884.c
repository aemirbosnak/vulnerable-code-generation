//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element *elements;
    int front, rear;
    int size;
    bool isFull;
} Queue;

void initQueue(Queue *q) {
    q->elements = (Element *)malloc(MAX_SIZE * sizeof(Element));
    q->front = q->rear = -1;
    q->size = 0;
    q->isFull = false;
}

void enqueue(Queue *q, int data, int priority) {
    if (q->isFull) {
        printf("Queue is Full\n");
        return;
    }
    if (q->front == -1) {
        q->front = q->rear = 0;
    } else if (q->rear == MAX_SIZE - 1) {
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->elements[q->rear].data = data;
    q->elements[q->rear].priority = priority;
    q->size++;
}

void dequeue(Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is Empty\n");
        return;
    }
    Element temp = q->elements[q->front];
    q->front++;
    q->size--;
    if (q->front == MAX_SIZE) {
        q->front = 0;
    }
    free(temp.data);
}

void display(Queue *q) {
    if (q->front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->elements[i].data);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10, 1);
    enqueue(&q, 20, 2);
    enqueue(&q, 30, 3);
    enqueue(&q, 40, 4);
    enqueue(&q, 50, 5);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    return 0;
}