//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

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

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
}

int dequeue(Queue *queue) {
    if (queue->front == NULL) {
        return -1;
    }

    int data = queue->front->data;
    QueueNode *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);

    queue->size--;

    return data;
}

int front(Queue *queue) {
    if (queue->front == NULL) {
        return -1;
    }

    return queue->front->data;
}

int rear(Queue *queue) {
    if (queue->rear == NULL) {
        return -1;
    }

    return queue->rear->data;
}

int size(Queue *queue) {
    return queue->size;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

void destroyQueue(Queue *queue) {
    QueueNode *current = queue->front;
    while (current != NULL) {
        QueueNode *next = current->next;
        free(current);
        current = next;
    }

    free(queue);
}

int main() {
    Queue *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Front: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));
    printf("Size: %d\n", size(queue));

    printf("Dequeue: %d\n", dequeue(queue));
    printf("Dequeue: %d\n", dequeue(queue));

    printf("Front: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));
    printf("Size: %d\n", size(queue));

    printf("Dequeue: %d\n", dequeue(queue));

    printf("Front: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));
    printf("Size: %d\n", size(queue));

    destroyQueue(queue);

    return 0;
}