//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: accurate
#include<stdio.h>

struct Process{
    int process_id, arrival_time, burst_time;
};

void main(){

    // Input
    int n,quantum_time;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    struct Process process[n];
    printf("\nEnter the arrival time and burst time for each process: \n");

    for(int i=0; i<n; i++){
        printf("Process %d : ", (i+1));
        scanf("%d%d",&process[i].arrival_time,&process[i].burst_time);
        process[i].process_id = (i+1);
    }

    printf("\nEnter the time quantum for Round Robin scheduling: ");
    scanf("%d",&quantum_time);

    // Calculation
    int completed = 0, processes_left = n;
    int waiting_time = 0, turnaround_time = 0;
    int timer = 0, current_process = 0;
    int remaining_burst[n];

    for(int i=0; i<n; i++){
        remaining_burst[i] = process[i].burst_time;
    }

    while(processes_left){

        // Execute the current process
        if(remaining_burst[current_process] <= quantum_time){

            timer += remaining_burst[current_process];
            remaining_burst[current_process] = 0;
            completed++;
            processes_left--;

            waiting_time += (timer - process[current_process].arrival_time - process[current_process].burst_time);
            turnaround_time += (timer - process[current_process].arrival_time);

        }else{

            timer += quantum_time;
            remaining_burst[current_process] -= quantum_time;

        }

        // Select the next process
        do{
            current_process = (current_process+1)%n;
        }while(remaining_burst[current_process]==0);

    }

    // Output
    printf("\n\nOutput:\n\n");

    printf("Process ID\tArrival\t\tBurst\t\tWaiting\t\tTurnaround\n");

    for(int i=0; i<n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i].process_id, process[i].arrival_time, process[i].burst_time, (waiting_time/n), (turnaround_time/n));
    }

}