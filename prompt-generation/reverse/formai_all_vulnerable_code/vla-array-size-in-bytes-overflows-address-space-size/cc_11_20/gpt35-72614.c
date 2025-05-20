//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: creative
#include<stdio.h>
#include<stdlib.h>

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

int main() {
    int n, time_slice, total_time = 0, total_waiting_time = 0, total_turnaround_time = 0, completed_processes = 0, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n], temp;

    for(i = 0; i < n; i++) {
        printf("\n--- Process %d ---\n", i + 1);
        printf("Enter the Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].process_id = i + 1;
    }

    printf("\nEnter the time slice: ");
    scanf("%d", &time_slice);

    // Round Robin Algorithm
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(processes[j].arrival_time < processes[i].arrival_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    int remaining_time[n];
    for(i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    int time = processes[0].arrival_time, flag = 0, index = 0;
    while(completed_processes < n) {
        if(flag % time_slice == 0 || remaining_time[index] == 0) {
            index = (index + 1) % n;
        }

        if(remaining_time[index] == 0) {
            index = (index + 1) % n;
            continue;
        }

        if(processes[index].arrival_time <= time) {
            printf("Process %d is executing at time %d\n", processes[index].process_id, time);
            remaining_time[index] -= 1;
            time++;
            if(remaining_time[index] == 0) {
                completed_processes++;
                processes[index].completion_time = time;
                processes[index].waiting_time = processes[index].completion_time - processes[index].burst_time - processes[index].arrival_time;
                processes[index].turnaround_time = processes[index].completion_time - processes[index].arrival_time;
                total_waiting_time += processes[index].waiting_time;
                total_turnaround_time += processes[index].turnaround_time;
            }
        } else {
            printf("Idle at time %d\n", time);
            time++;
        }

        flag++;
    }

    float average_waiting_time = (float)total_waiting_time / n;
    float average_turnaround_time = (float)total_turnaround_time / n;

    printf("\nProcessID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].completion_time);
    }
    printf("\nAverage waiting time: %.2f\n", average_waiting_time);
    printf("Average turnaround time: %.2f\n", average_turnaround_time);

    return 0;
}