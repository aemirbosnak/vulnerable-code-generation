//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>

#define TIME_QUANTUM 2 // time quantum in seconds

// process definition
struct process {
    int id;              // process id
    int arrival_time;    // arrival time
    int burst_time;      // burst time
    int remaining_time;  // remaining time
    int completion_time; // completion time
    int turnaround_time; // turnaround time
    int waiting_time;    // waiting time
};

int main() {
    int n; // number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // allocate memory for the processes
    struct process *processes = (struct process*) malloc(n * sizeof(struct process));

    // input the processes
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time of process %d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].id = i+1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    int t = 0; // current time
    int i = 0; // index of the current running process

    // run the processes
    while (1) {
        int done = 1; // check if all processes are done
        for (int j = 0; j < n; j++) {
            if (processes[j].remaining_time > 0) {
                done = 0;
                break;
            }
        }
        if (done) break;

        // run the current process for the time quantum
        if (processes[i].remaining_time > 0) {
            if (processes[i].remaining_time > TIME_QUANTUM) {
                t += TIME_QUANTUM;
                processes[i].remaining_time -= TIME_QUANTUM;
            }
            else {
                t += processes[i].remaining_time;
                processes[i].completion_time = t;
                processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                processes[i].remaining_time = 0;
            }
        }

        // move to the next process
        i = (i + 1) % n;

        // skip the idle time
        while (processes[i].remaining_time == 0)
            i = (i + 1) % n;
    }

    // print the results
    printf("Process     Arrival Time     Burst Time     Completion Time     Turnaround Time    Waiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%5d %15d %15d %19d %18d %15d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    free(processes); // free the memory

    return 0;
}