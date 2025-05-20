//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

struct queue_node {
    int data;
    struct queue_node *next;
};

struct queue {
    struct queue_node *front;
    struct queue_node *rear;
};

void enqueue(struct queue *q, int data) {
    struct queue_node *new_node = (struct queue_node*) malloc(sizeof(struct queue_node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(struct queue *q) {
    if (q->front == NULL) {
        return -1;
    }
    int data = q->front->data;
    struct queue_node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    return data;
}

int main() {
    struct queue q;
    q.front = NULL;
    q.rear = NULL;
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Dequeue 1: %d\n", dequeue(&q));
    printf("Dequeue 2: %d\n", dequeue(&q));
    printf("Dequeue 3: %d\n", dequeue(&q));
    printf("Dequeue 4: %d\n", dequeue(&q));
    printf("Dequeue 5: %d\n", dequeue(&q));
    return 0;
}