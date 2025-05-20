//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct queue {
    node* front;
    node* rear;
} queue;

void enqueue(queue* q, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->front->data;
    node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    return data;
}

int main() {
    queue q;
    q.front = NULL;
    q.rear = NULL;
    
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    
    printf("Queue: ");
    while (q.front!= NULL) {
        printf("%d ", q.front->data);
        q.front = q.front->next;
    }
    printf("\n");
    
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Queue: ");
    while (q.front!= NULL) {
        printf("%d ", q.front->data);
        q.front = q.front->next;
    }
    printf("\n");
    
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Queue: ");
    while (q.front!= NULL) {
        printf("%d ", q.front->data);
        q.front = q.front->next;
    }
    printf("\n");
    
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Queue is empty\n");
    
    return 0;
}