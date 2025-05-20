//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

struct process
{
    int pid;
    int arrivalTime;
    int serviceTime;
    int remainingTime;
    struct process* next;
};

void insertProcess(struct process** head, int arrivalTime, int serviceTime)
{
    struct process* newNode = (struct process*)malloc(sizeof(struct process));
    newNode->pid = rand() % MAX;
    newNode->arrivalTime = arrivalTime;
    newNode->serviceTime = serviceTime;
    newNode->remainingTime = serviceTime;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

void schedule()
{
    struct process* head = NULL;
    struct process* currentProcess = NULL;
    struct process* nextProcess = NULL;

    int time = 0;

    insertProcess(&head, 0, 5);
    insertProcess(&head, 2, 3);
    insertProcess(&head, 4, 2);

    while (head)
    {
        if (currentProcess == NULL || time >= currentProcess->arrivalTime)
        {
            currentProcess = head;
            head = head->next;
            currentProcess->remainingTime--;

            if (currentProcess->remainingTime == 0)
            {
                printf("Process %d completed.\n", currentProcess->pid);
            }
        }

        time++;
    }

    printf("All processes completed.\n");
}

int main()
{
    schedule();

    return 0;
}