//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct process
{
    int id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct process* next;
} process;

process* create_process(int id, int arrival_time, int service_time)
{
    process* new_process = (process*)malloc(sizeof(process));
    new_process->id = id;
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->completion_time = 0;
    new_process->next = NULL;

    return new_process;
}

void add_process(process* head, int id, int arrival_time, int service_time)
{
    process* new_process = create_process(id, arrival_time, service_time);

    if (head == NULL)
    {
        head = new_process;
    }
    else
    {
        process* current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new_process;
    }
}

void round_robin(process* head)
{
    int time = 0;
    process* current = head;
    process* next = NULL;

    while (current)
    {
        if (time >= current->arrival_time)
        {
            current->completion_time = time + current->service_time;
            next = current->next;
            free(current);
            current = next;
        }
        else
        {
            time++;
        }
    }
}

int main()
{
    process* head = NULL;
    add_process(head, 1, 0, 5);
    add_process(head, 2, 2, 4);
    add_process(head, 3, 4, 3);
    add_process(head, 4, 6, 2);
    add_process(head, 5, 8, 1);

    round_robin(head);

    for (process* current = head; current; current = current->next)
    {
        printf("Process ID: %d, Completion Time: %d\n", current->id, current->completion_time);
    }

    return 0;
}