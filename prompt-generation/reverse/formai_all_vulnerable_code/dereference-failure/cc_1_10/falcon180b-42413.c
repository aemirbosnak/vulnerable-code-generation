//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
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
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    int data = -1;
    if (q->front!= NULL) {
        data = q->front->data;
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    return data;
}

void display(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        Node* temp = q->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);

    int data = dequeue(q);
    printf("Dequeued element is: %d\n", data);
    display(q);

    data = dequeue(q);
    printf("Dequeued element is: %d\n", data);
    display(q);

    data = dequeue(q);
    printf("Dequeued element is: %d\n", data);
    display(q);

    data = dequeue(q);
    printf("Dequeued element is: %d\n", data);
    display(q);

    data = dequeue(q);
    printf("Dequeued element is: %d\n", data);
    display(q);

    return 0;
}