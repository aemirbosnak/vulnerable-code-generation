//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

struct process
{
    int id;
    int burst_time;
    int waiting_time;
    int turn_around_time;
    struct process* next;
};

struct process* create_process(int id, int burst_time)
{
    struct process* new_process = (struct process*)malloc(sizeof(struct process));
    new_process->id = id;
    new_process->burst_time = burst_time;
    new_process->waiting_time = 0;
    new_process->turn_around_time = 0;
    new_process->next = NULL;

    return new_process;
}

void schedule(struct process* head)
{
    struct process* current_process = head;
    while (current_process)
    {
        current_process->waiting_time++;
        current_process = current_process->next;
    }

    current_process = head;
    while (current_process)
    {
        current_process->turn_around_time = current_process->waiting_time + current_process->burst_time;
        current_process = current_process->next;
    }
}

int main()
{
    struct process* head = create_process(1, 5);
    head->next = create_process(2, 3);
    head->next->next = create_process(3, 8);
    head->next->next->next = create_process(4, 2);
    head->next->next->next->next = create_process(5, 4);

    schedule(head);

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("------------------------------------------------------------\n");
    for (struct process* current_process = head; current_process; current_process = current_process->next)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", current_process->id, current_process->burst_time, current_process->waiting_time, current_process->turn_around_time);
    }

    return 0;
}