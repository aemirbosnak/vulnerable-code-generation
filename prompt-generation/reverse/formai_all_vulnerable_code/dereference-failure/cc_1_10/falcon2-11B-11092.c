//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_QUEUE_SIZE 100
typedef struct queue_node {
    int data;
    struct queue_node* next;
} queue_node;
typedef struct queue {
    queue_node* front;
    queue_node* rear;
    int size;
} queue;
void queue_enqueue(queue* q, int data) {
    queue_node* new_node = (queue_node*)malloc(sizeof(queue_node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        q->size = 1;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
        q->size++;
    }
}
int queue_dequeue(queue* q) {
    if (q->front == NULL) {
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
    queue q;
    q.front = NULL;
    q.rear = NULL;
    q.size = 0;
    queue_enqueue(&q, 1);
    queue_enqueue(&q, 2);
    queue_enqueue(&q, 3);
    printf("Front element: %d\n", queue_dequeue(&q));
    printf("Rear element: %d\n", queue_dequeue(&q));
    printf("Front element: %d\n", queue_dequeue(&q));
    printf("Rear element: %d\n", queue_dequeue(&q));
    return 0;
}