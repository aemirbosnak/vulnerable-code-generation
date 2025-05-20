//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

void calculateWaitTime(struct Process proc[], int n, int quantum, int wait_time[]) {
    int rem_time[n];
    for (int i = 0; i < n; i++) {
        rem_time[i] = proc[i].burst_time;
    }

    int t = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_time[i] > 0) {
                done = 0;
                if (rem_time[i] > quantum) {
                    t += quantum;
                    rem_time[i] -= quantum;
                } else {
                    t = t + rem_time[i];
                    wait_time[i] = t - proc[i].burst_time;
                    rem_time[i] = 0;
                }
            }
        }
        if (done == 1) break; // all processes are done
    }
}

void calculateTurnAroundTime(struct Process proc[], int n, int wait_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = proc[i].burst_time + wait_time[i];
    }
}

void roundRobin(struct Process proc[], int n, int quantum) {
    int wait_time[MAX_PROCESSES];
    int turnaround_time[MAX_PROCESSES];

    calculateWaitTime(proc, n, quantum, wait_time);
    calculateTurnAroundTime(proc, n, wait_time, turnaround_time);
    
    printf("\nCheerful CPU Scheduling Results:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("   %d\t\t   %d\t\t   %d\t\t\t%d\n",
               proc[i].id,
               proc[i].burst_time,
               wait_time[i],
               turnaround_time[i]);
    }
}

int main() {
    printf("🎉 Welcome to the Cheerful CPU Scheduling Simulator! 🎉\n");
    struct Process proc[MAX_PROCESSES];
    int n, quantum;

    // User input for processes and quantum
    printf("How many processes do you want to schedule? (Max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    if (n > MAX_PROCESSES) {
        printf("👎 Oops! Too many processes! Let's stick to %d.\n", MAX_PROCESSES);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1; // Assigning process IDs
        printf("🎈 Enter burst time for Process %d: ", proc[i].id);
        scanf("%d", &proc[i].burst_time);
        proc[i].remaining_time = proc[i].burst_time; // Initializing remaining time
    }

    printf("🎈 Now, enter the time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);

    // Execute Round Robin Scheduling
    roundRobin(proc, n, quantum);

    printf("🌟 Thanks for using our CPU Scheduling Simulator! 🌟\n");
    return 0;
}