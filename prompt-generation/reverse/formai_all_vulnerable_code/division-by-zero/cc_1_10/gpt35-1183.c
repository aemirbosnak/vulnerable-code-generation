//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int burst_time[20], arrival_time[20], waiting_time[20], turnaround_time[20], priority[20], processes[20];
int n;

void roundRobin(int quantum) {
    int runtime = 0, counter = 0, turn_around = 0, waiting = 0, remaining_time[n];
    for(int i=0;i<n;i++)
        remaining_time[i] = burst_time[i]; //Initialize remaining_time
	
    while(1) {
        int flag = 1;
        for(int i=0;i<n;i++) {
            if (remaining_time[i] > 0) {
                flag = 0;
                if (remaining_time[i] > quantum) {
                    runtime += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    runtime += remaining_time[i];
                    waiting += runtime - arrival_time[i] - burst_time[i];
                    turn_around += runtime - arrival_time[i];
                    remaining_time[i] = 0;
                    processes[counter] = i+1;
                    counter++;
                }
            }
        }
        if (flag == 1)
            break;
    }
    printf("\n\tRound Robin Scheduling\n");
    printf("\n\tProcess\tBurst Time\tWaiting Time\tTurn Around Time");
    for(int i = 0; i < counter; i++){
        printf("\n\t%d\t\t%d\t\t%d\t\t%d", processes[i], burst_time[processes[i]-1], waiting_time[processes[i]-1], turnaround_time[processes[i]-1]);
        turn_around += turnaround_time[processes[i]-1];
        waiting += waiting_time[processes[i]-1];
    }
    printf("\n\n\tAverage waiting time = %d",waiting/n);
    printf("\n\tAverage Turn Around time = %d\n\n",turn_around/n);
}

void fcfs() {
    int waiting = 0, turn_around = 0;
    printf("\n\tFirst Come First Serve Scheduling\n");
	printf("\n\tProcess\tBurst Time\tWaiting Time\tTurn Around Time");
    for(int i=0;i<n;i++) {
        waiting_time[i] = waiting - arrival_time[i];
        turnaround_time[i] = waiting_time[i] + burst_time[i];
        waiting += burst_time[i];
        processes[i] = i+1;
        printf("\n\t%d\t\t%d\t\t%d\t\t%d", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
        turn_around += turnaround_time[i];
    }
    printf("\n\n\tAverage waiting time = %d",waiting/n);
    printf("\n\tAverage Turn Around time = %d\n\n",turn_around/n);
}

void priorityScheduling() {
    int position, swap, waiting = 0, turn_around = 0;
    for(int i=0;i<n;i++){
        position = i;
        for(int j=i+1;j<n;j++) {
            if (priority[j] < priority[position])
                position = j;
        }
        swap = priority[i];
        priority[i] = priority[position];
        priority[position] = swap;
        swap = burst_time[i];
        burst_time[i] = burst_time[position];
        burst_time[position] = swap;
        swap = processes[i];
        processes[i] = processes[position];
        processes[position] = swap;
    }
    printf("\n\tPriority Scheduling\n");
    printf("\n\tProcess\t\tBurst Time\tWaiting Time\tTurn Around Time");
    for(int i = 0 ; i < n; i++){
        waiting_time[i] = waiting;
        waiting += burst_time[i];
        turnaround_time[i] = waiting - arrival_time[i];
        printf("\n\t%d\t\t%d\t\t%d\t\t%d", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
        turn_around += turnaround_time[i];
    }
    printf("\n\n\tAverage waiting time = %d", waiting/n);
    printf("\n\tAverage Turn Around time = %d\n\n", turn_around/n);
}

int main(){
    int choice, quantum = 100;
    printf("\n\n\tEnter the number of processes: ");
    scanf("%d", &n);
    printf("\n\tEnter the burst time of the processes: ");
    for(int i=0;i<n;i++)
        scanf("%d", &burst_time[i]);
    printf("\n\tEnter the arrival time of the processes: ");
    for(int i=0;i<n;i++)
        scanf("%d", &arrival_time[i]);
    printf("\n\tEnter the priority of the processes: ");
    for(int i=0;i<n;i++)
        scanf("%d", &priority[i]);
    printf("\n\n\tSelect the CPU scheduling algorithm\n\t1. Round Robin\t2. First Come First Serve\t3. Priority Scheduling");
    printf("\n\n\tEnter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("\n\tEnter the time quantum: ");
            scanf("%d",&quantum);
            roundRobin(quantum);
            break;
        case 2:
            fcfs();
            break;
        case 3:
            priorityScheduling();
            break;
        default:
            printf("\n\tInvalid choice!");
    }
    return 0;
}