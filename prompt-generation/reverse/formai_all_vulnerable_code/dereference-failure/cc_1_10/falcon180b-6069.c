//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
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
    int size;
};

void init(struct queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

int is_empty(struct queue* q) {
    return q->front == NULL;
}

int is_full(struct queue* q) {
    return q->size == MAX_SIZE;
}

void enqueue(struct queue* q, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(q)) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

int dequeue(struct queue* q) {
    int data = -1;
    if (is_empty(q)) {
        printf("Queue is empty\n");
    } else {
        struct node* temp = q->front;
        data = temp->data;
        q->front = q->front->next;
        free(temp);
        q->size--;
    }
    return data;
}

void display(struct queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        struct node* temp = q->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    init(q);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    display(q);
    enqueue(q, 50);
    enqueue(q, 60);
    display(q);
    return 0;
}