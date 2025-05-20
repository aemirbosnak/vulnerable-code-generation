//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include<stdio.h>

//Structure representing a process
struct Process {
    int id; // process ID
    int arrival_time; //arrival time of process
    int burst_time; //burst time of process
    int completion_time; //completion time of process
    int turn_around_time; //turn around time of process
    int waiting_time; //waiting time of process
    int remaining_time; //remaining time of process
};

//Function to implement Round Robin scheduling algorithm
void roundRobin(struct Process processes[], int n, int time_quantum) {
    int time = 0;
    int i;
    int completed = 0;
    int sum_waiting_time = 0;
    int sum_turn_around_time = 0;
 
    // keep looping until all processes are completed
    while (completed < n) {
        // Loop through all processes and execute for given time quantum
        for (i=0; i<n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time <= time_quantum) {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].completion_time = time;
                    completed++;
                    sum_turn_around_time += processes[i].completion_time - processes[1].arrival_time;
                    sum_waiting_time += processes[i].completion_time - processes[i].arrival_time - processes[i].burst_time;
                } else {
                    time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                }
            }
        }
    }

    //Compute Average waiting and average turn around time for all processes
    float avg_wait_time = sum_waiting_time / (float) n;
    float avg_turn_around_time = sum_turn_around_time / (float) n;

    //Print the output
    printf("Round Robin Scheduling (time quantum = %d):\n", time_quantum);
    printf("----------------------------------------------------------------------------------------\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurn Around Time\n");
    printf("----------------------------------------------------------------------------------------\n");
    for (i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
            processes[i].id,
            processes[i].arrival_time,
            processes[i].burst_time,
            processes[i].completion_time,
            processes[i].completion_time - processes[i].arrival_time - processes[i].burst_time,
            processes[i].completion_time - processes[i].arrival_time);
    }

    printf("----------------------------------------------------------------------------------------\n");
    printf("Average Waiting Time: %f\n", avg_wait_time);
    printf("Average Turn-around Time: %f\n", avg_turn_around_time);
    printf("----------------------------------------------------------------------------------------\n");
}

int main() {
    int n;
    int time_quantum;
    int i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    //Get the details of all processes
    for (i=0; i<n; i++) {
        printf("Enter the arrival time and burst time for Process %d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].id = i+1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter the time quantum for Round Robin scheduling: ");
    scanf("%d", &time_quantum);

    //Call round robin function to execute the algorithm
    roundRobin(processes, n, time_quantum);

    return 0;
}