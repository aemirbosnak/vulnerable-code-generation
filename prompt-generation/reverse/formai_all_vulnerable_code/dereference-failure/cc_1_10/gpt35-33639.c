//FormAI DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100

typedef struct {
    int front, rear;
    int elements[MAX_LEN];
} Queue;

Queue* create_queue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int is_empty(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        return 1;
    } else {
        return 0;
    }
}

int is_full(Queue* q) {
    if (q->rear == MAX_LEN - 1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue* q, int item) {
    if (is_full(q)) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->elements[q->rear] = item;
    }
}

int dequeue(Queue* q) {
    int item;
    if (is_empty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    } else {
        item = q->elements[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

int main() {
    Queue* q = create_queue();

    printf("Is the queue empty? %d (1 = Yes, 0 = No)\n", is_empty(q));
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("\nDequeuing elements from queue:\n");
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    
    printf("\nIs the queue empty? %d (1 = Yes, 0 = No)\n", is_empty(q));

    enqueue(q, 40);
    enqueue(q, 50);

    printf("\nEnqueueing elements into queue:\n");
    printf("%d ", q->elements[q->front]);
    printf("%d\n", q->elements[q->rear]);

    printf("\nIs the queue full? %d (1 = Yes, 0 = No)\n", is_full(q));

    return 0;
}