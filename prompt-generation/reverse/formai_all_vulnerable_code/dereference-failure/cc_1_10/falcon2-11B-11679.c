//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct queue_node {
    int data;
    struct queue_node* next;
} queue_node;

typedef struct queue_t {
    queue_node* front;
    queue_node* rear;
    int size;
} queue_t;

queue_t* createQueue() {
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

int isQueueEmpty(queue_t* q) {
    return (q->front == NULL && q->rear == NULL);
}

int isQueueFull(queue_t* q) {
    return (q->size == MAX_QUEUE_SIZE);
}

void enqueue(queue_t* q, int data) {
    if (isQueueFull(q)) {
        printf("Queue is full. Cannot enqueue more elements.\n");
        return;
    }

    queue_node* newNode = (queue_node*)malloc(sizeof(queue_node));
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(queue_t* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot dequeue an element.\n");
        return -1;
    }

    int data = q->front->data;
    queue_node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return data;
}

int main() {
    queue_t* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    printf("Front element: %d\n", dequeue(q));
    printf("Front element: %d\n", dequeue(q));
    printf("Front element: %d\n", dequeue(q));
    printf("Front element: %d\n", dequeue(q));
    printf("Front element: %d\n", dequeue(q));

    printf("Queue is empty: %s\n", isQueueEmpty(q)? "true" : "false");

    free(q);

    return 0;
}