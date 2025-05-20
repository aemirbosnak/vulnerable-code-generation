//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    if (newQueue == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
    return newQueue;
}

bool isEmpty(Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

bool isFull(Queue* queue) {
    return (queue->size == MAX_SIZE);
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

int dequeue(Queue* queue) {
    int data;
    Node* tempNode;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    tempNode = queue->front;
    data = tempNode->data;
    queue->front = tempNode->next;
    free(tempNode);
    if (isEmpty(queue)) {
        queue->rear = NULL;
    }
    queue->size--;
    return data;
}

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->front->data;
}

void display(Queue* queue) {
    Node* tempNode = queue->front;
    printf("Queue elements are: ");
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    Queue* myQueue = createQueue();
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    enqueue(myQueue, 40);
    display(myQueue);
    printf("Dequeued element is: %d\n", dequeue(myQueue));
    display(myQueue);
    printf("Peek element is: %d\n", peek(myQueue));
    enqueue(myQueue, 50);
    display(myQueue);
    return 0;
}