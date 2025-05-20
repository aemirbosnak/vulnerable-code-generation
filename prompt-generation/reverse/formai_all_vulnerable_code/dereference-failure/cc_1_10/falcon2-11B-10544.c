//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1;
    }
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return temp->data;
}

int peek(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1;
    }
    return queue->front->data;
}

int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

int main() {
    struct Queue* myQueue = (struct Queue*)malloc(sizeof(struct Queue));
    myQueue->front = NULL;
    myQueue->rear = NULL;
    
    enqueue(myQueue, 1);
    enqueue(myQueue, 2);
    enqueue(myQueue, 3);
    
    printf("Front element: %d\n", peek(myQueue));
    printf("Rear element: %d\n", peek(myQueue));
    
    dequeue(myQueue);
    dequeue(myQueue);
    
    printf("Front element: %d\n", peek(myQueue));
    printf("Rear element: %d\n", peek(myQueue));
    
    if (isEmpty(myQueue)) {
        printf("Queue is empty.\n");
    }
    
    return 0;
}