//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

void create_queue(struct queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(struct queue* q) {
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

int is_full(struct queue* q) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;
    else {
        free(temp);
        return 0;
    }
}

void enqueue(struct queue* q, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Queue is full\n");
        return;
    }
    temp->data = data;
    temp->next = NULL;
    if (q->rear == NULL)
        q->front = temp;
    else
        q->rear->next = temp;
    q->rear = temp;
}

void dequeue(struct queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}

void display(struct queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue q;
    create_queue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);
    return 0;
}