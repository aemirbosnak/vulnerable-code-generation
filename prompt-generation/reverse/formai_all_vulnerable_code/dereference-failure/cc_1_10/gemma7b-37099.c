//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Queue {
    Node** arr;
    int front, rear, size;
};

void enqueue(struct Queue* queue, int data) {
    if (queue->size == MAX) {
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = newNode;
}

int dequeue(struct Queue* queue) {
    if (queue->size == 0) {
        return -1;
    }
    int data = queue->arr[queue->front]->data;
    free(queue->arr[queue->front]);
    queue->front++;

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    return data;
}

int main() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->arr = (Node**)malloc(MAX * sizeof(Node));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    int data = dequeue(queue);
    printf("Data: %d\n", data);

    data = dequeue(queue);
    printf("Data: %d\n", data);

    data = dequeue(queue);
    printf("Data: %d\n", data);

    data = dequeue(queue);
    printf("Data: %d\n", data);

    return 0;
}