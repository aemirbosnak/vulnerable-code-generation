//MISTRAL-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 10
#define QUANTUM 5

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int turnaround_time;
} Process;

void print_processes(Process processes[], int num_processes) {
    printf("\n Process ID | Arrival Time | Burst Time | Remaining Time | Turnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%5d | %10d | %10d | %15d | %15d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].remaining_time, processes[i].turnaround_time);
    }
}

void add_process(Process processes[], int* num_processes, int pid, int arrival_time, int burst_time) {
    if (*num_processes >= MAX_PROCESSES) {
        printf("\n System is full. Cannot add process %d.\n", pid);
        return;
    }
    processes[*num_processes].pid = pid;
    processes[*num_processes].arrival_time = arrival_time;
    processes[*num_processes].burst_time = burst_time;
    processes[*num_processes].remaining_time = burst_time;
    (*num_processes)++;
}

void round_robin(Process processes[], int num_processes) {
    int time = 0;
    int count = 0;
    int completed = 0;

    while (completed < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0) {
                if (time % processes[i].arrival_time == 0) {
                    printf("\n Process %d starts executing at time %d.\n", processes[i].pid, time);
                    if (processes[i].remaining_time <= QUANTUM) {
                        processes[i].remaining_time = 0;
                        processes[i].turnaround_time = time + processes[i].burst_time - processes[i].arrival_time;
                        completed++;
                    } else {
                        processes[i].remaining_time -= QUANTUM;
                    }
                }
            }
            time++;
        }
    }

    print_processes(processes, num_processes);
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    add_process(processes, &num_processes, 1, 0, 8);
    add_process(processes, &num_processes, 2, 3, 6);
    add_process(processes, &num_processes, 3, 5, 12);
    add_process(processes, &num_processes, 4, 7, 4);

    round_robin(processes, num_processes);

    return 0;
}