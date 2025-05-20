//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: real-life
#include <stdlib.h>
#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_TIME_SLICE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int burstTime) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = id;
    process->arrival_time = arrivalTime;
    process->burst_time = burstTime;
    process->remaining_time = burstTime;
    process->next = NULL;
    return process;
}

void roundRobin(Process* processes) {
    int time_slice = 0;
    Process* current_process = processes;
    while (processes) {
        if (time_slice == processes->arrival_time) {
            printf("Process %d arrived.\n", processes->process_id);
            current_process = processes;
            processes = processes->next;
            time_slice = 0;
        } else {
            time_slice++;
        }
    }

    printf("All processes have finished execution.\n");
}

int main() {
    Process* processes = NULL;
    processes = createProcess(1, 0, 5);
    processes = createProcess(2, 2, 4);
    processes = createProcess(3, 4, 3);
    processes = createProcess(4, 6, 2);
    processes = createProcess(5, 8, 1);

    roundRobin(processes);

    return 0;
}