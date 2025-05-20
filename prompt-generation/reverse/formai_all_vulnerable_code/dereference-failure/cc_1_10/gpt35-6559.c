//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

// Define process struct
typedef struct Process
{
    int pid; // process id
    int burst_time; // time required to complete execution
    int wait_time; // time spent waiting in the queue
    int turnaround_time; // total time spent by a process in the queue (wait + execution)
    int arrival_time; // time at which the process arrives in the queue
} Process;

// Function that returns the average waiting time and average turnaround time
void execute_scheduling_algorithm(Process *processes, int num_processes, char *algorithm)
{
    int total_wait_time = 0;
    int total_turnaround_time = 0;

    // Execute selected scheduling algorithm
    if(strcmp(algorithm, "FCFS") == 0) // First Come First Serve
    {
        int current_time = processes[0].arrival_time; // Initialize current time with arrival time of first process

        for(int i = 0; i < num_processes; i++)
        {
            if(processes[i].arrival_time > current_time) // If next process arrival time is larger than current time. Increment the current time upto the arrival time of next process.
                current_time = processes[i].arrival_time;

            processes[i].wait_time = current_time - processes[i].arrival_time; // Calculate wait time
            processes[i].turnaround_time = processes[i].wait_time + processes[i].burst_time; // Calculate turnaround time
            total_wait_time += processes[i].wait_time; // Add the wait time to the total wait time
            total_turnaround_time += processes[i].turnaround_time; // Add the turnaround time to the total turnaround time
            current_time += processes[i].burst_time; // Update the current time
        }
    }
    else if(strcmp(algorithm, "SJF") == 0) // Shortest Job First
    {
        int current_time = 0;
        int completed_processes = 0;

        while(completed_processes < num_processes)
        {
            int next_process_index = -1;
            int shortest_burst_time = -1;

            for(int i = 0; i < num_processes; i++)
            {
                if(processes[i].burst_time > 0 && processes[i].arrival_time <= current_time) // If process has not been completed and has arrived
                {
                    if(next_process_index == -1) // If no process has been selected yet
                    {
                        next_process_index = i;
                        shortest_burst_time = processes[i].burst_time;
                    }
                    else if(processes[i].burst_time < shortest_burst_time) // Compare burst time with previous selected process
                    {
                        next_process_index = i;
                        shortest_burst_time = processes[i].burst_time;
                    }
                }
            }

            if(next_process_index == -1) // If no process is available to execute
            {
                current_time++;
            }
            else // If a process is available to execute
            {
                processes[next_process_index].wait_time = current_time - processes[next_process_index].arrival_time; // Calculate wait time
                processes[next_process_index].turnaround_time = processes[next_process_index].wait_time + processes[next_process_index].burst_time; // Calculate turnaround time
                total_wait_time += processes[next_process_index].wait_time; // Add the wait time to the total wait time
                total_turnaround_time += processes[next_process_index].turnaround_time; // Add the turnaround time to the total turnaround time
                current_time += processes[next_process_index].burst_time; // Update the current time
                processes[next_process_index].burst_time = 0; // Mark the process as completed
                completed_processes++;
            }
        }
    }
    else // Invalid algorithm
    {
        printf("Invalid CPU scheduling algorithm specified\n");
        return;
    }

    // Print the wait time and turnaround time of each process
    printf("\nProcess ID\tWait Time\tTurnaround Time\n");
    for(int i = 0; i < num_processes; i++)
    {
        printf("%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].wait_time, processes[i].turnaround_time);
    }

    // Calculate and print the average wait time and average turnaround time
    double avg_wait_time = (double)total_wait_time / num_processes;
    double avg_turnaround_time = (double)total_turnaround_time / num_processes;
    printf("\nAverage Wait Time: %.2lf\nAverage Turnaround Time: %.2lf\n", avg_wait_time, avg_turnaround_time);
}

int main()
{
    srand(time(NULL));

    int num_processes = 5;
    Process *processes = malloc(num_processes * sizeof(Process));

    // Generate random processes
    for(int i = 0; i < num_processes; i++)
    {
        processes[i].pid = i + 1;
        processes[i].burst_time = rand() % 11 + 1;
        processes[i].wait_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].arrival_time = rand() % 5;
    }

    printf("Processes\n");
    printf("Process ID\tBurst Time\tArrival Time\n");
    for(int i = 0; i < num_processes; i++)
    {
        printf("%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time);
    }

    char algorithm[10];

    printf("\nEnter the CPU scheduling algorithm to simulate (FCFS / SJF): ");
    scanf("%s", algorithm);

    execute_scheduling_algorithm(processes, num_processes, algorithm);

    return 0;
}