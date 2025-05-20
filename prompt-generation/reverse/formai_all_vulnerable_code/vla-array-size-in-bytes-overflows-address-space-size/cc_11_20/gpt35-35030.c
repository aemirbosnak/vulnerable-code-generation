//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: real-life
#include<stdio.h>
#include<stdlib.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int remaining_time;
};

int main() {
    int n,i,j;
    float avg_turnaround_time=0.0;
    float avg_waiting_time=0.0;
    printf("Enter the total number of processes: ");
    scanf("%d",&n);
    struct Process p[n],temp;
    for(i=0;i<n;i++) {
        printf("Enter the arrival time and burst time for process %d: ",i+1);
        scanf("%d%d",&p[i].arrival_time,&p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
        p[i].pid = i+1;
    }
    //Implementation of SJF algorithm
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if(p[i].arrival_time > p[j].arrival_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    int t=0;
    int completed =0;
    int min_burst_time = 9999;
    int min_burst_index =-1;
    while(completed!=n) {
        min_burst_time = 9999;
        min_burst_index =-1;
        for(i=0;i<n;i++) {
            if(p[i].arrival_time <= t && p[i].remaining_time<min_burst_time && p[i].remaining_time>0) {
                min_burst_time = p[i].remaining_time;
                min_burst_index = i;
            }
        }
        if(min_burst_index == -1) {
            t++;
            continue;
        }
        else {
            p[min_burst_index].remaining_time--;
            if(p[min_burst_index].remaining_time == 0) {
                completed++;
                p[min_burst_index].completion_time = t+1;
                p[min_burst_index].turnaround_time = p[min_burst_index].completion_time - p[min_burst_index].arrival_time;
                p[min_burst_index].waiting_time = p[min_burst_index].turnaround_time - p[min_burst_index].burst_time;
                avg_turnaround_time += p[min_burst_index].turnaround_time;
                avg_waiting_time += p[min_burst_index].waiting_time;
            }
            t++;
        }
    }
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(i=0;i<n;i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].completion_time,p[i].turnaround_time,p[i].waiting_time);
    }
    printf("Average turnaround time = %.2f\n",avg_turnaround_time/n);
    printf("Average waiting time = %.2f\n",avg_waiting_time/n);

    return 0;
}