//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

void calculateTimes(Process *processes, int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

void printProcessTable(Process *processes, int n) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                processes[i].process_id, 
                processes[i].arrival_time, 
                processes[i].burst_time, 
                processes[i].completion_time, 
                processes[i].waiting_time, 
                processes[i].turnaround_time);
    }
}

void sjfScheduling(Process *processes, int n) {
    int current_time = 0;
    bool completed[n];
    for (int i = 0; i < n; i++) completed[i] = false;

    for (int i = 0; i < n; i++) {
        int idx = -1;
        int min_burst_time = 9999;

        for (int j = 0; j < n; j++) {
            if (!completed[j] && processes[j].arrival_time <= current_time) {
                if (processes[j].burst_time < min_burst_time) {
                    min_burst_time = processes[j].burst_time;
                    idx = j;
                }
            }
        }

        if (idx != -1) {
            current_time += processes[idx].burst_time;
            processes[idx].completion_time = current_time;
            completed[idx] = true;
            printf("Process %d started at time %d and finished at time %d\n", 
                   processes[idx].process_id, 
                   current_time - processes[idx].burst_time, 
                   current_time);
        }
        else {
            current_time++;
            i--; // re-evaluate the same index
        }
    }
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(n * sizeof(Process));

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    sjfScheduling(processes, n);
    
    calculateTimes(processes, n);
    printProcessTable(processes, n);

    free(processes);
    return 0;
}