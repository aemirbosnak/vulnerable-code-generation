//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    char data[MAX_QUEUE_SIZE][30];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueFull(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int isQueueEmpty(Queue *q) {
    return q->front == -1 && q->rear == -1;
}

void enqueue(Queue *q, char *data) {
    if (isQueueFull(q)) {
        printf("Queue is full. Cannot enqueue: %s\n", data);
        return;
    }

    if (isQueueEmpty(q)) {
        q->front = 0;
        strcpy(q->data[q->rear], data);
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    } else {
        strcpy(q->data[q->rear], data);
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }
}

char *dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return NULL;
    }

    char *data = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }

    return data;
}

int main() {
    Queue q;
    initQueue(&q);

    char survivors[11][30] = {"Mike", "Sarah", "Tom", "Emily", "John", "David", "Samantha", "Mark", "Rachel", "Daniel", "Oliver"};

    printf("In the post-apocalyptic world, only the following survivors were able to make it to the shelter:\n");

    for (int i = 0; i < 11; i++) {
        enqueue(&q, survivors[i]);
    }

    printf("\nSurvivors in the shelter queue:\n");

    while (!isQueueEmpty(&q)) {
        printf("%s\n", dequeue(&q));
    }

    printf("\nAll survivors have been evacuated.\n");

    return 0;
}