//FormAI DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

//Structure for queue
struct Queue
{
    int front;
    int rear;
    int *arr;
    int capacity;
};

//Function to create a queue
struct Queue* createQueue(int cap)
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    q->capacity = cap;
    q->arr = (int*)malloc(sizeof(int) * cap);
    return q;
}

//Function to enqueue an element
void enqueue(struct Queue *q, int data)
{
    if(q->rear == q->capacity - 1)
    {
        printf("Queue Overflow!\n");
        return;
    }
    else if(q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->arr[q->rear] = data;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = data;
    }
    printf("%d enqueued to the queue.\n", data);
}

//Function to dequeue an element
void dequeue(struct Queue *q)
{
    if(q->front == -1 || q->front > q->rear)
    {
        printf("Queue Underflow!\n");
        return;
    }
    else
    {
        printf("%d dequeued from the queue.\n", q->arr[q->front]);
        q->front++;
    }
}

//Function to display the elements of queue
void display(struct Queue *q)
{
    if(q->front == -1 || q->front > q->rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    else
    {
        printf("Elements of queue are: ");
        for(int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

//Main function
int main()
{
    int capacity;
    printf("Enter the capacity of queue: ");
    scanf("%d", &capacity);
    struct Queue *q = createQueue(capacity);
    int choice, data;
    while(1)
    {
        printf("Enter 1 to enqueue an element.\n");
        printf("Enter 2 to dequeue an element.\n");
        printf("Enter 3 to display the elements of queue.\n");
        printf("Enter 4 to exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
    }
    return 0;
}