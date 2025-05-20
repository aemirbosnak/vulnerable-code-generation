//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_waiting_time(Process processes[], int n, int quantum) {
    int rem_burst_time[n];
    for (int i = 0; i < n; i++) {
        rem_burst_time[i] = processes[i].burst_time;
    }
    
    int time = 0;
    int done;
    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_burst_time[i] > 0) {
                done = 0; // There is a pending process
                if (rem_burst_time[i] > quantum) {
                    time += quantum;
                    rem_burst_time[i] -= quantum;
                } else {
                    time += rem_burst_time[i];
                    processes[i].waiting_time = time - processes[i].burst_time;
                    rem_burst_time[i] = 0;
                    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
                }
            }
        }
    } while (!done);
}

void calculate_average_times(Process processes[], int n, int quantum) {
    calculate_waiting_time(processes, n, quantum);
    
    float total_waiting_time = 0, total_turnaround_time = 0;
    
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    
    printf("\nAverage Waiting Time = %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time = %.2f\n", total_turnaround_time / n);
}

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_processes(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    Process *processes = (Process *)malloc(n * sizeof(Process));
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter the burst time for Process P%d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    printf("Enter the time quantum for Round Robin Scheduling: ");
    scanf("%d", &quantum);
    
    // Sorting processes by burst time for demonstration purposes
    sort_processes(processes, n);
    
    calculate_average_times(processes, n, quantum);
    
    free(processes);
    return 0;
}