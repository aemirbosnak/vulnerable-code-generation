//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
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

void initialize_queue(Process** head) {
    *head = NULL;
}

void enqueue(Process** head, Process* process) {
    if (*head == NULL) {
        *head = process;
    } else {
        (*head)->next = process;
        *head = process;
    }
}

void dequeue(Process** head, Process** process) {
    if (*head == NULL) {
        return;
    } else {
        *process = *head;
        *head = (*head)->next;
    }
}

void calculate_waiting_time(Process* process, int quantum) {
    process->waiting_time = quantum - process->burst_time;
}

void calculate_turnaround_time(Process* process) {
    process->turnaround_time = process->waiting_time + process->burst_time;
}

void simulate_cpu_scheduling(int quantum) {
    Process* head = NULL;
    initialize_queue(&head);

    Process* process = NULL;
    for (int i = 0; i < MAX_PROCESS; i++) {
        process = (Process*)malloc(sizeof(Process));
        process->process_id = i;
        process->name[0] = 'A' + i;
        process->burst_time = rand() % MAX_QUEUE_SIZE;
        process->waiting_time = 0;
        process->turnaround_time = 0;
        enqueue(&head, process);
    }

    int time = 0;
    while (!head) {
        time++;
        if (time % quantum == 0) {
            Process* completed_process = NULL;
            dequeue(&head, &completed_process);
            if (completed_process) {
                calculate_waiting_time(completed_process, quantum);
                calculate_turnaround_time(completed_process);
                printf("Process %d completed with waiting time %d and turnaround time %d\n", completed_process->process_id, completed_process->waiting_time, completed_process->turnaround_time);
            }
        }
    }

    printf("All processes completed.\n");
}

int main() {
    simulate_cpu_scheduling(5);

    return 0;
}