//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int cpu_time;
} Process;

int main() {
    srand(time(0));
    int num_processes = 5;
    Process* processes = (Process*) malloc(num_processes * sizeof(Process));

    for (int i = 0; i < num_processes; i++) {
        processes[i].pid = i + 1;
        processes[i].arrival_time = rand() % 100;
        processes[i].burst_time = rand() % 100;
        processes[i].cpu_time = 0;
    }

    int current_time = 0;
    int next_time = processes[0].arrival_time;
    int cpu_times[num_processes];
    int time_slice = 10;

    while (current_time < 1000) {
        int process_id = 0;
        for (int i = 0; i < num_processes; i++) {
            if (current_time >= next_time && processes[i].cpu_time < processes[i].burst_time) {
                process_id = i;
                break;
            }
            next_time += time_slice;
        }

        processes[process_id].cpu_time += time_slice;
        current_time += time_slice;

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].cpu_time >= processes[i].burst_time) {
                printf("Process %d finished at time %d\n", processes[i].pid, current_time);
                processes[i].cpu_time = 0;
            }
        }
    }

    for (int i = 0; i < num_processes; i++) {
        printf("Process %d finished at time %d\n", processes[i].pid, processes[i].cpu_time);
    }

    free(processes);
    return 0;
}