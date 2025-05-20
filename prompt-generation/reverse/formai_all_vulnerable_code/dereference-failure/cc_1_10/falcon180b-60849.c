//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

void init_queue(struct queue* q) {
    q->front = q->rear = NULL;
}

int is_empty(struct queue* q) {
    return q->front == NULL;
}

void enqueue(struct queue* q, int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = value;
    new_node->next = NULL;
    if (is_empty(q)) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(struct queue* q) {
    int value = -1;
    struct node* temp = q->front;
    if (!is_empty(q)) {
        value = q->front->data;
        q->front = q->front->next;
        free(temp);
    }
    return value;
}

void display(struct queue* q) {
    struct node* temp = q->front;
    printf("Queue elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue q;
    init_queue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);
    int value = dequeue(&q);
    printf("Dequeued element is: %d\n", value);
    display(&q);
    value = dequeue(&q);
    printf("Dequeued element is: %d\n", value);
    display(&q);
    value = dequeue(&q);
    printf("Dequeued element is: %d\n", value);
    display(&q);
    value = dequeue(&q);
    printf("Dequeued element is: %d\n", value);
    display(&q);
    return 0;
}