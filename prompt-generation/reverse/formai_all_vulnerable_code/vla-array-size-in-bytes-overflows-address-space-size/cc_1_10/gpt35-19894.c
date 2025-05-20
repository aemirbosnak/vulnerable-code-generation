//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid; // process id
    int burst_time; // burst time
    int arrival_time; // arrival time
    int completion_time; // completion time
    int waiting_time; // waiting time
    int turnaround_time; // turnaround time
    int priority;
    int executed; // check if process has executed or not
};

void FCFS (struct Process arr[], int n) {
    int time = 0;
    float avg_wait_time = 0, avg_turnaround_time = 0;

    printf("\nFIRST COME FIRST SERVE (FCFS)\n");
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");

    for (int i = 0; i < n; i++) {
        time += arr[i].burst_time;
        arr[i].completion_time = time;
        arr[i].turnaround_time = arr[i].completion_time - arr[i].arrival_time;
        arr[i].waiting_time = arr[i].turnaround_time - arr[i].burst_time;

        avg_wait_time += arr[i].waiting_time;
        avg_turnaround_time += arr[i].turnaround_time;

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", arr[i].pid, arr[i].burst_time, arr[i].arrival_time, arr[i].waiting_time, arr[i].turnaround_time, arr[i].completion_time);
    }

    avg_wait_time /= n;
    avg_turnaround_time /= n;
    printf("\nAverage Waiting Time: %.2f", avg_wait_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
}

void SJF (struct Process arr[], int n) {
    int time = 0, min, current;
    float avg_wait_time = 0, avg_turnaround_time = 0;

    printf("\nSHORTEST JOB FIRST (SJF)\n");
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");

    for (int i = 0; i < n; i++) {
        min = 999;
        for (int j = 0; j < n; j++) {
            if (arr[j].arrival_time <= time && arr[j].executed == 0 && arr[j].burst_time < min) {
                min = arr[j].burst_time;
                current = j;
            }
        }
        arr[current].completion_time = time + arr[current].burst_time;
        arr[current].turnaround_time = arr[current].completion_time - arr[current].arrival_time;
        arr[current].waiting_time = arr[current].turnaround_time - arr[current].burst_time;

        avg_wait_time += arr[current].waiting_time;
        avg_turnaround_time += arr[current].turnaround_time;

        arr[current].executed = 1;
        time = arr[current].completion_time;

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", arr[current].pid, arr[current].burst_time, arr[current].arrival_time, arr[current].waiting_time, arr[current].turnaround_time, arr[current].completion_time);
    }

    avg_wait_time /= n;
    avg_turnaround_time /= n;
    printf("\nAverage Waiting Time: %.2f", avg_wait_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
}

void PriorityScheduling (struct Process arr[], int n) {
    int time = 0, min, current;
    float avg_wait_time = 0, avg_turnaround_time = 0;

    printf("\nPRIORITY SCHEDULING\n");
    printf("\nProcess\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\tCompletion Time\n");

    for (int i = 0; i < n; i++) {
        min = 999;
        for (int j = 0; j < n; j++) {
            if (arr[j].arrival_time <= time && arr[j].executed == 0 && arr[j].priority < min) {
                min = arr[j].priority;
                current = j;
            }
        }
        arr[current].completion_time = time + arr[current].burst_time;
        arr[current].turnaround_time = arr[current].completion_time - arr[current].arrival_time;
        arr[current].waiting_time = arr[current].turnaround_time - arr[current].burst_time;

        avg_wait_time += arr[current].waiting_time;
        avg_turnaround_time += arr[current].turnaround_time;

        arr[current].executed = 1;
        time = arr[current].completion_time;

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", arr[current].pid, arr[current].burst_time, arr[current].arrival_time, arr[current].priority, arr[current].waiting_time, arr[current].turnaround_time, arr[current].completion_time);
    }

    avg_wait_time /= n;
    avg_turnaround_time /= n;
    printf("\nAverage Waiting Time: %.2f", avg_wait_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main () {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process arr[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter the burst time of process %d: ", i+1);
        scanf("%d", &arr[i].burst_time);
        printf("Enter the arrival time of process %d: ", i+1);
        scanf("%d", &arr[i].arrival_time);
        printf("Enter the priority of process %d: ", i+1);
        scanf("%d", &arr[i].priority);
        arr[i].pid = i + 1;
        arr[i].executed = 0;
    }

    printf("\nProcesses before scheduling:\n");
    printf("\nProcess\tBurst Time\tArrival Time\tPriority\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", arr[i].pid, arr[i].burst_time, arr[i].arrival_time, arr[i].priority);
    }

    FCFS(arr, n);
    for (int i = 0; i < n; i++) {
        arr[i].executed = 0;
    }
    SJF(arr, n);
    for (int i = 0; i < n; i++) {
        arr[i].executed = 0;
    }
    PriorityScheduling(arr, n);

    return 0;
}