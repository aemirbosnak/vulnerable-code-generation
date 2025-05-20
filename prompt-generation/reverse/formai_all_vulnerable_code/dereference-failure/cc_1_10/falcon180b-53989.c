//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 1000

// Queue Node
typedef struct {
    int data;
    struct node* next;
} Node;

// Queue
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Initialize Queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Is Queue Empty?
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Is Queue Full?
int isFull(Queue* q) {
    return q->size == MAX_QUEUE_SIZE;
}

// Enqueue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory Allocation Failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// Dequeue
int dequeue(Queue* q) {
    int data = -1;
    if (isEmpty(q)) {
        printf("Error: Queue is Empty\n");
    }
    else {
        Node* temp = q->front;
        data = temp->data;
        q->front = q->front->next;
        free(temp);
        q->size--;
    }
    return data;
}

// Display Queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
    }
    else {
        Node* temp = q->front;
        printf("Queue: ");
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
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    return 0;
}