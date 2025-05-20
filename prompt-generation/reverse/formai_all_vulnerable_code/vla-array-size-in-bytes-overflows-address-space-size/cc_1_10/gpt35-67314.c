//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// The brave scheduling algorithm
void brave_scheduling(int burst_time[], int arrival_time[], int n)
{
    int waiting_time[n], turnaround_time[n], completion_time[n], avg_wait_time = 0, avg_turnaround_time = 0;
    int remaining_burst_time[n];
    int time = 0;
    int shortest = 0, flag = 0, remain = n;
  
    // Copying burst time into remaining_burst_time array
    for(int i = 0; i < n; i++)
        remaining_burst_time[i] = burst_time[i];
  
    // Running the brave algorithm until all processes complete execution
    while(remain != 0) {
        // Find process with shortest remaining burst time
        for(int i = 0; i < n; i++) {
            if(arrival_time[i] <= time && remaining_burst_time[i] < remaining_burst_time[shortest] && remaining_burst_time[i] > 0)
                shortest = i, flag = 1;
        }
  
        // No process found, increment time
        if(flag == 0) {
            time++;
            continue;
        }
  
        // Decrement remaining burst time
        remaining_burst_time[shortest]--;
  
        // Update shortest process
        shortest = (remaining_burst_time[shortest] == 0) ? ((shortest + 1) % n) : shortest;

        // If process completes execution
        if(remaining_burst_time[shortest] == 0) {
            remain--;
            completion_time[shortest] = time + 1;
            turnaround_time[shortest] = completion_time[shortest] - arrival_time[shortest];
            waiting_time[shortest] = turnaround_time[shortest] - burst_time[shortest];
            avg_turnaround_time += turnaround_time[shortest];
            avg_wait_time += waiting_time[shortest];
        }

        // Increment time
        time++;
    }
  
    // Printing process details
    printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i], completion_time[i]);
 
    // Printing average waiting time and average turnaround time
    printf("\nAverage Waiting Time: %f", (float)avg_wait_time / n);
    printf("\nAverage Turnaround Time: %f\n", (float)avg_turnaround_time / n);
}
 
int main()
{
    int n, bt[20], at[20];

    printf("Enter the number of processes: ");
    scanf("%d", &n);
  
    printf("\nEnter the Arrival time for each process:\n");
    for(int i = 0; i < n; i++) {
        printf("Arrival time of process %d: ", i+1);
        scanf("%d", &at[i]);
    }

    printf("\nEnter the Burst time for each process:\n");
    for(int i = 0; i < n; i++) {
        printf("Burst time of process %d: ", i+1);
        scanf("%d", &bt[i]);
    }

    brave_scheduling(bt, at, n);
  
    return 0;
}