//FormAI DATASET v1.0 Category: System boot optimizer ; Style: satisfied
#include<stdio.h>
#include<math.h>

int main()
{
    // Displaying welcome message
    printf("Welcome to C System boot optimizer!\n");
    
    // Initializing variables
    int num_of_processes, boot_time;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    
    // Getting user input
    printf("Enter the number of processes: ");
    scanf("%d", &num_of_processes);
    
    printf("Enter the boot time: ");
    scanf("%d", &boot_time);
    
    // Initializing arrays
    int arrival_time[num_of_processes], burst_time[num_of_processes], completion_time[num_of_processes], turnaround_time[num_of_processes], wait_time[num_of_processes], remaining_time[num_of_processes];
    
    // Getting process arrival time and burst time from user
    for(int i=0; i<num_of_processes; i++)
    {
        printf("Enter the arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }
    
    // Applying SJF algorithm for optimal scheduling
    int completed_processes = 0, current_time = 0, shortest_process = 0;
    int min_remaining_time = 9999, flag = 0;
    
    while(completed_processes != num_of_processes)
    {
        for(int i=0; i<num_of_processes; i++)
        {
            if(arrival_time[i] <= current_time && remaining_time[i] < min_remaining_time && remaining_time[i] > 0)
            {
                shortest_process = i;
                min_remaining_time = remaining_time[i];
                flag = 1;
            }
        }
        
        if(flag == 0)
        {
            current_time++;
            continue;
        }
        
        // Processing current shortest process
        remaining_time[shortest_process]--;
        min_remaining_time = remaining_time[shortest_process];
        
        // Checking if process is completed
        if(remaining_time[shortest_process] == 0)
        {
            completed_processes++;
            flag = 0;
            
            // Completion time
            completion_time[shortest_process] = current_time + 1;
            
            // Turnaround time
            turnaround_time[shortest_process] = completion_time[shortest_process] - arrival_time[shortest_process];
            
            // Wait time
            wait_time[shortest_process] = turnaround_time[shortest_process] - burst_time[shortest_process];
            
            // Calculating average wait time and average turnaround time
            avg_turnaround_time += turnaround_time[shortest_process];
            avg_wait_time += wait_time[shortest_process];
        }
        
        // Incrementing current time
        current_time++;
    }
    
    avg_turnaround_time /= num_of_processes;
    avg_wait_time /= num_of_processes;
    
    int boot_optimized_time = current_time + boot_time;
    
    // Displaying results
    printf("\n");
    printf("Total time taken to complete all processes: %d\n", current_time);
    printf("Average turnaround time: %f\n", avg_turnaround_time);
    printf("Average wait time: %f\n", avg_wait_time);
    printf("Boot optimized time for the system: %d\n", boot_optimized_time);
    
    // Exiting program
    return 0;
}