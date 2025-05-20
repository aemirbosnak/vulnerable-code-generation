//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

struct process {
    int pid;                // Process ID
    int arrival_time;       // Time at which process arrives in the ready queue
    int burst_time;         // Time required by process for CPU execution
    int waiting_time;       // Time spent by process waiting in the ready queue
    int turnaround_time;    // Total time taken by process for execution
    int completion_time;    // Time at which process completes execution
};

void round_robin(struct process p[], int n, int quantum);
void print_gantt_chart(struct process p[], int n);

int main() {
    int n, quantum;
    printf("Enter number of processes(maximum %d): ", MAX_PROCESS);
    scanf("%d", &n);

    // Input the process details
    struct process p[MAX_PROCESS];
    printf("Enter details of %d processes:\n", n);
    for(int i=0; i<n; i++) {
        p[i].pid = i+1;

        printf("Arrival Time of Process %d: ", p[i].pid);
        scanf("%d", &p[i].arrival_time);

        printf("Burst Time of Process %d: ", p[i].pid);
        scanf("%d", &p[i].burst_time);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    // Scheduling the processes using Round Robin Algorithm
    round_robin(p, n, quantum);

    // Printing the Gantt Chart
    print_gantt_chart(p, n);

    return 0;
}

// Function to perform CPU scheduling using Round Robin Algorithm
void round_robin(struct process p[], int n, int quantum) {
    int time = 0, remaining_time[n];
    int flag, total_waiting_time = 0, total_turnaround_time = 0;

    for(int i=0; i<n; i++)
        remaining_time[i] = p[i].burst_time;

    while(1) {
        flag = 1;
        for(int i=0; i<n; i++) {
            if(remaining_time[i] > 0) {
                flag = 0;

                if(remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                }
                else {
                    time += remaining_time[i];
                    p[i].completion_time = time;
                    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if(flag == 1)
            break;
    }
}

// Function to print the Gantt Chart
void print_gantt_chart(struct process p[], int n) {
    // Finding the total time taken by all processes for execution
    int total_time = p[0].arrival_time;
    for(int i=0; i<n; i++)
        total_time += p[i].burst_time;

    // Printing the Gantt Chart
    printf("\nGantt Chart:\n");
    for(int i=0; i<total_time; i++)
        printf("-");
    printf("\n| ");
    for(int i=0; i<n; i++) {
        for(int j=0; j<p[i].burst_time; j++) {
            printf("P%d", p[i].pid);
        }
        printf(" | ");
    }
    printf("\n");
    for(int i=0; i<total_time; i++)
        printf("-");

    // Printing the Process Table
    printf("\n\nProcess Table:\n");
    printf("+-----+------------+--------------+-----------------+-----------------+-----------------+\n");
    printf("| PID | Arrival Time | Burst Time | Waiting Time | Turnaround Time | Completion Time |\n");
    printf("+-----+------------+--------------+-----------------+-----------------+-----------------+\n");
    for(int i=0; i<n; i++) {
        printf("| P%d ", p[i].pid);
        printf("|      %2d      ", p[i].arrival_time);
        printf("|      %2d     ", p[i].burst_time);
        printf("|        %2d       ", p[i].waiting_time);
        printf("|         %2d        ", p[i].turnaround_time);
        printf("|         %2d        ", p[i].completion_time);
        printf("|\n");
    }
    printf("+-----+------------+--------------+-----------------+-----------------+-----------------+\n");
}