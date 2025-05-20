//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    void **data;
    int front;
    int rear;
    int size;
} Queue;

Queue* create_queue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->data = (void**)malloc(MAX_QUEUE_SIZE * sizeof(void*));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, void *data) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    void **rear_ptr = &q->data[++q->rear];
    *rear_ptr = data;
    q->size++;
}

void dequeue(Queue *q) {
    if (q->front == -1 || q->rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    void *data = q->data[q->front];
    q->data[q->front] = NULL;
    q->front++;
    q->size--;
}

void *peek(Queue *q) {
    if (q->front == -1 || q->rear == -1) {
        printf("Queue is empty\n");
        return NULL;
    }
    return q->data[q->front];
}

bool is_empty(Queue *q) {
    return q->front == -1 && q->rear == -1;
}

int get_size(Queue *q) {
    return q->size;
}

void destroy_queue(Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    Queue *q = create_queue();
    enqueue(q, "Hello");
    enqueue(q, "World");
    printf("%s\n", (char*)peek(q));
    dequeue(q);
    printf("%s\n", (char*)peek(q));
    destroy_queue(q);
    return 0;
}