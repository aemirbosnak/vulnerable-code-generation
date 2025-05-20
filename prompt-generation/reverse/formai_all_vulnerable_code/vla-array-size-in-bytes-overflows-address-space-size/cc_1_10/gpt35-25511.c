//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

struct process {
    int p_id;  // process ID
    int arrival_time;  // Arrival Time
    int burst_time;  // Burst Time
    int priority;  // Priority
    int waiting_time;  // Waiting Time
    int turnaround_time;  // Turnaround Time
};

// Function to find the waiting time for all processes
void find_waiting_time(struct process proc[], int n, int wt[])
{
    int rt[n];
    // Copy the burst time into rt[]
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].burst_time;
     
    int complete = 0, t = 0, minm = 99999999;
    int shortest = 0, finish_time;
    int check = 0;
    // Process until all processes are complete
    while (complete != n) {
        // Find process with the smallest burst time and highest priority
        for (int j = 0; j < n; j++) {
            if ((proc[j].arrival_time <= t) &&
            (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }
 
        if (check == 0) {
            t++;
            continue;
        }
 
        // Decrease remaining time by one
        rt[shortest]--;
 
        // Update minimum
        minm = rt[shortest];
        if (minm == 0)
            minm = 99999999;

        // If process is complete
        if (rt[shortest] == 0) {
            // Increment complete
            complete++;
            // Set finish time
            finish_time = t + 1;
            // Calculate waiting time
            proc[shortest].waiting_time = finish_time -
            proc[shortest].burst_time - proc[shortest].arrival_time;
            if (proc[shortest].waiting_time < 0)
                proc[shortest].waiting_time = 0;
        }
        // Move to next second
        t++;
    }

}

// Function to find the turnaround time for all processes
void find_turnaround_time(struct process proc[], int n, int wt[], int tat[])
{
    // Calculate turnaround time by adding burst time and waiting time
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].burst_time + wt[i];
}

// Function to calculate average waiting time and average turnaround time
void find_avg_time(struct process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0,
    total_tat = 0;
    
    // Find waiting time for each process
    find_waiting_time(proc, n, wt);
    
    // Find turnaround time for each process
    find_turnaround_time(proc, n, wt, tat);
    printf("Processes  Arrival Time  Burst Time  Priority  Waiting Time  Turnaround Time\n");
    // Calculate and display the results
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + proc[i].waiting_time;
        total_tat = total_tat + tat[i];
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d\n", proc[i].p_id, proc[i].arrival_time, proc[i].burst_time, proc[i].priority, proc[i].waiting_time, tat[i]);
    }
    printf("Average waiting time = %f", (float)total_wt / (float)n);
    printf("\nAverage turnaround time = %f", (float)total_tat / (float)n);
}

// Main function
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Dynamically allocate memory for processes array
    struct process *proc = malloc(n * sizeof(struct process));

    // Get input from user
    printf("Enter the arrival time, burst time and priority for each process:\n");
    for(int i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d %d", &proc[i].arrival_time, &proc[i].burst_time, &proc[i].priority);
        proc[i].p_id = i+1;
    }

    // Sort processes by arrival time
    int i, j;
    struct process temp;
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(proc[j].arrival_time > proc[j+1].arrival_time) {
                temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }

    // Call the function to calculate average waiting time and average turnaround time
    find_avg_time(proc, n);
    
    return 0;
}