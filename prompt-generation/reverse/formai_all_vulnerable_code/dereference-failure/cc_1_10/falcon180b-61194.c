//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
} queue;

void init_queue(queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(queue* q, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(queue* q) {
    if (q->front == NULL)
        return -1;

    int data = q->front->data;
    node* temp = q->front;

    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    }
    else {
        q->front = q->front->next;
    }

    free(temp);

    return data;
}

void display_queue(queue* q) {
    node* temp = q->front;

    if (temp == NULL)
        printf("Queue is empty\n");
    else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    queue q;
    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display_queue(&q);

    int dequeued_data = dequeue(&q);
    printf("Dequeued element: %d\n", dequeued_data);

    display_queue(&q);

    return 0;
}