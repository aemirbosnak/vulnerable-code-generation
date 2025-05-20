//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>

typedef struct queue {
    int *buf;
    int size;
    int head, tail;
} queue_t;

queue_t *queue_new(int size) {
    queue_t *q = malloc(sizeof(queue_t));
    q->buf = malloc(sizeof(int) * size);
    q->size = size;
    q->head = q->tail = 0;
    return q;
}

void queue_free(queue_t *q) {
    free(q->buf);
    free(q);
}

int queue_is_empty(queue_t *q) {
    return q->head == q->tail;
}

int queue_is_full(queue_t *q) {
    return (q->tail + 1) % q->size == q->head;
}

int queue_enqueue(queue_t *q, int val) {
    if (queue_is_full(q))
        return -1;
    q->buf[q->tail] = val;
    q->tail = (q->tail + 1) % q->size;
    return 0;
}

int queue_dequeue(queue_t *q, int *val) {
    if (queue_is_empty(q))
        return -1;
    *val = q->buf[q->head];
    q->head = (q->head + 1) % q->size;
    return 0;
}

int main() {
    queue_t *q = queue_new(5);
    for (int i = 0; i < 5; i++)
        queue_enqueue(q, i);
    int val;
    while (!queue_is_empty(q)) {
        queue_dequeue(q, &val);
        printf("%d\n", val);
    }
    queue_free(q);
    return 0;
}