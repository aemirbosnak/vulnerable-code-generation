//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void enqueue(Queue *queue, int data) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->size == 0) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

int dequeue(Queue *queue) {
    if (queue->size == 0) {
        return -1;
    }
    QueueNode *temp = queue->front;
    queue->front = queue->front->next;
    queue->size--;
    free(temp);
    return temp->data;
}

bool isEmpty(Queue *queue) {
    return queue->size == 0;
}

int peek(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->front->data;
}

void printQueue(Queue *queue) {
    QueueNode *node = queue->front;
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Queue *queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printQueue(queue);
    printf("Dequeued value: %d\n", dequeue(queue));
    printQueue(queue);
    printf("Peek value: %d\n", peek(queue));
    printf("Queue is empty: %s\n", isEmpty(queue)? "true" : "false");
    return 0;
}