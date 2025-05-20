//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define the process structure
typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Define the queue structure
typedef struct {
    Process **processes;
    int front;
    int rear;
} Queue;

// Create a process instance
Process* create_process(int id, int arrival_time, int burst_time, int priority) {
    Process *new_process = (Process*) malloc(sizeof(Process));
    new_process->id = id;
    new_process->arrival_time = arrival_time;
    new_process->burst_time = burst_time;
    new_process->priority = priority;
    new_process->remaining_time = burst_time;
    new_process->completion_time = 0;
    new_process->waiting_time = 0;
    new_process->turnaround_time = 0;
    return new_process;
}

// Start the execution of a process
void execute_process(Process *process, int time) {
    printf("[%d]: Process %d started execution.\n", time, process->id);
}

// Finish the execution of a process
void complete_process(Process *process, int time) {
    process->remaining_time = 0;
    process->completion_time = time;
    process->turnaround_time = process->completion_time - process->arrival_time;
    process->waiting_time = process->turnaround_time - process->burst_time;
    printf("[%d]: Process %d completed execution.\n", time, process->id);
}

// Add a process to the queue
void enqueue(Queue *queue, Process *process) {
    queue->rear++;
    queue->processes[queue->rear] = process;
}

// Remove and return the next process from the queue
Process* dequeue(Queue *queue) {
    queue->front++;
    return queue->processes[queue->front];
}

// Check if the queue is empty
int is_empty(Queue *queue) {
    return queue->front == queue->rear;
}

// Perform the Priority scheduling algorithm
void priority_scheduling(Process **processes, int num_processes) {
    int time = 0;
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->processes = (Process**) malloc(sizeof(Process) * num_processes);
    queue->front = -1;
    queue->rear = -1;
    while (1) {
        // Add any arriving processes to the queue
        for (int i = 0; i < num_processes; i++) {
            if (processes[i]->arrival_time == time) {
                enqueue(queue, processes[i]);
            }
        }
        // If there are no processes remaining, end the simulation
        if (is_empty(queue)) {
            printf("[%d]: No more processes remaining.\n", time);
            break;
        }
        // Find the process with the highest priority
        Process *highest_priority_process = NULL;
        int highest_priority = -1;
        for (int i = queue->front + 1; i <= queue->rear; i++) {
            if (queue->processes[i]->remaining_time > 0 && queue->processes[i]->priority > highest_priority) {
                highest_priority_process = queue->processes[i];
                highest_priority = highest_priority_process->priority;
            }
        }
        // Execute the highest priority process for 1 time slice
        if (highest_priority_process != NULL) {
            execute_process(highest_priority_process, time);
            highest_priority_process->remaining_time--;
            // If the process has run to completion, remove it from the queue
            if (highest_priority_process->remaining_time == 0) {
                complete_process(highest_priority_process, time);
            }
        }
        // Advance the time by 1
        time++;
    }
    // Print the final statistics
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", processes[i]->id, processes[i]->arrival_time, processes[i]->burst_time, processes[i]->priority, processes[i]->completion_time, processes[i]->waiting_time, processes[i]->turnaround_time);
    }
}

int main() {
    int num_processes = 4;
    Process *p1 = create_process(1, 0, 3, 1);
    Process *p2 = create_process(2, 2, 6, 2);
    Process *p3 = create_process(3, 4, 4, 3);
    Process *p4 = create_process(4, 6, 2, 4);
    Process *processes[] = {p1, p2, p3, p4};
    priority_scheduling(processes, num_processes);
    return 0;
}