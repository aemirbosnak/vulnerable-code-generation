//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct my_queue {
    int front;
    int rear;
    int arr[MAX_QUEUE_SIZE];
} queue;

queue *my_queue_create() {
    queue *q = (queue *) malloc(sizeof(queue));
    q->front = q->rear = -1;
    return q;
}

void my_queue_destroy(queue **q) {
    free(*q);
    *q = NULL;
}

int my_queue_is_full(queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int my_queue_is_empty(queue *q) {
    return q->front == q->rear;
}

void my_queue_enqueue(queue *q, int data) {
    if (my_queue_is_full(q)) {
        printf("Queue is full! Data not added.\n");
        return;
    }

    if (my_queue_is_empty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }

    q->arr[q->rear] = data;
}

int my_queue_dequeue(queue *q) {
    int data;

    if (my_queue_is_empty(q)) {
        printf("Queue is empty! Data not removed.\n");
        return -1;
    }

    if (q->front == q->rear) {
        data = q->arr[q->front];
        q->front = q->rear = -1;
    } else {
        data = q->arr[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }

    return data;
}

void print_queue(queue *q) {
    int i = q->front;

    if (my_queue_is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    do {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    } while (i != q->rear);

    printf("\n");
}

int main() {
    queue *q = my_queue_create();

    my_queue_enqueue(q, 5);
    my_queue_enqueue(q, 10);
    my_queue_enqueue(q, 15);

    print_queue(q);

    int data = my_queue_dequeue(q);
    printf("Dequeued data: %d\n", data);

    my_queue_destroy(&q);

    return 0;
}