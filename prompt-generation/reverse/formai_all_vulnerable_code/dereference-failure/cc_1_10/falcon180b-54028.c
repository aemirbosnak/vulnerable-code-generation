//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
} queue;

queue* createQueue() {
    queue* newQueue = (queue*)malloc(sizeof(queue));
    if (newQueue == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

void enqueue(queue* q, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory error\n");
        return;
    }
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

int dequeue(queue* q) {
    int data = -1;
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return data;
    }
    node* temp = q->front;
    data = temp->data;
    q->front = temp->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return data;
}

void display(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    node* temp = q->front;
    printf("Queue elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    display(q);
    int data = dequeue(q);
    printf("Dequeued element is: %d\n", data);
    display(q);
    return 0;
}