//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct queue {
    int *array;
    int front;
    int rear;
    int size;
} queue;

queue* create_queue() {
    queue *q = (queue*) malloc(sizeof(queue));
    q->array = (int*) malloc(MAX * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

void enqueue(queue *q, int item) {
    if (q->size == MAX) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->array[q->rear] = item;
    q->size++;
}

int dequeue(queue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->array[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return item;
}

void print_queue(queue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i!= -1; i = (i + 1) % MAX) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

int main() {
    queue *q = create_queue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    print_queue(q);
    printf("Dequeued item: %d\n", dequeue(q));
    print_queue(q);
    printf("Dequeued item: %d\n", dequeue(q));
    print_queue(q);
    printf("Dequeued item: %d\n", dequeue(q));
    print_queue(q);
    printf("Dequeued item: %d\n", dequeue(q));
    print_queue(q);
    printf("Dequeued item: %d\n", dequeue(q));
    printf("Queue is empty\n");
    return 0;
}