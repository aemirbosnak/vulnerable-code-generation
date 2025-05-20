//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, time_slice, t = 0, total_t=0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int burst_time[n], waiting_time[n], turnaround_time[n], remaining_time[n];
    printf("Enter the Burst time for each process:\n");
    for(i=0;i<n;i++){
        printf("Process %d: ", i+1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }
    printf("Enter the Time Slice: ");
    scanf("%d", &time_slice);
    while(1){
        int flag = 0;
        for(i=0;i<n;i++){
            if (remaining_time[i]>0){
                flag = 1;
                if (remaining_time[i]>time_slice){
                    t += time_slice;
                    remaining_time[i] -= time_slice;
                }
                else{
                    t = t + remaining_time[i];
                    waiting_time[i] = t - burst_time[i];
                    remaining_time[i] = 0;
                }
            }
            total_t++;
        }
        if (flag == 0)
            break;
    }
    for (i=0; i<n; i++){
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
        printf("\nProcess %d: Burst Time: %d \t Waiting Time: %d \t Turnaround Time: %d", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    avg_waiting_time = avg_waiting_time/n;
    avg_turnaround_time = avg_turnaround_time/n;
    printf("\n\nAverage Waiting Time: %f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %f", avg_turnaround_time);
    printf("\nTotal Time Slots: %d", total_t);

    return 0;
}