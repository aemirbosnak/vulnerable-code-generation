//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Creating a structure to represent a process.
struct process {
    int process_id;         // The ID of the process.
    int arrival_time;       // The arrival time of the process.
    int burst_time;         // The burst time of the process.
    int priority;           // The priority of the process.
    int waiting_time;       // The waiting time of the process.
    int turnaround_time;    // The turnaround time of the process.
    int completion_time;    // The completion time of the process.
};

// Function to sort the processes by arrival time.
void sort_by_arrival_time(struct process *p, int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].arrival_time > p[j].arrival_time) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// Function to display the processes.
void display_processes(struct process *p, int n) {
    printf("Process ID\tArrival Time\tBurst Time\tPriority\n");
    int i;
    for(i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].process_id, p[i].arrival_time, p[i].burst_time, p[i].priority);
    }
    printf("\n\n");
}

// Function to calculate the waiting time, turnaround time, and completion time of the processes.
void calculate_times(struct process *p, int n) {
    int time = 0;
    int i;
    for(i=0; i<n; i++) {
        time = time + p[i].burst_time;
        p[i].completion_time = time;                        // Calculating the completion time.
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time; // Calculating the turnaround time.
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;    // Calculating the waiting time.
    }
}

// Function to sort the processes by priority.
void sort_by_priority(struct process *p, int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].priority < p[j].priority) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// Function to print the average waiting time and average turnaround time of the processes.
void print_average_times(struct process *p, int n) {
    float avg_waiting_time = 0.0;
    float avg_turnaround_time = 0.0;
    int i;
    for(i=0; i<n; i++) {
        avg_waiting_time = avg_waiting_time + p[i].waiting_time;
        avg_turnaround_time = avg_turnaround_time + p[i].turnaround_time;
    }
    avg_waiting_time = avg_waiting_time/n;
    avg_turnaround_time = avg_turnaround_time/n;
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n\n", avg_turnaround_time);
}

// Main function.
int main() {

    // Taking the number of processes as input.
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Creating an array of processes.
    struct process *p = (struct process*)malloc(n * sizeof(struct process));

    // Taking the process details as input.
    int i;
    for(i=0; i<n; i++) {
        printf("Enter the arrival time, burst time, and priority of process %d separated by spaces: ", i);
        scanf("%d %d %d", &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
        p[i].process_id = i;
    }

    // Sorting the processes by arrival time.
    sort_by_arrival_time(p, n);

    // Displaying the processes.
    display_processes(p, n);

    // Calculating the waiting time, turnaround time, and completion time of the processes.
    calculate_times(p, n);

    // Sorting the processes by priority.
    sort_by_priority(p, n);

    // Displaying the processes.
    display_processes(p, n);

    // Printing the average waiting time and average turnaround time of the processes.
    print_average_times(p, n);

    // Freeing the memory.
    free(p);

    // Returning from main.
    return 0;

}