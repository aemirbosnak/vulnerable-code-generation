//FormAI DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

struct QNode {
    int data;
    struct QNode* next;
};

struct Queue {
    struct QNode *front, *rear;
};

struct QNode* newNode(int data)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, int data)
{
    struct QNode* temp = newNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void deQueue(struct Queue* q)
{
    if (q->front == NULL)
        return;
    struct QNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}

void printQueue(struct Queue* q)
{
    struct QNode* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Queue* q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    printQueue(q);
    deQueue(q);
    printQueue(q);
    return 0;
}