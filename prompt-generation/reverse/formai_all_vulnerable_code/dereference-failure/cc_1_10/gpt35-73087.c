//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

struct Process{
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void fcfs(struct Process *processes, int n){
    printf("\nFirst Come First Serve Policy:\n");

    float avg_waiting_time=0, avg_turnaround_time=0;

    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    for(int i=1; i<n; i++){
        processes[i].waiting_time = processes[i-1].turnaround_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    for(int i=0; i<n; i++){
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(int i=0; i<n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
}

void sjf(struct Process *processes, int n){
    printf("\nShortest Job First Policy:\n");

    int completed_processes=0, time=0, min_burst_time=99999, min_index=-1;
    float avg_waiting_time=0, avg_turnaround_time=0;

    while(completed_processes < n){
        for(int i=0; i<n; i++){
            if(processes[i].arrival_time <= time && processes[i].burst_time < min_burst_time && processes[i].burst_time > 0){
                min_index = i;
                min_burst_time = processes[i].burst_time;
            }
        }

        if(min_index == -1){
            time++;
            continue;
        }

        processes[min_index].waiting_time = time - processes[min_index].arrival_time;
        processes[min_index].turnaround_time = processes[min_index].waiting_time + processes[min_index].burst_time;

        avg_waiting_time += processes[min_index].waiting_time;
        avg_turnaround_time += processes[min_index].turnaround_time;

        min_burst_time = 99999;
        min_index = -1;

        completed_processes++;
        time++;
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(int i=0; i<n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
}

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process *processes = (struct Process *) malloc(n * sizeof(struct Process));

    for(int i=0; i<n; i++){
        printf("\nEnter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].id = i+1;
    }

    fcfs(processes, n);
    sjf(processes, n);

    return 0;
}