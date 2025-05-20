//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10
#define QUEUE_ITEM_SIZE 50

typedef struct queue {
    char data[MAX_QUEUE_SIZE][QUEUE_ITEM_SIZE];
    int head;
    int tail;
    int count;
} queue_t;

void initQueue(queue_t *q) {
    q->head = -1;
    q->tail = -1;
    q->count = 0;
}

bool isFull(queue_t *q) {
    return ((q->count + 1) % MAX_QUEUE_SIZE == q->head);
}

bool isEmpty(queue_t *q) {
    return (q->head == -1 && q->tail == -1);
}

void enqueue(queue_t *q, char *str) {
    if (isFull(q)) {
        fprintf(stderr, "Error: Queue is full.\n");
        return;
    }

    int next = (q->tail + 1) % MAX_QUEUE_SIZE;

    strcpy(q->data[q->tail], str);
    q->tail = next;
    q->count++;
}

char *dequeue(queue_t *q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Error: Queue is empty.\n");
        return NULL;
    }

    char *str = &q->data[q->head][0];
    q->head = (q->head + 1) % MAX_QUEUE_SIZE;
    q->count--;

    return str;
}

void printQueue(queue_t *q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty.\n");
        return;
    }

    int i;
    for (i = q->head; i != q->tail; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%s\n", q->data[i]);
    }
    printf("%s\n", q->data[q->tail]);
}

int main() {
    queue_t q;
    initQueue(&q);

    char str1[QUEUE_ITEM_SIZE] = "Hello, world!";
    char str2[QUEUE_ITEM_SIZE] = "Shannon was a genius.";
    char str3[QUEUE_ITEM_SIZE] = "Queues are useful.";

    enqueue(&q, str1);
    enqueue(&q, str2);
    enqueue(&q, str3);

    printQueue(&q);

    char *str;
    while ((str = dequeue(&q)) != NULL) {
        printf("Dequeued: %s\n", str);
    }

    return 0;
}