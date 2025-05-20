//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    char name[20];
    int burst_time;
    int remaining_time;
    int status;
    struct Process* next;
} Process;

void initialize_processes(Process** head) {
    *head = NULL;
}

void add_process(Process** head, int process_id, char* name, int burst_time) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = process_id;
    strcpy(new_process->name, name);
    new_process->burst_time = burst_time;
    new_process->remaining_time = burst_time;
    new_process->status = 0;
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
    while (current_process) {
        current_process->remaining_time--;
        if (current_process->remaining_time == 0) {
            current_process->status = 1;
            printf("Process %d completed.\n", current_process->process_id);
            current_process = NULL;
        } else {
            current_process = current_process->next;
        }

        time_t end_time = time(NULL);
        int time_spent = end_time - start_time;
        start_time = end_time;
        printf("Time spent on process %d: %d seconds.\n", current_process->process_id, time_spent);
    }
}

int main() {
    Process* processes = NULL;
    initialize_processes(&processes);

    add_process(&processes, 1, "Process A", 5);
    add_process(&processes, 2, "Process B", 3);
    add_process(&processes, 3, "Process C", 8);
    add_process(&processes, 4, "Process D", 2);

    round_robin(&processes);

    return 0;
}