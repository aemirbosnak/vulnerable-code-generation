//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct queue {
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
} queue;

void initializeQueue(queue *q) {
    q->front = 0;
    q->rear = -1;
}

bool isQueueFull(queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

bool isQueueEmpty(queue *q) {
    return (q->rear == -1);
}

void enqueue(queue *q, int item) {
    if (isQueueFull(q)) {
        printf("Error: Queue is full.\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

int dequeue(queue *q) {
    if (isQueueEmpty(q)) {
        printf("Error: Queue is empty.\n");
        return -1;
    }

    int item = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return item;
}

void printQueue(queue *q) {
    if (isQueueEmpty(q)) {
        printf("Error: Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i = q->front;
    do {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    } while (i != q->rear);
    printf("\n");
}

queue *createQueue() {
    queue *q = malloc(sizeof(queue));
    initializeQueue(q);
    return q;
}

void destroyQueue(queue *q) {
    free(q);
}

void processCrimeScene(char *evidence) {
    queue *cluesQueue = createQueue();
    char *token;
    int clueId = 1;

    token = strtok(evidence, " ");
    while (token != NULL) {
        enqueue(cluesQueue, clueId++ * 10 + atoi(token));
        token = strtok(NULL, " ");
    }

    printf("Clues Queue:\n");
    printQueue(cluesQueue);

    int sum = 0;
    while (!isQueueEmpty(cluesQueue)) {
        int clue = dequeue(cluesQueue);
        sum += clue;
    }

    printf("Total clues value: %d\n", sum);

    destroyQueue(cluesQueue);
}

int main() {
    char evidence[] = "20 30 1 10 5 2 25 50";
    processCrimeScene(evidence);

    return 0;
}