//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Process{
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int response_time;
    int turnaround_time;
    int color; //for maintaining multi player queue
};

void sort_arrival(struct Process p[], int n){
    //Sorts processes based on their arrival time using bubble sort
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(p[j].arrival_time > p[j+1].arrival_time){
                struct Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void sort_burst(struct Process p[], int n){
    //Sorts processes based on their burst time using bubble sort
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(p[j].burst_time > p[j+1].burst_time){
                struct Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void calculate_waiting_time(struct Process p[], int n){
    //Calculates waiting time for each process
    p[0].waiting_time = 0;
    for(int i=1; i<n; i++){
        p[i].waiting_time = p[i-1].burst_time + p[i-1].waiting_time + (p[i].arrival_time - p[i-1].arrival_time);
    }
}

void calculate_turnaround_time(struct Process p[], int n){
    //Calculates turnaround time for each process
    for(int i=0; i<n; i++){
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

void calculate_response_time(struct Process p[], int n){
    //Calculates response time for each process
    p[0].response_time = 0;
    for(int i=1; i<n; i++){
        p[i].response_time = p[i-1].burst_time + p[i-1].response_time + (p[i].arrival_time - p[i-1].arrival_time);
    }
}

void print_output(struct Process p[], int n){
    //Prints the output
    printf("Pid\tArrival Time\tBurst Time\tWaiting Time\tResponse Time\tTurnaround Time\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].response_time, p[i].turnaround_time);
    }
}

void run_process(struct Process p[], int n, int current_time){
    //Runs the process
    sort_burst(p, n);
    int i=0;
    while(i<n && p[i].arrival_time <= current_time){
        p[i].burst_time -= 1;
        if(p[i].burst_time == 0){
            p[i].turnaround_time = current_time+1 - p[i].arrival_time;
            p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
            p[i].response_time = p[i].arrival_time - current_time;
        }
        i++;
    }
}

void multi_player_queue(struct Process p[], int n){
    //Maintains multiple queues for processes with different arrival times
    sort_arrival(p, n);
    int start_time = p[0].arrival_time;
    int end_time = p[n-1].arrival_time;
    for(int i=start_time; i<=end_time; i++){
        for(int j=0; j<n; j++){
            if(p[j].arrival_time == i){
                p[j].color = 0;
            }
            else{
                p[j].color++;
            }
        }
        for(int j=0; j<n; j++){
            if(p[j].burst_time > 0 && p[j].arrival_time <= i && p[j].color < 5){
                run_process(&p[j], 1, i);
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for(int i=0; i<n; i++){
        printf("Enter the arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].pid = i+1;
    }
    calculate_waiting_time(p, n);
    calculate_turnaround_time(p, n);
    calculate_response_time(p, n);
    multi_player_queue(p, n); //use this function instead of running a single queue
    print_output(p, n);
    return 0;
}