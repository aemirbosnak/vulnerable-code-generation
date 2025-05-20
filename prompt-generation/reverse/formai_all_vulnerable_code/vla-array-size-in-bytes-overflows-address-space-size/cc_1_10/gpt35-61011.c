//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

// Task structure
struct Task {
    int id, arrival_time, burst_time, completion_time, waiting_time, turnaround_time, remaining_time;
};

// Function to perform the FCFS scheduling algorithm
void fcfs(struct Task tasks[], int n) {
    int current_time = 0;

    // Loop through each task and calculate its completion and waiting times
    for(int i = 0; i < n; i++) {
        // Set this task's completion time to the current time plus its burst time
        tasks[i].completion_time = current_time + tasks[i].burst_time;

        // Calculate this task's waiting time as the difference between its completion time and its arrival time
        tasks[i].waiting_time = tasks[i].completion_time - tasks[i].arrival_time - tasks[i].burst_time;

        // Update the current time to the completion time of this task
        current_time = tasks[i].completion_time;
    }

    // Calculate the turnaround time for each task
    for(int i = 0; i < n; i++) {
        tasks[i].turnaround_time = tasks[i].completion_time - tasks[i].arrival_time;
    }
}

// Function to perform the round-robin scheduling algorithm
void round_robin(struct Task tasks[], int n, int quantum) {
    int current_time = 0;

    // Loop through each task until all tasks are complete
    while(1) {
        int complete = 1;

        // Loop through each task and perform a single quantum of execution
        for(int i = 0; i < n; i++) {
            // If this task has remaining time to execute, continue executing it
            if(tasks[i].remaining_time > 0) {
                complete = 0;

                // If the remaining time for this task is less than the quantum,
                // execute the remaining time and update the current time accordingly
                if(tasks[i].remaining_time <= quantum) {
                    current_time += tasks[i].remaining_time;
                    tasks[i].remaining_time = 0;
                } 
                // Otherwise, execute a single quantum of time and update the remaining time
                else {
                    current_time += quantum;
                    tasks[i].remaining_time -= quantum;
                }

                // Check if this task has completed execution
                if(tasks[i].remaining_time == 0) {
                    // Calculate the completion time for this task
                    tasks[i].completion_time = current_time;

                    // Calculate the waiting time for this task
                    tasks[i].waiting_time = tasks[i].completion_time - tasks[i].arrival_time - tasks[i].burst_time;

                    // Calculate the turnaround time for this task
                    tasks[i].turnaround_time = tasks[i].completion_time - tasks[i].arrival_time;
                }
            }
        }

        // If all tasks have completed execution, stop the loop
        if(complete == 1) break;
    }
}

int main() {
    int n, algorithm, quantum;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    // Initialize the tasks with the input values
    struct Task tasks[n];
    for(int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for task %d: ", i+1);
        scanf("%d %d", &tasks[i].arrival_time, &tasks[i].burst_time);
        tasks[i].id = i+1;
        tasks[i].completion_time = 0;
        tasks[i].waiting_time = 0;
        tasks[i].turnaround_time = 0;
        tasks[i].remaining_time = tasks[i].burst_time;
    }

    // Get the scheduling algorithm choice from the user
    printf("Enter the scheduling algorithm to use (1 - FCFS, 2 - Round-Robin): ");
    scanf("%d", &algorithm);

    // If using Round-Robin, get the quantum from the user
    if(algorithm == 2) {
        printf("Enter the quantum size: ");
        scanf("%d", &quantum);
    }

    // Run the selected scheduling algorithm
    switch(algorithm) {
        case 1:
            fcfs(tasks, n);
            break;

        case 2:
            round_robin(tasks, n, quantum);
            break;

        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printf("\n");
    printf("ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");

    // Print the result table
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", tasks[i].id, tasks[i].arrival_time, tasks[i].burst_time, tasks[i].completion_time, tasks[i].waiting_time, tasks[i].turnaround_time);
    }

    return 0;
}