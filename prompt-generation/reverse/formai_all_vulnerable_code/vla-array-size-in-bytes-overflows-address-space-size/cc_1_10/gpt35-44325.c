//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int start_time;
};

void display(struct process arr[], int n){
    printf("Process ID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",arr[i].pid,arr[i].arrival_time,arr[i].burst_time,arr[i].priority,arr[i].completion_time,arr[i].turnaround_time,arr[i].waiting_time);
    }
}

void sort(struct process arr[], int n){
    struct process temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i].arrival_time > arr[j].arrival_time){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else if(arr[i].arrival_time == arr[j].arrival_time){
                if(arr[i].priority < arr[j].priority){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

void findCompletionTime(struct process arr[], int n){
    int time = 0;
    for(int i=0;i<n;i++){
        arr[i].start_time = time;
        arr[i].completion_time = time + arr[i].burst_time;
        time = arr[i].completion_time;
    }
}

void findTurnaroundTime(struct process arr[], int n){
    for(int i=0;i<n;i++){
        arr[i].turnaround_time = arr[i].completion_time - arr[i].arrival_time;
    }
}

void findWaitingTime(struct process arr[], int n){
    for(int i=0;i<n;i++){
        arr[i].waiting_time = arr[i].turnaround_time - arr[i].burst_time;
    }
}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++){
        printf("Enter the arrival time of process %d: ",i+1);
        scanf("%d",&p[i].arrival_time);
        printf("Enter the burst time of process %d: ",i+1);
        scanf("%d",&p[i].burst_time);
        printf("Enter the priority of process %d: ",i+1);
        scanf("%d",&p[i].priority);
        p[i].pid = i + 1;
    }
    sort(p,n);
    findCompletionTime(p,n);
    findTurnaroundTime(p,n);
    findWaitingTime(p,n);
    display(p,n);
    return 0;
}