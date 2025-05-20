//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROC 10

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    struct Process* next;
};

void roundRobin(struct Process* head)
{
    struct Process* currentProcess = head;
    while (currentProcess)
    {
        printf("Process %d is running...\n", currentProcess->id);
        sleep(currentProcess->burstTime);
        currentProcess->remainingTime--;
        if (currentProcess->remainingTime == 0)
        {
            printf("Process %d is completed.\n", currentProcess->id);
            struct Process* nextProcess = currentProcess->next;
            free(currentProcess);
            currentProcess = nextProcess;
        }
    }
}

int main()
{
    struct Process* head = NULL;

    // Create some processes
    for (int i = 0; i < MAX_PROC; i++)
    {
        struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
        newProcess->id = i;
        newProcess->arrivalTime = rand() % 10;
        newProcess->burstTime = rand() % 5;
        newProcess->remainingTime = newProcess->burstTime;
        newProcess->next = head;
        head = newProcess;
    }

    roundRobin(head);

    return 0;
}