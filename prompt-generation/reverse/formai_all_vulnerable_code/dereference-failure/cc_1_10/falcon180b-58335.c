//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

bool isEmptyQueue(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmptyQueue(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    int data = -1;

    if (!isEmptyQueue(queue)) {
        Node* temp = queue->front;
        data = temp->data;
        queue->front = temp->next;

        if (queue->front == NULL) {
            queue->rear = NULL;
        }

        free(temp);
    }

    return data;
}

void displayQueue(Queue* queue) {
    Node* temp = queue->front;

    if (isEmptyQueue(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    displayQueue(&queue);

    int dequeuedData = dequeue(&queue);
    printf("Dequeued data: %d\n", dequeuedData);

    displayQueue(&queue);

    return 0;
}