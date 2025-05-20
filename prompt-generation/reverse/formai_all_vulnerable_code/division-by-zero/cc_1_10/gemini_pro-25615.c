//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Linus Torvalds style queue implementation

struct queue {
    int *arr;
    int head;
    int tail;
    int size;
};

struct queue *queue_init(int size) {
    struct queue *q = malloc(sizeof(struct queue));
    if (!q)
        return NULL;

    q->arr = malloc(sizeof(int) * size);
    if (!q->arr) {
        free(q);
        return NULL;
    }

    q->head = 0;
    q->tail = 0;
    q->size = size;

    return q;
}

void queue_destroy(struct queue *q) {
    free(q->arr);
    free(q);
}

int queue_is_empty(struct queue *q) {
    return q->head == q->tail;
}

int queue_is_full(struct queue *q) {
    return (q->tail + 1) % q->size == q->head;
}

int queue_enqueue(struct queue *q, int data) {
    if (queue_is_full(q))
        return -1;

    q->arr[q->tail] = data;
    q->tail = (q->tail + 1) % q->size;

    return 0;
}

int queue_dequeue(struct queue *q, int *data) {
    if (queue_is_empty(q))
        return -1;

    *data = q->arr[q->head];
    q->head = (q->head + 1) % q->size;

    return 0;
}

int main() {
    struct queue *q = queue_init(10);

    queue_enqueue(q, 1);
    queue_enqueue(q, 2);
    queue_enqueue(q, 3);

    int data;
    queue_dequeue(q, &data);
    printf("Dequeued: %d\n", data);
    queue_dequeue(q, &data);
    printf("Dequeued: %d\n", data);
    queue_dequeue(q, &data);
    printf("Dequeued: %d\n", data);

    queue_destroy(q);

    return 0;
}