//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Structure of a stack node
struct StackNode
{
    int data;
    struct StackNode *next;
};

// Structure of a queue node
struct QueueNode
{
    int data;
    struct QueueNode *next;
};

// Function to create a new stack node
struct StackNode *createStackNode(int data)
{
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue node
struct QueueNode *createQueueNode(int data)
{
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(struct StackNode **top, int data)
{
    struct StackNode *newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a node from the stack
int pop(struct StackNode **top)
{
    if (*top == NULL)
    {
        return -1;
    }
    int data = (*top)->data;
    *top = (*top)->next;
    return data;
}

// Function to enqueue a node into the queue
void enqueue(struct QueueNode **front, struct QueueNode **rear, int data)
{
    struct QueueNode *newNode = createQueueNode(data);
    if (*front == NULL)
    {
        *front = *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Function to dequeue a node from the queue
int dequeue(struct QueueNode **front, struct QueueNode **rear)
{
    if (*front == NULL)
    {
        return -1;
    }
    int data = (*front)->data;
    *front = (*front)->next;
    if (*front == NULL)
    {
        *rear = NULL;
    }
    return data;
}

// Function to solve the Tower of Hanoi problem using stacks
void towerOfHanoiUsingStacks(int n, struct StackNode **source, struct StackNode **destination, struct StackNode **auxiliary)
{
    if (n == 1)
    {
        int data = pop(source);
        push(destination, data);
        return;
    }
    towerOfHanoiUsingStacks(n - 1, source, auxiliary, destination);
    int data = pop(source);
    push(destination, data);
    towerOfHanoiUsingStacks(n - 1, auxiliary, destination, source);
}

// Function to solve the Tower of Hanoi problem using queues
void towerOfHanoiUsingQueues(int n, struct QueueNode **source, struct QueueNode **destination, struct QueueNode **auxiliary)
{
    int count = 1;
    while (count <= n)
    {
        enqueue(source, NULL, count);
        count++;
    }
    while (!(*source == NULL && *destination == NULL && *auxiliary == NULL))
    {
        if (*source != NULL)
        {
            int data = dequeue(source, NULL);
            enqueue(destination, NULL, data);
        }
        else if (*destination != NULL)
        {
            int data = dequeue(destination, NULL);
            enqueue(auxiliary, NULL, data);
        }
        else if (*auxiliary != NULL)
        {
            int data = dequeue(auxiliary, NULL);
            enqueue(source, NULL, data);
        }
    }
}

// Main function
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Create three stacks
    struct StackNode *source = NULL;
    struct StackNode *destination = NULL;
    struct StackNode *auxiliary = NULL;

    // Create three queues
    struct QueueNode *sourceQueue = NULL;
    struct QueueNode *destinationQueue = NULL;
    struct QueueNode *auxiliaryQueue = NULL;

    // Solve the Tower of Hanoi problem using stacks
    towerOfHanoiUsingStacks(n, &source, &destination, &auxiliary);

    // Solve the Tower of Hanoi problem using queues
    towerOfHanoiUsingQueues(n, &sourceQueue, &destinationQueue, &auxiliaryQueue);

    return 0;
}