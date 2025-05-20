//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    char name[20];
    int burst_time;
    int waiting_time;
    int remaining_time;
} Process;

void roundRobin(Process processes[], int n);

int main() {
    Process processes[MAX_PROCESSES];
    int i, n, time_quantum = 5;

    // Create processes
    for (i = 0; i < MAX_PROCESSES; i++) {
        processes[i].process_id = i + 1;
        processes[i].name[0] = 'A' + i;
        processes[i].burst_time = rand() % 10 + 1;
        processes[i].waiting_time = 0;
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Round robin scheduling
    roundRobin(processes, n);

    // Print results
    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("Process ID: %d, Waiting Time: %d, Remaining Time: %d\n", processes[i].process_id, processes[i].waiting_time, processes[i].remaining_time);
    }

    return 0;
}

void roundRobin(Process processes[], int n) {
    int current_process = 0;
    int time_elapsed = 0;

    while (!processes[n - 1].waiting_time) {
        processes[current_process].waiting_time++;
        time_elapsed++;

        if (processes[current_process].remaining_time > 0) {
            processes[current_process].remaining_time--;
            time_elapsed++;
        }

        current_process = (current_process + 1) % n;
    }
}