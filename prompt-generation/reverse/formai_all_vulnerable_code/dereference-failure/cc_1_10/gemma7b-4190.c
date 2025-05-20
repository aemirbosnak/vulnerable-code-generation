//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process
{
    int arrival_time;
    int processing_time;
    int completion_time;
    struct Process* next;
} Process;

Process* createProcess(int arrival_time, int processing_time)
{
    Process* process = (Process*)malloc(sizeof(Process));
    process->arrival_time = arrival_time;
    process->processing_time = processing_time;
    process->completion_time = 0;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, int arrival_time, int processing_time)
{
    Process* process = createProcess(arrival_time, processing_time);
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

void schedule(Process* head)
{
    int time = 0;
    Process* currentProcess = NULL;

    while (!head->completion_time)
    {
        time++;

        if (currentProcess == NULL || currentProcess->arrival_time <= time)
        {
            currentProcess = head;
            currentProcess->completion_time = time + currentProcess->processing_time;
        }

        if (currentProcess)
        {
            printf("Process %d is completed at time %d.\n", currentProcess->arrival_time, currentProcess->completion_time);
        }

        time++;
    }

    printf("All processes are completed.\n");
}

int main()
{
    Process* head = NULL;

    addProcess(head, 0, 5);
    addProcess(head, 2, 4);
    addProcess(head, 4, 3);
    addProcess(head, 6, 2);
    addProcess(head, 8, 1);

    schedule(head);

    return 0;
}