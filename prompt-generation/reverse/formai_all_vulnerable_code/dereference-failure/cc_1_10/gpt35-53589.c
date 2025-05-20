//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

#define MAX 20

int n;

struct process{
    int pid;
    int burst_time;
    int priority;
};

void sort_by_priority(struct process p[]){
    int i,j;
    struct process temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(p[j].priority > p[j+1].priority){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void sort_by_burst_time(struct process p[]){
    int i,j;
    struct process temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(p[j].burst_time > p[j+1].burst_time){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void fcfs(struct process p[]){
    int i, waiting_time=0, turn_around_time=0;
    printf("FCFS Scheduling Algorithm\n");
    printf("PID\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0; i<n; i++){
        turn_around_time += p[i].burst_time;
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, waiting_time, turn_around_time);
        waiting_time += p[i].burst_time;
    }
}

void priority(struct process p[]){
    int i, waiting_time=0, turn_around_time=0;
    sort_by_priority(p);
    printf("Priority Scheduling Algorithm\n");
    printf("PID\tPriority\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0; i<n; i++){
        turn_around_time += p[i].burst_time;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].priority, p[i].burst_time, waiting_time, turn_around_time);
        waiting_time += p[i].burst_time;
    }
}

void round_robin(struct process p[]){
    int i, j, waiting_time=0, turn_around_time=0, time_quantum;
    printf("Round Robin Scheduling Algorithm\n");
    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);
    int *burst_time = (int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++){
        burst_time[i] = p[i].burst_time;
    }
    i=0;
    while(1){
        int flag=1;
        for(j=0; j<n; j++){
            if(burst_time[j] > 0){
                flag=0;
                if(burst_time[j] > time_quantum){
                    turn_around_time += time_quantum;
                    burst_time[j] -= time_quantum;
                }
                else{
                    turn_around_time += burst_time[j];
                    waiting_time += turn_around_time - burst_time[j];
                    burst_time[j] = 0;
                    printf("%d\t%d\t\t%d\t\t%d\n", p[j].pid, p[j].burst_time, waiting_time, turn_around_time);
                }
            }
        }
        if(flag)
            break;
    }
}

void sjf(struct process p[]){
    int i, waiting_time=0, turn_around_time=0;
    sort_by_burst_time(p);
    printf("Shortest Job First Scheduling Algorithm\n");
    printf("PID\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0; i<n; i++){
        turn_around_time += p[i].burst_time;
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, waiting_time, turn_around_time);
        waiting_time += p[i].burst_time;
    }
}

int main(){
    int i, choice;
    struct process p[MAX];
    printf("Enter No. of Processes: ");
    scanf("%d", &n);
    printf("Enter Process Details:\n");
    for(i=0; i<n; i++){
        printf("Enter Process ID: ");
        scanf("%d", &p[i].pid);
        printf("Enter Burst Time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].burst_time);
        printf("Enter Priority for Process %d: ", p[i].pid);
        scanf("%d", &p[i].priority);
    }
    printf("Select Scheduling Algorithm:\n1. FCFS\n2. Priority\n3. Round Robin\n4. Shortest Job First\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1: fcfs(p);
                break;
        case 2: priority(p);
                break;
        case 3: round_robin(p);
                break;
        case 4: sjf(p);
                break;
        default: printf("Invalid Choice!\n");
                 break;
    }
    return 0;
}