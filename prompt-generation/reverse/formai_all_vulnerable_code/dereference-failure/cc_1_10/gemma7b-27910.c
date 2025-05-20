//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    char name[20];
    int burst_time;
    int waiting_time;
    int turnaround_time;
    struct Process* next;
} Process;

void create_process(Process** head, int id, char* name, int burst_time)
{
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = id;
    strcpy(new_process->name, name);
    new_process->burst_time = burst_time;
    new_process->waiting_time = 0;
    new_process->turnaround_time = 0;
    new_process->next = NULL;

    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
    }
}

void round_robin(Process** head)
{
    int time_quantum = 5;
    Process* current_process = *head;
    while (current_process) {
        if (current_process->burst_time > 0) {
            current_process->waiting_time++;
            current_process->burst_time--;
            printf("Process %d is running...\n", current_process->process_id);
            sleep(time_quantum);
        } else {
            current_process->waiting_time = 0;
            current_process->turnaround_time = time_quantum + current_process->waiting_time;
            printf("Process %d is completed.\n", current_process->process_id);
            current_process = current_process->next;
        }
    }
}

int main()
{
    Process* head = NULL;
    create_process(&head, 1, "Process A", 8);
    create_process(&head, 2, "Process B", 10);
    create_process(&head, 3, "Process C", 6);
    create_process(&head, 4, "Process D", 7);
    create_process(&head, 5, "Process E", 9);

    round_robin(&head);

    return 0;
}