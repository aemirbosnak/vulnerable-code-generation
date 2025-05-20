//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define MAX_CPU_BURST 100

typedef struct {
    int pid;
    int cpu_burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void execute_processes(Process *processes, int num_processes) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (int i = 0; i < num_processes; i++) {
        int cpu_bursts = (processes[i].cpu_burst_time + MAX_CPU_BURST - 1) / MAX_CPU_BURST;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;

        for (int j = 0; j < cpu_bursts; j++) {
            if (processes[i].waiting_time > 0) {
                total_waiting_time += processes[i].waiting_time;
                processes[i].waiting_time = 0;
            }

            if (processes[i].turnaround_time > 0) {
                total_turnaround_time += processes[i].turnaround_time;
                processes[i].turnaround_time = 0;
            }

            printf("CPU is executing process %d\n", processes[i].pid);
            fflush(stdout);
        }
    }

    printf("Average waiting time: %d\n", total_waiting_time / num_processes);
    printf("Average turnaround time: %d\n", total_turnaround_time / num_processes);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <number_of_processes> <cpu_burst_time>\n", argv[0]);
        return 1;
    }

    int num_processes = atoi(argv[1]);
    int cpu_burst_time = atoi(argv[2]);

    Process processes[MAX_PROCESSES];

    for (int i = 0; i < num_processes; i++) {
        processes[i].pid = i + 1;
        processes[i].cpu_burst_time = cpu_burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    execute_processes(processes, num_processes);

    return 0;
}