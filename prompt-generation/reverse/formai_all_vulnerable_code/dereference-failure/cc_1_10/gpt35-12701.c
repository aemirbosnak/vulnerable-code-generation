//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

struct process{
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

void fcfs(struct process proc[], int n){
    int i;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = proc[0].arrival_time;
    
    printf("\nExecuting FCFS CPU Scheduling Algorithm");
    
    //calculating completion time, waiting time and turnaround time for all processes
    for(i = 0; i < n; i++){
        if(current_time < proc[i].arrival_time){
            current_time = proc[i].arrival_time;
        }
        
        proc[i].completion_time = current_time + proc[i].burst_time;
        proc[i].waiting_time = current_time - proc[i].arrival_time;
        proc[i].turnaround_time = proc[i].completion_time - proc[i].arrival_time;

        current_time = proc[i].completion_time;
        
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
    }
    
    //calculating average waiting time and average turnaround time
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    
    printf("\n\nProcess\t\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    
    for(i = 0; i < n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].arrival_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
    
    printf("\n\nAverage waiting time: %0.2f", avg_waiting_time);
    printf("\nAverage turnaround time: %0.2f\n\n", avg_turnaround_time);
}

void sjf(struct process proc[], int n){
    int i, j, temp;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = proc[0].arrival_time;
    
    printf("\n\nExecuting SJF CPU Scheduling Algorithm");
    
    //sorting processes based on burst time
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(proc[i].burst_time > proc[j].burst_time){
                temp = proc[i].burst_time;
                proc[i].burst_time = proc[j].burst_time;
                proc[j].burst_time = temp;
                
                temp = proc[i].arrival_time;
                proc[i].arrival_time = proc[j].arrival_time;
                proc[j].arrival_time = temp;
                
                temp = proc[i].priority;
                proc[i].priority = proc[j].priority;
                proc[j].priority = temp;
                
                temp = proc[i].pid;
                proc[i].pid = proc[j].pid;
                proc[j].pid = temp;
            }
        }
    }
    
    //calculating completion time, waiting time and turnaround time for all processes
    for(i = 0; i < n; i++){
        if(current_time < proc[i].arrival_time){
            current_time = proc[i].arrival_time;
        }
        
        proc[i].completion_time = current_time + proc[i].burst_time;
        proc[i].waiting_time = current_time - proc[i].arrival_time;
        proc[i].turnaround_time = proc[i].completion_time - proc[i].arrival_time;

        current_time = proc[i].completion_time;
        
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
    }
    
    //calculating average waiting time and average turnaround time
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    
    printf("\n\nProcess\t\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    
    for(i = 0; i < n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].arrival_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
    
    printf("\n\nAverage waiting time: %0.2f", avg_waiting_time);
    printf("\nAverage turnaround time: %0.2f\n\n", avg_turnaround_time);
}

void priority(struct process proc[], int n){
    int i, j, temp;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = proc[0].arrival_time;
    
    printf("\n\nExecuting Priority CPU Scheduling Algorithm");
    
    //sorting processes based on priority
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(proc[i].priority > proc[j].priority){
                temp = proc[i].burst_time;
                proc[i].burst_time = proc[j].burst_time;
                proc[j].burst_time = temp;
                
                temp = proc[i].arrival_time;
                proc[i].arrival_time = proc[j].arrival_time;
                proc[j].arrival_time = temp;
                
                temp = proc[i].priority;
                proc[i].priority = proc[j].priority;
                proc[j].priority = temp;
                
                temp = proc[i].pid;
                proc[i].pid = proc[j].pid;
                proc[j].pid = temp;
            }
        }
    }
    
    //calculating completion time, waiting time and turnaround time for all processes
    for(i = 0; i < n; i++){
        if(current_time < proc[i].arrival_time){
            current_time = proc[i].arrival_time;
        }
        
        proc[i].completion_time = current_time + proc[i].burst_time;
        proc[i].waiting_time = current_time - proc[i].arrival_time;
        proc[i].turnaround_time = proc[i].completion_time - proc[i].arrival_time;

        current_time = proc[i].completion_time;
        
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
    }
    
    //calculating average waiting time and average turnaround time
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    
    printf("\n\nProcess\t\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
    
    for(i = 0; i < n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].arrival_time, proc[i].priority, proc[i].waiting_time, proc[i].turnaround_time);
    }
    
    printf("\n\nAverage waiting time: %0.2f", avg_waiting_time);
    printf("\nAverage turnaround time: %0.2f\n\n", avg_turnaround_time);
}

int main(){
    int i, n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct process proc[n];
    
    for(i = 0; i < n; i++){
        proc[i].pid = i+1;
        
        printf("\nEnter the burst time of process %d: ", i+1);
        scanf("%d", &proc[i].burst_time);
        
        printf("Enter the arrival time of process %d: ", i+1);
        scanf("%d", &proc[i].arrival_time);
        
        printf("Enter the priority of process %d: ", i+1);
        scanf("%d", &proc[i].priority);
    }
    
    fcfs(proc, n);
    sjf(proc, n);
    priority(proc, n);
    
    return 0;
}