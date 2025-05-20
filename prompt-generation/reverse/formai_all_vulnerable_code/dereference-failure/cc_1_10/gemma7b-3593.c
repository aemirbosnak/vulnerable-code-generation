//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10

typedef struct Process
{
    int process_id;
    char name[20];
    int arrival_time;
    int burst_time;
    int remaining_time;
    int status;
} Process;

void roundrobin(Process **processes, int num_processes)
{
    int current_time = 0;
    int next_process = 0;

    while (!processes[next_process]->status)
    {
        processes[next_process]->remaining_time--;

        if (processes[next_process]->remaining_time == 0)
        {
            processes[next_process]->status = 1;
            printf("Process %d completed.\n", processes[next_process]->process_id);
            next_process = (next_process + 1) % num_processes;
        }

        current_time++;
    }
}

int main()
{
    Process processes[MAX_PROCESS];

    for (int i = 0; i < MAX_PROCESS; i++)
    {
        processes[i].process_id = i + 1;
        processes[i].arrival_time = rand() % 10;
        processes[i].burst_time = rand() % 5;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].status = 0;
    }

    roundrobin(processes, MAX_PROCESS);

    return 0;
}