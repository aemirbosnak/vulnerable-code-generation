//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESS 10

struct process {
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct process* next;
};

void add_process(struct process** head, char* name, int burst_time)
{
    struct process* new_process = malloc(sizeof(struct process));

    new_process->pid = getpid();
    strcpy(new_process->name, name);
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

void preemptive_scheduler(struct process** head)
{
    struct process* current_process = *head;
    struct process* next_process = NULL;

    while (current_process)
    {
        if (current_process->remaining_time > 0)
        {
            current_process->remaining_time--;

            if (next_process == NULL)
            {
                next_process = current_process->next;
            }
        }
        else
        {
            printf("Process %s completed.\n", current_process->name);

            if (next_process)
            {
                current_process = next_process;
                next_process = NULL;
            }
            else
            {
                current_process = NULL;
            }
        }
    }
}

int main()
{
    struct process* head = NULL;

    add_process(&head, "Process A", 5);
    add_process(&head, "Process B", 3);
    add_process(&head, "Process C", 4);
    add_process(&head, "Process D", 2);

    preemptive_scheduler(&head);

    return 0;
}