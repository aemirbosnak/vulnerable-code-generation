//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    char name[20];
    int arrival_time;
    int burst_time;
    int remaining_time;
    struct Node* next;
} Process;

typedef struct Node {
    Process* process;
    struct Node* next;
} Node;

void initialize_processes(Process** processes) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i] = NULL;
    }
}

void insert_process(Process** processes, Process* new_process) {
    new_process->next = NULL;
    if (*processes == NULL) {
        *processes = new_process;
    } else {
        (*processes)->next = new_process;
        *processes = new_process;
    }
}

void simulate_round_robin(Process** processes) {
    int quantum = 5;
    time_t start_time = time(NULL);
    Process* current_process = processes[0];

    while (current_process) {
        int time_spent = 0;
        while (time_spent < quantum) {
            printf("Process: %s, Time Remaining: %d\n", current_process->name, current_process->remaining_time);
            time_spent++;
            sleep(1);
        }
        current_process->remaining_time -= quantum;
        current_process = processes[0];
    }
}

int main() {
    Process* processes[MAX_PROCESSES];
    initialize_processes(processes);

    Process* new_process1 = (Process*)malloc(sizeof(Process));
    new_process1->process_id = 1;
    strcpy(new_process1->name, "Process A");
    new_process1->arrival_time = 0;
    new_process1->burst_time = 8;
    insert_process(processes, new_process1);

    Process* new_process2 = (Process*)malloc(sizeof(Process));
    new_process2->process_id = 2;
    strcpy(new_process2->name, "Process B");
    new_process2->arrival_time = 2;
    new_process2->burst_time = 10;
    insert_process(processes, new_process2);

    Process* new_process3 = (Process*)malloc(sizeof(Process));
    new_process3->process_id = 3;
    strcpy(new_process3->name, "Process C");
    new_process3->arrival_time = 4;
    new_process3->burst_time = 6;
    insert_process(processes, new_process3);

    simulate_round_robin(processes);

    return 0;
}