//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node_t;

typedef struct {
    node_t* front;
    node_t* rear;
    int size;
} queue_t;

void init_queue(queue_t* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool is_empty(queue_t* q) {
    return q->size == 0;
}

bool is_full(queue_t* q) {
    return q->size == MAX_QUEUE_SIZE;
}

void enqueue(queue_t* q, int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
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

int dequeue(queue_t* q) {
    int data = -1;

    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return data;
    }

    node_t* temp = q->front;
    data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;

    return data;
}

int main() {
    queue_t q;
    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));

    enqueue(&q, 50);
    enqueue(&q, 60);

    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));

    return 0;
}