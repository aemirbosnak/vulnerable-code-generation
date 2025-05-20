//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct {
    int front;
    int rear;
    int capacity;
    int* elements;
} Queue;

void create_queue(Queue* q) {
    q->front = -1;
    q->rear = -1;
    q->capacity = MAX_SIZE;
    q->elements = (int*) malloc(q->capacity * sizeof(int));
}

void destroy_queue(Queue* q) {
    free(q->elements);
}

int is_full(Queue* q) {
    return (q->rear + 1) % q->capacity == q->front;
}

int is_empty(Queue* q) {
    return q->front == -1 && q->rear == -1;
}

void enqueue(Queue* q, int data) {
    if (is_full(q)) {
        printf("Error: Queue is full.\n");
        return;
    }

    q->rear = (q->rear + 1) % q->capacity;
    q->elements[q->rear] = data;

    printf("Star %d added to the queue. (Twinkling effect...)\n", data);
    fflush(stdout);
    sleep(1);
}

int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Error: Queue is empty.\n");
        return -1;
    }

    int data = q->elements[q->front];

    q->front = (q->front + 1) % q->capacity;

    printf("Star %d removed from the queue. (Twinkling effect...)\n", data);
    fflush(stdout);
    sleep(1);

    return data;
}

int main() {
    Queue q;
    create_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("Current queue state:\n");
    for (int i = q.front; i != q.rear; i = (i + 1) % q.capacity) {
        printf("Star %d\n", q.elements[i]);
    }
    printf("Star %d\n", q.elements[q.rear]);

    dequeue(&q);
    dequeue(&q);

    printf("Current queue state after dequeueing 2 stars:\n");
    for (int i = q.front; i != q.rear; i = (i + 1) % q.capacity) {
        printf("Star %d\n", q.elements[i]);
    }

    destroy_queue(&q);

    return 0;
}