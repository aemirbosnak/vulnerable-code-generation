//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: satisfied
#include <stdio.h>

/* Custom structure to represent a process */
struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority; // lower values indicate higher priority
};

/* Function to swap two processes */
void swap(struct process *a, struct process *b) {
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to perform Bubble Sort on an array of processes based on their arrival time */
void bubbleSort(struct process p[], int n) {
    int i, j;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(p[j].arrival_time > p[j+1].arrival_time) {
                swap(&p[j], &p[j+1]);
            }
        }
    }
}

/* Function to perform Round Robin Scheduling algorithm on an array of processes */
void roundRobin(struct process p[], int n, int time_slice) {
    int i, j, total_time=0, total_burst_time=0, sum=0;
    float avg_wt=0, avg_tt=0;

    printf("\nRound Robin Scheduling:\n\n");
    printf("PID\tBurst Time\tArrival Time\tPriority\n");

    /* Bubble Sort processes based on their arrival time */
    bubbleSort(p, n);

    /* Calculate total burst time */
    for(i=0; i<n; i++) {
        total_burst_time += p[i].burst_time;
    }

    /* Perform Round Robin Scheduling */
    for(i=0; total_burst_time!=0; ) {
        if(p[i].burst_time <= time_slice && p[i].burst_time > 0) {
            printf("P%d\t%3d\t\t%3d\t\t%3d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].priority);
            total_time += p[i].burst_time;
            total_burst_time -= p[i].burst_time;
            sum = 1;
            p[i].burst_time = 0;
        } else if(p[i].burst_time > 0) {
            printf("P%d\t%3d\t\t%3d\t\t%3d\n", p[i].pid, time_slice, p[i].arrival_time, p[i].priority);
            p[i].burst_time -= time_slice;
            total_time += time_slice;
            total_burst_time -= time_slice;
        }

        if(p[i].burst_time == 0 && sum == 1) {
            avg_wt += total_time - p[i].arrival_time - p[i].burst_time;
            avg_tt += total_time - p[i].arrival_time;
            sum = 0;
        }
        if(i == n-1) {
            i = 0;
        }
        else if(p[i+1].arrival_time <= total_time) {
            i++;
        }
        else {
            i = 0;
        }
    }

    avg_wt /= n;
    avg_tt /= n;

    printf("\nAverage Waiting Time = %0.2f\n", avg_wt);
    printf("Average Turnaround Time = %0.2f\n\n", avg_tt);
}

/* Main function */
int main() {
    int i, n, time_slice;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    printf("\nEnter Burst Time, Arrival Time and Priority for each process:\n");
    for(i=0; i<n; i++) {
        printf("\nProcess %d:\n", i+1);
        p[i].pid = i+1;
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
    }

    printf("\nEnter time slice for Round Robin Scheduling: ");
    scanf("%d", &time_slice);

    printf("\n");

    /* Perform Round Robin Scheduling */
    roundRobin(p, n, time_slice);

    return 0;
}