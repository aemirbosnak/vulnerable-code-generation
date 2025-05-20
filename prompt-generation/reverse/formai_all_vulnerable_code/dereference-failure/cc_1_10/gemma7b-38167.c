//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct Process
{
    int process_id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int burstTime)
{
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = id;
    process->burst_time = burstTime;
    process->waiting_time = 0;
    process->turnaround_time = 0;
    process->next = NULL;

    return process;
}

void addProcess(Process* head, int id, int burstTime)
{
    Process* process = createProcess(id, burstTime);
    if (head == NULL)
    {
        head = process;
    }
    else
    {
        process->next = head;
        head = process;
    }
}

void roundRobin(Process* head, int quantum)
{
    time_t start_time = time(NULL);
    Process* currentProcess = head;

    while (currentProcess)
    {
        int remainingTime = currentProcess->burst_time - currentProcess->waiting_time;
        if (remainingTime > quantum)
        {
            currentProcess->waiting_time += quantum;
            currentProcess = currentProcess->next;
        }
        else
        {
            currentProcess->waiting_time += remainingTime;
            currentProcess->turnaround_time = time(NULL) - start_time;
            currentProcess = currentProcess->next;
        }
    }
}

int main()
{
    Process* head = NULL;
    addProcess(head, 1, 5);
    addProcess(head, 2, 8);
    addProcess(head, 3, 3);
    addProcess(head, 4, 4);
    addProcess(head, 5, 6);

    roundRobin(head, 2);

    for (Process* process = head; process; process = process->next)
    {
        printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", process->process_id, process->waiting_time, process->turnaround_time);
    }

    return 0;
}