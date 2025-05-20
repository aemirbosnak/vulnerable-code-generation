//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Process Structure
struct Process {
    char name[10];
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
};

// Function to find the Waiting Time of a Process
void findWaitingTime(struct Process *processes, int n) {
    int i, j, total = 0;
    processes[0].waitingTime = 0;
    for(i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i-1].burstTime + processes[i-1].waitingTime;
        total += processes[i].waitingTime;
    }
}

// Function to find the Turnaround Time of a Process
void findTurnaroundTime(struct Process *processes, int n) {
    int i;
    for(i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}

// Function to find the Completion Time of a Process
void findCompletionTime(struct Process *processes, int n) {
    int i;
    processes[0].completionTime = processes[0].burstTime;
    for(i = 1; i < n; i++) {
        processes[i].completionTime = processes[i-1].completionTime + processes[i].burstTime;
    }
}

// Function to find the Average Waiting Time
float findAverageWaitingTime(struct Process *processes, int n) {
    int i, total = 0;
    findWaitingTime(processes, n);
    for(i = 0; i < n; i++) {
        total += processes[i].waitingTime;
    }
    return (float) total / n;
}

// Function to find the Average Turnaround Time
float findAverageTurnaroundTime(struct Process *processes, int n) {
    int i, total = 0;
    findTurnaroundTime(processes, n);
    for(i = 0; i < n; i++) {
        total += processes[i].turnaroundTime;
    }
    return (float) total / n;
}

// Function to print the Gantt Chart
void printGanttChart(struct Process *processes, int n) {
    int i, j;
    printf("\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < processes[i].burstTime; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n|");
    for(i = 0; i < n; i++) {
        for(j = 0; j < processes[i].burstTime - 1; j++) {
            printf(" ");
        }
        printf("%s", processes[i].name);
        for(j = 0; j < processes[i].burstTime - 1; j++) {
            printf(" ");
        }
        printf("|");
    }
    printf("\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < processes[i].burstTime; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n");
    printf("0");
    for(i = 0; i < n; i++) {
        for(j = 0; j < processes[i].burstTime; j++) {
            printf("  ");
        }
        if(processes[i].completionTime > 9) {
            printf("\b");
        }
        printf("%d", processes[i].completionTime);
    }
    printf("\n");
}

// Function to perform Round Robin Scheduling
void roundRobinScheduling(struct Process *processes, int n, int quantum) {
    int i, j, time = 0, completed = 0, flag = 0, current = 0, remainTime[n];
    for(i = 0; i < n; i++) {
        remainTime[i] = processes[i].burstTime;
    }
    while(completed != n) {
        flag = 0;
        for(i = 0; i < n; i++) {
            if(remainTime[i] > 0) {
                flag = 1;
                if(remainTime[i] > quantum) {
                    remainTime[i] -= quantum;
                    time += quantum;
                }
                else {
                    time += remainTime[i];
                    remainTime[i] = 0;
                    processes[i].completionTime = time;
                    completed++;
                }
                if(i != current) {
                    printf("\n%d - %d: %s", time - quantum, time, processes[current].name);
                    current = i;
                }
            }
        }
        if(flag == 0) {
            break;
        }
    }
    printf("\n%d - %d: %s", time - quantum, time, processes[current].name);
}

int main() {
    int n, i, j, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for(i = 0; i < n; i++) {
        printf("Enter the name of process %d: ", i+1);
        scanf("%s", processes[i].name);
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter the arrival time of process %d: ", i+1);
        scanf("%d", &processes[i].arrivalTime);
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    roundRobinScheduling(processes, n, quantum);
    findWaitingTime(processes, n);
    findTurnaroundTime(processes, n);
    findCompletionTime(processes, n);
    printf("\n\nName\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for(i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].name, processes[i].burstTime, processes[i].arrivalTime, processes[i].waitingTime, processes[i].turnaroundTime, processes[i].completionTime);
    }
    printf("\nAverage Waiting Time: %.2f", findAverageWaitingTime(processes, n));
    printf("\nAverage Turnaround Time: %.2f\n", findAverageTurnaroundTime(processes, n));
    printGanttChart(processes, n);
    return 0;
}