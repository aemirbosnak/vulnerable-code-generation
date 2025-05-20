//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
        q->size++;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->size++;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    
    Node* temp = q->front;
    q->front = q->front->next;
    q->size--;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return temp->data;
}

void display(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    Node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    q.size = 0;
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    
    display(&q);
    printf("%d\n", dequeue(&q));
    display(&q);
    printf("%d\n", dequeue(&q));
    display(&q);
    printf("%d\n", dequeue(&q));
    display(&q);
    printf("%d\n", dequeue(&q));
    
    return 0;
}