//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_TIME 10

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    struct process* next;
};

void insert_process(struct process** head, int pid, int arrival_time, int burst_time) {
    struct process* new_process = (struct process*)malloc(sizeof(struct process));
    new_process->pid = pid;
    new_process->arrival_time = arrival_time;
    new_process->burst_time = burst_time;
    new_process->remaining_time = burst_time;
    new_process->next = NULL;

    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
    }
}

void preemptive_round_robin(struct process** head) {
    struct process* current_process = *head;
    struct process* ready_queue = NULL;

    while (current_process) {
        if (current_process->remaining_time > 0) {
            insert_process(&ready_queue, current_process, 0, current_process->remaining_time);
        }

        current_process->remaining_time--;

        if (current_process->remaining_time == 0) {
            printf("Process %d completed.\n", current_process->pid);
        }

        current_process = current_process->next;
    }

    printf("All processes completed.\n");
}

int main() {
    struct process* head = NULL;

    insert_process(&head, 1, 0, 5);
    insert_process(&head, 2, 2, 4);
    insert_process(&head, 3, 4, 3);
    insert_process(&head, 4, 6, 2);
    insert_process(&head, 5, 8, 1);

    preemptive_round_robin(&head);

    return 0;
}