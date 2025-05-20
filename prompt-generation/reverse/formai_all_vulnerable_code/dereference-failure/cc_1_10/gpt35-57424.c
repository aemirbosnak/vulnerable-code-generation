//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

//Structure to hold process parameters
struct Process{
    int process_no;
    int burst_time;
    int arrival_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int response_time;
    int priority;
    int remaining_time;
};

//Function to sort processes based on arrival time or priority depending on 'choice'
void sort_processes(struct Process *processes, int n, int choice){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(choice==1){
                if(processes[j].arrival_time>processes[j+1].arrival_time){
                    struct Process temp=processes[j];
                    processes[j]=processes[j+1];
                    processes[j+1]=temp;
                }
            }
            else if(choice==2){
                if(processes[j].priority<processes[j+1].priority){
                    struct Process temp=processes[j];
                    processes[j]=processes[j+1];
                    processes[j+1]=temp;
                }
            }
        }
    }
}

//Function to implement Round Robin CPU Scheduling Algorithm
void round_robin(struct Process *processes, int n, int quantum){
    int time=0;
    int completed=n;
    while(completed>0){
        for(int i=0;i<n;i++){
            if(processes[i].remaining_time>0){
                if(processes[i].remaining_time>quantum){
                    time+=quantum;
                    processes[i].remaining_time-=quantum;
                }
                else{
                    time+=processes[i].remaining_time;
                    processes[i].completion_time=time;
                    processes[i].turn_around_time=processes[i].completion_time-processes[i].arrival_time;
                    processes[i].waiting_time=processes[i].turn_around_time-processes[i].burst_time;
                    processes[i].response_time=processes[i].completion_time-processes[i].burst_time;
                    processes[i].remaining_time=0;
                    completed--;
                }
            }
        }
    }
}

//Function to implement Priority CPU Scheduling Algorithm
void priority_scheduling(struct Process *processes, int n){
    int time=0;
    int completed=n;
    while(completed>0){
        sort_processes(processes, n, 2);
        for(int i=0;i<n;i++){
            if(processes[i].arrival_time<=time && processes[i].remaining_time>0){
                time+=processes[i].burst_time;
                processes[i].completion_time=time;
                processes[i].turn_around_time=processes[i].completion_time-processes[i].arrival_time;
                processes[i].waiting_time=processes[i].turn_around_time-processes[i].burst_time;
                processes[i].response_time=processes[i].completion_time-processes[i].burst_time;
                processes[i].remaining_time=0;
                completed--;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    struct Process *processes=(struct Process*)malloc(n*sizeof(struct Process));

    for(int i=0;i<n;i++){
        printf("Enter the burst time and arrival time for process %d:\n",i+1);
        scanf("%d%d",&processes[i].burst_time,&processes[i].arrival_time);
        processes[i].process_no=i+1;
        processes[i].priority=0;
        processes[i].remaining_time=processes[i].burst_time;
    }

    printf("Choose CPU Scheduling Algorithm:\n");
    printf("1. Round Robin\n2. Priority\n");
    int choice;
    scanf("%d",&choice);

    if(choice==1){
        int quantum;
        printf("Enter the quantum time: ");
        scanf("%d",&quantum);
        round_robin(processes, n, quantum);
    }
    else{
        for(int i=0;i<n;i++){
            printf("Enter the priority for process %d:\n",i+1);
            scanf("%d",&processes[i].priority);
        }
        priority_scheduling(processes, n);
    }

    printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tTurn Around Time\tWaiting Time\tResponse Time\tPriority\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\t\t%d\n",processes[i].process_no,processes[i].burst_time,processes[i].arrival_time,processes[i].completion_time,processes[i].turn_around_time,processes[i].waiting_time,processes[i].response_time,processes[i].priority);
    }

    free(processes);
    return 0;
}