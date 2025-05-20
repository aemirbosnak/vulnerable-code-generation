//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
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

void dequeue(Process** head) {
    Process* process = *head;
    *head = process->next;
    free(process);
}

void round_robin(Process** head) {
    Process* current_process = *head;
    int time_quantum = 0;

    while (current_process) {
        time_quantum++;
        if (current_process->remaining_time > 0) {
            current_process->remaining_time--;
        } else {
            dequeue(head);
            enqueue(head, current_process);
        }

        if (time_quantum % 2 == 0) {
            printf("Process ID: %d, Remaining Time: %d\n", current_process->process_id, current_process->remaining_time);
        }
    }
}

int main() {
    Process* processes[MAX_PROCESS] = {NULL};
    initialize_queue(&processes[0]);

    // Create some processes
    processes[0] = (Process*)malloc(sizeof(Process));
    processes[0]->process_id = 1;
    processes[0]->arrival_time = 0;
    processes[0]->burst_time = 5;
    processes[0]->remaining_time = processes[0]->burst_time;

    processes[1] = (Process*)malloc(sizeof(Process));
    processes[1]->process_id = 2;
    processes[1]->arrival_time = 2;
    processes[1]->burst_time = 4;
    processes[1]->remaining_time = processes[1]->burst_time;

    processes[2] = (Process*)malloc(sizeof(Process));
    processes[2]->process_id = 3;
    processes[2]->arrival_time = 3;
    processes[2]->burst_time = 3;
    processes[2]->remaining_time = processes[2]->burst_time;

    processes[3] = (Process*)malloc(sizeof(Process));
    processes[3]->process_id = 4;
    processes[3]->arrival_time = 4;
    processes[3]->burst_time = 2;
    processes[3]->remaining_time = processes[3]->burst_time;

    processes[4] = (Process*)malloc(sizeof(Process));
    processes[4]->process_id = 5;
    processes[4]->arrival_time = 5;
    processes[4]->burst_time = 1;
    processes[4]->remaining_time = processes[4]->burst_time;

    round_robin(&processes[0]);

    return 0;
}