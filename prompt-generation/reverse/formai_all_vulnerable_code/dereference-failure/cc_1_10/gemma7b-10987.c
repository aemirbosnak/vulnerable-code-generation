//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_QUEUE_SIZE 5

typedef struct process
{
    int pid;
    char name[20];
    int burst_time;
    int waiting_time;
    int turn_around_time;
    int status;
} process;

void roundrobin(process **processes, int quantum)
{
    int i = 0;
    int current_process = 0;
    time_t start_time, end_time;

    start_time = time(NULL);

    while (!processes[current_process]->status)
    {
        end_time = time(NULL);
        processes[current_process]->waiting_time += end_time - start_time;

        printf("Process %d is running...", processes[current_process]->pid);
        sleep(processes[current_process]->burst_time);

        processes[current_process]->status = 1;
        current_process = (current_process + 1) % MAX_PROCESS;
        start_time = time(NULL);
    }

    end_time = time(NULL);
    for (i = 0; i < MAX_PROCESS; i++)
    {
        processes[i]->turn_around_time = processes[i]->waiting_time + processes[i]->burst_time;
    }

    printf("**Process Scheduling Results:**\n");
    for (i = 0; i < MAX_PROCESS; i++)
    {
        printf("Process ID: %d\n", processes[i]->pid);
        printf("Name: %s\n", processes[i]->name);
        printf("Burst Time: %d\n", processes[i]->burst_time);
        printf("Waiting Time: %d\n", processes[i]->waiting_time);
        printf("Turnaround Time: %d\n", processes[i]->turn_around_time);
        printf("\n");
    }
}

int main()
{
    process processes[MAX_PROCESS];
    int i;

    // Create processes
    for (i = 0; i < MAX_PROCESS; i++)
    {
        processes[i].pid = i + 1;
        strcpy(processes[i].name, "Process " + (i + 1));
        processes[i].burst_time = rand() % 5 + 1;
        processes[i].waiting_time = 0;
        processes[i].turn_around_time = 0;
        processes[i].status = 0;
    }

    // Round Robin scheduling
    roundrobin(processes, 2);

    return 0;
}