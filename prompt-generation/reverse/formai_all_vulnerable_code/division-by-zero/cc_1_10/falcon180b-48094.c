//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_PROCESS_NAME_LEN 20

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LEN];
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int start_time;
    int end_time;
} Process;

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    Process processes[MAX_PROCESSES];
    printf("Enter the process details:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d:\n", i+1);
        printf("Enter the process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Enter the process name: ");
        scanf("%s", processes[i].name);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    int quantum = 2;
    int current_time = 0;
    int completed_processes = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    while (completed_processes < num_processes) {
        int min_burst_time = 9999999;
        int min_index = -1;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].burst_time > 0 && processes[i].burst_time <= min_burst_time) {
                min_burst_time = processes[i].burst_time;
                min_index = i;
            }
        }

        if (min_index == -1) {
            current_time += quantum;
            continue;
        }

        int time_slice = min_burst_time <= quantum? min_burst_time : quantum;
        current_time += time_slice;
        processes[min_index].burst_time -= time_slice;

        if (processes[min_index].burst_time == 0) {
            completed_processes++;
            processes[min_index].end_time = current_time;
            processes[min_index].turnaround_time = processes[min_index].end_time - processes[min_index].start_time;
            processes[min_index].waiting_time = processes[min_index].turnaround_time - processes[min_index].burst_time;
            total_waiting_time += processes[min_index].waiting_time;
            total_turnaround_time += processes[min_index].turnaround_time;
        } else {
            processes[min_index].start_time = current_time;
        }
    }

    printf("\nProcess ID\tProcess Name\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].name, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage waiting time: %d\n", total_waiting_time / num_processes);
    printf("Average turnaround time: %d\n", total_turnaround_time / num_processes);

    return 0;
}