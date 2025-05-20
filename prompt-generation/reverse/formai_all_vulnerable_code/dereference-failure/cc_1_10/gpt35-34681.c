//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>

// Function to calculate the waiting time
void waiting_time(int arrival_time[], int burst_time[], int n, int waiting[])
{
    int completion_time[n], remaining_burst_time[n];
    int min_arrival = arrival_time[0], total_waiting = 0;

    // Initialize remaining time with burst time
    for(int i=0; i<n; i++)
    {
        remaining_burst_time[i] = burst_time[i];
        
        // Find minimum arrival time
        if(arrival_time[i] < min_arrival)
            min_arrival = arrival_time[i];
    }

    int t = min_arrival;  // Current time
    int complete_count = 0;  // Count of completed processes

    // Loop until all processes are done
    while(complete_count != n)
    {
        // Find process with minimum remaining time
        int min_burst_time = 10000000, min_index = -1;
        for(int i=0; i<n; i++)
        {
            if(arrival_time[i] <= t && remaining_burst_time[i] < min_burst_time && remaining_burst_time[i] > 0)
            {
                min_burst_time = remaining_burst_time[i];
                min_index = i;
            }
        }

        // If there are no processes available at current time, increase time
        if(min_index == -1)
        {
            t++;
            continue;
        }

        // Update remaining time of the process
        remaining_burst_time[min_index]--;

        // If process has completed its execution, find its completion time
        if(remaining_burst_time[min_index] == 0)
        {
            complete_count++;
            completion_time[min_index] = t + 1;
            waiting[min_index] = completion_time[min_index] - arrival_time[min_index] - burst_time[min_index];
            
            // If waiting time is negative, make it 0
            if(waiting[min_index] < 0)
                waiting[min_index] = 0;
            
            total_waiting += waiting[min_index];
        }

        // Increase time
        t++;
    }

    // Print waiting time
    printf("Waiting Time: ");
    for(int i=0; i<n; i++)
        printf("%d ", waiting[i]);
    printf("\nAverage Waiting Time: %f\n", (float)total_waiting/n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input arrival and burst time
    int arrival_time[n], burst_time[n], waiting[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }

    // Calculate waiting time
    waiting_time(arrival_time, burst_time, n, waiting);
    
    return 0;
}