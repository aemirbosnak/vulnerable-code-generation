//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PROC 5

struct Process {
    int pid;
    char name[20];
    int cpu_time;
    int waiting_time;
    struct Process* next;
};

void insert_process(struct Process** head, int pid, char* name, int cpu_time)
{
    struct Process* new_process = malloc(sizeof(struct Process));
    new_process->pid = pid;
    strcpy(new_process->name, name);
    new_process->cpu_time = cpu_time;
    new_process->waiting_time = 0;
    new_process->next = NULL;

    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
    }
}

void round_robin(struct Process** head)
{
    struct Process* current_process = *head;
    while (current_process) {
        current_process->waiting_time++;
        sleep(1);
        current_process->waiting_time--;
        current_process = current_process->next;
    }
}

int main()
{
    struct Process* head = NULL;

    insert_process(&head, 1, "Process A", 5);
    insert_process(&head, 2, "Process B", 3);
    insert_process(&head, 3, "Process C", 4);
    insert_process(&head, 4, "Process D", 6);
    insert_process(&head, 5, "Process E", 2);

    round_robin(&head);

    return 0;
}