//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: portable
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
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    int data = -1;
    if (q->front!= NULL) {
        Node* temp = q->front;
        q->front = q->front->next;
        data = temp->data;
        free(temp);
    }
    return data;
}

int isEmpty(Queue* q) {
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

int size(Queue* q) {
    int count = 0;
    Node* temp = q->front;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void display(Queue* q) {
    Node* temp = q->front;
    printf("Queue: ");
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
    display(q);
    printf("Size of the queue is: %d\n", size(q));
    printf("Dequeued element is: %d\n", dequeue(q));
    display(q);
    printf("Size of the queue is: %d\n", size(q));
    printf("Dequeued element is: %d\n", dequeue(q));
    display(q);
    printf("Size of the queue is: %d\n", size(q));
    return 0;
}