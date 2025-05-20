//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct QueueElm {
    int data;
    struct QueueElm *next;
} QueueElm;

typedef struct Queue {
    QueueElm *head;
    QueueElm *tail;
} Queue;

Queue *createQueue() {
    Queue *q = malloc(sizeof(Queue));
    q->head = q->tail = NULL;
    return q;
}

void enqueue(Queue *q, int data) {
    QueueElm *newElm = malloc(sizeof(QueueElm));
    newElm->data = data;
    newElm->next = NULL;
    if (q->tail) {
        q->tail->next = newElm;
    } else {
        q->head = newElm;
    }
    q->tail = newElm;
}

int dequeue(Queue *q) {
    if (!q->head) {
        return -1;
    }
    QueueElm *elm = q->head;
    int data = elm->data;
    q->head = elm->next;
    if (!q->head) {
        q->tail = NULL;
    }
    free(elm);
    return data;
}

int main() {
    Queue *q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    if (dequeue(q) == -1) {
        printf("Queue is empty\n");
    }
    free(q);
    return 0;
}