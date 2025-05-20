//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: portable
#include <stdlib.h>
#include <stdio.h>

#define QUEUE_SIZE 100

typedef struct _queue {
    int head;
    int tail;
    int count;
    int data[QUEUE_SIZE];
} queue;

queue *create_queue() {
    queue *q = malloc(sizeof(queue));
    if (q == NULL) {
        return NULL;
    }
    q->head = 0;
    q->tail = 0;
    q->count = 0;
    return q;
}

int enqueue(queue *q, int data) {
    if (q->count == QUEUE_SIZE) {
        return 0;
    }
    q->data[q->tail] = data;
    q->tail = (q->tail + 1) % QUEUE_SIZE;
    q->count++;
    return 1;
}

int dequeue(queue *q) {
    if (q->count == 0) {
        return -1;
    }
    int data = q->data[q->head];
    q->head = (q->head + 1) % QUEUE_SIZE;
    q->count--;
    return data;
}

int main() {
    queue *q = create_queue();
    if (q == NULL) {
        printf("Error creating queue.\n");
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        if (!enqueue(q, i)) {
            printf("Error enqueueing %d.\n", i);
            return 1;
        }
    }
    for (int i = 0; i < 10; i++) {
        int data = dequeue(q);
        if (data == -1) {
            printf("Error dequeueing.\n");
            return 1;
        }
        printf("%d\n", data);
    }
    return 0;
}