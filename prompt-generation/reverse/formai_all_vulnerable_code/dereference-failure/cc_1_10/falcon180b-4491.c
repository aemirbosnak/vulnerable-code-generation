//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element *queueArray;
    int front, rear;
    int count;
} Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    if (newQueue == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newQueue->queueArray = (Element*) malloc(MAX_SIZE * sizeof(Element));
    if (newQueue->queueArray == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newQueue->front = newQueue->rear = -1;
    newQueue->count = 0;
    return newQueue;
}

void destroyQueue(Queue* queue) {
    free(queue->queueArray);
    free(queue);
}

int isEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(Queue* queue, int data, int priority) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->queueArray[queue->rear].data = data;
    queue->queueArray[queue->rear].priority = priority;
    queue->count++;
}

Element* dequeue(Queue* queue) {
    Element* element;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    element = &queue->queueArray[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    queue->count--;
    return element;
}

Element* peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return &queue->queueArray[queue->front];
}

void display(Queue* queue) {
    int i;
    for (i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->queueArray[i].data);
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10, 1);
    enqueue(queue, 20, 2);
    enqueue(queue, 30, 3);
    display(queue);
    Element* element = peek(queue);
    printf("Peek element: %d\n", element->data);
    element = dequeue(queue);
    printf("Dequeued element: %d\n", element->data);
    display(queue);
    destroyQueue(queue);
    return 0;
}