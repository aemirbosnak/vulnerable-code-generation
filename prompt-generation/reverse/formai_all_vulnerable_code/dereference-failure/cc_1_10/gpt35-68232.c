//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int pid;
    int burst_time;
    int priority;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

void fcfs_scheduling(Process *process_list, int num_processes);
void sjf_scheduling(Process *process_list, int num_processes);
void priority_scheduling(Process *process_list, int num_processes);

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    Process *process_list = (Process*) malloc(num_processes * sizeof(Process));

    printf("Enter burst time and priority for each process:\n");
    for (int i = 0; i < num_processes; i++) {
        process_list[i].pid = i+1;
        printf("P%d: ", i+1);
        scanf("%d %d", &process_list[i].burst_time, &process_list[i].priority);
    }

    printf("\n----- FCFS Scheduling -----\n");
    fcfs_scheduling(process_list, num_processes);
    printf("\n----- SJF Scheduling -----\n");
    sjf_scheduling(process_list, num_processes);
    printf("\n----- Priority Scheduling -----\n");
    priority_scheduling(process_list, num_processes);

    free(process_list);
    return 0;
}

void fcfs_scheduling(Process *process_list, int num_processes) {
    int time = 0;
    for (int i = 0; i < num_processes; i++) {
        process_list[i].completion_time = time + process_list[i].burst_time;
        process_list[i].turnaround_time = process_list[i].completion_time;
        process_list[i].waiting_time = time;

        time = process_list[i].completion_time;
    }

    printf("PID\tBurst Time\tCompletion Time\tTurnaround Time\tWait Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", process_list[i].pid, 
                                                    process_list[i].burst_time,
                                                    process_list[i].completion_time,
                                                    process_list[i].turnaround_time,
                                                    process_list[i].waiting_time);
    }
}

void sjf_scheduling(Process *process_list, int num_processes) {
    Process *sorted_list = (Process*) malloc(num_processes * sizeof(Process));
    for (int i = 0; i < num_processes; i++) {
        sorted_list[i] = process_list[i];
    }

    for (int i = 0; i < num_processes-1; i++) {
        for (int j = 0; j < num_processes-i-1; j++) {
            if (sorted_list[j].burst_time > sorted_list[j+1].burst_time) {
                Process temp = sorted_list[j];
                sorted_list[j] = sorted_list[j+1];
                sorted_list[j+1] = temp;
            }
        }
    }

    fcfs_scheduling(sorted_list, num_processes);
    free(sorted_list);
}

void priority_scheduling(Process *process_list, int num_processes) {
    Process *sorted_list = (Process*) malloc(num_processes * sizeof(Process));
    for (int i = 0; i < num_processes; i++) {
        sorted_list[i] = process_list[i];
    }

    for (int i = 0; i < num_processes-1; i++) {
        for (int j = 0; j < num_processes-i-1; j++) {
            if (sorted_list[j].priority < sorted_list[j+1].priority) {
                Process temp = sorted_list[j];
                sorted_list[j] = sorted_list[j+1];
                sorted_list[j+1] = temp;
            }
        }
    }

    fcfs_scheduling(sorted_list, num_processes);
    free(sorted_list);
}