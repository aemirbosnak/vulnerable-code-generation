//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_Quantum 5

typedef struct Process
{
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

void RoundRobin(Process* head)
{
    Process* current = head;
    while (current)
    {
        printf("Process: %s, remaining time: %d\n", current->name, current->remaining_time);
        current->remaining_time--;
        if (current->remaining_time == 0)
        {
            printf("Process: %s completed.\n", current->name);
            current = current->next;
        }
    }
}

int main()
{
    Process* head = NULL;
    Process* tail = NULL;

    // Create some processes
    for (int i = 0; i < MAX_PROCESS; i++)
    {
        Process* newProcess = (Process*)malloc(sizeof(Process));
        newProcess->pid = i;
        sprintf(newProcess->name, "Process %d", i);
        newProcess->burst_time = rand() % MAX_Quantum;
        newProcess->remaining_time = newProcess->burst_time;
        newProcess->next = NULL;

        if (head == NULL)
        {
            head = newProcess;
            tail = newProcess;
        }
        else
        {
            tail->next = newProcess;
            tail = newProcess;
        }
    }

    // Round Robin scheduling
    RoundRobin(head);

    return 0;
}