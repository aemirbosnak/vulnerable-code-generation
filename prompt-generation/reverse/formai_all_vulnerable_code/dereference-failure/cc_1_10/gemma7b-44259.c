//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct process
{
    int process_id;
    char name[20];
    int burst_time;
    int remaining_time;
    struct process* next;
} process;

process* create_process(int process_id, char* name, int burst_time)
{
    process* new_process = (process*)malloc(sizeof(process));
    new_process->process_id = process_id;
    strcpy(new_process->name, name);
    new_process->burst_time = burst_time;
    new_process->remaining_time = burst_time;
    new_process->next = NULL;
    return new_process;
}

void add_process(process** head, int process_id, char* name, int burst_time)
{
    process* new_process = create_process(process_id, name, burst_time);
    if (*head == NULL)
    {
        *head = new_process;
    }
    else
    {
        (*head)->next = new_process;
    }
}

void round_robin(process** head)
{
    int time_quantum = 5;
    process* current_process = *head;

    while (*head)
    {
        current_process->remaining_time -= time_quantum;
        if (current_process->remaining_time == 0)
        {
            printf("Process %d completed.\n", current_process->process_id);
            free(current_process);
            *head = (*head)->next;
        }
        else
        {
            current_process = current_process->next;
        }
    }
}

int main()
{
    process** ready_queue = (process**)malloc(MAX_QUEUE_SIZE * sizeof(process));
    process** waiting_queue = (process**)malloc(MAX_QUEUE_SIZE * sizeof(process));

    add_process(ready_queue, 1, "A", 10);
    add_process(ready_queue, 2, "B", 5);
    add_process(ready_queue, 3, "C", 8);
    add_process(waiting_queue, 4, "D", 12);
    add_process(waiting_queue, 5, "E", 6);

    round_robin(ready_queue);

    return 0;
}