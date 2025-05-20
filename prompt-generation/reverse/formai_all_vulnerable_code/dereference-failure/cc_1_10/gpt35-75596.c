//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdbool.h>

#define QUANTUM 2 // Time slice for each process

// Struct for the process
typedef struct process {
    int pid; // Process ID
    int burst_time; // Time required to complete the process
    int remaining_time; // Remaining time needed to complete the process
} process;

// Queue structure for ready processes
typedef struct queue {
    process *pro; // Pointer to the process
    struct queue *next; // Pointer to the next process in the queue
} queue;

// Function to create a new process with given process ID and burst time
process *create_process(int pid, int burst_time) {
    process *pro = (process *) malloc(sizeof(process));
    pro->pid = pid;
    pro->burst_time = burst_time;
    pro->remaining_time = burst_time;
    return pro;
}

// Function to add a process to the ready queue
void enqueue(queue **ready_queue, process *pro) {
    queue *new_process = (queue *) malloc(sizeof(queue));
    new_process->pro = pro;
    new_process->next = NULL;
    if(*ready_queue == NULL) {
        *ready_queue = new_process;
    }
    else {
        queue *ptr = *ready_queue;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_process;
    }
    printf("Process %d added to the ready queue.\n", pro->pid);
}

// Function to remove a process from the ready queue
void dequeue(queue **ready_queue) {
    if(*ready_queue == NULL) {
        return;
    }
    queue *next_process;
    process *pro = (*ready_queue)->pro;
    next_process = (*ready_queue)->next;
    free(*ready_queue);
    *ready_queue = next_process;
    printf("Process %d removed from the ready queue.\n", pro->pid);
    free(pro);
}

// Function to check if the ready queue is empty
bool is_queue_empty(queue *ready_queue) {
    if(ready_queue == NULL) {
        return true;
    }
    return false;
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    process *processes[n]; // Array of processes
    queue *ready_queue = NULL; // Ready queue for the processes
    for(int i=0; i<n; i++) {
        int burst_time;
        printf("Enter the burst time for process %d: ", i+1);
        scanf("%d", &burst_time);
        processes[i] = create_process(i+1, burst_time);
        enqueue(&ready_queue, processes[i]);
    }
    int total_time = 0; // Total time elapsed
    while(!is_queue_empty(ready_queue)) {
        bool flag = false;
        process *pro = ready_queue->pro;
        dequeue(&ready_queue);
        printf("Process %d is executing.\n", pro->pid);
        int remaining_time = pro->remaining_time - QUANTUM;
        if(remaining_time <= 0) {
            total_time += (QUANTUM + remaining_time);
            printf("Process %d finished execution in %d units.\n", pro->pid, QUANTUM + remaining_time);
            pro->remaining_time = 0;
        }
        else {
            total_time += QUANTUM;
            pro->remaining_time = remaining_time;
            printf("Remaining burst time for process %d is %d units.\n", pro->pid, pro->remaining_time);
            flag = true;
        }
        for(int i=0; i<n; i++) {
            if(processes[i]->remaining_time > 0) {
                enqueue(&ready_queue, processes[i]);
            }
        }
        if(flag) {
            enqueue(&ready_queue, pro);
        }
    }
    float avg_wait_time = (float) total_time / n; // Average waiting time for the processes
    printf("Average waiting time for the processes is %.2f units.\n", avg_wait_time);
    return 0;
}