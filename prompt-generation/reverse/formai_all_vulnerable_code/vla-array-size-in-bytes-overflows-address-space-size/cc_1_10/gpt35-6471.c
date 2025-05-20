//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include<stdio.h>

struct process{
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

void swap(struct process *a, struct process *b){
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

void print_table(struct process *p, int n){
    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
    }
}

void fcfs_scheduling(struct process *p, int n){
    int current_time = 0;
    for(int i=0; i<n; i++){
        if(current_time < p[i].arrival_time){
            current_time = p[i].arrival_time;
        }
        p[i].waiting_time = current_time - p[i].arrival_time;
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
        current_time += p[i].burst_time;
    }
    print_table(p, n);
}

void sjf_scheduling(struct process *p, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(p[j].burst_time > p[j+1].burst_time){
                swap(&p[j], &p[j+1]);
            }
        }
    }
    fcfs_scheduling(p, n);
}

void round_robin_scheduling(struct process *p, int n, int quantum){
    int current_time = 0, total_burst_time = 0;
    for(int i=0; i<n; i++){
        total_burst_time += p[i].burst_time;
    }
    while(total_burst_time > 0){
        for(int i=0; i<n; i++){
            if(p[i].burst_time <= 0){
                continue;
            }
            if(p[i].arrival_time <= current_time){
                if(p[i].burst_time > quantum){
                    p[i].burst_time -= quantum;
                    total_burst_time -= quantum;
                    current_time += quantum;
                }
                else{
                    current_time += p[i].burst_time;
                    total_burst_time -= p[i].burst_time;
                    p[i].waiting_time = current_time - p[i].arrival_time - p[i].burst_time;
                    p[i].turnaround_time = current_time - p[i].arrival_time;
                    p[i].burst_time = 0;
                }
            }
        }
    }
    print_table(p, n);
}

int main(){
    int n, algorithm_choice, quantum;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    struct process p[n];
    printf("Enter the details of the processes:\n");
    for(int i=0; i<n; i++){
        p[i].pid = i+1;
        printf("Process %d -\nBurst Time: ", i+1);
        scanf("%d", &p[i].burst_time);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        p[i].waiting_time = 0;
        p[i].turnaround_time = 0;
    }
    printf("Choose a scheduling algorithm -\n1. First-Come-First-Serve\n2. Shortest Job First\n3. Round Robin\n");
    scanf("%d", &algorithm_choice);
    if(algorithm_choice == 1){
        fcfs_scheduling(p, n);
    }
    else if(algorithm_choice == 2){
        sjf_scheduling(p, n);
    }
    else if(algorithm_choice == 3){
        printf("Enter the quantum time: ");
        scanf("%d", &quantum);
        round_robin_scheduling(p, n, quantum);
    }
    else{
        printf("Invalid choice!");
    }
    return 0;
}