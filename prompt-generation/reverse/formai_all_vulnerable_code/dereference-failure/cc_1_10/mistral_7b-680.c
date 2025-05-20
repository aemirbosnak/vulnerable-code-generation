//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct queue_tag {
    int front, rear;
    int data[MAX_QUEUE_SIZE];
} queue_t;

queue_t *createQueue() {
    queue_t *q = (queue_t *)calloc(1, sizeof(queue_t));
    q->front = q->rear = -1;
    return q;
}

int isFull(queue_t *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int isEmpty(queue_t *q) {
    return q->front == q->rear;
}

void enqueue(queue_t *q, int data) {
    if (isFull(q)) {
        fprintf(stderr, "Queue Overflow!\n");
        exit(EXIT_FAILURE);
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }

    q->data[q->rear] = data;
}

int dequeue(queue_t *q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Queue Underflow!\n");
        exit(EXIT_FAILURE);
    }

    int data = q->data[q->front];

    if (q->rear == q->front) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }

    return data;
}

int main() {
    queue_t *q = createQueue();

    char str[10];
    int i, num;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (isdigit(str[i])) {
            sscanf(&str[i], "%d", &num);
            enqueue(q, num);
        }
    }

    printf("Queue elements: ");
    while (!isEmpty(q)) {
        printf("%d ", dequeue(q));
    }
    printf("\n");

    free(q);

    return EXIT_SUCCESS;
}