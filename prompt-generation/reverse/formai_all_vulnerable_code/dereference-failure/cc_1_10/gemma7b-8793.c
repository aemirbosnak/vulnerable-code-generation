//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct Process
{
    char name[20];
    int priority;
    int cpu_burst_time;
    int remaining_burst_time;
    struct Process* next;
} Process;

Process* createProcess(char* name, int priority, int cpu_burst_time)
{
    Process* newProcess = (Process*)malloc(sizeof(Process));
    strcpy(newProcess->name, name);
    newProcess->priority = priority;
    newProcess->cpu_burst_time = cpu_burst_time;
    newProcess->remaining_burst_time = cpu_burst_time;
    newProcess->next = NULL;
    return newProcess;
}

void roundRobin(Process* readyQueue)
{
    Process* currentProcess = readyQueue;
    while (currentProcess)
    {
        printf("%s is running...\n", currentProcess->name);
        currentProcess->remaining_burst_time--;
        if (currentProcess->remaining_burst_time == 0)
        {
            printf("%s has finished.\n", currentProcess->name);
            free(currentProcess);
            currentProcess = readyQueue;
        }
        else
        {
            currentProcess = currentProcess->next;
        }
    }
}

int main()
{
    Process* head = NULL;
    Process* tail = NULL;

    // Create a few processes
    Process* process1 = createProcess("Process 1", 1, 5);
    Process* process2 = createProcess("Process 2", 2, 3);
    Process* process3 = createProcess("Process 3", 3, 2);
    Process* process4 = createProcess("Process 4", 4, 4);

    // Add processes to the ready queue
    process1->next = process2;
    process2->next = process3;
    process3->next = process4;

    // Round robin scheduling
    roundRobin(process1);

    return 0;
}