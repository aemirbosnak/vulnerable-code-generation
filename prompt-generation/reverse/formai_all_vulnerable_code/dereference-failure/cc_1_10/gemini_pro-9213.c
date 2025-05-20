//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *back;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->back = NULL;
    return queue;
}

void enqueue(Queue *queue, int data) {
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    node->data = data;
    node->next = NULL;
    if (queue->front == NULL) {
        queue->front = node;
        queue->back = node;
    } else {
        queue->back->next = node;
        queue->back = node;
    }
}

int dequeue(Queue *queue) {
    if (queue->front == NULL) {
        return -1;
    } else {
        QueueNode *node = queue->front;
        int data = node->data;
        queue->front = node->next;
        free(node);
        if (queue->front == NULL) {
            queue->back = NULL;
        }
        return data;
    }
}

int peek(Queue *queue) {
    if (queue->front == NULL) {
        return -1;
    } else {
        return queue->front->data;
    }
}

int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

void printQueue(Queue *queue) {
    QueueNode *node = queue->front;
    while (node != NULL) {
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
    enqueue(queue, 4);
    enqueue(queue, 5);
    printQueue(queue);
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printQueue(queue);
    enqueue(queue, 6);
    enqueue(queue, 7);
    printQueue(queue);
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Is empty: %d\n", isEmpty(queue));
    return 0;
}