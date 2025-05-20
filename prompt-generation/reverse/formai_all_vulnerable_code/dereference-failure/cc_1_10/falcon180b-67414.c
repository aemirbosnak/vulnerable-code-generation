//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(Queue* q) {
    if(q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

int isFull(Queue* q) {
    Node* temp = q->rear->next;
    if(temp == q->front)
        return 1;
    else
        return 0;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    int data;
    Node* temp = q->front;

    if(isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    else if(q->front == q->rear) {
        data = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    }
    else {
        data = q->front->data;
        q->front = q->front->next;
        free(temp);
    }

    return data;
}

void display(Queue* q) {
    Node* temp = q->front;

    if(isEmpty(q)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue elements are: ");
        while(temp!= NULL) {
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

    int dequeuedItem = dequeue(q);
    printf("Dequeued element is: %d\n", dequeuedItem);

    dequeuedItem = dequeue(q);
    printf("Dequeued element is: %d\n", dequeuedItem);

    display(q);

    return 0;
}