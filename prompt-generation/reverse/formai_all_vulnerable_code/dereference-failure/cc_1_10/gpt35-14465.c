//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A structure to represent a process
struct Process {
    int name; // process name
    int arrival_time; // arrival time of process
    int burst_time; // burst time of process
    int remaining_time; // remaining burst time of process
    int completion_time; // completion time of process
    int waiting_time; // waiting time of process
    int turnaround_time; // turnaround time of process
};

// Function to generate random arrival time and burst time for a process
void generateProcess(struct Process *p) {
    p->arrival_time = rand() % 100; // arrival time between 0 and 99
    p->burst_time = rand() % 20 + 1; // burst time between 1 and 20
    p->remaining_time = p->burst_time; // initially set remaining time to burst time
}

// Function to print the details of a process
void printProcess(struct Process *p) {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->name, p->arrival_time, p->burst_time,
            p->remaining_time, p->completion_time, p->waiting_time, p->turnaround_time);
}

// Function to perform round-robin scheduling
void roundRobinScheduling(struct Process *p, int n, int quantum) {
    int time = 0; // current time
    int total_waiting_time = 0; // total waiting time of all processes
    int total_turnaround_time = 0; // total turnaround time of all processes
    int completed_processes = 0; // number of processes completed
    int current_process = 0; // index of process currently being executed
    int *remaining_quantum = (int *) malloc(n * sizeof(int)); // remaining quantum for each process
    for (int i = 0; i < n; i++) {
        remaining_quantum[i] = quantum; // initialize remaining quantum to quantum
    }
    while (completed_processes < n) {
        if (p[current_process].remaining_time <= remaining_quantum[current_process]) { // process will complete within quantum
            time += p[current_process].remaining_time; // add remaining time to time
            remaining_quantum[current_process] -= p[current_process].remaining_time; // remaining quantum becomes 0
            p[current_process].remaining_time = 0; // remaining time becomes 0
            p[current_process].completion_time = time; // set completion time to current time
            p[current_process].turnaround_time = p[current_process].completion_time - p[current_process].arrival_time; // calculate turnaround time
            p[current_process].waiting_time = p[current_process].turnaround_time - p[current_process].burst_time; // calculate waiting time
            total_waiting_time += p[current_process].waiting_time; // add waiting time to total waiting time
            total_turnaround_time += p[current_process].turnaround_time; // add turnaround time to total turnaround time
            completed_processes++; // increment number of completed processes
        } else { // process will not complete within quantum
            time += remaining_quantum[current_process]; // add quantum to time
            p[current_process].remaining_time -= remaining_quantum[current_process]; // subtract quantum from remaining time
            remaining_quantum[current_process] = 0; // remaining quantum becomes 0
        }
        // find next process to be executed
        int next_process = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= time && p[i].remaining_time > 0 && remaining_quantum[i] > 0 && (next_process == -1 || p[i].remaining_time < p[next_process].remaining_time)) {
                next_process = i;
            }
        }
        if (next_process != -1) { // found next process
            current_process = next_process; // set current process to next process
        } else { // no process found
            int min_arrival_time = p[0].arrival_time;
            for (int i = 1; i < n; i++) {
                if (p[i].arrival_time < min_arrival_time && p[i].remaining_time > 0) {
                    min_arrival_time = p[i].arrival_time;
                    current_process = i;
                }
            }
        }
    }
    // print results
    printf("Round-Robin Scheduling\n");
    printf("P\tAT\tBT\tRT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printProcess(&p[i]); // print details of each process
    }
    printf("Average waiting time: %f\n", (float) total_waiting_time / n); // print average waiting time
    printf("Average turnaround time: %f\n", (float) total_turnaround_time / n); // print average turnaround time
    free(remaining_quantum); // free memory used by remaining quantum
}

int main() {
    srand(time(NULL)); // seed random number generator
    int n = 5; // number of processes
    struct Process *p = (struct Process *) malloc(n * sizeof(struct Process)); // allocate memory for processes
    for (int i = 0; i < n; i++) {
        p[i].name = i + 1; // set process name to i + 1
        generateProcess(&p[i]); // generate arrival time and burst time for process
    }
    int quantum = 4; // quantum for round-robin scheduling
    roundRobinScheduling(p, n, quantum); // perform round-robin scheduling
    free(p); // free memory used by processes
    return 0;
}