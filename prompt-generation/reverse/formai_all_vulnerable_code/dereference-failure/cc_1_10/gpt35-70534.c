//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

//Custom struct for Process
struct Process {
    int pid; //Process ID
    int burst_time; //Burst Time
    int priority; //Priority Level
    int waiting_time; //Waiting Time
    int turnaround_time; //Turnaround Time
    int arrival_time; //Arrival Time
};

//Function to swap two processes
void swap(struct Process* a, struct Process* b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

//Function to sort processes based on their arrival time
void sortProcesses(struct Process* process, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (process[j].arrival_time > process[j + 1].arrival_time) {
                swap(&process[j], &process[j + 1]);
            }
        }
    }
}

//Function to calculate waiting time and turnaround time
void calculateTimes(struct Process* process, int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    process[0].waiting_time = 0;
    process[0].turnaround_time = process[0].burst_time;

    for (int i = 1; i < n; i++) {
        process[i].waiting_time = process[i - 1].waiting_time + process[i - 1].burst_time;
        process[i].turnaround_time = process[i].waiting_time + process[i].burst_time;
    }

    for (int i = 0; i < n; i++) {
        total_waiting_time += process[i].waiting_time;
        total_turnaround_time += process[i].turnaround_time;
    }

    float average_waiting_time = (float)total_waiting_time / (float)n;
    float average_turnaround_time = (float)total_turnaround_time / (float)n;

    printf("Average waiting time: %f\n", average_waiting_time);
    printf("Average turnaround time: %f\n", average_turnaround_time);
}

//FCFS Scheduling Algorithm
void fcfs(struct Process* process, int n) {
    printf("\nFCFS Scheduling Algorithm\n");
    sortProcesses(process, n);
    calculateTimes(process, n);
}

//SJF Scheduling Algorithm
void sjf(struct Process* process, int n) {
    printf("\nSJF Scheduling Algorithm\n");
    sortProcesses(process, n);
    int current_time = 0;
    int total_waiting_time = 0, total_turnaround_time = 0;

    printf("Process Execution Order: ");
    for (int i = 0; i < n; i++) {
        int shortest = i;
        for (int j = i + 1; j < n; j++) {
            if (process[j].burst_time < process[shortest].burst_time) {
                shortest = j;
            }
        }
        swap(&process[i], &process[shortest]);
        process[i].waiting_time = current_time;
        process[i].turnaround_time = current_time + process[i].burst_time;
        total_waiting_time += process[i].waiting_time;
        total_turnaround_time += process[i].turnaround_time;
        current_time += process[i].burst_time;
        printf("%d ", process[i].pid);
    }

    float average_waiting_time = (float)total_waiting_time / (float)n;
    float average_turnaround_time = (float)total_turnaround_time / (float)n;

    printf("\nAverage waiting time: %f\n", average_waiting_time);
    printf("Average turnaround time: %f\n", average_turnaround_time);
}

//Priority Scheduling Algorithm
void priority(struct Process* process, int n) {
    printf("\nPriority Scheduling Algorithm\n");
    sortProcesses(process, n);
    int current_time = 0;
    int total_waiting_time = 0, total_turnaround_time = 0;

    printf("Process Execution Order: ");
    for (int i = 0; i < n; i++) {
        int highest_priority = i;
        for (int j = i + 1; j < n; j++) {
            if (process[j].priority > process[highest_priority].priority) {
                highest_priority = j;
            }
        }
        swap(&process[i], &process[highest_priority]);
        process[i].waiting_time = current_time;
        process[i].turnaround_time = current_time + process[i].burst_time;
        total_waiting_time += process[i].waiting_time;
        total_turnaround_time += process[i].turnaround_time;
        current_time += process[i].burst_time;
        printf("%d ", process[i].pid);
    }

    float average_waiting_time = (float)total_waiting_time / (float)n;
    float average_turnaround_time = (float)total_turnaround_time / (float)n;

    printf("\nAverage waiting time: %f\n", average_waiting_time);
    printf("Average turnaround time: %f\n", average_turnaround_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    //Allocate memory for processes
    struct Process* process = (struct Process*)malloc(n * sizeof(struct Process));

    //Read process details from user
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &process[i].burst_time);

        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &process[i].priority);

        process[i].pid = i + 1; //Setting Process ID

        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &process[i].arrival_time);
    }

    fcfs(process, n); //FCFS Scheduling Algorithm
    sjf(process, n); //SJF Scheduling Algorithm
    priority(process, n); //Priority Scheduling Algorithm

    //Free allocated memory
    free(process);

    return 0;
}