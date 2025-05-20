//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// custom struct for Process
struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int waitTime;
    int turnaroundTime;
};

// helper function to print the output
void printOutput(struct Process processes[], int count) {
    printf("PID\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrivalTime, processes[i].burstTime, processes[i].waitTime, processes[i].turnaroundTime);
    }

    printf("\n");
}

// First Come First Serve (FCFS) Algorithm
void fcfsScheduling(struct Process processes[], int count) {
    // initialize start time with the arrival time of first process
    int startTime = processes[0].arrivalTime;
    int completionTime, totalWaitTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < count; i++) {
        // calculate completion time of the current process
        completionTime = startTime + processes[i].burstTime;

        // update wait time and turnaround time of current process
        processes[i].waitTime = startTime - processes[i].arrivalTime;
        processes[i].turnaroundTime = completionTime - processes[i].arrivalTime;

        // update total wait time and total turnaround time
        totalWaitTime += processes[i].waitTime;
        totalTurnaroundTime += processes[i].turnaroundTime;

        // update start time for next process
        startTime = completionTime;
    }

    // calculate average wait time and average turnaround time
    float avgWaitTime = (float)totalWaitTime / count;
    float avgTurnaroundTime = (float)totalTurnaroundTime / count;

    // print the output
    printf("First Come First Serve (FCFS) Scheduling Algorithm:\n");
    printOutput(processes, count);
    printf("Average Wait Time: %.2f\n", avgWaitTime);
    printf("Average Turnaround Time: %.2f\n\n", avgTurnaroundTime);
}

// Shortest Job First (SJF) Algorithm
void sjfScheduling(struct Process processes[], int count) {
    // sort the processes based on burst time in ascending order
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    fcfsScheduling(processes, count);
}

// Round Robin (RR) Algorithm
void rrScheduling(struct Process processes[], int count, int timeQuantum) {
    // initialize wait time, turnaround time, and remaining burst time
    int waitTime[count], turnaroundTime[count], remainingTime[count];
    for (int i = 0; i < count; i++) {
        waitTime[i] = 0;
        turnaroundTime[i] = 0;
        remainingTime[i] = processes[i].burstTime;
    }

    int totalTime = 0, totalWaitTime = 0, totalTurnaroundTime = 0, completedCount = 0;

    // continue the loop until all processes are completed
    while (completedCount != count) {
        bool isCompleted = true;

        // iterate over all processes
        for (int i = 0; i < count; i++) {
            // skip the completed processes
            if (remainingTime[i] == 0) {
                continue;
            }

            // process is not completed yet
            isCompleted = false;

            if (remainingTime[i] > timeQuantum) {
                // the remaining time is greater than time quantum
                totalTime += timeQuantum;
                remainingTime[i] -= timeQuantum;
            } else {
                // the remaining time is less than or equal to time quantum
                totalTime += remainingTime[i];
                remainingTime[i] = 0;
                completedCount++;

                // set the wait time and turnaround time of this process
                waitTime[i] = totalTime - processes[i].burstTime - processes[i].arrivalTime;
                turnaroundTime[i] = totalTime - processes[i].arrivalTime;

                // update total wait time and total turnaround time
                totalWaitTime += waitTime[i];
                totalTurnaroundTime += turnaroundTime[i];
            }
        }

        // if no process is completed in this iteration, increase total time by 1
        if (isCompleted) {
            totalTime++;
        }
    }

    // calculate average wait time and average turnaround time
    float avgWaitTime = (float)totalWaitTime / count;
    float avgTurnaroundTime = (float)totalTurnaroundTime / count;

    // print the output
    printf("Round Robin (RR) Scheduling Algorithm (with Time Quantum %d):\n", timeQuantum);
    for (int i = 0; i < count; i++) {
        processes[i].waitTime = waitTime[i];
        processes[i].turnaroundTime = turnaroundTime[i];
    }
    printOutput(processes, count);
    printf("Average Wait Time: %.2f\n", avgWaitTime);
    printf("Average Turnaround Time: %.2f\n\n", avgTurnaroundTime);
}

int main() {
    int count;
    printf("Enter the number of processes: ");
    scanf("%d", &count);

    struct Process processes[count];

    // accept the inputs from user for each process
    for (int i = 0; i < count; i++) {
        struct Process newProcess;
        newProcess.pid = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", newProcess.pid);
        scanf("%d %d", &newProcess.arrivalTime, &newProcess.burstTime);
        processes[i] = newProcess;
    }

    fcfsScheduling(processes, count);
    sjfScheduling(processes, count);

    int timeQuantum;
    printf("Enter the Time Quantum for Round Robin Scheduling Algorithm: ");
    scanf("%d", &timeQuantum);
    rrScheduling(processes, count, timeQuantum);

    return 0;
}