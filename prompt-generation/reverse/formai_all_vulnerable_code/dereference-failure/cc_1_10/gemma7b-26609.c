//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct Node* next;
} Process;

typedef struct Node {
    Process* process;
    struct Node* next;
} Node;

void initialize_processes(Process** processes) {
    *processes = malloc(MAX_PROCESSES * sizeof(Process));
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i] = NULL;
    }
}

void add_process(Process** processes, int pid, char* name, int burst_time) {
    Process* new_process = malloc(sizeof(Process));
    new_process->pid = pid;
    strcpy(new_process->name, name);
    new_process->burst_time = burst_time;
    new_process->remaining_time = burst_time;
    new_process->next = NULL;

    if (*processes == NULL) {
        *processes = new_process;
    } else {
        (*processes)->next = new_process;
    }
}

void round_robin(Process** processes) {
    time_t start_time = time(NULL);
    Process* current_process = processes[0];

    while (current_process->remaining_time > 0) {
        printf("Process: %s, Remaining Time: %d\n", current_process->name, current_process->remaining_time);
        sleep(1);
        current_process->remaining_time--;
    }

    time_t end_time = time(NULL);
    printf("Total Time: %ld seconds\n", end_time - start_time);
}

int main() {
    Process** processes = NULL;

    initialize_processes(&processes);
    add_process(processes, 1, "Process A", 5);
    add_process(processes, 2, "Process B", 3);
    add_process(processes, 3, "Process C", 2);

    round_robin(processes);

    return 0;
}