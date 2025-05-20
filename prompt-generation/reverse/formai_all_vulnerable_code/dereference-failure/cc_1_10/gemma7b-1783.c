//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct process
{
    int pid;
    char name[20];
    int cpu_burst;
    int waiting_time;
    int turnaround_time;
    struct process* next;
} process;

process* createProcess(int pid, char* name, int cpu_burst)
{
    process* newProcess = (process*)malloc(sizeof(process));
    newProcess->pid = pid;
    strcpy(newProcess->name, name);
    newProcess->cpu_burst = cpu_burst;
    newProcess->waiting_time = 0;
    newProcess->turnaround_time = 0;
    newProcess->next = NULL;
    return newProcess;
}

void simulateRoundRobin(process* head)
{
    time_t start_time = time(NULL);
    process* currentProcess = head;
    while (currentProcess)
    {
        printf("Process %d is running...\n", currentProcess->pid);
        sleep(currentProcess->cpu_burst);
        currentProcess->waiting_time++;
        currentProcess = currentProcess->next;
    }

    time_t end_time = time(NULL);
    int total_time = (int)(end_time - start_time);
    printf("Total time taken: %d seconds\n", total_time);
}

int main()
{
    process* head = createProcess(1, "A", 5);
    head = createProcess(2, "B", 3);
    head = createProcess(3, "C", 4);
    head = createProcess(4, "D", 2);
    head = createProcess(5, "E", 6);

    simulateRoundRobin(head);

    return 0;
}