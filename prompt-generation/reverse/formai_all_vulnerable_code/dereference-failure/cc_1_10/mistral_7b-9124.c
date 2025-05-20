//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#define QUEUE_SIZE 10

typedef struct CircularBuffer {
    void *buffer;
    size_t size;
    size_t head;
    size_t tail;
} CircularBuffer;

CircularBuffer *queue_create(size_t item_size) {
    CircularBuffer *q = malloc(sizeof(CircularBuffer));
    if (q == NULL) {
        return NULL;
    }

    q->buffer = malloc(QUEUE_SIZE * item_size);
    if (q->buffer == NULL) {
        free(q);
        return NULL;
    }

    q->size = QUEUE_SIZE * item_size;
    q->head = 0;
    q->tail = 0;

    return q;
}

bool queue_is_full(CircularBuffer *q) {
    return ((q->tail + 1) % QUEUE_SIZE == q->head);
}

bool queue_is_empty(CircularBuffer *q) {
    return (q->head == q->tail);
}

void queue_enqueue(CircularBuffer *q, void *item) {
    if (queue_is_full(q)) {
        fprintf(stderr, "Queue is full.\n");
        return;
    }

    void *buffer = (char *)q->buffer + q->tail * sizeof(void *);
    memcpy(buffer, item, sizeof(void *));
    q->tail = (q->tail + 1) % QUEUE_SIZE;
}

void *queue_dequeue(CircularBuffer *q) {
    if (queue_is_empty(q)) {
        fprintf(stderr, "Queue is empty.\n");
        return NULL;
    }

    void *item = NULL;
    void *buffer = (char *)q->buffer + q->head * sizeof(void *);

    item = malloc(sizeof(void *));
    memcpy(item, buffer, sizeof(void *));

    q->head = (q->head + 1) % QUEUE_SIZE;
    return item;
}

void queue_destroy(CircularBuffer *q) {
    free(q->buffer);
    free(q);
}

void print_queue(CircularBuffer *q) {
    if (queue_is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    size_t i = q->head;
    void *item;

    printf("Queue contents:\n");

    do {
        item = queue_dequeue(q);
        printf("%p ", item);
        free(item);
    } while (i != (q->head) && !queue_is_empty(q));

    printf("\n");
}

int main() {
    CircularBuffer *queue = queue_create(sizeof(int));

    int i;
    for (i = 0; i < 15; i++) {
        queue_enqueue(queue, &i);
    }

    printf("Queue size: %ld\n", (long)queue->size);
    printf("Queue is full: %s\n", queue_is_full(queue) ? "true" : "false");

    print_queue(queue);

    for (i = 0; i < 5; i++) {
        int popped_item;
        popped_item = *(int *)queue_dequeue(queue);
        printf("Popped item: %d\n", popped_item);
    }

    print_queue(queue);

    queue_destroy(queue);

    return 0;
}