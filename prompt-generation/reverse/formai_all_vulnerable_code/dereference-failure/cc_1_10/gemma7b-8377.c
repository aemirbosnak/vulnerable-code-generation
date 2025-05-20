//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

typedef struct Process
{
    int process_id;
    char name[20];
    int burst_time;
    int waiting_time;
    int turn_around_time;
} Process;

void calculate_waiting_time(Process *processes)
{
    int i;
    processes->waiting_time = 0;
    for (i = 0; i < MAX_PROCESS; i++)
    {
        processes[i].waiting_time = processes[i - 1].burst_time;
    }
}

void calculate_turn_around_time(Process *processes)
{
    int i;
    calculate_waiting_time(processes);
    for (i = 0; i < MAX_PROCESS; i++)
    {
        processes[i].turn_around_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

int main()
{
    Process processes[MAX_PROCESS];
    int i;

    for (i = 0; i < MAX_PROCESS; i++)
    {
        processes[i].process_id = i + 1;
        processes[i].name[0] = 'A' + i;
        processes[i].burst_time = rand() % 5;
    }

    calculate_waiting_time(processes);
    calculate_turn_around_time(processes);

    for (i = 0; i < MAX_PROCESS; i++)
    {
        printf("Process ID: %d, Name: %s, Burst Time: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].process_id, processes[i].name, processes[i].burst_time, processes[i].waiting_time, processes[i].turn_around_time);
    }

    return 0;
}