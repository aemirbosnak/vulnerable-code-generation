//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4
#define MAX_QUEUE_SIZE 5

typedef struct Process
{
    int id;
    char name[20];
    int burst_time;
    int waiting_time;
    int remaining_time;
    struct Process* next;
} Process;

void initialize_queue(Process** head, int size)
{
    *head = NULL;
    for (int i = 0; i < size; i++)
    {
        *head = malloc(sizeof(Process));
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void add_process(Process** head, int id, char* name, int burst_time)
{
    *head = malloc(sizeof(Process));
    (*head)->id = id;
    strcpy((*head)->name, name);
    (*head)->burst_time = burst_time;
    (*head)->waiting_time = 0;
    (*head)->remaining_time = burst_time;
    (*head)->next = NULL;
    head = &((*head)->next);
}

void round_robin(Process** head)
{
    time_t start_time = time(NULL);
    Process* current_process = head;

    while (current_process)
    {
        current_process->waiting_time++;

        if (current_process->remaining_time == 0)
        {
            printf("Process %s completed.\n", current_process->name);
            current_process = current_process->next;
        }
        else
        {
            current_process->remaining_time--;
            time_t end_time = time(NULL);
            printf("Process %s is running for %d cycles.\n", current_process->name, end_time - start_time);
            start_time = end_time;
        }
    }

    printf("All processes completed.\n");
}

int main()
{
    Process* head = NULL;
    initialize_queue(&head, MAX_QUEUE_SIZE);

    add_process(&head, 1, "A", 5);
    add_process(&head, 2, "B", 3);
    add_process(&head, 3, "C", 7);
    add_process(&head, 4, "D", 4);

    round_robin(&head);

    return 0;
}