//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process {
    int PID; //Process ID
    int ArrivalTime; //Arrival Time
    int CPUburst; //CPU Burst Time
    int CompletionTime; //Completion Time
    int TurnaroundTime; //Turnaround Time
    int WaitingTime; //Waiting Time
    int RemainingTime; //Remaining Time
};

//Round Robin scheduling algorithm
void RoundRobin(struct Process* processes, int n, int quantum) {
    int time = 0, done = 0;
    while(done != n) {
        for(int i = 0; i < n; i++) {
            if(processes[i].RemainingTime > 0) {
                if(processes[i].RemainingTime > quantum) {
                    time += quantum;
                    processes[i].RemainingTime -= quantum;
                } else {
                    time += processes[i].RemainingTime;
                    processes[i].WaitingTime = time - processes[i].CPUburst - processes[i].ArrivalTime;
                    processes[i].RemainingTime = 0;
                    processes[i].TurnaroundTime = processes[i].WaitingTime + processes[i].CPUburst;
                    processes[i].CompletionTime = time;
                    done++;
                }
            }
        }
    }
}

//Implementation of FCFS scheduling algorithm
void FCFS(struct Process* processes, int n) {
    int time = 0;
    for(int i = 0; i < n; i++) {
        if(time < processes[i].ArrivalTime) {
            time = processes[i].ArrivalTime;
        }
        processes[i].CompletionTime = time + processes[i].CPUburst;
        processes[i].TurnaroundTime = processes[i].CompletionTime - processes[i].ArrivalTime;
        processes[i].WaitingTime = processes[i].TurnaroundTime - processes[i].CPUburst;
        time = processes[i].CompletionTime;
    }
}

//Implementation of SJF scheduling algorithm
void SJF(struct Process* processes, int n) {
    int time = 0;
    struct Process* readyQ = (struct Process*) malloc(n * sizeof(struct Process));
    int qsize = 0;
    for(int i = 0; i < n; i++) {
        if(time < processes[i].ArrivalTime) {
            time = processes[i].ArrivalTime;
        }
        int j;
        for(j = qsize; j > 0; j--) {
            if(processes[i].CPUburst > readyQ[j - 1].CPUburst) {
                readyQ[j] = readyQ[j - 1];
            } else {
                break;
            }
        }
        readyQ[j] = processes[i];
        qsize++;
        while(qsize > 0) {
            struct Process p = readyQ[0];
            for(int j = 0; j < qsize - 1; j++) {
                readyQ[j] = readyQ[j + 1];
            }
            qsize--;
            time += p.CPUburst;
            p.CompletionTime = time;
            p.TurnaroundTime = p.CompletionTime - p.ArrivalTime;
            p.WaitingTime = p.TurnaroundTime - p.CPUburst;
        }
    }
    free(readyQ);
}

int main() {
    printf("Enter Number of Processes: ");
    int n;
    scanf("%d", &n);
    
    struct Process* processes = (struct Process*) malloc(n * sizeof(struct Process));
    
    printf("Enter Arrival Time and CPU Burst for Each Process:\n");
    for(int i = 0; i < n; i++) {
        processes[i].PID = i + 1;
        scanf("%d%d", &processes[i].ArrivalTime, &processes[i].CPUburst);
        processes[i].RemainingTime = processes[i].CPUburst;
    }
    
    //Round Robin scheduling algorithm
    printf("\nEnter Time Quantum for Round Robin Algorithm: ");
    int quantum;
    scanf("%d", &quantum);
    RoundRobin(processes, n, quantum);
    
    //FCFS scheduling algorithm
    FCFS(processes, n);
    
    //SJF scheduling algorithm
    SJF(processes, n);
    
    //Print Results
    printf("\nROUND ROBIN ALGORITHM:\n");
    printf("PID\tArrival Time\tCPU Burst\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i < n; i++) {
        struct Process p = processes[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p.PID, p.ArrivalTime, p.CPUburst, p.CompletionTime, p.TurnaroundTime, p.WaitingTime);
    }
    printf("\nFCFS ALGORITHM:\n");
    printf("PID\tArrival Time\tCPU Burst\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i < n; i++) {
        struct Process p = processes[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p.PID, p.ArrivalTime, p.CPUburst, p.CompletionTime, p.TurnaroundTime, p.WaitingTime);
    }
    printf("\nSJF ALGORITHM:\n");
    printf("PID\tArrival Time\tCPU Burst\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i < n; i++) {
        struct Process p = processes[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p.PID, p.ArrivalTime, p.CPUburst, p.CompletionTime, p.TurnaroundTime, p.WaitingTime);
    }
    free(processes);
    return 0;
}