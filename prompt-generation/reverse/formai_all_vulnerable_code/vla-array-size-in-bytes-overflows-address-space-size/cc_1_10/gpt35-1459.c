//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// function to sort the processes according to arrival time
void sortArrivalTime(struct process *p, int n){
    int i, j;
    struct process temp;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(p[i].arrival_time > p[j].arrival_time){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// function to calculate the waiting time for each process
void calculateWaitingTime(struct process *p, int n){
    int i;
    p[0].waiting_time = 0;
    for(i=1; i<n; i++){
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
    }
}

// function to calculate the turnaround time for each process
void calculateTurnaroundTime(struct process *p, int n){
    int i;
    for(i=0; i<n; i++){
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

// function to print the final results
void printResults(struct process *p, int n){
    int i;
    printf("PID\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");
    for(i=0; i<n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
}

// function to implement FCFS scheduling algorithm
void FCFS(struct process *p, int n){
    sortArrivalTime(p, n);
    calculateWaitingTime(p, n);
    calculateTurnaroundTime(p, n);
    printResults(p, n);
}

// function to implement SJF scheduling algorithm
void SJF(struct process *p, int n){
    int i, j, minIndex;
    struct process temp;
    for(i=0; i<n-1; i++){
        minIndex = i;
        for(j=i+1; j<n; j++){
            if(p[j].burst_time < p[minIndex].burst_time){
                minIndex = j;
            }
        }
        temp = p[i];
        p[i] = p[minIndex];
        p[minIndex] = temp;
    }
    calculateWaitingTime(p, n);
    calculateTurnaroundTime(p, n);
    printResults(p, n);
}

// function to implement Round Robin scheduling algorithm
void RR(struct process *p, int n, int quantum){
    int i, time=0, completed=0, remain;
    remain = n;
    while(remain!=0){
        for(i=0; i<n; i++){
            if(p[i].burst_time > 0 && p[i].arrival_time <= time){
                if(p[i].burst_time > quantum){
                    time += quantum;
                    p[i].burst_time -= quantum;
                }
                else{
                    time += p[i].burst_time;
                    p[i].waiting_time = time - p[i].burst_time - p[i].arrival_time;
                    p[i].burst_time = 0;
                    remain--;
                }
            }
        }
    }
    calculateTurnaroundTime(p, n);
    printResults(p, n);
}

int main(){
    int n, i, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    printf("Enter the arrival time and burst time for each process:\n");
    for(i=0; i<n; i++){
        printf("Process %d:\n", i+1);
        printf("Arrival time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &p[i].burst_time);
        p[i].pid = i+1;
    }
    printf("Enter the time quantum for Round Robin scheduling algorithm: ");
    scanf("%d", &quantum);
    printf("FCFS scheduling algorithm:\n");
    FCFS(p, n);
    printf("\nSJF scheduling algorithm:\n");
    SJF(p, n);
    printf("\nRound Robin scheduling algorithm:\n");
    RR(p, n, quantum);
    return 0;
}