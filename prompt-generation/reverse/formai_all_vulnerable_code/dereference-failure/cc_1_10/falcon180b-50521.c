//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    int data;

    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    Node* temp = q->front;
    data = temp->data;
    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

void display(Queue* q) {
    Node* temp = q->front;

    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printf("Queue after enqueue:\n");
    display(q);

    int dequeuedData;

    dequeuedData = dequeue(q);
    printf("Dequeued data: %d\n", dequeuedData);

    dequeuedData = dequeue(q);
    printf("Dequeued data: %d\n", dequeuedData);

    dequeuedData = dequeue(q);
    printf("Dequeued data: %d\n", dequeuedData);

    dequeuedData = dequeue(q);
    printf("Dequeued data: %d\n", dequeuedData);

    dequeuedData = dequeue(q);
    printf("Dequeued data: %d\n", dequeuedData);

    printf("Queue after dequeue:\n");
    display(q);

    return 0;
}