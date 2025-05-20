//FormAI DATASET v1.0 Category: Queue ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5 //I am not a fan of long queues, 5 is enough!

typedef struct queue //I am creating a queue structure
{
    int rear;
    int front;
    int arr[MAX_QUEUE_SIZE];
} Queue;

Queue* newQueue() //Creating a new queue, don't mess with it!
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->rear = -1;
    q->front= -1;
    return q;   
}

int isQueueFull(Queue *q)  //Are we full? I am always hungry!
{
    if(q->rear == MAX_QUEUE_SIZE-1){
        printf("ERROR: The queue is full, can't add more items \n");
        return 1;
     } else {
         return 0;
     }
}

int isQueueEmpty(Queue *q) //Feeling empty? Queue is empty!
{
    if(q->front == -1 || q->front > q->rear)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q,int num) //Adding an item, yum yum!
{
    if(isQueueFull(q))
        return;
    else {
        q->rear++;
        q->arr[q->rear] = num;
        if(q->front==-1) //Top priority, no more waiting!
            q->front=0;
    }
}

int dequeue(Queue *q) //Removing an item, no more food...
{
    int num;
    if(isQueueEmpty(q)) {
        printf("ERROR: The queue is empty, can't remove any item \n");
        return -1;
    }
    else {
        num=q->arr[q->front];
        q->front++;
        if(q->front>q->rear){ //Great, now the line is shorter!
            q->front=q->rear=-1;
        }
        return num;
    }
}

void display(Queue *q) //Printing the queue, gotta look good!
{
    int i;
    if(isQueueEmpty(q)) {
        printf("Queue is empty, nothing to display! \n");
        return;  
    }
    printf("The elements of the queue are: \n");
    for(i=q->front;i<=q->rear;i++) {
        printf("%d \t",q->arr[i]);
    }
    printf("\n");
}

int main()
{
    Queue* q = newQueue(); //New queue please!
    int choice, num;
    while(1) {
        printf("-------------------------------\n");
        printf("1. Add an item to the queue \n");
        printf("2. Remove an item from the queue \n");
        printf("3. Display the queue \n");
        printf("4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) //What are we doing today?
        {
            case 1:
                printf("Enter the number to be added: ");
                scanf("%d",&num);
                enqueue(q,num);
                break;
            case 2:
                num = dequeue(q);
                if(num!=-9999)
                    printf("The removed number is %d \n",num);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Bye bye, see you later... \n");
                exit(0);
                break;
            default:
                printf("INVALID CHOICE! Please enter a valid choice. \n");
                break;
        }
    }
    return 0;
}