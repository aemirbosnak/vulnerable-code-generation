//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    int data;
    struct queue *next;
} node;

typedef struct {
    node *front;
    node *rear;
} queue;

void enqueue(queue *q, int item) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = item;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(queue *q) {
    if (q->front == NULL) {
        return -1;
    }

    int item = q->front->data;
    node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return item;
}

void printQueue(queue *q) {
    node *temp = q->front;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue q;
    q.front = NULL;
    q.rear = NULL;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);

    printf("Front: %d, Rear: %d\n", q.front->data, q.rear->data);
    printQueue(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    printf("Front: %d, Rear: %d\n", q.front->data, q.rear->data);
    printQueue(&q);

    return 0;
}