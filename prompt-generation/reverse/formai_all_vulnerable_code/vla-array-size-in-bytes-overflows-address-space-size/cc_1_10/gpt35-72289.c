//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include<stdio.h>

//structure to represent process
struct process {
    int pid;  //process id
    int burst_time;  //burst time of the process
    int arrival_time;  //arrival time of the process
    int waiting_time;  //waiting time of the process
    int turnaround_time;  //turnaround time of the process
    int status;  //status of the process -> 0 for waiting state and 1 for completion state
};

//function to implement round robin scheduling algorithm
void round_robin(struct process proc[], int n, int quantum) {
    int count = 0;
    int time = 0;
    int remain = n;

    //loop until all processes have been completely executed
    while(remain != 0) {
        //iterate over all the processes
        for(int i=0; i < n; i++) {
            if(proc[i].arrival_time <= time && proc[i].status == 0) {
                //process has arrived and yet to be completed

                if(proc[i].burst_time <= quantum) {
                    //process finishes execution within the given time quantum
                    time += proc[i].burst_time;
                    proc[i].turnaround_time = time - proc[i].arrival_time;
                    proc[i].waiting_time = proc[i].turnaround_time - proc[i].burst_time;  //calculating waiting time
                    proc[i].status = 1;  //marking process as completed
                    remain--;
                }
                else {
                    //process does not finish execution within the given time quantum
                    time += quantum;
                    proc[i].burst_time -= quantum;
                }
            }
        }
    }
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process proc[n];

    for(int i=0; i < n; i++) {
        printf("Enter the arrival time of process %d: ", i+1);
        scanf("%d", &proc[i].arrival_time);
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &proc[i].burst_time);
        proc[i].pid = i+1;
        proc[i].status = 0;  //process is in waiting state initially
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    round_robin(proc, n, quantum);

    printf("\n\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    int total_waiting_time = 0, total_turnaround_time = 0;

    for(int i=0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].arrival_time, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
    }

    printf("\n\nAverage Waiting Time: %.2f", (double)total_waiting_time/n);
    printf("\nAverage Turnaround Time: %.2f\n", (double)total_turnaround_time/n);

    return 0;
}