//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct process {
    int process_id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct process *next;
} process;

void roundrobin(process *ready_queue, process **completed_processes)
{
    time_t current_time = time(NULL);
    process *current_process = NULL;

    while (!completed_processes)
    {
        if (ready_queue)
        {
            if (current_process == NULL)
            {
                current_process = ready_queue;
            }
            else
            {
                current_process = current_process->next;
            }

            if (current_process->arrival_time <= current_time)
            {
                current_process->completion_time = current_time + current_process->service_time;
                completed_processes = current_process;
                printf("Process %d completed.\n", current_process->process_id);
            }
        }

        sleep(1);
    }
}

int main()
{
    process *processes = NULL;
    process *completed_processes = NULL;

    // Create processes
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        processes = malloc(sizeof(process));
        processes->process_id = i + 1;
        processes->arrival_time = rand() % MAX_QUEUE_SIZE;
        processes->service_time = rand() % MAX_QUEUE_SIZE;
        processes->next = processes;
    }

    roundrobin(processes, &completed_processes);

    return 0;
}