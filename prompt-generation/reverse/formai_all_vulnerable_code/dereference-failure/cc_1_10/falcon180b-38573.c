//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Element;

typedef struct {
    Element *arr;
    int front;
    int rear;
    int size;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (Element *)malloc(MAX_SIZE * sizeof(Element));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int value) {
    if (q->size == MAX_SIZE) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear].data = value;
    q->arr[q->rear].index = q->size;
    q->size++;
}

int dequeue(Queue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->arr[q->front].data;
    q->front++;
    q->size--;
    return value;
}

int peek(Queue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front].data;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

int isFull(Queue *q) {
    return q->size == MAX_SIZE;
}

void display(Queue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i].data);
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    display(q);
    int value = dequeue(q);
    printf("Dequeued element is: %d\n", value);
    display(q);
    int peekValue = peek(q);
    printf("Peeked element is: %d\n", peekValue);
    printf("Queue is %s\n", isEmpty(q)? "empty" : "not empty");
    printf("Queue is %s\n", isFull(q)? "full" : "not full");
    free(q->arr);
    free(q);
    return 0;
}