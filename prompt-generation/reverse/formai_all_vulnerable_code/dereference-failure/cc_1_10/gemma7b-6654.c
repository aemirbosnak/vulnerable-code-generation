//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct Process
{
    int pid;
    char name[20];
    int burst_time;
    int waiting_time;
    int turn_around_time;
    struct Process* next;
} Process;

Process* createProcess(int pid, char* name, int burst_time)
{
    Process* process = (Process*)malloc(sizeof(Process));
    process->pid = pid;
    strcpy(process->name, name);
    process->burst_time = burst_time;
    process->waiting_time = 0;
    process->turn_around_time = 0;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, int pid, char* name, int burst_time)
{
    Process* process = createProcess(pid, name, burst_time);
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

void roundRobin(Process* head)
{
    time_t start_time = time(NULL);

    Process* current_process = head;
    while (current_process)
    {
        int remaining_time = current_process->burst_time - current_process->waiting_time;
        if (remaining_time > 0)
        {
            current_process->waiting_time++;
            printf("Process %d is waiting...\n", current_process->pid);
            sleep(1);
        }
        else
        {
            current_process->turn_around_time = time(NULL) - start_time;
            printf("Process %d completed!\n", current_process->pid);
            current_process = current_process->next;
        }
    }

    printf("All processes completed.\n");
}

int main()
{
    Process* head = NULL;
    addProcess(head, 1, "A", 5);
    addProcess(head, 2, "B", 4);
    addProcess(head, 3, "C", 3);
    addProcess(head, 4, "D", 2);
    addProcess(head, 5, "E", 1);

    roundRobin(head);

    return 0;
}