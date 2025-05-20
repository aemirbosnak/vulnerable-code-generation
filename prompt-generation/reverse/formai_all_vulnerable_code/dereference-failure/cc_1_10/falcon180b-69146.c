//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
    int count;
} queue;

void enqueue(queue* q, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->count++;
}

int dequeue(queue* q) {
    if (q->front == NULL) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    node* temp = q->front;
    int data = temp->data;
    q->front = temp->next;
    free(temp);
    q->count--;
    return data;
}

int is_empty(queue* q) {
    return q->front == NULL;
}

int size(queue* q) {
    return q->count;
}

void print_queue(queue* q) {
    node* temp = q->front;
    printf("Queue: ");
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
    q.count = 0;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    print_queue(&q);

    int dequeued_data = dequeue(&q);
    printf("Dequeued data: %d\n", dequeued_data);
    print_queue(&q);

    int size_of_queue = size(&q);
    printf("Size of queue: %d\n", size_of_queue);

    if (is_empty(&q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    return 0;
}