//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct Process
{
    int process_id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct Process* next;
} Process;

void initialize_queue(Process** head)
{
    *head = NULL;
}

void insert_process(Process** head, int arrival_time, int service_time)
{
    Process* new_process = malloc(sizeof(Process));
    new_process->process_id = MAX_PROCESS + 1;
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->completion_time = 0;
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

void round_robin(Process** head)
{
    Process* current_process = *head;
    while (current_process)
    {
        current_process->completion_time = current_process->arrival_time + current_process->service_time;
        current_process = current_process->next;
    }
}

int main()
{
    Process* head = NULL;
    initialize_queue(&head);

    insert_process(&head, 0, 5);
    insert_process(&head, 2, 3);
    insert_process(&head, 4, 4);
    insert_process(&head, 6, 2);

    round_robin(&head);

    for (Process* process = head; process; process = process->next)
    {
        printf("Process ID: %d, Arrival Time: %d, Service Time: %d, Completion Time: %d\n", process->process_id, process->arrival_time, process->service_time, process->completion_time);
    }

    return 0;
}