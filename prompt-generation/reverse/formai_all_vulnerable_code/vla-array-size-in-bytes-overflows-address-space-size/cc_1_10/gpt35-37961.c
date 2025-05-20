//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include<stdlib.h>
#include<stdio.h>
struct process{
    int pid;
    int burstTime;
    int arrivalTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};
void sort(struct process *p, int n){
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].priority > p[j+1].priority){
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}
void calculateWaitingTime(struct process *p, int n){
    int i;
    p[0].waitingTime = 0;
    for(i=1;i<n;i++){
        p[i].waitingTime = p[i-1].waitingTime + p[i-1].burstTime;
    }
}
void calculateTurnaroundTime(struct process *p, int n){
    int i;
    for(i=0;i<n;i++){
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
    }
}
void print(struct process *p, int n){
    int i;
    printf("PID\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].burstTime,p[i].arrivalTime,p[i].priority,p[i].waitingTime,p[i].turnaroundTime);
    }
}
void findAverageTime(struct process *p, int n){
    float totalWaitingTime=0, totalTurnaroundTime=0;
    int i;
    calculateWaitingTime(p,n);
    calculateTurnaroundTime(p,n);
    for(i=0;i<n;i++){
        totalWaitingTime += p[i].waitingTime;
        totalTurnaroundTime += p[i].turnaroundTime;
    }
    printf("Average Waiting Time: %.2f\nAverage Turnaround Time: %.2f",totalWaitingTime/n,totalTurnaroundTime/n);
}
int main(){
    int i,n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct process p[n];
    for(i=0;i<n;i++){
        printf("Enter burst time, arrival time and priority of process %d: ",i+1);
        scanf("%d %d %d",&p[i].burstTime,&p[i].arrivalTime,&p[i].priority);
        p[i].pid = i+1;
    }
    sort(p,n);
    findAverageTime(p,n);
    print(p,n);
    return 0;
}