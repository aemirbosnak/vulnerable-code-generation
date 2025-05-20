//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Creating a data structure to represent a process
struct Process {
    int process_id;
    int burst_time;  // Time taken by process for execution
    int priority;    // Priority of process
    int waiting_time;
    int turnaround_time;
};

int main() {

    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Creating an array of processes of size 'n'
    struct Process processes[n];

    // Reading the details of each process
    for (int i = 0; i < n; i++) {
        printf("Enter details of Process #%d:\n", i+1);
        printf("Process ID: ");
        scanf("%d", &processes[i].process_id);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }

    // Implementing Priority Scheduling Algorithm
    // Sort by Priority and then execute the process

    // Sorting Processes by Priority
    // Selection Sort Used
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (processes[j].priority < processes[min_index].priority) {
                min_index = j;
            }
        }
        struct Process temp = processes[i];
        processes[i] = processes[min_index];
        processes[min_index] = temp;
    }

    // Calculating Waiting Time and Turnaround Time for each process
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;
    float waiting_time_avg = processes[0].waiting_time;
    float turnaround_time_avg = processes[0].turnaround_time;

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i-1].turnaround_time;
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
        waiting_time_avg += processes[i].waiting_time;
        turnaround_time_avg += processes[i].turnaround_time;
    } 

    // Printing a Gantt Chart
    printf("\nGantt Chart:\n");
    printf("%d | ", processes[0].process_id);
    for (int i = 1; i < n; i++) {
        printf("P%d | %d | ", processes[i].process_id, processes[i-1].turnaround_time);
    }

    // Printing Final Results
    waiting_time_avg /= n;
    turnaround_time_avg /= n;
    printf("\n\n\t\t\t\t\t\tSummary\n");
    printf("__________________________________________________________________\n");
    printf("|\tProcesses\t|\tWaiting Time\t|\tTurnaround Time\t|\n");
    printf("|_______________________|_______________________|___________________|\n");
    for (int i = 0; i < n; i++) {
        printf("|\tP%d\t\t|\t%d\t\t|\t%d\t\t|\n", processes[i].process_id, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("|_______________________|_______________________|___________________|\n");
    printf("\nAverage Waiting Time: %f", waiting_time_avg);
    printf("\nAverage Turnaround Time: %f", turnaround_time_avg);

    return 0;
}