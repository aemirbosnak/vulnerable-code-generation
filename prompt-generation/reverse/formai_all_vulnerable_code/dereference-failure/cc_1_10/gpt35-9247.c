//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>  // for sleep function
#include<time.h>    // for random seed generator
#include<stdbool.h>
#include<limits.h>  // for INT_MIN and INT_MAX

#define MAX_PROCESS 10  // maximum number of processes allowed
#define MIN_BURST_TIME 1  // minimum burst time allowed
#define MAX_BURST_TIME 10  // maximum burst time allowed
#define MIN_ARRIVAL_TIME 0  // minimum arrival time allowed
#define MAX_ARRIVAL_TIME 20  // maximum arrival time allowed

// structure to hold details of a process
struct process{
    int process_id;  // unique identifier for a process
    int arrival_time;  // time when the process arrives in ready queue
    int burst_time;  // total time required for the process to complete
    int remaining_time;  // time remaining for the process to complete
    int waiting_time;  // time the process has been waiting in ready queue
};

// function to generate a random number between min and max
int random_number(int min, int max){
    static bool initialized = false;
    if(!initialized){
        srand(time(NULL));  // initializing random number generator
        initialized = true;
    }
    return (rand() % (max - min + 1)) + min;
}

// function to initialize the processes
void initialize_processes(struct process* processes, int num_processes){
    for(int i=0; i<num_processes; i++){
        processes[i].process_id = i+1;
        processes[i].arrival_time = random_number(MIN_ARRIVAL_TIME, MAX_ARRIVAL_TIME);
        processes[i].burst_time = random_number(MIN_BURST_TIME, MAX_BURST_TIME);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
    }
}

// function to print the details of all processes
void display_processes(struct process* processes, int num_processes){
    printf("\nProcess\tArrival Time\tBurst Time\n");
    for(int i=0; i<num_processes; i++){
        printf("%d\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time);
    }
}

// function to sort the processes by their arrival time
void sort_by_arrival_time(struct process* processes, int num_processes){
    for(int i=0; i<num_processes; i++){
        for(int j=i+1; j<num_processes; j++){
            if(processes[i].arrival_time > processes[j].arrival_time){
                // swap the processes
                struct process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// function to find the process with minimum remaining time
int find_min_remaining_time(struct process* processes, int num_processes){
    int min_time = INT_MAX;
    int min_index = -1;
    for(int i=0; i<num_processes; i++){
        if(processes[i].remaining_time < min_time){
            min_time = processes[i].remaining_time;
            min_index = i;
        }
    }
    return min_index;
}

// function to implement shortest remaining time first scheduling algorithm
void shortest_remaining_time_first(struct process* processes, int num_processes){
    int current_time = 0;  // current time in simulation
    int completed_processes = 0;  // number of processes completed so far
    int current_process = -1;  // index of process currently executing
    bool* process_completed = calloc(num_processes, sizeof(bool));  // array to keep track of completed processes
    if(process_completed == NULL){
        printf("\nMemory allocation error!\n");
        exit(1);
    }
    while(completed_processes < num_processes){
        int min_time_index = find_min_remaining_time(processes, num_processes);
        if(min_time_index == -1){  // no process in ready queue
            printf("Idle for 1 second...\n");
            current_time++;
            continue;
        }
        if(current_process == -1){  // no process currently executing
            current_process = min_time_index;
            printf("Process %d starts executing at time %d.\n", processes[current_process].process_id, current_time);
        }
        else if(min_time_index != current_process){  // context switch needed
            printf("Context switch from process %d to process %d at time %d.\n", processes[current_process].process_id, processes[min_time_index].process_id, current_time);
            processes[current_process].waiting_time += current_time - processes[current_process].arrival_time;
            current_process = min_time_index;
        }
        processes[current_process].remaining_time--;
        if(processes[current_process].remaining_time == 0){  // current process completed
            printf("Process %d completed at time %d.\n", processes[current_process].process_id, current_time+1);
            process_completed[current_process] = true;
            completed_processes++;
            current_process = -1;  // mark no process currently executing
        }
        current_time++;
        sleep(1);  // simulate 1 second
    }
    float total_waiting_time = 0.0;
    for(int i=0; i<num_processes; i++){
        total_waiting_time += processes[i].waiting_time;
    }
    printf("\nAverage waiting time: %.2f seconds\n", total_waiting_time/num_processes);
}

// main function
int main(){
    int num_processes = random_number(1, MAX_PROCESS);
    struct process* processes = malloc(num_processes * sizeof(struct process));
    if(processes == NULL){
        printf("\nMemory allocation error!\n");
        exit(1);
    }
    initialize_processes(processes, num_processes);
    display_processes(processes, num_processes);
    sort_by_arrival_time(processes, num_processes);
    shortest_remaining_time_first(processes, num_processes);
    free(processes);
    return 0;
}