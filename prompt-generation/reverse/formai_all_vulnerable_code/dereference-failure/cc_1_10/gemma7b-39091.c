//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    struct process* next;
};

void insert_process(struct process** head, int id, int burst_time)
{
    struct process* new_process = (struct process*)malloc(sizeof(struct process));
    new_process->id = id;
    new_process->burst_time = burst_time;
    new_process->waiting_time = 0;
    new_process->turnaround_time = 0;
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

void simulate_cpu(struct process** head)
{
    struct process* current_process = *head;
    int time = 0;

    while (current_process)
    {
        printf("Process %d is running...", current_process->id);
        sleep(current_process->burst_time);

        current_process->waiting_time++;
        current_process->turnaround_time = time + current_process->burst_time;

        time++;

        current_process = current_process->next;
    }

    printf("All processes are completed.");
}

int main()
{
    struct process* head = NULL;

    insert_process(&head, 1, 5);
    insert_process(&head, 2, 8);
    insert_process(&head, 3, 3);
    insert_process(&head, 4, 6);
    insert_process(&head, 5, 7);

    simulate_cpu(&head);

    return 0;
}