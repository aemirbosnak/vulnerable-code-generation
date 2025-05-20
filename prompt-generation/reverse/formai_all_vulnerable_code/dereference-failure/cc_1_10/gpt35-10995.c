//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MAX_PRIORITY 99

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
} Process;

int num_processes = 0;

Process* generate_processes(int num) {
    Process* processes = (Process*) malloc(num * sizeof(Process));
    srand(time(NULL));
    for (int i = 0; i < num; i++) {
        processes[i].pid = i+1;
        processes[i].arrival_time = rand() % SIZE;
        processes[i].burst_time = rand() % SIZE + 1;
        processes[i].priority = rand() % MAX_PRIORITY + 1;
    }
    return processes;
}

void print_processes(Process* processes, int num) {
    printf("PID\tARRIVAL TIME\tBURST TIME\tPRIORITY\n");
    for (int i = 0; i < num; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority);
    }
    printf("\n");
}

void execute(Process* processes, int num) {
    int time = 0;
    int* remaining_time = (int*) malloc(num * sizeof(int));
    int* waiting_time = (int*) malloc(num * sizeof(int));
    int* turnaround_time = (int*) malloc(num * sizeof(int));
    int* completed = (int*) malloc(num * sizeof(int));
    int num_completed = 0;
    for (int i = 0; i < num; i++) {
        remaining_time[i] = processes[i].burst_time;
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
        completed[i] = 0;
    }

    while (num_completed < num) {
        // Find process with highest priority among uncompleted processes
        int highest_priority_index = -1;
        int highest_priority_val = MAX_PRIORITY + 1;
        for (int i = 0; i < num; i++) {
            if (!completed[i] && processes[i].priority < highest_priority_val) {
                highest_priority_index = i;
                highest_priority_val = processes[i].priority;
            }
        }

        // Execute process
        remaining_time[highest_priority_index]--;
        time++;

        // Update waiting and turnaround times for all uncompleted processes
        for (int i = 0; i < num; i++) {
            if (!completed[i]) {
                turnaround_time[i]++;
                if (i != highest_priority_index) {
                    waiting_time[i]++;
                }
            }
        }

        // Check if process completed
        if (remaining_time[highest_priority_index] == 0) {
            num_completed++;
            completed[highest_priority_index] = 1;
        }
    }

    printf("PID\tWAITING TIME\tTURNAROUND TIME\n");
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < num; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].pid, waiting_time[i], turnaround_time[i]);
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    printf("Average waiting time: %f\n", (float) total_waiting_time / num);
    printf("Average turnaround time: %f\n", (float) total_turnaround_time / num);
}

int main() {
    Process* processes = generate_processes(SIZE);
    print_processes(processes, SIZE);
    execute(processes, SIZE);
    free(processes);
    return 0;
}