//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

typedef struct queue {
    node_t* front;
    node_t* rear;
} queue_t;

void init_queue(queue_t* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(queue_t* q, int data) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(queue_t* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = q->front->data;
    node_t* temp_node = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp_node);

    return data;
}

int peek(queue_t* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    return q->front->data;
}

void print_queue(queue_t* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node_t* temp_node = q->front;

    printf("Queue elements are:\n");
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

int main() {
    queue_t q;
    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    print_queue(&q);

    printf("Dequeued element is: %d\n", dequeue(&q));

    print_queue(&q);

    printf("Peek element is: %d\n", peek(&q));

    return 0;
}