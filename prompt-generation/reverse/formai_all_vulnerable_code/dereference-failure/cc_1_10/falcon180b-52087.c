//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

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
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

int isEmpty(Queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

int isFull(Queue* q) {
    return (q->size == MAX_SIZE);
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(q)) {
        q->front = q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue* q) {
    int data;
    Node* temp = q->front;
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        exit(0);
    }
    data = q->front->data;
    q->front = q->front->next;
    q->size--;
    free(temp);
    return data;
}

void display(Queue* q) {
    Node* temp = q->front;
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        exit(0);
    }
    printf("Queue elements are: ");
    while(temp!= NULL) {
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
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}