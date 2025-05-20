//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: artistic
// Artistic CPU Scheduling Algorithm program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// struct for process block
typedef struct {
    int pid; // process ID
    int burst_time; // process burst time
    int arrival_time; // process arrival time
    int priority; // process priority
} process;

// function to generate random integer
int rand_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// function to print process block
void print_process(process p) {
    printf("PID: %d, Burst Time: %d, Arrival Time: %d, Priority: %d\n", p.pid, p.burst_time, p.arrival_time, p.priority);
}

// function to initialize process block array
process* init_processes(int n) {
    process* processes = malloc(n * sizeof(process));
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].burst_time = rand_int(1, 10);
        processes[i].arrival_time = rand_int(0, 10);
        processes[i].priority = rand_int(1, 5);
    }
    return processes;
}

// function to sort process block array by arrival time
void sort_processes(process* processes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                // swap
                process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// function for first-come, first-served scheduling algorithm
void fcfs(process* processes, int n) {
    printf("First-Come, First-Served Scheduling Algorithm\n");
    int total_time = 0;
    float avg_wait_time = 0;
    for (int i = 0; i < n; i++) {
        total_time += processes[i].burst_time;
        printf("Process %d starts at time %d\n", processes[i].pid, total_time - processes[i].burst_time);
        printf("Process %d ends at time %d\n", processes[i].pid, total_time);
        avg_wait_time += total_time - processes[i].arrival_time - processes[i].burst_time;
    }
    avg_wait_time /= n;
    printf("Average waiting time: %.2f\n", avg_wait_time);
}

// function for round-robin scheduling algorithm
void round_robin(process* processes, int n, int quantum) {
    printf("Round-Robin Scheduling Algorithm (Quantum = %d)\n", quantum);
    int* remaining_time = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }
    int total_time = 0;
    float avg_wait_time = 0;
    int finished_count = 0;
    while (finished_count < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                int run_time = remaining_time[i] < quantum ? remaining_time[i] : quantum;
                total_time += run_time;
                remaining_time[i] -= run_time;
                printf("Process %d runs from time %d to time %d\n", processes[i].pid, total_time - run_time, total_time);
                if (remaining_time[i] == 0) {
                    finished_count++;
                    avg_wait_time += total_time - processes[i].arrival_time - processes[i].burst_time;
                }
            }
        }
    }
    avg_wait_time /= n;
    printf("Average waiting time: %.2f\n", avg_wait_time);
}

// function for priority scheduling algorithm
void priority(process* processes, int n) {
    printf("Priority Scheduling Algorithm\n");
    int total_time = 0;
    float avg_wait_time = 0;
    process* queue = malloc(n * sizeof(process));
    int queue_size = 0;
    int* remaining_time = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }
    while (queue_size != n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= total_time && remaining_time[i] > 0) {
                // add to queue
                int j = queue_size - 1;
                while (j >= 0 && processes[i].priority > queue[j].priority) {
                    queue[j + 1] = queue[j];
                    j--;
                }
                queue[j + 1] = processes[i];
                queue_size++;
            }
        }
        if (queue_size > 0) {
            process p = queue[0];
            total_time += p.burst_time;
            printf("Process %d starts at time %d\n", p.pid, total_time - p.burst_time);
            printf("Process %d ends at time %d\n", p.pid, total_time);
            avg_wait_time += total_time - p.arrival_time - p.burst_time;
            for (int i = 0; i < queue_size - 1; i++) {
                queue[i] = queue[i + 1];
            }
            queue_size--;
        } else {
            total_time++;
        }
    }
    avg_wait_time /= n;
    printf("Average waiting time: %.2f\n", avg_wait_time);
}

int main() {
    srand(time(NULL));
    
    int n = 5; // number of processes
    
    process* processes = init_processes(n);
    sort_processes(processes, n);
    
    for (int i = 0; i < n; i++) {
        print_process(processes[i]);
    }
    
    fcfs(processes, n);
    
    round_robin(processes, n, 3);
    
    priority(processes, n);
    
    free(processes);
    
    return 0;
}