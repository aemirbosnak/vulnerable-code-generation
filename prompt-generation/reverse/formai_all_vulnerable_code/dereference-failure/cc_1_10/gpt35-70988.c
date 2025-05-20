//FormAI DATASET v1.0 Category: Queue Implementation ; Style: creative
#include<stdio.h>
#include<stdlib.h>

struct Queue
{
        int data;
        struct Queue* next;
};

struct Queue* front=NULL;
struct Queue* rear=NULL;

void Enqueue(int x)
{
        struct Queue* temp=(struct Queue*)malloc(sizeof(struct Queue));
        temp->data=x;
        temp->next=NULL;
        if(front==NULL && rear==NULL)
        {
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
}

void Dequeue()
{
        struct Queue* temp=front;
        if(front==NULL)
        {
            printf("Queue is empty\n");
            return;
        }
        if(front==rear)
        {
            front=rear=NULL;
        }
        else
        {
            front=front->next;
        }
        free(temp);
}

void printQueue()
{
        struct Queue* temp=front;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
}

int main()
{
        Enqueue(2);
        Enqueue(4);
        Enqueue(6);
        Dequeue();
        Enqueue(8);
        printQueue();
        return 0;
}