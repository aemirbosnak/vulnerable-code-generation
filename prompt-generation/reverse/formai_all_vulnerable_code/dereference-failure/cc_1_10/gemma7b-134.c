//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4
#define MAX_QUEUE_SIZE 10

typedef struct Process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    struct Process* next;
} Process;

void roundrobin(Process** head)
{
    int i = 0;
    Process* current_process = *head;
    while (current_process)
    {
        printf("Process %d is running...\n", current_process->process_id);
        current_process->completion_time = time(NULL) + current_process->burst_time;
        current_process = current_process->next;
    }
}

void preemptive_fair(Process** head)
{
    int i = 0;
    Process* current_process = *head;
    while (current_process)
    {
        printf("Process %d is running...\n", current_process->process_id);
        current_process->completion_time = time(NULL) + current_process->burst_time;
        if (current_process->burst_time > 0)
        {
            current_process->burst_time--;
            current_process = current_process->next;
        }
    }
}

int main()
{
    Process* head = NULL;
    Process* process_1 = malloc(sizeof(Process));
    process_1->process_id = 1;
    process_1->arrival_time = 0;
    process_1->burst_time = 5;

    Process* process_2 = malloc(sizeof(Process));
    process_2->process_id = 2;
    process_2->arrival_time = 2;
    process_2->burst_time = 3;

    Process* process_3 = malloc(sizeof(Process));
    process_3->process_id = 3;
    process_3->arrival_time = 4;
    process_3->burst_time = 2;

    head = process_1;
    head->next = process_2;
    head->next->next = process_3;

    roundrobin(&head);
    preemptive_fair(&head);

    return 0;
}