//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include<stdio.h>

struct process{
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
};

int main(){

    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    struct process p[n];
    int i,j;

    for(i=0;i<n;i++){
        p[i].pid = i+1;
        printf("\nEnter the Arrival Time, Burst Time and Priority for process %d\n",p[i].pid);
        scanf("%d %d %d",&p[i].arrival_time,&p[i].burst_time,&p[i].priority);
        p[i].remaining_time = p[i].burst_time;
    }

    int quantum,remaining_processes=n,total_turnaround_time=0,total_waiting_time=0;

    printf("\nEnter time quantum for Round Robin algorithm: ");
    scanf("%d",&quantum);

    printf("\nProcess Execution order: \n");

    i=0;
    int time=0;

    while(remaining_processes>0){

        if(p[i].remaining_time>0){

            if(p[i].remaining_time<=quantum){

                time += p[i].remaining_time;
                p[i].remaining_time = 0;
            }
            else{

                time += quantum;
                p[i].remaining_time -= quantum;
            }

            printf("P%d ",p[i].pid);
        }

        if(p[i].remaining_time==0){
            remaining_processes--;
            p[i].turnaround_time = time - p[i].arrival_time;
            p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;

            total_turnaround_time += p[i].turnaround_time;
            total_waiting_time += p[i].waiting_time;
        }

        i = (i+1)%n;
    }

    printf("\n\nResults:\n\n");
    printf("Process No.\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for(i=0;i<n;i++){

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].priority,p[i].waiting_time,p[i].turnaround_time);
    }

    float avg_waiting_time,avg_turnaround_time;

    avg_waiting_time = (float)total_waiting_time/(float)n;
    avg_turnaround_time = (float)total_turnaround_time/(float)n;

    printf("\nAverage Waiting Time: %f\n",avg_waiting_time);
    printf("\nAverage Turnaround Time: %f\n",avg_turnaround_time);

    return 0;
}