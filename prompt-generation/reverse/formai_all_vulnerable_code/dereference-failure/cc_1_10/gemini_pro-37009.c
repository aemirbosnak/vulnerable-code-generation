//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

void enQueue(Queue *queue, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
}

int deQueue(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

int peek(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->front->data;
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
    enQueue(queue, 10);
    enQueue(queue, 20);
    enQueue(queue, 30);
    enQueue(queue, 40);
    displayQueue(queue);
    printf("Peek: %d\n", peek(queue));
    printf("Dequeue: %d\n", deQueue(queue));
    printf("Dequeue: %d\n", deQueue(queue));
    displayQueue(queue);
    return 0;
}