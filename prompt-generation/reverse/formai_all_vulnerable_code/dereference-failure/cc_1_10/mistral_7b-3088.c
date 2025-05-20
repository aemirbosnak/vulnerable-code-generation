//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100
#define QUEUE_ELEMENT_SIZE 50

typedef struct queue {
    int front;
    int rear;
    char elements[MAX_QUEUE_SIZE][QUEUE_ELEMENT_SIZE];
} queue_t;

void initializeQueue(queue_t *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(queue_t *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int isEmpty(queue_t *q) {
    return q->front == -1 && q->rear == -1;
}

void enqueue(queue_t *q, const char *element) {
    if (isFull(q)) {
        fprintf(stderr, "Queue overflow!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    strcpy(q->elements[q->rear], element);
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

const char *dequeue(queue_t *q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Queue underflow!\n");
        return NULL;
    }
    const char *element = q->elements[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    return element;
}

int main(void) {
    queue_t q;
    initializeQueue(&q);

    const char *str1 = "Hello";
    const char *str2 = "World";
    const char *str3 = "Donald";
    const char *str4 = "Knuth";

    enqueue(&q, str1);
    enqueue(&q, str2);
    enqueue(&q, str3);
    enqueue(&q, str4);

    printf("Queue contents:\n");
    while (!isEmpty(&q)) {
        const char *element = dequeue(&q);
        printf("%s\n", element);
    }

    return 0;
}