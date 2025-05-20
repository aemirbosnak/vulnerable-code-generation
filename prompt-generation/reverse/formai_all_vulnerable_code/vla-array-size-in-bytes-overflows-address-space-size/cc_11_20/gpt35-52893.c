//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

int main() {
    int n, i, j;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Create an array of processes
    struct process processes[n];

    // Input arrival time, burst time and priority for each process
    for (i = 0; i < n; i++) {
        printf("Enter arrival time of process %d: ", i+1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);

        printf("Enter priority of process %d: ", i+1);
        scanf("%d", &processes[i].priority);
    }

    // Sort processes by arrival time
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                struct process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Initialize completion time of first process
    processes[0].completion_time = processes[0].arrival_time + processes[0].burst_time;

    // Calculate completion time, turnaround time, waiting time and response time for each process using Priority Scheduling algorithm
    for (i = 1; i < n; i++) {
        int highest_priority_process_index = i;
        for (j = i+1; j < n; j++) {
            if (processes[j].arrival_time <= processes[i-1].completion_time && processes[j].priority < processes[highest_priority_process_index].priority) {
                highest_priority_process_index = j;
            }
        }
        struct process temp = processes[i];
        processes[i] = processes[highest_priority_process_index];
        processes[highest_priority_process_index] = temp;

        processes[i].completion_time = processes[i-1].completion_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        processes[i].response_time = processes[i].completion_time - processes[i].arrival_time;
    }

    // Calculate average turnaround time, waiting time and response time
    float avg_turnaround_time = 0, avg_waiting_time = 0, avg_response_time = 0;
    for (i = 0; i < n; i++) {
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
        avg_response_time += processes[i].response_time;
    }
    avg_turnaround_time /= n;
    avg_waiting_time /= n;
    avg_response_time /= n;

    // Print Gantt chart
    printf("\nGantt chart:\n");
    printf("|");
    for (i = 0; i < n; i++) {
        for (j = 0; j < processes[i].burst_time; j++) {
            printf(" ");
        }
        printf("|");
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d", processes[i].completion_time);
        for (j = 0; j < processes[i].burst_time-1; j++) {
            printf(" ");
        }
    }
    printf("%d\n", processes[n-1].completion_time);

    // Print process table
    printf("\nProcess table:\n");
    printf("+-----+---------------+-------------+-----------------+-----------------+---------------+\n");
    printf("| PID | Arrival Time | Burst Time  | Completion Time | Turnaround Time | Waiting Time |\n");
    printf("+-----+---------------+-------------+-----------------+-----------------+---------------+\n");
    for (i = 0; i < n; i++) {
        printf("| P%-2d |       %-2d      |       %-2d      |       %-2d         |       %-2d         |       %-2d      |\n",
            processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time,
            processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("+-----+---------------+-------------+-----------------+-----------------+---------------+\n");

    // Print average turnaround time, waiting time and response time
    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);
    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Response Time: %.2f\n", avg_response_time);

    return 0;
}