//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This program simulates the round-robin CPU scheduling algorithm.
 * Each process is given a time slice of 10ms and the algorithm continues
 * until all processes have completed their execution.
 * This is a fun and energetic example of how computer processes can be 
 * scheduled in a fair and efficient manner.
 */

struct process {
    int pid;            // process ID
    int burst_time;     // time required for execution
    int remaining_time; // time remaining for execution
};

int main() {
    int num_processes, i = 0, j = 0, time_quantum = 10;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    printf("\nHey there, I'm your friendly CPU scheduling algorithm!\n");
    printf("Let's get started by entering the number of processes: ");
    scanf("%d", &num_processes);
    struct process processes[num_processes], temp;
    srand(time(0));

    // Initialize the array of processes with random burst times
    for(i=0; i<num_processes; i++) {
        processes[i].pid = i;
        processes[i].burst_time = rand() % 50 + 1; // burst time ranging from 1-50ms
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("\nGreat! Here are the details of the processes:\n");
    printf("--------------------------------------------------------\n");
    printf("Process\tBurst Time\tRemaining Time\n");
    printf("--------------------------------------------------------\n");
    for(i=0; i<num_processes; i++) {
        printf("P%d\t\t%dms\t\t%dms\n", processes[i].pid, processes[i].burst_time, processes[i].remaining_time);
    }
    printf("--------------------------------------------------------\n");

    // Implement the round-robin algorithm
    i = 0; j = 0;
    while(j<num_processes) {
        if(processes[i].remaining_time <= time_quantum && processes[i].remaining_time > 0) {
            avg_wait_time += (j * time_quantum) - processes[i].burst_time;   // calculate wait time
            processes[i].remaining_time = 0;
            j++; // process completed executing
        } else if(processes[i].remaining_time > 0) {
            processes[i].remaining_time -= time_quantum;  // execute process for time quantum
        }
        i++;
        if(i == num_processes) {
            i = 0;  // start again from the first process
        }
    }

    printf("\nAwesome! All processes have completed execution.\n");
    printf("Here are the final results:\n");
    printf("--------------------------------------------------------\n");
    printf("Process\tBurst Time\tTurnaround Time\n");
    printf("--------------------------------------------------------\n");

    for(i=0; i<num_processes; i++) {
        printf("P%d\t\t%dms\t\t%dms\n", processes[i].pid, processes[i].burst_time, 
               (processes[i].burst_time + (int) (avg_wait_time/num_processes + 0.5)));
        avg_turnaround_time += (processes[i].burst_time + (int) (avg_wait_time/num_processes + 0.5));
    }

    printf("--------------------------------------------------------\n");
    printf("Average Wait Time: %.2fms\n", avg_wait_time/num_processes);
    printf("Average Turnaround Time: %.2fms\n\n", avg_turnaround_time/num_processes);
    printf("Thanks for running this program with me! Bye bye!\n");

    return 0;
}