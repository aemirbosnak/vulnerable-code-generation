//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int *burst_time = malloc(n * sizeof(int));
    printf("Enter the burst time for each process:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    int *waiting_time = calloc(n, sizeof(int));
    int *turnaround_time = calloc(n, sizeof(int));
    int remaining_time[n];
    for(int i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
    }

    int current_time = 0;
    while(1) {
        int done = 1;
        for(int i = 0; i < n; i++) {
            if(remaining_time[i] > 0) {
                done = 0;
                if(remaining_time[i] > time_quantum) {
                    current_time += time_quantum;
                    remaining_time[i] -= time_quantum;
                }
                else {
                    current_time += remaining_time[i];
                    waiting_time[i] = current_time - burst_time[i];
                    remaining_time[i] = 0;
                    turnaround_time[i] = current_time;
                }
            }
        }
        if(done == 1) break;
    }

    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time/n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time/n);

    free(burst_time);
    free(waiting_time);
    free(turnaround_time);

    return 0;
}