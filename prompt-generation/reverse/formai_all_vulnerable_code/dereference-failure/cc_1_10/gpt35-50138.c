//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;  // process ID
    int arrival_time;  // process arrival time
    int burst_time;  // process burst or execution time
    int completion_time;  // process completion time
    int turnaround_time;  // process turnaround time
    int waiting_time;  // process waiting time
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process *procs = (struct process*) malloc(n * sizeof(struct process));

    // Taking input from user
    for (int i = 0; i < n; i++) {
        printf("\nEnter the Arrival Time of process[%d]: ", i+1);
        scanf("%d", &procs[i].arrival_time);
        printf("Enter the Burst Time of process [%d]: ", i+1);
        scanf("%d", &procs[i].burst_time);
        procs[i].pid = i + 1;
    }

    // Implementing Shortest Job First Algorithm
    int time = 0;
    for (int i = 0; i < n; i++) {
        int min_burst_time = 9999;
        int index = -1;
        for (int j = 0; j < n; j++) {
            if (procs[j].arrival_time <= time && procs[j].burst_time < min_burst_time && procs[j].completion_time == 0) {
                min_burst_time = procs[j].burst_time;
                index = j;
            }
        }
        if (index != -1) {
            time += procs[index].burst_time;
            procs[index].completion_time = time;
            procs[index].turnaround_time = procs[index].completion_time - procs[index].arrival_time;
            procs[index].waiting_time = procs[index].turnaround_time - procs[index].burst_time;
        }
    }

    // Displaying the result
    printf("\nPID\tARRIVAL\tBURST\tCOMPLETION\tTURNAROUND\tWAITING\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", procs[i].pid, procs[i].arrival_time, procs[i].burst_time, procs[i].completion_time, procs[i].turnaround_time, procs[i].waiting_time);
    }

    free(procs);
    return 0;
}