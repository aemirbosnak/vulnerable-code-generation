//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
#include <stdio.h>

// Defining Processes structure
struct Process {
    int pid; //Process ID
    int arrival_time; // Arrival Time
    int burst_time; // Burst Time
    int waiting_time; // Waiting Time
    int turnaround_time; // Turnaround Time
    int remaining_time; // Remaining Burst Time
    int completed; // Completed Flag
};

// Function to find the minimum arrival time process
int find_minimum_arrival_time_process(struct Process processes[], int n) {
    int min_arrival_time = 99999;
    int min_arrival_time_process = -1;
    
    // Loop through all processes
    for(int i=0; i<n; i++) {
        // If process is not completed and its arrival time is less than min_arrival_time
        if(processes[i].completed == 0 && processes[i].arrival_time < min_arrival_time) {
            min_arrival_time = processes[i].arrival_time;
            min_arrival_time_process = i;
        }
    }
    return min_arrival_time_process;
}

// Function to implement Shortest Remaining Time First CPU Scheduling Algorithm
void shortest_remaining_time_first(struct Process processes[], int n) {
    int time = 0;
    int completed_processes = 0;

    // Loop until all processes are completed
    while(completed_processes < n) {
        int process_index = find_minimum_arrival_time_process(processes, n);

        // If no processes has arrived yet at this time, move ahead in time
        if(process_index == -1) {
            time += 1;
            continue;
        }

        // Find the process with shortest remaining burst time
        for(int i=0; i<n; i++) {
            if(processes[i].completed == 0 && processes[i].arrival_time <= time && processes[i].remaining_time < processes[process_index].remaining_time) {
                process_index = i;
            }
        }

        // Process execution starting
        processes[process_index].remaining_time -= 1;

        // Checking if process completion has occured
        if(processes[process_index].remaining_time == 0) {
            processes[process_index].completed = 1;

            completed_processes++;

            // Updating Completion Time
            processes[process_index].turnaround_time = time + 1 - processes[process_index].arrival_time;

            // Updating Waiting Time
            processes[process_index].waiting_time = processes[process_index].turnaround_time - processes[process_index].burst_time;
        }

        time += 1;
    }

    // Printing Final Output
    printf("Shortest Remaining Time First Scheduling Algorithm Output\n");
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    int average_waiting_time = 0;
    int average_turnaround_time = 0;

    for(int i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
        average_waiting_time += processes[i].waiting_time;
        average_turnaround_time += processes[i].turnaround_time;
    }

    average_waiting_time /= n;
    average_turnaround_time /= n;
    printf("Average Waiting Time: %d\n", average_waiting_time);
    printf("Average Turnaround Time: %d", average_turnaround_time);
}

// Function to initialize processes from user input
void initialize_processes(struct Process processes[], int n) {
    for(int i=0; i<n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].pid = i+1;
    }
}

// Main Function
int main() {
    int n;

    // Accepting number of processes from user
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    initialize_processes(processes, n);

    shortest_remaining_time_first(processes, n);

    return 0;
}