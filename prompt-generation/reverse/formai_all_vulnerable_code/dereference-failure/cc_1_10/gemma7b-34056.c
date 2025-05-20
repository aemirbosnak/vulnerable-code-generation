//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_SCHEDULE_SIZE 10

typedef struct Process
{
    int process_id;
    char name[20];
    int cpu_burst_time;
    int remaining_burst_time;
    int waiting_time;
    struct Process* next;
} Process;

Process* create_process(int id, char* name, int burst_time)
{
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = id;
    strcpy(new_process->name, name);
    new_process->cpu_burst_time = burst_time;
    new_process->remaining_burst_time = burst_time;
    new_process->waiting_time = 0;
    new_process->next = NULL;

    return new_process;
}

void add_process(Process** head, int id, char* name, int burst_time)
{
    Process* new_process = create_process(id, name, burst_time);

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

void round_robin(Process* head)
{
    time_t start_time = time(NULL);
    int current_process = 0;
    int quantum = 5;

    while (head)
    {
        Process* current_process_ptr = head->next;
        head->remaining_burst_time--;

        if (head->remaining_burst_time == 0)
        {
            head->waiting_time++;
            printf("Process %d completed.\n", head->process_id);
            free(head);
            head = NULL;
        }
        else if (current_process_ptr)
        {
            current_process = (current_process + 1) % MAX_SCHEDULE_SIZE;
            head = current_process_ptr;
        }
        else
        {
            head = NULL;
        }

        time_t end_time = time(NULL);
        int time_taken = end_time - start_time;
        printf("Time taken for process %d: %d seconds.\n", head->process_id, time_taken);
    }
}

int main()
{
    Process* head = NULL;
    add_process(&head, 1, "Process A", 8);
    add_process(&head, 2, "Process B", 10);
    add_process(&head, 3, "Process C", 6);
    add_process(&head, 4, "Process D", 4);
    add_process(&head, 5, "Process E", 2);

    round_robin(head);

    return 0;
}