//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmptyQueue(Queue *q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue *q, int data) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->front->data;
    QueueNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

void displayQueue(Queue *q) {
    QueueNode *temp = q->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    displayQueue(&q);
    printf("%d\n", dequeue(&q));
    displayQueue(&q);
    printf("%d\n", dequeue(&q));
    displayQueue(&q);
    printf("%d\n", dequeue(&q));
    displayQueue(&q);
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    return 0;
}