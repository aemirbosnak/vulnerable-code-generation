//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front, *rear;
    int size;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void enqueue(Queue *queue, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
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
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
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

void displayQueue(Queue *queue) {
    Node *temp = queue->front;
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

    printf("Queue: ");
    displayQueue(queue);
    printf("Size: %d\n", size(queue));
    printf("Front: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    printf("Queue after removing 3 elements: ");
    displayQueue(queue);
    printf("Size: %d\n", size(queue));
    printf("Front: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));

    isEmpty(queue) ? printf("Queue is empty\n") : printf("Queue is not empty\n");

    return 0;
}