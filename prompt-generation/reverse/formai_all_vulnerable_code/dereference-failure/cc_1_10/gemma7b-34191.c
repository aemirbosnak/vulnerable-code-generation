//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_QUEUE_SIZE 20

typedef struct Process
{
    int pid;
    char name[20];
    int burst_time;
    int waiting_time;
    int turnaround_time;
    struct Process* next;
} Process;

Process* createProcess(int pid, char* name, int burst_time)
{
    Process* process = (Process*)malloc(sizeof(Process));
    process->pid = pid;
    strcpy(process->name, name);
    process->burst_time = burst_time;
    process->waiting_time = 0;
    process->turnaround_time = 0;
    process->next = NULL;

    return process;
}

void addProcess(Process* head, Process* process)
{
    if (head == NULL)
    {
        head = process;
    }
    else
    {
        head->next = process;
        head = process;
    }
}

void roundRobin(Process* head)
{
    time_t start_time = time(NULL);
    int quantum = 5;
    Process* current_process = head;

    while (current_process)
    {
        int remaining_time = current_process->burst_time - current_process->waiting_time;

        if (remaining_time > quantum)
        {
            current_process->waiting_time += quantum;
            current_process = current_process->next;
        }
        else
        {
            current_process->waiting_time += remaining_time;
            current_process->turnaround_time = time(NULL) - start_time;
            printf("Process %d completed: %s, waiting time %d, turnaround time %d\n", current_process->pid, current_process->name, current_process->waiting_time, current_process->turnaround_time);
            current_process = current_process->next;
        }
    }
}

int main()
{
    Process* head = NULL;

    addProcess(head, createProcess(1, "A", 8));
    addProcess(head, createProcess(2, "B", 12));
    addProcess(head, createProcess(3, "C", 6));
    addProcess(head, createProcess(4, "D", 10));

    roundRobin(head);

    return 0;
}