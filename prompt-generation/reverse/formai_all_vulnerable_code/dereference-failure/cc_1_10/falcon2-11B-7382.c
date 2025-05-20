//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <pthread.h>

#define NUM_PROCESSES 10
#define TASK_PERIOD 100
#define NUM_THREADS 3

// Structure to represent a process
struct process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
};

// Structure to represent a thread
struct thread {
    pthread_t thread_id;
    struct process* process;
};

// Function to create a new process
struct process* create_process(int id, int arrival_time, int burst_time) {
    struct process* process = malloc(sizeof(struct process));
    process->id = id;
    process->arrival_time = arrival_time;
    process->burst_time = burst_time;
    process->remaining_time = burst_time;
    return process;
}

// Function to calculate the remaining time for a process
void update_remaining_time(struct process* process) {
    process->remaining_time = process->burst_time - (clock() - process->arrival_time);
}

// Function to print the status of a process
void print_process(struct process* process) {
    printf("Process ID: %d\n", process->id);
    printf("Arrival Time: %d\n", process->arrival_time);
    printf("Burst Time: %d\n", process->burst_time);
    printf("Remaining Time: %d\n", process->remaining_time);
}

// Function to run a process on a thread
void* run_process(void* arg) {
    struct thread* thread = (struct thread*)arg;
    struct process* process = thread->process;
    
    // Sleep for the remaining time of the process
    clock_t remaining_time = process->remaining_time;
    while (remaining_time > 0) {
        sleep(remaining_time);
        remaining_time = process->remaining_time;
    }
    
    // Print the status of the process
    printf("Process %d finished running\n", process->id);
    
    // Delete the process
    free(process);
    return NULL;
}

// Function to create a new thread
struct thread* create_thread(struct process* process) {
    struct thread* thread = malloc(sizeof(struct thread));
    thread->process = process;
    pthread_create(&thread->thread_id, NULL, run_process, thread);
    return thread;
}

// Function to start the CPU scheduler
void start_scheduler() {
    srand(time(NULL));
    
    // Create processes
    struct process* processes[NUM_PROCESSES];
    for (int i = 0; i < NUM_PROCESSES; i++) {
        int arrival_time = rand() % TASK_PERIOD;
        int burst_time = rand() % TASK_PERIOD;
        processes[i] = create_process(i, arrival_time, burst_time);
    }
    
    // Start the scheduler
    for (int i = 0; i < NUM_THREADS; i++) {
        struct thread* thread = create_thread(processes[i % NUM_PROCESSES]);
        pthread_join(thread->thread_id, NULL);
    }
}

int main() {
    start_scheduler();
    return 0;
}