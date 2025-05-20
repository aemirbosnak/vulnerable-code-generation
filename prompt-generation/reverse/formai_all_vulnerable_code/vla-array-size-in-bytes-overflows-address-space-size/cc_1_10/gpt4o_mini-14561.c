//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include <stdio.h>

typedef struct {
    int process_id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateTimes(Process processes[], int n) {
    processes[0].waiting_time = 0;

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void findAverageTimes(Process processes[], int n) {
    float total_waiting_time = 0.0;
    float total_turnaround_time = 0.0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
}

void printProcesses(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", 
                processes[i].process_id, 
                processes[i].burst_time, 
                processes[i].waiting_time, 
                processes[i].turnaround_time);
    }
}

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter burst time for Process %d: ", processes[i].process_id);
        scanf("%d", &processes[i].burst_time);
    }

    calculateTimes(processes, n);
    printProcesses(processes, n);
    findAverageTimes(processes, n);

    return 0;
}