//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct process {
    int process_id;
    char name[20];
    int burst_time;
    int remaining_time;
    struct process* next;
} process;

void insert_process(process** head, process* new_process)
{
    if (*head == NULL)
    {
        *head = new_process;
    }
    else
    {
        ((*head)->next = new_process);
        *head = new_process;
    }
}

void round_robin(process** head)
{
    process* current_process = *head;
    int time_quantum = 5;

    while (current_process)
    {
        current_process->remaining_time -= time_quantum;
        if (current_process->remaining_time == 0)
        {
            printf("Process %d completed.\n", current_process->process_id);
            insert_process(head, current_process);
            current_process = NULL;
        }
        else
        {
            current_process = current_process->next;
        }
    }
}

int main()
{
    process* processes[MAX_PROCESS] = {NULL};

    // Create 5 processes
    for (int i = 0; i < MAX_PROCESS; i++)
    {
        processes[i] = (process*)malloc(sizeof(process));
        processes[i]->process_id = i + 1;
        processes[i]->name[0] = 'A' + i;
        processes[i]->burst_time = rand() % 10;
        processes[i]->remaining_time = processes[i]->burst_time;
        processes[i]->next = NULL;
    }

    // Insert processes into the queue
    process* head = NULL;
    for (int i = 0; i < MAX_PROCESS; i++)
    {
        insert_process(&head, processes[i]);
    }

    // Round robin scheduling
    round_robin(&head);

    return 0;
}