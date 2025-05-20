//FormAI DATASET v1.0 Category: Queue ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct {
    struct node *front;
    struct node *rear;
}Queue;

Queue *createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(Queue *q) {
    return (q->front == NULL);
}

void enqueue(Queue *q, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(q->front == NULL && q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}

void dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty!");
        return;
    }
    struct node *current_node = q->front;
    q->front = q->front->next;
    if(q->front == NULL) {
        q->rear = NULL;
    }
    printf("%d is dequeued.\n", current_node->data);
    free(current_node);
}

void display(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    struct node *current_node = q->front;
    while(current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue();
    printf("Adding elements to the queue.\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    display(q);
    printf("Dequeuing elements from the queue.\n");
    dequeue(q);
    dequeue(q);
    display(q);
    printf("Adding more elements to the queue.\n");
    enqueue(q, 50);
    enqueue(q, 60);
    display(q);
    return 0;
}