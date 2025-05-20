//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include<stdio.h>

struct process{
    int pid;
    int burstTime;
    int priority;
};

void waitingTime(struct process pr[], int n, int wt[]){
    // Initializing waiting time of first process as 0
    wt[0] = 0; 
    
    // Calculate waiting time of other processes
    for (int i = 1; i < n; i++){
        wt[i] = pr[i-1].burstTime + wt[i-1];
    }
}

void turnAroundTime(struct process pr[], int n, int wt[], int tat[]){
    // Calculate turn around time by adding burst time and waiting time
    for (int i = 0; i < n; i++)
     tat[i] = pr[i].burstTime + wt[i];
}

void avgTime(struct process pr[], int n){
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Calculate waiting time of each process
    waitingTime(pr, n, wt);

    // Calculate turn around time of each process
    turnAroundTime(pr, n, wt, tat);

    // Display processes along with their burst time, priority, waiting time, and turnaround time
    printf("PID\tBurst time\tPriority\tWaiting time\tTurnaround time\n");
    for (int i = 0; i < n; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", pr[i].pid, pr[i].burstTime, pr[i].priority, wt[i], tat[i]);
    }

    printf("Average waiting time = %d\n", total_wt/n);
    printf("Average turnaround time = %d", total_tat/n);
}

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process pr[n];

    // Read process details
    for(int i = 0; i < n; i++){
        printf("Enter process %d details:\n", i+1);
        printf("Enter PID: ");
        scanf("%d", &pr[i].pid);

        printf("Enter burst time: ");
        scanf("%d", &pr[i].burstTime);

        printf("Enter priority: ");
        scanf("%d", &pr[i].priority);
    }

    avgTime(pr, n);
    return 0;
}