//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct process {
    int pid;
    int arrival_time;
    int service_time;
    int remaining_time;
    struct process* next;
} process;

process* create_process(int pid, int arrival_time, int service_time) {
    process* new_process = (process*)malloc(sizeof(process));
    new_process->pid = pid;
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->remaining_time = service_time;
    new_process->next = NULL;

    return new_process;
}

void add_process(process* head, process* new_process) {
    if (head == NULL) {
        head = new_process;
    } else {
        head->next = new_process;
        head = new_process;
    }
}

void preemptive_round_robin(process* head) {
    int time_quantum = 5;
    int current_time = 0;
    process* current_process = NULL;

    while (!head->next || current_time < head->arrival_time) {
        current_time++;
    }

    while (head) {
        if (current_process == NULL || current_process->remaining_time < time_quantum) {
            current_process = head;
        }

        current_time++;
        current_process->remaining_time--;

        if (current_process->remaining_time == 0) {
            printf("Process %d completed.\n", current_process->pid);
            free(current_process);
            current_process = NULL;
        }
    }
}

int main() {
    process* head = NULL;

    // Create some processes
    process* process1 = create_process(1, 0, 8);
    process* process2 = create_process(2, 2, 10);
    process* process3 = create_process(3, 4, 6);
    process* process4 = create_process(4, 6, 4);
    process* process5 = create_process(5, 8, 2);

    // Add processes to the queue
    add_process(head, process1);
    add_process(head, process2);
    add_process(head, process3);
    add_process(head, process4);
    add_process(head, process5);

    // Preemptive round robin scheduling
    preemptive_round_robin(head);

    return 0;
}