//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct Process* next;
} Process;

void initialize_processes(Process** head) {
    *head = NULL;
}

void add_process(Process** head, int id, int arrival_time, int service_time) {
    Process* new_process = malloc(sizeof(Process));
    new_process->process_id = id;
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->completion_time = 0;
    new_process->next = NULL;

    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
    }
}

void round_robin(Process** head) {
    time_t start_time = time(NULL);
    Process* current_process = head;
    Process* next_process = NULL;

    while (!current_process->completion_time) {
        next_process = current_process->next;
        current_process->completion_time = start_time + current_process->service_time;
        current_process = next_process;

        if (next_process == NULL) {
            current_process = head;
        }
    }
}

int main() {
    Process* processes = NULL;
    initialize_processes(&processes);

    add_process(&processes, 1, 0, 5);
    add_process(&processes, 2, 2, 4);
    add_process(&processes, 3, 4, 3);

    round_robin(&processes);

    for (Process* process = processes; process; process = process->next) {
        printf("Process ID: %d, Completion Time: %d\n", process->process_id, process->completion_time);
    }

    return 0;
}