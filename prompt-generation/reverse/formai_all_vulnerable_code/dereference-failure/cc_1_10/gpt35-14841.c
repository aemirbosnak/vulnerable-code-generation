//FormAI DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

struct queue
{
    int item[MAX_SIZE];
    int front;
    int rear;
};

struct queue* create_queue();
void enqueue(struct queue*, int);
int dequeue(struct queue*);
void display(struct queue*);

int main()
{
    int option, value;
    struct queue* q;
    q=create_queue();

    do
    {
        printf("\n\n***MENU***\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\nEnter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nEnter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;

            case 2:
                value=dequeue(q);
                if(value!=-1)
                {
                    printf("\nDequeued Value: %d", value);
                }
                break;

            case 3:
                display(q);
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("\nInvalid Option");
        }
    }while(option!=4);

    return 0;
}

struct queue* create_queue()
{
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    return q;
}

void enqueue(struct queue* q, int value)
{
    if(q->rear==MAX_SIZE-1)
    {
        printf("\nQueue Overflow");
        return;
    }
    else
    {
        if(q->front==-1)
        {
            q->front=0;
        }
        q->rear++;
        q->item[q->rear]=value;
        printf("\nValue Inserted");
    }
}

int dequeue(struct queue* q)
{
    int value;
    if(q->front==-1)
    {
        printf("\nQueue Underflow");
        return -1;
    }
    else
    {
        value=q->item[q->front];
        q->front++;
        if(q->front>q->rear)
        {
            q->front=q->rear=-1;
        }
        return value;
    }
}

void display(struct queue* q)
{
    int i;
    if(q->front==-1)
    {
        printf("\nQueue Empty");
    }
    else
    {
        printf("\nQueue Contains: ");
        for(i=q->front; i<=q->rear; i++)
        {
            printf("%d ", q->item[i]);
        }
    }
}