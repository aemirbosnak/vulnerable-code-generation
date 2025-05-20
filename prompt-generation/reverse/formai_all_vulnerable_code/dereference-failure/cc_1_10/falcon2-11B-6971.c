//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct queue_node {
    int data;
    struct queue_node *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

void enqueue(Queue *queue, int data) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue *queue) {
    if (queue->front == NULL) {
        return -1;
    }

    QueueNode *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

void printQueue(Queue *queue) {
    QueueNode *current = queue->front;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));

    printQueue(queue);

    return 0;
}