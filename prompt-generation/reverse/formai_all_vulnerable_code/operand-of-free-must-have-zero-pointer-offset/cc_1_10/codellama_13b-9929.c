//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
/**
 * Queue Implementation Example Program in a Sherlock Holmes style
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int data;
    struct node *next;
} node;

typedef struct {
    node *front;
    node *rear;
    int size;
} queue;

queue *create_queue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(queue *q, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }

    q->size++;
}

int dequeue(queue *q) {
    if (q->size == 0) {
        return -1;
    }

    int data = q->front->data;
    node *tmp = q->front;
    q->front = q->front->next;
    free(tmp);
    q->size--;
    return data;
}

int main() {
    queue *q = create_queue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));

    return 0;
}