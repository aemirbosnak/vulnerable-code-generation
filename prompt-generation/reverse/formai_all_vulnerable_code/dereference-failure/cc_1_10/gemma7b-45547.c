//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct process
{
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    struct process* next;
};

void createProcess(struct process** head)
{
    *head = (struct process*)malloc(sizeof(struct process));
    (*head)->pid = 1;
    (*head)->arrivalTime = 0;
    (*head)->burstTime = 5;
    (*head)->completionTime = 0;
    (*head)->next = NULL;
}

void addProcess(struct process** head, int pid, int arrivalTime, int burstTime)
{
    struct process* newNode = (struct process*)malloc(sizeof(struct process));
    newNode->pid = pid;
    newNode->arrivalTime = arrivalTime;
    newNode->burstTime = burstTime;
    newNode->completionTime = 0;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
        *head = newNode;
    }
}

void roundRobin(struct process** head)
{
    struct process* currentProcess = *head;
    int i = 0;

    while (currentProcess)
    {
        printf("Process %d is being scheduled...\n", currentProcess->pid);
        currentProcess->completionTime = i + currentProcess->burstTime;
        i++;
        currentProcess = currentProcess->next;
    }

    printf("All processes have been scheduled.\n");
}

int main()
{
    struct process* head = NULL;

    createProcess(&head);
    addProcess(&head, 2, 1, 6);
    addProcess(&head, 3, 2, 3);
    addProcess(&head, 4, 3, 4);

    roundRobin(&head);

    return 0;
}