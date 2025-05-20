//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// process struct 
struct process{
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int wait_time;
    int turnaround_time;
    int remaining_time; // for Round Robin algorithm
    bool completed; // for SJF algorithm
};

// function to sort the processes based on priority
void sort_priority(struct process *p, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(p[i].priority > p[j].priority){
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// function to sort the processes based on burst time for non-preemptive SJF
void sort_burst_time(struct process *p, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(p[i].burst_time > p[j].burst_time){
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    // get input for each process
    for(int i=0; i<n; i++){
        p[i].pid = i+1;
        printf("Enter arrival time for process %d: ", i+1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &p[i].burst_time);
        printf("Enter priority for process %d (lower number indicates higher priority): ", i+1);
        scanf("%d", &p[i].priority);
        p[i].remaining_time = p[i].burst_time;
        p[i].completed = false;
    }

    // initialize remaining variables for each process
    int current_time = 0;
    int completed_processes = 0;

    // apply Priority algorithm
    sort_priority(p, n);

    while(completed_processes < n){
        int min_priority = 999;
        int min_priority_pid = -1;
        for(int i=0; i<n; i++){
            // select process with highest priority that has arrived
            if(p[i].arrival_time <= current_time && !p[i].completed && p[i].priority < min_priority){
                min_priority = p[i].priority;
                min_priority_pid = i;
            }
        }

        if(min_priority_pid == -1){ // no process has arrived yet
            printf("CPU is idle at time %d\n", current_time);
            current_time++;
            continue;
        }

        struct process *current_process = &p[min_priority_pid];

        printf("Process %d is running at time %d\n", current_process->pid, current_time);

        // run process for its entire burst time
        for(int i=0; i<current_process->burst_time; i++){
            current_time++;

            // check if any new processes have arrived while current process is running
            for(int j=0; j<n; j++){
                if(p[j].arrival_time <= current_time && j != min_priority_pid && !p[j].completed && p[j].priority < current_process->priority){
                    printf("Process %d is preempted by process %d at time %d\n", current_process->pid, p[j].pid, current_time);
                    current_process->remaining_time = current_process->burst_time - i;
                    current_process = &p[j];
                    printf("Process %d is running at time %d\n", current_process->pid, current_time);
                    break;
                }
            }

            current_process->remaining_time--;

            // process is complete
            if(current_process->remaining_time == 0){
                printf("Process %d has completed execution at time %d\n", current_process->pid, current_time);
                current_process->completed = true;
                current_process->turnaround_time = current_time - current_process->arrival_time;
                current_process->wait_time = current_process->turnaround_time - current_process->burst_time;
                completed_processes++;
                break;
            }
        }
    }

    // print output
    printf("\nPID\tArrival Time\tBurst Time\tPriority\tWait Time\tTurnaround Time\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].wait_time, p[i].turnaround_time);
    }

    return 0;
}