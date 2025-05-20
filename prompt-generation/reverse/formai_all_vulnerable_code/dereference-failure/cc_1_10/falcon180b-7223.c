//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

int isFull(Queue* q) {
    return q->rear == NULL;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    int data;
    Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        data = temp->data;
        q->front = temp->next;
        free(temp);
    }

    return data;
}

void display(Queue* q) {
    Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
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
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Queue elements after enqueue:\n");
    display(&q);

    int dequeuedData = dequeue(&q);
    printf("Dequeued element: %d\n", dequeuedData);

    printf("Queue elements after dequeue:\n");
    display(&q);

    dequeue(&q);
    dequeue(&q);

    printf("Queue elements after multiple dequeue:\n");
    display(&q);

    return 0;
}