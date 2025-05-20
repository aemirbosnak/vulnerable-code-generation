//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue* queue) {
    if (queue->front == NULL && queue->rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    Node* temp = queue->front;
    int data = temp->data;

    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = temp->next;
    }

    free(temp);

    return data;
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = queue->front;

    printf("Queue elements: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    display(queue);

    int dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);

    display(queue);

    dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);

    display(queue);

    dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);

    display(queue);

    dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);

    display(queue);

    return 0;
}