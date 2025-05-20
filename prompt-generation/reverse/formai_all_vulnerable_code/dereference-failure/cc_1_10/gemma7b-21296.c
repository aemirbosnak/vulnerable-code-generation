//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define MAX_Quantum 5

typedef struct Process
{
    int process_id;
    int arrival_time;
    int execution_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* head = NULL;

void add_process(int process_id, int arrival_time, int execution_time)
{
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = process_id;
    new_process->arrival_time = arrival_time;
    new_process->execution_time = execution_time;
    new_process->remaining_time = execution_time;
    new_process->next = NULL;

    if (head == NULL)
    {
        head = new_process;
    }
    else
    {
        Process* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_process;
    }
}

void simulate_scheduler()
{
    Process* current_process = head;
    int time = 0;

    while (current_process && time < MAX_Quantum)
    {
        time++;
        current_process->remaining_time--;

        if (current_process->remaining_time == 0)
        {
            printf("Process %d completed.\n", current_process->process_id);
            free(current_process);
            current_process = head;
        }
    }

    printf("Time: %d\n", time);
}

int main()
{
    add_process(1, 0, 5);
    add_process(2, 2, 4);
    add_process(3, 4, 3);
    add_process(4, 6, 2);

    simulate_scheduler();

    return 0;
}