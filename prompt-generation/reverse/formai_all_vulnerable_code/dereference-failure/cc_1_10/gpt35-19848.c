//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the order of execution of processes

void print_execution_order(int process_order[], int n) {
    
    printf("\n\n");
    for(int i=0; i<n; i++) {
        printf("P%d ",process_order[i]);
    }
    printf("\n\n");
}

// Function to swap the values of 2 integers

void swap(int *a, int *b) {
    
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the processes in increasing order of arrival time

void sort_arrival_time(int arrival_time[], int burst_time[], int n) {
    
    for(int i=0; i<n-1; i++) {
        
        for(int j=0; j<n-i-1; j++) {
            
            if(arrival_time[j] > arrival_time[j+1]) {
                swap(&arrival_time[j], &arrival_time[j+1]);
                swap(&burst_time[j], &burst_time[j+1]);
            }
        }
    }
}

// Function to implement Round Robin scheduling algorithm

void round_robin(int process_id[], int arrival_time[], int burst_time[], int quantum_time, int n) {
    
    int completion_time[n];
    int turnaround_time[n];
    int waiting_time[n];
    int remaining_time[n];
    int process_order[n];
    int current_time = 0;
    int remaining_processes = n;
    int front = 0, rear = -1;
    
    // Initializing remaining time of all processes to their burst time
    
    for(int i=0; i<n; i++) {
        remaining_time[i] = burst_time[i];
    }
    
    // Implementing Queue for Round Robin scheduling
    
    while(remaining_processes != 0) {
        
        // Traversing through the processes
        
        for(int i=0; i<n; i++) {
            
            if(arrival_time[i] <= current_time && remaining_time[i] > 0) {
                
                // Checking if the process has been enqueued previously
                
                bool already_enqueued = false;
                for(int j=front; j<=rear; j++) {
                    if(process_order[j] == process_id[i]) {
                        already_enqueued = true;
                    }
                }
                
                // If the process has not been enqueued, add to queue
                
                if(!already_enqueued) {
                    process_order[++rear] = process_id[i];
                }
            }
        }
        
        // If the queue is not empty, do the following
        
        if(front <= rear) {
            
            int current_process = process_order[front++];
            remaining_time[current_process-1] -= quantum_time;
            
            // If the burst time of the process is less than or equal to the quantum time
            
            if(remaining_time[current_process-1] <= 0) {
            
                remaining_processes--;
                
                completion_time[current_process-1] = current_time + quantum_time + remaining_time[current_process-1];
                turnaround_time[current_process-1] = completion_time[current_process-1] - arrival_time[current_process-1];
                waiting_time[current_process-1] = turnaround_time[current_process-1] - burst_time[current_process-1];
                
                current_time = completion_time[current_process-1];
            }
            
            // If the burst time of the process is greater than the quantum time
            
            else {
                current_time += quantum_time;
            }
        }
        
        // If the queue is empty, go to the next process
        
        else {
            current_time++;
        }
    }
    
    // Printing the results
    
    printf("\n\nRound Robin Scheduling Results:\n\n");
    
    printf("Process_ID \t Arrival_time \t Burst_time \t Completion_time \t Turnaround_time \t Waiting_time \n\n");
    
    for(int i=0; i<n; i++) {
        
        printf("%d \t\t %d \t\t %d \t\t %d \t\t\t %d \t\t\t %d \n", process_id[i], arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }
    
    print_execution_order(process_order, n);
    
}

// Driver function to implement CPU Scheduling

int main() {
    
    int n;                          // Number of processes
    int *process_id;                // Array to store Process IDs
    int *arrival_time;              // Array to store Arrival Times of Processes
    int *burst_time;                // Array to store Burst Times of Processes
    int quantum_time;               // Quantum Time for Round Robin Scheduling
    
    // Getting the inputs from user
    
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    
    process_id = (int*)malloc(n*sizeof(int));
    arrival_time = (int*)malloc(n*sizeof(int));
    burst_time = (int*)malloc(n*sizeof(int));
    
    printf("Enter the details of each process:\n");
    
    for(int i=0; i<n; i++) {
        
        printf("Process %d:\n",i+1);
        
        printf("Process ID: ");
        scanf("%d",&process_id[i]);
        
        printf("Arrival Time: ");
        scanf("%d",&arrival_time[i]);
        
        printf("Burst Time: ");
        scanf("%d",&burst_time[i]);
    }
    
    printf("Enter the Quantum Time for Round Robin Scheduling: ");
    scanf("%d",&quantum_time);
    
    // Printing the inputs
    
    printf("\n\nInputs:\n\n");
    
    printf("Process_ID \t Arrival_time \t Burst_time \n\n");
    
    for(int i=0; i<n; i++) {
        
        printf("%d \t\t %d \t\t %d \n", process_id[i], arrival_time[i], burst_time[i]);
    }
    
    sort_arrival_time(arrival_time, burst_time, n);
    
    round_robin(process_id, arrival_time, burst_time, quantum_time, n);
    
    return 0;
}