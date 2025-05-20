//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10

typedef struct queue_node {
    int data;
    struct queue_node *next;
} QueueNode;

typedef struct queue {
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

void init_queue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int is_empty(Queue *q) {
    return q->front == NULL;
}

int is_full(Queue *q) {
    return q->size == MAX_SIZE;
}

void enqueue(Queue *q, int data) {
    if (is_full(q)) {
        printf("Queue is full!\n");
        return;
    }
    QueueNode *new_node = (QueueNode*)malloc(sizeof(QueueNode));
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = q->front->data;
    QueueNode *temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return data;
}

void print_queue(Queue *q) {
    QueueNode *node = q->front;
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    init_queue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    print_queue(&q);
    printf("%d\n", dequeue(&q));
    print_queue(&q);
    printf("%d\n", dequeue(&q));
    print_queue(&q);
    printf("%d\n", dequeue(&q));
    printf("Queue is empty: %s\n", is_empty(&q)? "Yes" : "No");
    return 0;
}