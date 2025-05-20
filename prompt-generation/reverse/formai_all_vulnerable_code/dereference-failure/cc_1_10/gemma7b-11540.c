//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    struct Process* next;
} Process;

void initialize_queue(Process** head) {
    *head = NULL;
}

void insert_process(Process** head, Process* new_process) {
    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
        *head = new_process;
    }
}

void round_robin(Process** head, int time_quantum) {
    Process* current_process = *head;
    while (current_process) {
        if (current_process->burst_time > 0) {
            current_process->burst_time--;
            current_process->waiting_time++;
        } else {
            current_process->turnaround_time = current_process->waiting_time + current_process->burst_time;
            insert_process(&(*head), current_process);
            current_process = *head;
        }
        sleep(time_quantum);
    }
}

int main() {
    Process* processes[MAX_PROCESSES];
    initialize_queue(processes);

    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i] = malloc(sizeof(Process));
        processes[i]->process_id = i + 1;
        processes[i]->arrival_time = rand() % MAX_QUEUE_SIZE;
        processes[i]->burst_time = rand() % MAX_QUEUE_SIZE;
        insert_process(&processes[i], processes[i]);
    }

    round_robin(processes, 2);

    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i]->process_id, processes[i]->waiting_time, processes[i]->turnaround_time);
    }

    return 0;
}