//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_QUEUE_SIZE 5

typedef struct Process {
    int process_id;
    char name[20];
    int burst_time;
    int remaining_time;
    int status;
    struct Process* next;
} Process;

void initialize_process_queue(Process** head) {
    *head = NULL;
}

void insert_process_into_queue(Process** head, Process* new_process) {
    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
        *head = new_process;
    }
}

void round_robin_scheduling(Process** head) {
    int time_quantum = 5;
    Process* current_process = *head;
    while (current_process) {
        if (current_process->remaining_time > 0) {
            current_process->remaining_time -= time_quantum;
            printf("Process %d is running for %d time quantum\n", current_process->process_id, time_quantum);
            time_quantum = 5;
        } else {
            current_process->status = 0;
            printf("Process %d is completed\n", current_process->process_id);
            current_process = current_process->next;
        }
    }
}

int main() {
    Process* process_queue = NULL;
    initialize_process_queue(&process_queue);

    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = 1;
    strcpy(new_process->name, "Process A");
    new_process->burst_time = 10;
    new_process->remaining_time = new_process->burst_time;
    new_process->status = 1;
    insert_process_into_queue(&process_queue, new_process);

    new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = 2;
    strcpy(new_process->name, "Process B");
    new_process->burst_time = 5;
    new_process->remaining_time = new_process->burst_time;
    new_process->status = 1;
    insert_process_into_queue(&process_queue, new_process);

    new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = 3;
    strcpy(new_process->name, "Process C");
    new_process->burst_time = 7;
    new_process->remaining_time = new_process->burst_time;
    new_process->status = 1;
    insert_process_into_queue(&process_queue, new_process);

    round_robin_scheduling(&process_queue);

    return 0;
}