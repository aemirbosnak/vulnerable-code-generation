//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
} queue;

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Failed to allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void enqueue(queue* q, int data) {
    if (q->rear == NULL) {
        q->front = q->rear = create_node(data);
    } else {
        q->rear->next = create_node(data);
        q->rear = q->rear->next;
    }
}

int dequeue(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = q->front->data;
    node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    return data;
}

void print_queue(queue* q) {
    node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue q;
    q.front = NULL;
    q.rear = NULL;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    print_queue(&q);

    printf("Dequeued: %d\n", dequeue(&q));

    print_queue(&q);

    return 0;
}