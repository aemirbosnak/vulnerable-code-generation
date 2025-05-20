//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;         // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int waiting;    // Waiting time
    int turnaround; // Turnaround time
};

// Function to calculate waiting and turnaround times for each process
void calculateTimes(struct Process proc[], int n) {
    // Initializing waiting and turnaround times
    proc[0].waiting = 0; // First process has no waiting time

    // Calculate waiting and turnaround time
    for (int i = 1; i < n; i++) {
        proc[i].waiting = proc[i - 1].waiting + proc[i - 1].burst;
        proc[i].turnaround = proc[i].waiting + proc[i].burst;
    }
}

// Function to sort processes by arrival time
void sortProcesses(struct Process proc[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].arrival > proc[j].arrival) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

// Function to display the process details and average times
void displayProcesses(struct Process proc[], int n) {
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    float totalWaiting = 0, totalTurnaround = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
            proc[i].id, proc[i].arrival, proc[i].burst, 
            proc[i].waiting, proc[i].turnaround);
        totalWaiting += proc[i].waiting;
        totalTurnaround += proc[i].turnaround;
    }
    printf("Average Waiting Time: %.2f\n", totalWaiting / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaround / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *proc = (struct Process *)malloc(n * sizeof(struct Process));

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1; // Assign process ID
        printf("Enter arrival time for process %d: ", proc[i].id);
        scanf("%d", &proc[i].arrival);
        printf("Enter burst time for process %d: ", proc[i].id);
        scanf("%d", &proc[i].burst);
    }

    sortProcesses(proc, n);
    calculateTimes(proc, n);
    displayProcesses(proc, n);

    free(proc);
    return 0;
}