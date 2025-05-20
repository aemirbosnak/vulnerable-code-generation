//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
#include<stdio.h>
#include<stdlib.h>

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

int main() {
    int n, i, j, pos, run_time = 0, total_waiting_time = 0,
        total_turnaround_time = 0, avg_waiting_time, avg_turnaround_time;
    struct Process *processes, temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    processes = (struct Process*) malloc(n * sizeof(struct Process));

    for(i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time of process %d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i+1;
    }

    // implementing shortest job first algorithm
    for(i = 0; i < n; i++) {
        pos = i;
        for(j = i+1; j < n; j++) {
            if(processes[j].arrival_time <= run_time && processes[j].burst_time < processes[pos].burst_time) {
                pos = j;
            }
        }
        temp = processes[i];
        processes[i] = processes[pos];
        processes[pos] = temp;

        run_time += processes[i].burst_time;
        processes[i].completion_time = run_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    avg_waiting_time = total_waiting_time / n;
    avg_turnaround_time = total_turnaround_time / n;

    printf("\n PID \t Arrival Time \t Burst Time \t Completion Time \t Waiting Time \t Turnaround Time\n");
    for(i = 0; i < n; i++) {
        printf(" %d \t %d \t\t %d \t\t %d \t\t %d \t\t %d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average waiting time: %d\n", avg_waiting_time);
    printf("Average turnaround time: %d\n", avg_turnaround_time);

    return 0;
}