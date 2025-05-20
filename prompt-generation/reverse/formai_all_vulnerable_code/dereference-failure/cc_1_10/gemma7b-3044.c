//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4
#define MAX_SCHEDULE_SIZE 10

typedef struct Process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

void insert_process(Process** head, int arrival_time, int burst_time)
{
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = rand() % MAX_PROCESSORS;
    new_process->arrival_time = arrival_time;
    new_process->burst_time = burst_time;
    new_process->remaining_time = burst_time;
    new_process->next = NULL;

    if (*head == NULL)
    {
        *head = new_process;
    }
    else
    {
        (*head)->next = new_process;
    }
}

void schedule_process(Process** head)
{
    time_t current_time = time(NULL);
    Process* current_process = NULL;

    if (*head != NULL)
    {
        for (Process* process = *head; process; process = process->next)
        {
            if (process->arrival_time <= current_time && process->remaining_time > 0)
            {
                current_process = process;
            }
        }

        if (current_process)
        {
            current_process->remaining_time--;
            printf("Process %d is running...\n", current_process->process_id);
        }
    }
}

int main()
{
    Process* head = NULL;

    // Insert processes
    insert_process(&head, 0, 5);
    insert_process(&head, 2, 3);
    insert_process(&head, 3, 4);
    insert_process(&head, 4, 2);

    // Schedule processes
    schedule_process(&head);

    // Repeat until all processes are finished
    while (head)
    {
        schedule_process(&head);
    }

    return 0;
}