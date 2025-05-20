//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 50

typedef struct {
    char name[MAX_PROCESS_NAME];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void FCFS(Process processes[], int num_processes) {
    int completed_processes = 0;
    int current_time = 0;

    while (completed_processes < num_processes) {
        int i;
        for (i = 0; i < num_processes; i++) {
            if (processes[i].waiting_time == 0 && processes[i].burst_time > current_time) {
                current_time += processes[i].burst_time;
                processes[i].waiting_time = current_time - processes[i].burst_time;
                completed_processes++;
            } else if (processes[i].waiting_time > 0) {
                processes[i].waiting_time--;
            }
        }
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\n", processes[i].name, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    Process processes[num_processes];

    printf("\nEnter process details:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d:\n", i+1);
        printf("Name: ");
        scanf("%s", processes[i].name);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    FCFS(processes, num_processes);

    return 0;
}