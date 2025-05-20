//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
    int time_quantum;
    struct Process* next;
};

void addProcessToFront(struct Process** frontPtr, struct Process* newProcess) {
    newProcess->next = *frontPtr;
    *frontPtr = newProcess;
}

void removeProcessFromFront(struct Process** frontPtr) {
    *frontPtr = (*frontPtr)->next;
}

void addProcessToTail(struct Process** tailPtr, struct Process* newProcess) {
    if (*tailPtr == NULL) {
        *tailPtr = newProcess;
        newProcess->next = NULL;
    } else {
        (*tailPtr)->next = newProcess;
        *tailPtr = newProcess;
        newProcess->next = NULL;
    }
}

int main() {
    int numProcesses, quantum, t = 0, i, timeToCompletion = 0;
    float avgTurnaroundTime = 0.0, avgWaitingTime = 0.0;
    struct Process* front = NULL;
    struct Process* tail = NULL;
    struct Process* ptr;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    struct Process* processes[numProcesses];
    for (i = 0; i < numProcesses; i++) {
        processes[i] = (struct Process*) malloc(sizeof(struct Process));
        processes[i]->pid = i+1;
        printf("Enter arrival time of process #%d: ", i+1);
        scanf("%d", &processes[i]->arrival_time);
        printf("Enter burst time of process #%d: ", i+1);
        scanf("%d", &processes[i]->burst_time);
        processes[i]->remaining_time = processes[i]->burst_time;
        processes[i]->next = NULL;
        addProcessToTail(&tail, processes[i]);
    }
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    printf("-----------------------------------------------\n");
    while (front != NULL || tail != NULL) {
        ptr = front;
        while (ptr != NULL) {
            ptr->waiting_time = t - ptr->arrival_time;
            if (ptr->waiting_time < 0)
                ptr->waiting_time = 0;
            ptr = ptr->next;
        }
        while (tail != NULL && tail->arrival_time <= t) {
            addProcessToFront(&front, tail);
            tail = tail->next;
        }
        if (front == NULL)
            t++;
        else {
            ptr = front;
            while (ptr != NULL) {
                if (ptr->remaining_time <= quantum) {
                    t += ptr->remaining_time;
                    ptr->remaining_time = 0;
                    ptr->completion_time = t;
                    ptr->turnaround_time = ptr->completion_time - ptr->arrival_time;
                    front = front->next;
                    addProcessToTail(&tail, ptr);
                } else {
                    t += quantum;
                    ptr->remaining_time -= quantum;
                    addProcessToTail(&tail, ptr);
                    removeProcessFromFront(&front);
                }
                ptr = front;
            }
        }
    }
    printf("PID\t ARRIVAL\t BURST\t COMPLETION\t TURNAROUND\t WAITING\n");
    for (i = 0; i < numProcesses; i++) {
        printf("%d\t %d\t\t %d\t %d\t\t %d\t\t %d\n", processes[i]->pid, processes[i]->arrival_time, processes[i]->burst_time, processes[i]->completion_time, processes[i]->turnaround_time, processes[i]->waiting_time);
        avgTurnaroundTime += processes[i]->turnaround_time;
        avgWaitingTime += processes[i]->waiting_time;
    }
    avgTurnaroundTime /= numProcesses;
    avgWaitingTime /= numProcesses;
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
    return 0;
}