//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process
{
    int process_id;
    char name[20];
    int burst_time;
    int waiting_time;
    int remaining_time;
    struct Node* next;
} Process;

typedef struct Node
{
    Process* process;
    struct Node* next;
} Node;

void create_process(Process** head, int id, char* name, int burst_time)
{
    *head = (Process*)malloc(sizeof(Process));
    (*head)->process_id = id;
    strcpy((*head)->name, name);
    (*head)->burst_time = burst_time;
    (*head)->waiting_time = 0;
    (*head)->remaining_time = burst_time;
    (*head)->next = NULL;
}

void add_process(Process** head, Process* new_process)
{
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

void round_robin(Process** head)
{
    time_t start_time = time(NULL);
    int current_process = 0;
    int quantum = 2;

    while (*head)
    {
        Process* process = (*head)->next;

        if (process)
        {
            process->waiting_time++;

            if (process->remaining_time - quantum > 0)
            {
                process->remaining_time -= quantum;
            }
            else
            {
                process->remaining_time = 0;
                process->waiting_time = 0;
            }

            current_process++;

            if (current_process == MAX_PROCESSES)
            {
                current_process = 0;
            }

            printf("Process %d is completed.\n", process->process_id);
        }

        sleep(1);
    }

    time_t end_time = time(NULL);
    printf("Total time taken: %f seconds\n", (end_time - start_time) / MAX_PROCESSES);
}

int main()
{
    Process* head = NULL;

    create_process(&head, 1, "Process A", 5);
    create_process(&head, 2, "Process B", 4);
    create_process(&head, 3, "Process C", 6);
    create_process(&head, 4, "Process D", 3);
    create_process(&head, 5, "Process E", 2);

    round_robin(&head);

    return 0;
}