//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include<stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Queue
{
    struct Node* head;
    struct Node* tail;
};

//Function to insert an element at the end of the queue
void enqueue(struct Queue* q, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(q->tail == NULL)
    {
        q->head = newNode;
        q->tail = newNode;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

//Function to remove an element from the front of the queue
int dequeue(struct Queue* q)
{
    if(q->head == q->tail)
    {
        return -1;
    }
    else
    {
        int data = q->head->data;
        q->head = q->head->next;
        free(q->head);
        return data;
    }
}

int main()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Elements in queue: ");
    while(q->head!= NULL)
    {
        printf("%d ", q->head->data);
        q->head = q->head->next;
    }
    printf("\n");

    int data = dequeue(q);
    if(data!= -1)
    {
        printf("Element removed from queue: %d\n", data);
    }

    return 0;
}