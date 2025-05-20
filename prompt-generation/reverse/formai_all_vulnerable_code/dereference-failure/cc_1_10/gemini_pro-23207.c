//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Queue
{
    struct Node *front, *rear;
};
void enqueue(struct Queue *q, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
int dequeue(struct Queue *q)
{
    if (q->front == NULL)
        return -1;
    int x = q->front->data;
    struct Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return x;
}
int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    printf("Queue: ");
    while (q->front != NULL)
    {
        printf("%d ", dequeue(q));
    }
    printf("\n");
    return 0;
}