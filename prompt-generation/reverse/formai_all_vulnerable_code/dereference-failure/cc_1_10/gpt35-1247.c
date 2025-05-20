//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include<stdio.h>
#include<stdlib.h>

// Custom function to sort processes according to arrival time
void sort_processes(int** process_info, int num_processes)
{
    for(int i=0;i<num_processes-1;i++)
    {
        for(int j=0;j<num_processes-i-1;j++)
        {
            if(process_info[j][1]>process_info[j+1][1])
            {
                int* temp = process_info[j];
                process_info[j] = process_info[j+1];
                process_info[j+1] = temp;
            }
        }
    }
}

// Custom function to find the index of process with minimum burst time
int get_min_burst_time(int** process_info, int num_processes)
{
    int min_burst_time = 9999;
    int min_burst_time_index = -1;
    for(int i=0;i<num_processes;i++)
    {
        if(process_info[i][2]<min_burst_time && process_info[i][2]!=0)
        {
            min_burst_time = process_info[i][2];
            min_burst_time_index = i;
        }
    }
    return min_burst_time_index;
}

int main()
{
    printf("***** WELCOME TO THE CPU SCHEDULING ALGORITHM *****\n\n");

    // Get number of processes from user
    int num_processes;
    printf("Please enter the number of processes to schedule: ");
    scanf("%d",&num_processes);

    // Create a 2D dynamic array to store process information
    int** process_info = (int**)malloc(num_processes*sizeof(int*));
    for(int i=0;i<num_processes;i++)
    {
        process_info[i] = (int*)malloc(3*sizeof(int));
    }

    // Get process information from user
    for(int i=0;i<num_processes;i++)
    {
        printf("\n**** PROCESS %d ****\n",i+1);

        printf("Please enter the arrival time of process %d: ",i+1);
        scanf("%d",&process_info[i][1]);

        printf("Please enter the burst time of process %d: ",i+1);
        scanf("%d",&process_info[i][2]);

        process_info[i][0] = i+1;
    }

    // Sort the processes according to arrival time
    sort_processes(process_info,num_processes);

    // Initialize variables for calculating waiting time, turnaround time and average time
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    float average_waiting_time = 0;
    float average_turnaround_time = 0;

    // Initialize clock and current process index
    int current_time = 0;
    int current_process_index = 0;

    // Print initial status
    printf("\n\n**** CURRENT STATUS (at time 0) ****\n");
    printf("CURRENT PROCESS: NONE\n");
    printf("WAITING PROCESSES: ");
    for(int i=0;i<num_processes;i++)
    {
        printf("P%d ",process_info[i][0]);
    }
    printf("\n\n");

    // Run scheduling algorithm
    while(current_process_index<num_processes)
    {
        // Search for process with minimum burst time
        current_process_index = get_min_burst_time(process_info,num_processes);

        // If no process is running at this time, start the first process
        if(current_time==0 && current_process_index!=-1)
        {
            printf("\n*** Starting process P%d at time %d ***\n\n",process_info[current_process_index][0],process_info[current_process_index][1]);
            current_time = process_info[current_process_index][1] + process_info[current_process_index][2];
            total_waiting_time += 0;
            total_turnaround_time += current_time - process_info[current_process_index][1];
            process_info[current_process_index][2] = 0;
        }
        // If there is a running process, check if the current process has arrived
        else if(current_process_index!=-1 && process_info[current_process_index][1]<=current_time)
        {
            printf("\n*** Switching from process P%d to P%d at time %d ***\n\n",process_info[current_process_index-1][0],process_info[current_process_index][0],current_time);
            total_waiting_time += current_time - process_info[current_process_index][1];
            total_turnaround_time += current_time + process_info[current_process_index][2] - process_info[current_process_index][1];
            current_time += process_info[current_process_index][2];
            process_info[current_process_index][2] = 0;
        }
        // If no process has arrived yet, increment clock
        else
        {
            current_time++;
        }
    }

    // Calculate average waiting time and turnaround time
    average_waiting_time = (float)total_waiting_time/num_processes;
    average_turnaround_time = (float)total_turnaround_time/num_processes;

    // Print final results
    printf("\n***** FINAL RESULTS *****\n");
    printf("AVERAGE WAITING TIME: %.2f\n",average_waiting_time);
    printf("AVERAGE TURNAROUND TIME: %.2f\n",average_turnaround_time);

    // Free memory
    for(int i=0;i<num_processes;i++)
    {
        free(process_info[i]);
    }
    free(process_info);

    return 0;
}