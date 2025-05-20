//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME 10

struct Process
{
    int process_id;
    int arrival_time;
    int service_time;
    int completion_time;
    int waiting_time;
    struct Process* next;
};

void create_process(int id, int arrival_time, int service_time)
{
    struct Process* new_process = (struct Process*)malloc(sizeof(struct Process));
    new_process->process_id = id;
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->completion_time = 0;
    new_process->waiting_time = 0;
    new_process->next = NULL;

    return;
}

void round_robin(struct Process* processes)
{
    int current_time = 0;
    struct Process* current_process = processes;

    while (processes)
    {
        if (current_time >= processes->arrival_time)
        {
            current_process->completion_time = current_time + processes->service_time;
            current_process->waiting_time = current_process->completion_time - processes->arrival_time;

            printf("Process %d completed at time %d, waiting time %d\n", processes->process_id, current_process->completion_time, current_process->waiting_time);

            processes = processes->next;
            current_process = processes;
        }
        else
        {
            current_time++;
        }
    }
}

int main()
{
    struct Process* processes = NULL;

    create_process(1, 0, 5);
    create_process(2, 2, 3);
    create_process(3, 4, 4);
    create_process(4, 6, 2);
    create_process(5, 8, 3);

    round_robin(processes);

    return 0;
}