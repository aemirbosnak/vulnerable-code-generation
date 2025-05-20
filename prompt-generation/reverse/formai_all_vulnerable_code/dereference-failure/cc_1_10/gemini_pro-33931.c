//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: expert-level
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

Queue* createQueue() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void enqueue(Queue *queue, int data) {
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
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
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    if (queue->size == 0) {
        queue->rear = NULL;
    }
    return data;
}

int front(Queue *queue) {
    if (queue->size == 0) {
        return -1;
    }
    return queue->front->data;
}

int rear(Queue *queue) {
    if (queue->size == 0) {
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

void printQueue(Queue *queue) {
    QueueNode *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
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
    printf("Front of the queue: %d\n", front(queue));
    printf("Rear of the queue: %d\n", rear(queue));
    printf("Size of the queue: %d\n", size(queue));
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    printf("Front of the queue: %d\n", front(queue));
    printf("Rear of the queue: %d\n", rear(queue));
    printf("Size of the queue: %d\n", size(queue));
    return 0;
}