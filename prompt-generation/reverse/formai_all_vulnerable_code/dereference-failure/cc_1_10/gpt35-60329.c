//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>

// Struct for storing process information
struct process
{
    int pid,arrival_time,burst_time,remaining_time,start_time,completion_time,turnaround_time,waiting_time;
};

// Function to sort the processes by their arrival time
void sort_processes_by_arrival_time(struct process *p,int n)
{
    struct process temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].arrival_time>p[j+1].arrival_time)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

// Function to implement Round Robin CPU scheduling algorithm
void round_robin_scheduling(struct process *p,int n,int quantum)
{
    int current_time=0;
    int i=0;
    while(i<n)
    {
        if(p[i].remaining_time<=quantum && p[i].remaining_time>0)
        {
            current_time+=p[i].remaining_time;
            p[i].remaining_time=0;
            p[i].completion_time=current_time;
            p[i].turnaround_time=p[i].completion_time-p[i].arrival_time;
            p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;
            i++;
        }
        else if(p[i].remaining_time>0)
        {
            current_time+=quantum;
            p[i].remaining_time-=quantum;
            for(int j=i+1;j<n;j++)
            {
                if(p[j].arrival_time<=current_time)
                {
                    i=j;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            i++;
        }
    }
}

// Function to calculate average waiting time and average turnaround time
void calculate_average_times(struct process *p,int n,float *avg_waiting_time,float *avg_turnaround_time)
{
    float total_waiting_time=0,total_turnaround_time=0;
    for(int i=0;i<n;i++)
    {
        total_waiting_time+=p[i].waiting_time;
        total_turnaround_time+=p[i].turnaround_time;
    }
    *avg_waiting_time=total_waiting_time/n;
    *avg_turnaround_time=total_turnaround_time/n;
}

int main()
{
    int n,quantum;
    float avg_waiting_time,avg_turnaround_time;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct process *p=(struct process *)malloc(n*sizeof(struct process));
    printf("Enter the arrival time and burst time of each process:\n");
    for(int i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("Process %d: ",p[i].pid);
        scanf("%d %d",&p[i].arrival_time,&p[i].burst_time);
        p[i].remaining_time=p[i].burst_time;
    }
    printf("\nEnter the time quantum: ");
    scanf("%d",&quantum);
    sort_processes_by_arrival_time(p,n);
    round_robin_scheduling(p,n,quantum);
    calculate_average_times(p,n,&avg_waiting_time,&avg_turnaround_time);
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].completion_time,p[i].turnaround_time,p[i].waiting_time);
    }
    printf("Average Waiting Time: %.2f\n",avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n",avg_turnaround_time);
    free(p);
    return 0;
}