//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

//Brave style CPU Scheduling Algorithm implementation
int main() {
    int n, i, j, t, burst_time[20], waiting_time[20], turnaround_time[20], avg_wait_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int process_id[n];
    printf("\nEnter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process[%d]: ", i + 1);
        scanf("%d", &burst_time[i]);
        process_id[i] = i + 1;
    }

    //Implementing Brave Style CPU Scheduling Algorithm
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burst_time[i] > burst_time[j]) {
                t = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = t;

                t = process_id[i];
                process_id[i] = process_id[j];
                process_id[j] = t;
            }
        }
    }

    waiting_time[0] = 0;
    for (i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++)
            waiting_time[i] += burst_time[j];

        avg_wait_time += waiting_time[i];
    }

    avg_wait_time /= n;
    printf("\n\n>>>>>>>>>>>>>>>>>> BRAVE STYLE CPU SCHEDULING ALGORITHM  <<<<<<<<<<<<<<<<<<<\n\n");
    printf("Processes\t Burst Time\t Waiting Time\t Turnaround Time\n");

    for (i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
        printf("\n   P%d \t\t   %d \t\t   %d \t\t\t%d", process_id[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    avg_turnaround_time /= n;
    printf("\n\n\tAverage Waiting Time = %d", avg_wait_time);
    printf("\n\tAverage Turnaround Time = %d\n\n", avg_turnaround_time);

    return 0;
}