//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if (q->front == NULL) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(Queue* q) {
    Node* temp = q->front;
    int data = temp->data;

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

void display(Queue* q) {
    Node* temp = q->front;

    if (temp == NULL) {
        printf("Queue is empty\n");
    }
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
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    display(q);

    int data = dequeue(q);
    printf("Dequeued element is: %d\n", data);

    display(q);

    data = dequeue(q);
    printf("Dequeued element is: %d\n", data);

    display(q);

    data = dequeue(q);
    printf("Dequeued element is: %d\n", data);

    display(q);

    data = dequeue(q);
    printf("Dequeued element is: %d\n", data);

    display(q);

    return 0;
}