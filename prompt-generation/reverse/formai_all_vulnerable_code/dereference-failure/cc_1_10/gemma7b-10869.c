//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSORS 4
#define MAX_TIME_Quantum 10

typedef struct Process
{
    int process_id;
    int arrival_time;
    int execution_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* head = NULL;

void addProcess(int process_id, int arrival_time, int execution_time)
{
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->process_id = process_id;
    newProcess->arrival_time = arrival_time;
    newProcess->execution_time = execution_time;
    newProcess->remaining_time = execution_time;
    newProcess->next = NULL;

    if (head == NULL)
    {
        head = newProcess;
    }
    else
    {
        Process* tail = head;
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = newProcess;
    }
}

void roundRobin(int current_time)
{
    Process* process = head;
    int i = 0;

    while (process)
    {
        if (process->arrival_time <= current_time && process->remaining_time > 0)
        {
            process->remaining_time--;
            printf("Process %d is running\n", process->process_id);
            i++;
        }
    }

    if (i == 0)
    {
        printf("No processes are running\n");
    }
}

int main()
{
    addProcess(1, 0, 5);
    addProcess(2, 2, 4);
    addProcess(3, 4, 3);
    addProcess(4, 6, 2);

    for (int time = 0; time < MAX_TIME_Quantum; time++)
    {
        roundRobin(time);
    }

    return 0;
}