//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

void initQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

bool isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

bool isFull(struct Queue* queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Error: Unable to allocate memory.\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    if (isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    }
    else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        exit(1);
    }
    struct Node* node = queue->front;
    int data = node->data;
    queue->front = node->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(node);
    queue->size--;
    return data;
}

int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        exit(1);
    }
    return queue->front->data;
}

void printQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue: ");
        struct Node* node = queue->front;
        while (node!= NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue queue;
    initQueue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    printQueue(&queue);
    printf("Dequeued element: %d\n", dequeue(&queue));
    printQueue(&queue);
    printf("Peek element: %d\n", peek(&queue));
    dequeue(&queue);
    dequeue(&queue);
    printQueue(&queue);
    return 0;
}