//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turn_around_time;
} process;

void roundRobin(process **processes, int num_processes) {
    int current_time = 0;
    int i = 0;
    int completed = 0;

    while (!completed) {
        for (i = 0; i < num_processes; i++) {
            if (processes[i]->arrival_time <= current_time && processes[i]->burst_time > 0) {
                processes[i]->waiting_time++;
                processes[i]->burst_time--;
                if (processes[i]->burst_time == 0) {
                    completed = 1;
                    processes[i]->turn_around_time = current_time - processes[i]->arrival_time + processes[i]->waiting_time;
                }
            }
        }

        current_time++;
    }
}

int main() {
    process processes[MAX_PROCESS] = {
        {1, 0, 5, 0, 0},
        {2, 2, 4, 0, 0},
        {3, 4, 3, 0, 0},
        {4, 6, 2, 0, 0},
        {5, 8, 1, 0, 0}
    };

    roundRobin(processes, MAX_PROCESS);

    for (int i = 0; i < MAX_PROCESS; i++) {
        printf("Process ID: %d\n", processes[i].id);
        printf("Arrival Time: %d\n", processes[i].arrival_time);
        printf("Burst Time: %d\n", processes[i].burst_time);
        printf("Waiting Time: %d\n", processes[i].waiting_time);
        printf("Turnaround Time: %d\n", processes[i].turn_around_time);
        printf("\n");
    }

    return 0;
}