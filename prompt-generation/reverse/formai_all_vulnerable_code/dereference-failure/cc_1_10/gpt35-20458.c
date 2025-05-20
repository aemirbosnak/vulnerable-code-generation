//FormAI DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
//Welcome to my unique C Queue Implementation program!
//This program will allow you to create and manipulate a Queue data structure using C language.

//First, let's start by including the necessary libraries: 
#include<stdio.h>
#include<stdlib.h>

//Next, we will define a structure that will represent our Queue. 
struct Queue 
{
    int front, rear, maxSize;
    int *arr;
};

//Now, let's create a function that will initialize our Queue with a certain maximum size.
//This function will return a pointer to the Queue.
struct Queue* createQueue(int maxSize)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue -> front = queue -> rear = -1;
    queue -> maxSize = maxSize;
    queue -> arr = (int*) malloc(queue -> maxSize * sizeof(int));
    
    return queue;
}

//This function will check if our Queue is empty or not.
int isQueueEmpty(struct Queue* queue)
{
    return queue -> front == -1;
}

//This function will check if our Queue is full or not.
int isQueueFull(struct Queue* queue)
{
    return queue -> rear == queue -> maxSize - 1;
}

//This function will add an element to our Queue.
void enqueue(struct Queue* queue, int element)
{
    if(isQueueFull(queue))
    {
        printf("Sorry, the Queue is full!\n");
        return;
    }
    
    if(queue -> front == -1)
    {
        queue -> front = 0;
    }
    
    queue -> rear++;
    queue -> arr[queue -> rear] = element;
    printf("%d is added to the Queue!\n", element);
}

//This function will remove an element from our Queue.
int dequeue(struct Queue* queue)
{
    int element;
    
    if(isQueueEmpty(queue))
    {
        printf("Sorry, the Queue is empty!\n");
        return -1;
    }
    
    element = queue -> arr[queue -> front];
    queue -> front++;
    
    if(queue -> front > queue -> rear)
    {
        queue -> front = queue -> rear = -1;
    }
    
    printf("%d is removed from the Queue!\n", element);
    return element;
}

//This function will return the front element of our Queue.
int queueFront(struct Queue* queue)
{
    if(isQueueEmpty(queue))
    {
        printf("Sorry, the Queue is empty!\n");
        return -1;
    }
    
    return queue -> arr[queue -> front];
}

//This function will display the elements of our Queue.
void displayQueue(struct Queue* queue)
{
    if(isQueueEmpty(queue))
    {
        printf("Sorry, the Queue is empty!\n");
        return;
    }
    
    printf("The Queue: ");
    
    for(int i = queue -> front; i <= queue -> rear; i++)
    {
        printf("%d ", queue -> arr[i]);
    }
    
    printf("\n");
}

//Now let's test our Queue!
int main()
{
    struct Queue* queue = createQueue(5);
    
    enqueue(queue, 5);
    enqueue(queue, 3);
    enqueue(queue, 9);
    
    dequeue(queue);
    
    displayQueue(queue);
    
    printf("The front element of the Queue is %d\n", queueFront(queue));
    
    return 0;
}