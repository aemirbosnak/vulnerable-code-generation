//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: introspective
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
    int count;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
    return queue;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->count++;
}

int dequeue(Queue* queue) {
    int data;
    Node* temp = queue->front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        exit(0);
    }
    data = temp->data;
    queue->front = temp->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    queue->count--;
    return data;
}

void display(Queue* queue) {
    Node* temp = queue->front;
    printf("Queue elements are:\n");
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
    enqueue(queue, 40);
    display(queue);
    printf("Dequeued element is: %d\n", dequeue(queue));
    display(queue);
    printf("Dequeued element is: %d\n", dequeue(queue));
    display(queue);
    printf("Dequeued element is: %d\n", dequeue(queue));
    display(queue);
    printf("Dequeued element is: %d\n", dequeue(queue));
    display(queue);
    return 0;
}