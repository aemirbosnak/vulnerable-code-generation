//FormAI DATASET v1.0 Category: Queue ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct queue
{
    int front, rear;
    int size;
    int* arr;
};

struct queue* createQueue(int size)
{
    struct queue* Q = (struct queue*)malloc(sizeof(struct queue));
    Q->arr = (int*)malloc(sizeof(int)*size);
    Q->front = -1;
    Q->rear = -1;
    Q->size = size;
    return Q;
}

int isFull(struct queue* Q)
{
    return (Q->rear == Q->size-1);
}

int isEmpty(struct queue* Q)
{
    return (Q->front == -1 && Q->rear == -1);
}

void enQueue(struct queue* Q, int data)
{
    if(isFull(Q))
    {
        printf("I am sorry! Your queue case is full of candies, try some other day...\n");
        return;
    }
    else if(isEmpty(Q))
    {
        Q->front = Q->rear = 0;
        Q->arr[Q->rear] = data;
    }
    else
    {
        Q->rear++;
        Q->arr[Q->rear] = data;
    }
    printf("Oops, Your queue case is almost full. Please hold on while we add your candies to the queue...\n");
}

void deQueue(struct queue* Q)
{
    if(isEmpty(Q))
    {
        printf("I am sorry! Your queue case is empty, please add some candies first...\n");
        return;
    }
    else if(Q->front == Q->rear)
    {
        Q->front = Q->rear = -1;
    }
    else
    {
        Q->front++;
    }
    printf("We hope you enjoyed your candies. Hope to see you soon...\n");
}

void display(struct queue* Q)
{
    if(isEmpty(Q))
    {
        printf("I am sorry! Your queue case is empty, please add some candies first...\n");
        return;
    }
    printf("Your queue case looks like this:\n");
    for(int i = Q->front; i <= Q->rear; i++)
    {
        printf("%d ", Q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct queue* Q;
    int size;
    printf("Welcome to the Candy Store! How many candies would you like to buy?\n");
    scanf("%d", &size);
    Q = createQueue(size);
    printf("Awesome! You chose %d candies. Let's add them to your queue case.\n", size);

    srand(time(0));
    for(int i = 0; i < size; i++)
    {
        enQueue(Q, (rand()%10)+1);
    }
    display(Q);
    printf("Oh no! It looks like the queue case has a hole in it. We lost one candy. Let's remove it from the queue case.\n");
    deQueue(Q);
    display(Q);
    printf("Thanks for visiting the Candy Store. Have a sweet day!\n");

    free(Q->arr);
    free(Q);
    return 0;
}