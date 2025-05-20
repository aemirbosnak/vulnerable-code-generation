//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, burst_time[20], waiting_time[20], turnaround_time[20], average_waiting_time, total_turnaround_time = 0;
    float average_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the burst time for each process:\n");
    for(int i = 0; i < n; i++)
    {
        printf("\nProcess %d: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    //Initializing the clock
    srand(time(NULL));
    int clock = rand() % 5 + 1;

    printf("\nThe clock starts at %d\n", clock);

    //Applying Round Robin scheduling algorithm with variable time quantum
      
    int time_quantum = clock;
    int completed_processes = 0;
    int index = 0;
    
    printf("\nProcesses\tBurst Time\tTurnaround Time\tWaiting Time\n");
    while(completed_processes < n)
    {
        if(burst_time[index] > time_quantum)
        {
            burst_time[index] -= time_quantum;
            clock += time_quantum;
            index = (index + 1) % n;
        }
        
        else if(burst_time[index] == time_quantum)
        {
            burst_time[index] = 0;
            turnaround_time[index] = clock + time_quantum;
            waiting_time[index] = turnaround_time[index] - time_quantum;            
            total_turnaround_time += turnaround_time[index];
            completed_processes++;

            printf("P%d\t\t%d\t\t%d\t\t%d\n", index+1, time_quantum, 
            turnaround_time[index]-clock, waiting_time[index]);

            clock = turnaround_time[index];
            index = (index + 1) % n;
            
        }
        
        else
        {
            clock += burst_time[index];
            completed_processes++;
            turnaround_time[index] = clock;
            waiting_time[index] = turnaround_time[index] - burst_time[index];
            total_turnaround_time += turnaround_time[index];

            printf("P%d\t\t%d\t\t%d\t\t%d\n", index+1, burst_time[index], 
            turnaround_time[index]-clock, waiting_time[index]);

            burst_time[index] = 0;
            index = (index + 1) % n;
        }
    }

    average_turnaround_time = total_turnaround_time / n;
    average_waiting_time = average_turnaround_time - time_quantum;

    printf("\nAverage Waiting Time: %d", average_waiting_time);
    printf("\nAverage Turnaround Time: %0.2f", average_turnaround_time);

    return 0;
}