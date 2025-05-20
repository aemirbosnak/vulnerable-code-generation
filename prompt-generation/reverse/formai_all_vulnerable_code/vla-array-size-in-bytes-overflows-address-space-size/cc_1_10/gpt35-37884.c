//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: safe
#include<stdio.h>
#include<stdlib.h>

struct Process{
    int pid;
    int burst_time;
    int arrival_time;
    int wait_time;
    int turnaround_time;
    int remaining_time;
};

void FCFS(struct Process *pro, int n){
    int t=0,wait_sum=0,turnaround_sum=0,i;

    printf("\nFCFS CPU Scheduling\n\n");

    printf("Process\tBurst time\tArrival time\tTurnaround time\tWaiting time\n");
    for(i=0;i<n;i++){
        pro[i].wait_time=t-pro[i].arrival_time;
        if(pro[i].wait_time<0) pro[i].wait_time=0;
        pro[i].turnaround_time=pro[i].wait_time+pro[i].burst_time;
        pro[i].remaining_time=0;
        wait_sum+=pro[i].wait_time;
        turnaround_sum+=pro[i].turnaround_time;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
        pro[i].pid,pro[i].burst_time,pro[i].arrival_time,pro[i].turnaround_time,pro[i].wait_time);

        t+=pro[i].burst_time;
    }
    printf("\nAverage Wait Time : %f",wait_sum*1.0/n);
    printf("\nAverage Turnaround Time : %f\n\n",turnaround_sum*1.0/n);
}

void SJF(struct Process *pro, int n){
    int t=0,wait_sum=0,turnaround_sum=0,i,j;
    struct Process temp;

    printf("\nSJF CPU Scheduling\n\n");

    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            if(pro[j].burst_time>pro[j+1].burst_time){
                temp=pro[j];
                pro[j]=pro[j+1];
                pro[j+1]=temp;
            }
        }
    }

    printf("Process\tBurst time\tArrival time\tTurnaround time\tWaiting time\n");

    for(i=0;i<n;i++){
        pro[i].wait_time=t-pro[i].arrival_time;
        if(pro[i].wait_time<0) pro[i].wait_time=0;
        pro[i].turnaround_time=pro[i].wait_time+pro[i].burst_time;
        pro[i].remaining_time=0;
        wait_sum+=pro[i].wait_time;
        turnaround_sum+=pro[i].turnaround_time;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
        pro[i].pid,pro[i].burst_time,pro[i].arrival_time,pro[i].turnaround_time,pro[i].wait_time);

        t+=pro[i].burst_time;
    }

    printf("\nAverage Wait Time : %f",wait_sum*1.0/n);
    printf("\nAverage Turnaround Time : %f\n\n",turnaround_sum*1.0/n);
}

int main(){
    int n,i;

    printf("Enter the number of Processes : ");
    scanf("%d",&n);

    struct Process pro[n];

    printf("\nEnter Burst Time and Arrival Time for each Process.\n\n");

    for(i=0;i<n;i++){
        printf("Process %d\n",i+1);

        printf("Burst Time : ");
        scanf("%d",&pro[i].burst_time);

        printf("Arrival Time : ");
        scanf("%d",&pro[i].arrival_time);

        pro[i].pid=i+1;
    }

    FCFS(pro,n);

    SJF(pro,n);

    return 0;
}