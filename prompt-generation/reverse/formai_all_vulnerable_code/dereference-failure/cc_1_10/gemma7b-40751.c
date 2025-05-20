//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void insert(Node* head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }
}

void printQueue(Node* head)
{
    Node* current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void schedule(Node* readyQueue, Node* waitingQueue)
{
    if (readyQueue == NULL)
    {
        return;
    }

    int quantum = 0;
    Node* current = readyQueue;

    while (quantum < 10)
    {
        printf("CPU is busy with process %d\n", current->data);
        quantum++;
        current = current->next;
    }

    printf("Process %d completed\n", readyQueue->data);
    insert(waitingQueue, readyQueue);
    readyQueue = NULL;
}

int main()
{
    Node* readyQueue = NULL;
    Node* waitingQueue = NULL;

    insert(readyQueue, 1);
    insert(readyQueue, 3);
    insert(readyQueue, 5);
    insert(waitingQueue, 2);
    insert(waitingQueue, 4);

    schedule(readyQueue, waitingQueue);

    printQueue(readyQueue);
    printQueue(waitingQueue);

    return 0;
}