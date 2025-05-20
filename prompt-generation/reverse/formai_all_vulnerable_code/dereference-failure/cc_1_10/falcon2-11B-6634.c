//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

struct Queue {
    Node* front;
    Node* rear;
};

typedef struct Queue Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return -1;
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return temp->data;
}

int main() {
    Queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printf("Dequeued value: %d\n", dequeue(queue));
    printf("Dequeued value: %d\n", dequeue(queue));
    printf("Dequeued value: %d\n", dequeue(queue));
    return 0;
}