//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_QUEUE_SIZE 5

typedef struct Process {
    int process_id;
    char name[20];
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void create_process(Process **processes, int index) {
    processes[index] = (Process *)malloc(sizeof(Process));
    processes[index]->process_id = index + 1;
    processes[index]->name[0] = '\0';
    processes[index]->arrival_time = 0;
    processes[index]->burst_time = 0;
    processes[index]->waiting_time = 0;
    processes[index]->turnaround_time = 0;
}

void calculate_waiting_time(Process *process) {
    process->waiting_time = process->arrival_time - process->burst_time;
}

void calculate_turnaround_time(Process *process) {
    process->turnaround_time = process->waiting_time + process->burst_time;
}

void display_processes(Process **processes) {
    for (int i = 0; i < MAX_PROCESS; i++) {
        if (processes[i] != NULL) {
            printf("Process ID: %d, Name: %s, Arrival Time: %d, Burst Time: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i]->process_id, processes[i]->name, processes[i]->arrival_time, processes[i]->burst_time, processes[i]->waiting_time, processes[i]->turnaround_time);
        }
    }
}

int main() {
    Process **processes = (Process **)malloc(MAX_PROCESS * sizeof(Process));

    // Create processes
    for (int i = 0; i < MAX_PROCESS; i++) {
        create_process(processes, i);
    }

    // Calculate waiting and turnaround times
    for (int i = 0; i < MAX_PROCESS; i++) {
        calculate_waiting_time(processes[i]);
        calculate_turnaround_time(processes[i]);
    }

    // Display processes
    display_processes(processes);

    return 0;
}