//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 10

typedef struct queue_tag {
    int front;
    int rear;
    int data[QUEUE_SIZE];
} queue_t;

queue_t* my_queue_init() {
    queue_t* q = (queue_t*)calloc(1, sizeof(queue_t));
    q->front = q->rear = -1;
    return q;
}

void my_queue_enqueue(queue_t* q, int data) {
    if (q->rear == QUEUE_SIZE - 1) {
        printf("Queue is full.\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear++;
    q->data[q->rear] = data;
}

int my_queue_dequeue(queue_t* q) {
    int data = -1;

    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty.\n");
        return data;
    }

    data = q->data[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }

    return data;
}

void my_queue_destroy(queue_t* q) {
    free(q);
}

int main() {
    queue_t* q = my_queue_init();

    my_queue_enqueue(q, 5);
    my_queue_enqueue(q, 10);
    my_queue_enqueue(q, 15);

    printf("Dequeued %d\n", my_queue_dequeue(q));
    printf("Dequeued %d\n", my_queue_dequeue(q));

    my_queue_destroy(q);

    return 0;
}