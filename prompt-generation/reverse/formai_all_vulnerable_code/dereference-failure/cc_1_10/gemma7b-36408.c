//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10

typedef struct Process
{
    int pid;
    char name[20];
    int burst_time;
    int waiting_time;
    int remaining_time;
    struct Process* next;
} Process;

void roundrobin(Process* head)
{
    Process* current = head;
    while (current)
    {
        current->remaining_time--;
        if (current->remaining_time == 0)
        {
            printf("Process %d (%s) completed.\n", current->pid, current->name);
            current->waiting_time = 0;
            current = current->next;
        }
    }
}

int main()
{
    Process* head = NULL;
    for (int i = 0; i < MAX_PROCESS; i++)
    {
        Process* newProcess = (Process*)malloc(sizeof(Process));
        newProcess->pid = i + 1;
        sprintf(newProcess->name, "Process %d", newProcess->pid);
        newProcess->burst_time = rand() % 5 + 1;
        newProcess->waiting_time = 0;
        newProcess->remaining_time = newProcess->burst_time;
        newProcess->next = head;
        head = newProcess;
    }

    roundrobin(head);

    return 0;
}