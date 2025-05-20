//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

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
    *processes = (Process*)malloc(MAX_PROCESSES * sizeof(Process));
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i] = NULL;
    }
}

void add_process(Process** processes, char* name, int burst_time) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->pid = MAX_PROCESSES - 1;
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

    while (time(NULL) - start_time < 10) {
        current_process->remaining_time--;

        if (current_process->remaining_time == 0) {
            printf("Process %s completed.\n", current_process->name);
            free(current_process);
            current_process = processes[0];
        } else {
            current_process = current_process->next;
        }
    }

    printf("All processes completed.\n");
}

int main() {
    Process** processes = NULL;

    initialize_processes(&processes);
    add_process(processes, "A", 5);
    add_process(processes, "B", 3);
    add_process(processes, "C", 2);
    add_process(processes, "D", 4);
    add_process(processes, "E", 6);

    round_robin(processes);

    return 0;
}