//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct process {
    int pid;         // Process ID
    int arrival;     // Arrival time
    int burst;       // Burst time
    int remaining;   // Remaining burst time
    int start;       // Start time
    int finish;      // Finish time
} process;

// Scheduling algorithm type
typedef enum scheduling_algorithm {
    FCFS,
    SJF,
    SRTF,
    RR
} scheduling_algorithm;

// Function to initialize the process
process* init_process(int pid, int arrival, int burst) {
    process* p = (process*)malloc(sizeof(process));
    p->pid = pid;
    p->arrival = arrival;
    p->burst = burst;
    p->remaining = burst;
    return p;
}

// Function to create a list of processes
process** init_processes(int n) {
    process** processes = (process**)malloc(n * sizeof(process*));
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        int arrival, burst;
        printf("Arrival time: ");
        scanf("%d", &arrival);
        printf("Burst time: ");
        scanf("%d", &burst);
        processes[i] = init_process(i + 1, arrival, burst);
    }
    return processes;
}

// Function to compare processes based on arrival time
int compare_arrival(const void* a, const void* b) {
    process* p1 = (process*)a;
    process* p2 = (process*)b;
    return p1->arrival - p2->arrival;
}

// Function to print the Gantt chart
void print_gantt_chart(process** processes, int n, scheduling_algorithm algo) {
    int curr_time = 0;
    process* running = NULL;
    printf("Gantt Chart for %s Scheduling Algorithm:\n", algo == FCFS ? "FCFS" : (algo == SJF ? "SJF" : (algo == SRTF ? "SRTF" : "RR")));
    printf("--------------------------------------------------\n");
    while (curr_time < processes[n - 1]->finish) {
        // Find the next process to run
        running = NULL;
        for (int i = 0; i < n; i++) {
            if (processes[i]->arrival <= curr_time && (running == NULL || processes[i]->remaining < running->remaining)) {
                running = processes[i];
            }
        }
        // If no process is available, idle the CPU
        if (running == NULL) {
            printf("CPU Idle");
            curr_time++;
        }
        // Otherwise, run the process and update the remaining time
        else {
            printf("P%d", running->pid);
            running->remaining--;
            curr_time++;
            if (running->remaining == 0) {
                running->finish = curr_time;
            }
        }
        // Wait for the user to press enter
        printf(" ");
        getchar();  
    }
    printf("\n--------------------------------------------------\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Initialize the processes
    process** processes = init_processes(n);

    // Sort the processes by arrival time
    qsort(processes, n, sizeof(process*), compare_arrival);

    // Choose the scheduling algorithm
    scheduling_algorithm algo;
    int choice;
    printf("Choose the scheduling algorithm:\n");
    printf("1. First-Come First-Served (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Shortest Remaining Time First (SRTF)\n");
    printf("4. Round Robin (RR)\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            algo = FCFS;
            break;
        case 2:
            algo = SJF;
            break;
        case 3:
            algo = SRTF;
            break;
        case 4:
            algo = RR;
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    // Print the Gantt chart
    print_gantt_chart(processes, n, algo);

    return 0;
}