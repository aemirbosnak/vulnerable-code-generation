//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    char name[20];
    int arrival_time;
    int service_time;
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

void add_process(Process** processes, int arrival_time, char* name, int service_time) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = processes[arrival_time]->process_id + 1;
    strcpy(new_process->name, name);
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->remaining_time = service_time;
    new_process->next = processes[arrival_time];
    processes[arrival_time] = new_process;
}

void simulate_cpu(Process** processes) {
    time_t start_time = time(NULL);
    int current_time = 0;
    Node* ready_queue = NULL;

    while (current_time < processes[0]->arrival_time) {
        current_time = time(NULL) - start_time;
    }

    while (processes[0]->remaining_time > 0) {
        current_time = time(NULL) - start_time;
        if (ready_queue == NULL) {
            add_process(&processes, current_time, "Process A", 5);
            ready_queue = processes[0]->next;
        } else {
            ready_queue = ready_queue->next;
            processes[0]->remaining_time--;
        }
    }

    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i] != NULL) {
            printf("Process ID: %d, Name: %s, Arrival Time: %d, Service Time: %d, Remaining Time: %d\n", processes[i]->process_id, processes[i]->name, processes[i]->arrival_time, processes[i]->service_time, processes[i]->remaining_time);
        }
    }
}

int main() {
    Process** processes = NULL;
    initialize_processes(&processes);
    add_process(&processes, 0, "Process A", 5);
    add_process(&processes, 2, "Process B", 4);
    add_process(&processes, 4, "Process C", 3);
    simulate_cpu(processes);

    return 0;
}