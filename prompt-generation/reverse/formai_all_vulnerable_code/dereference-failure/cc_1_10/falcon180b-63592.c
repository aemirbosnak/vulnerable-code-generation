//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* temp = (Node*) malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    temp->data = data;
    temp->next = NULL;
    if (q->front == NULL) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(Queue* q) {
    int data = -1;
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return data;
    }
    Node* temp = q->front;
    data = temp->data;
    q->front = temp->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return data;
}

void display(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    return 0;
}