//FormAI DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initQueue(struct Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(struct Queue* q)
{
    if (q->front == NULL && q->rear == NULL) {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue* q, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    struct Node* temp = q->front;
    int data = q->front->data;

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

void printQueue(struct Queue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = q->front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    initQueue(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printf("Queue: ");
    printQueue(q);

    int x = dequeue(q);
    printf("Dequeued element: %d\n", x);

    printf("Queue: ");
    printQueue(q);

    return 0;
}