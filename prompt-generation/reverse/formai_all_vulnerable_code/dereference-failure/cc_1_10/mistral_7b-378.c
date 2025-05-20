//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define QUEUE_SIZE 10

typedef struct {
    char data[QUEUE_SIZE][20];
    int head;
    int tail;
} queue;

void initQueue(queue *q) {
    q->head = -1;
    q->tail = -1;
}

int isFull(queue *q) {
    return ((q->tail + 1) % QUEUE_SIZE == q->head);
}

int isEmpty(queue *q) {
    return (q->head == -1 && q->tail == -1);
}

void enqueue(queue *q, const char *str) {
    if (isFull(q)) {
        fprintf(stderr, "Error: Queue is full.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(q->data[q->tail], str);

    q->tail = (q->tail + 1) % QUEUE_SIZE;

    if (q->head == -1) {
        q->head = q->tail;
    }
}

char dequeue(queue *q) {
    char str[20];
    int old_tail;

    if (isEmpty(q)) {
        fprintf(stderr, "Error: Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    old_tail = q->tail;

    strcpy(str, q->data[q->head]);

    q->head = (q->head + 1) % QUEUE_SIZE;

    if (q->head == old_tail) {
        q->head = -1;
        q->tail = -1;
    }

    return str[strlen(str) - 1];
}

int main() {
    queue q;
    int i;

    initQueue(&q);

    for (i = 0; i < QUEUE_SIZE; ++i) {
        enqueue(&q, "Item ");
    }

    fprintf(stderr, "Error: Queue is full.\n"); // Testing isFull

    for (i = 0; i < QUEUE_SIZE; ++i) {
        printf("%c", dequeue(&q));
    }

    fprintf(stderr, "Error: Queue is empty.\n"); // Testing isEmpty

    return EXIT_SUCCESS;
}