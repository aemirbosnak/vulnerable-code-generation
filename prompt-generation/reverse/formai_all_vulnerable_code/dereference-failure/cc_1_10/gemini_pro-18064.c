//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void enqueue(Queue *queue, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
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
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

int peek(Queue *queue) {
    if (queue->front == NULL) {
        return -1;
    }
    return queue->front->data;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

int main() {
    Queue *queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printf("Queue: ");
    while (!isEmpty(queue)) {
        printf("%d ", dequeue(queue));
    }
    printf("\n");
    return 0;
}