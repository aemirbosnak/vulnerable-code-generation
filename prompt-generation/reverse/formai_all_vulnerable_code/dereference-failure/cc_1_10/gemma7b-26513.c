//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct process
{
    int pid;
    int burst_time;
    int waiting_time;
    int turn_around_time;
    struct process* next;
} process;

process* createProcess(int pid, int burst_time)
{
    process* newProcess = (process*)malloc(sizeof(process));
    newProcess->pid = pid;
    newProcess->burst_time = burst_time;
    newProcess->waiting_time = 0;
    newProcess->turn_around_time = 0;
    newProcess->next = NULL;

    return newProcess;
}

void addProcess(process* head, process* newProcess)
{
    if (head == NULL)
    {
        head = newProcess;
    }
    else
    {
        head->next = newProcess;
        head = newProcess;
    }
}

void roundRobin(process* head)
{
    time_t start_time = time(NULL);

    while (head)
    {
        process* currentProcess = head;
        head = head->next;

        currentProcess->waiting_time++;

        if (currentProcess->burst_time == 0)
        {
            currentProcess->turn_around_time = time(NULL) - start_time;
            printf("Process %d completed.\n", currentProcess->pid);
        }
    }
}

int main()
{
    process* head = NULL;

    // Create a few processes
    process* process1 = createProcess(1, 5);
    process* process2 = createProcess(2, 3);
    process* process3 = createProcess(3, 8);
    process* process4 = createProcess(4, 2);
    process* process5 = createProcess(5, 4);

    // Add processes to the queue
    addProcess(head, process1);
    addProcess(head, process2);
    addProcess(head, process3);
    addProcess(head, process4);
    addProcess(head, process5);

    // Round robin scheduling
    roundRobin(head);

    return 0;
}