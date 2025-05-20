//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

typedef struct Process
{
    char name[20];
    int burstTime;
    int remainingTime;
    struct Process* next;
} Process;

void createProcess(Process** head)
{
    *head = (Process*)malloc(sizeof(Process));
    (*head)->name[0] = '\0';
    (*head)->burstTime = 0;
    (*head)->remainingTime = 0;
    (*head)->next = NULL;
}

void addProcess(Process** head, char* name, int burstTime)
{
    Process* newNode = (Process*)malloc(sizeof(Process));
    newNode->name[0] = '\0';
    newNode->burstTime = burstTime;
    newNode->remainingTime = burstTime;
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

void roundRobin(Process** head)
{
    int i = 0;
    Process* currentProcess = *head;
    time_t startTime = time(NULL);

    while (currentProcess)
    {
        time_t currentTime = time(NULL);
        int timeSpent = currentTime - startTime;

        if (timeSpent >= currentProcess->remainingTime)
        {
            currentProcess->remainingTime = 0;
            printf("%s completed.\n", currentProcess->name);
        }
        else
        {
            currentProcess->remainingTime -= timeSpent;
            printf("%s is running...\n", currentProcess->name);
        }

        i++;
        currentProcess = currentProcess->next;

        if (i == MAX)
        {
            i = 0;
            startTime = time(NULL);
        }
    }
}

int main()
{
    Process* head = NULL;

    createProcess(&head);
    addProcess(&head, "A", 5);
    addProcess(&head, "B", 3);
    addProcess(&head, "C", 7);
    addProcess(&head, "D", 4);
    addProcess(&head, "E", 2);

    roundRobin(&head);

    return 0;
}