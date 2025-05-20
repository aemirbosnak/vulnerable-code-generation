//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10

typedef struct queue_tag {
    int data[MAX_QUEUE_SIZE];
    int head;
    int tail;
    int count;
} queue_t;

queue_t* queue_create() {
    queue_t* q = malloc(sizeof(queue_t));
    if (q == NULL) {
        fprintf(stderr, "Error: unable to allocate memory for queue.\n");
        return NULL;
    }

    q->head = 0;
    q->tail = -1;
    q->count = 0;

    return q;
}

int queue_is_full(queue_t* q) {
    return q->count == MAX_QUEUE_SIZE;
}

int queue_is_empty(queue_t* q) {
    return q->count == 0;
}

int queue_enqueue(queue_t* q, int data) {
    if (queue_is_full(q)) {
        fprintf(stderr, "Error: queue is full. Cannot enqueue %d.\n", data);
        return -1;
    }

    q->data[q->tail] = data;
    q->tail = (q->tail + 1) % MAX_QUEUE_SIZE;
    q->count++;

    return 0;
}

int queue_dequeue(queue_t* q, int* data) {
    if (queue_is_empty(q)) {
        fprintf(stderr, "Error: queue is empty. Cannot dequeue.\n");
        return -1;
    }

    *data = q->data[q->head];
    q->head = (q->head + 1) % MAX_QUEUE_SIZE;
    q->count--;

    return 0;
}

void queue_destroy(queue_t* q) {
    free(q);
}

void print_queue(queue_t* q) {
    if (queue_is_empty(q)) {
        printf("Empty queue.\n");
        return;
    }

    int i;
    printf("Queue contents: [");
    for (i = q->head; i != q->tail; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d, ", q->data[i]);
    }
    printf("%d]\n", q->data[i]);
}

int main() {
    queue_t* q = queue_create();

    int data;

    queue_enqueue(q, 5);
    queue_enqueue(q, 10);
    queue_enqueue(q, 15);

    print_queue(q);

    queue_dequeue(q, &data);
    print_queue(q);

    queue_dequeue(q, &data);
    print_queue(q);

    queue_enqueue(q, 20);
    print_queue(q);

    queue_destroy(q);

    return 0;
}