//FormAI DATASET v1.0 Category: Queue Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int head;
    int tail;
    int size;
    int *arr;
} Queue;

Queue* create_queue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->head = -1;
    q->tail = -1;
    q->size = size;
    q->arr = (int *)malloc(size * sizeof(int));
    return q;
}

int is_full(Queue *q) {
    return (q->tail == q->size - 1);
}

int is_empty(Queue *q) {
    return (q->head == -1 && q->tail == -1);
}

void enqueue(Queue *q, int data) {
    if (is_full(q)) {
        printf("Error: Queue full\n");
        return;
    }
    else if (is_empty(q)) {
        q->head = 0;
        q->tail = 0;
    }
    else {
        q->tail++;
    }
    q->arr[q->tail] = data;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Error: Queue empty\n");
        return -1;
    }
    else if (q->head == q->tail) {
        int data = q->arr[q->head];
        q->head = -1;
        q->tail = -1;
        return data;
    }
    else {
        int data = q->arr[q->head];
        q->head++;
        return data;
    }
}

void print_queue(Queue *q) {
    if (is_empty(q)) {
        printf("Empty Queue\n");
        return;
    }
    int i = q->head;
    for(; i <= q->tail; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue *q = create_queue(5);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    print_queue(q);
    printf("Dequeue: %d\n", dequeue(q));
    print_queue(q);
    enqueue(q, 4);
    enqueue(q, 5);
    printf("Queue full?\n");
    enqueue(q, 6);
    print_queue(q);

    return 0;
}