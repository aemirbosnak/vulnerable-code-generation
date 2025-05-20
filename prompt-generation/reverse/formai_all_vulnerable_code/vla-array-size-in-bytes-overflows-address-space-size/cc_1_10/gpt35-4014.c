//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n], remaining_time[n];
    bool is_completed[n];

    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        printf("Enter Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst Time: ");
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
        is_completed[i] = false;
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &time_quantum);

    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    printf("\nGantt Chart:\n");

    while (true) {
        bool is_any_completed = false;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                is_any_completed = true;

                if (remaining_time[i] > time_quantum) {
                    current_time += time_quantum;
                    remaining_time[i] -= time_quantum;
                    printf("P%d (%d-%d) ", i+1, current_time-time_quantum, current_time);
                } else {
                    current_time += remaining_time[i];
                    printf("P%d (%d-%d) ", i+1, current_time-remaining_time[i], current_time);
                    is_completed[i] = true;
                    remaining_time[i] = 0;
                    total_waiting_time += current_time - arrival_time[i] - burst_time[i];
                    total_turnaround_time += current_time - arrival_time[i];
                }
            }
        }

        if (!is_any_completed) {
            break;
        }
    }

    printf("\n\nAverage Waiting Time: %.2f", (float)total_waiting_time/n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_turnaround_time/n);

    return 0;
}