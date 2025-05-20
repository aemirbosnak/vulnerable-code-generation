//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int id; // Process ID
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turn_around_time;
} Process;

void findWaitingTimeFCFS(Process proc[], int n) {
    proc[0].waiting_time = 0;

    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
    }
}

void findTurnAroundTimeFCFS(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turn_around_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void findWaitingTimeSJF(Process proc[], int n) {
    int complete = 0, t = 0, min_index;
    while (complete != n) {
        min_index = -1;
        for (int i = 0; i < n; i++) {
            if (proc[i].arrival_time <= t && (min_index == -1 || proc[i].burst_time < proc[min_index].burst_time) && proc[i].burst_time > 0) {
                min_index = i;
            }
        }

        if (min_index != -1) {
            t += proc[min_index].burst_time;
            proc[min_index].burst_time = 0;
            proc[min_index].waiting_time = t - proc[min_index].arrival_time;
            complete++;
        } else {
            t++;
        }
    }
}

void findTurnAroundTimeSJF(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turn_around_time = proc[i].waiting_time + proc[i].burst_time;
    }
}

void findWaitingTimeRR(Process proc[], int n, int quantum) {
    int remaining_burst_time[n];
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = proc[i].burst_time;
        proc[i].waiting_time = 0;
    }

    int complete = 0, t = 0;

    while (complete < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                if (remaining_burst_time[i] > quantum) {
                    t += quantum;
                    remaining_burst_time[i] -= quantum;
                } else {
                    t += remaining_burst_time[i];
                    proc[i].waiting_time += t - proc[i].arrival_time - proc[i].burst_time;
                    remaining_burst_time[i] = 0;
                    complete++;
                }
            }
        }
    }
}

void findTurnAroundTimeRR(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turn_around_time = proc[i].waiting_time + proc[i].burst_time;
    }
}

void printAverageTimes(Process proc[], int n) {
    float total_waiting_time = 0, total_turn_around_time = 0;
    printf("Process ID\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", proc[i].id, proc[i].waiting_time, proc[i].turn_around_time);
        total_waiting_time += proc[i].waiting_time;
        total_turn_around_time += proc[i].turn_around_time;
    }
    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turn Around Time: %.2f\n", total_turn_around_time / n);
}

int main() {
    int n, choice;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    Process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &proc[i].arrival_time, &proc[i].burst_time);
    }

    printf("Choose Scheduling Algorithm:\n1. FCFS\n2. SJF\n3. Round Robin\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // FCFS
            findWaitingTimeFCFS(proc, n);
            findTurnAroundTimeFCFS(proc, n);
            break;

        case 2: // SJF
            findWaitingTimeSJF(proc, n);
            findTurnAroundTimeSJF(proc, n);
            break;

        case 3: // Round Robin
            printf("Enter time quantum: ");
            int quantum;
            scanf("%d", &quantum);
            findWaitingTimeRR(proc, n, quantum);
            findTurnAroundTimeRR(proc, n);
            break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printAverageTimes(proc, n);
    return 0;
}