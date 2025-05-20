//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSORS 8

typedef struct Process
{
    int pid;
    int cpu_time;
    struct Process* next;
} Process;

Process* head = NULL;

void addProcess(int pid, int cpu_time)
{
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->pid = pid;
    newProcess->cpu_time = cpu_time;
    newProcess->next = NULL;

    if (head == NULL)
    {
        head = newProcess;
    }
    else
    {
        Process* lastProcess = head;
        while (lastProcess->next != NULL)
        {
            lastProcess = lastProcess->next;
        }
        lastProcess->next = newProcess;
    }
}

void schedule()
{
    Process* currentProcess = head;
    while (currentProcess)
    {
        printf("Process %d is running on CPU %d.\n", currentProcess->pid, currentProcess->cpu_time);
        currentProcess->cpu_time--;
        if (currentProcess->cpu_time == 0)
        {
            currentProcess = currentProcess->next;
        }
    }
}

int main()
{
    addProcess(1, 5);
    addProcess(2, 3);
    addProcess(3, 2);
    addProcess(4, 4);

    schedule();

    return 0;
}