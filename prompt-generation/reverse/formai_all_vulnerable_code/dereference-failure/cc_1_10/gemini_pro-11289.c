//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Burst time of all processes
int burst_time[100];

// Arrival time of all processes
int arrival_time[100];

// Process ID
int pid[100];

// Total number of processes
int num_processes;

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int at[], int wt[])
{
    // Waiting time for the first process is 0
    wt[0] = 0;

    // Calculating waiting time
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

// Function to calculate turnaround time
void findTurnAroundTime(int processes[], int n, int bt[], int at[], int wt[], int tat[])
{
    // Calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[], int at[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, at, wt);

    // Function to find turnaround time of all processes
    findTurnAroundTime(processes, n, bt, at, wt, tat);

    // Display processes along with all details
    printf("Processes  Burst Time  Arrival Time  Waiting Time  Turnaround Time\n");

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d\t\t  %d\t\t    %d\t\t%d\t\t\t%d\n", processes[i], bt[i], at[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %f\n", (float)total_wt / (float)n);
    printf("Average turnaround time = %f\n", (float)total_tat / (float)n);
}

// Main function
int main()
{
    // Input number of processes
    printf("Enter total number of processes: ");
    scanf("%d", &num_processes);

    // Input burst time
    printf("Enter burst time: ");
    for (int i = 0; i < num_processes; i++)
    {
        scanf("%d", &burst_time[i]);
    }

    // Input arrival time
    printf("Enter arrival time: ");
    for (int i = 0; i < num_processes; i++)
    {
        scanf("%d", &arrival_time[i]);
    }

    // Input process id
    printf("Enter process id: ");
    for (int i = 0; i < num_processes; i++)
    {
        scanf("%d", &pid[i]);
    }

    // Calculate average time
    findavgTime(pid, num_processes, burst_time, arrival_time);
    return 0;
}