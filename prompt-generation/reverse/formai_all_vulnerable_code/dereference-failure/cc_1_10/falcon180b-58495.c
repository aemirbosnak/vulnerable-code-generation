//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sched.h>

#define NUM_PROCESSES 5
#define PRIORITY_LEVELS 3

typedef struct {
    int id;
    char *name;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void print_processes(Process *processes, int num_processes) {
    printf("ID\tName\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].name, processes[i].priority, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    Process processes[NUM_PROCESSES];
    int num_processes = NUM_PROCESSES;

    srand(time(NULL));

    // Initialize processes
    for (int i = 0; i < num_processes; i++) {
        processes[i].id = i + 1;
        processes[i].name = (char *)malloc(10 * sizeof(char));
        sprintf(processes[i].name, "P%d", processes[i].id);
        processes[i].priority = rand() % PRIORITY_LEVELS + 1;
        processes[i].burst_time = rand() % 100 + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    // Print initial state of processes
    print_processes(processes, num_processes);

    // Simulate CPU scheduling algorithm
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < processes[i].burst_time; j++) {
            // Execute process for one time quantum
            processes[i].turnaround_time++;
            processes[i].waiting_time += processes[i].burst_time - j;
        }
    }

    // Print final state of processes
    print_processes(processes, num_processes);

    return 0;
}