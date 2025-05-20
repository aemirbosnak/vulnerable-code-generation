//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    struct Process* next;
};

void create_process(struct Process** head)
{
    *head = (struct Process*)malloc(sizeof(struct Process));
    (*head)->process_id = 0;
    (*head)->arrival_time = rand() % 10;
    (*head)->burst_time = rand() % 5;
    (*head)->remaining_time = (*head)->burst_time;
    (*head)->next = NULL;
}

void add_process(struct Process** head, int process_id)
{
    struct Process* new_process = (struct Process*)malloc(sizeof(struct Process));
    new_process->process_id = process_id;
    new_process->arrival_time = rand() % 10;
    new_process->burst_time = rand() % 5;
    new_process->remaining_time = new_process->burst_time;
    new_process->next = NULL;

    if (*head == NULL)
    {
        *head = new_process;
    }
    else
    {
        (*head)->next = new_process;
        *head = new_process;
    }
}

void round_robin(struct Process** head)
{
    struct Process* current_process = *head;
    struct Process* next_process = NULL;

    while (current_process)
    {
        current_process->remaining_time--;

        if (current_process->remaining_time == 0)
        {
            printf("Process %d completed.\n", current_process->process_id);
            next_process = current_process->next;
            free(current_process);
            current_process = next_process;
        }
    }
}

int main()
{
    struct Process* head = NULL;

    for (int i = 0; i < MAX_PROCESS; i++)
    {
        add_process(&head, i);
    }

    round_robin(&head);

    return 0;
}