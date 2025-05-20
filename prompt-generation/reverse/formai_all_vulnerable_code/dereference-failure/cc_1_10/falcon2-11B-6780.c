//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue createQueue() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    return q;
}

void enqueue(Queue *q, int data) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        return -1;
    }

    int data = q->front->data;
    QueueNode *temp = q->front;
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return data;
}

void printQueue(Queue *q) {
    QueueNode *temp = q->front;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q = createQueue();

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printQueue(&q); // 1 2 3

    printf("Dequeued: %d\n", dequeue(&q)); // 1

    printQueue(&q); // 2 3

    return 0;
}