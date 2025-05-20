//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100 // Maximum size of the queue

/* Process structure containing information about a process */
typedef struct {
    int pid;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int waiting_time;
} Process;

/* Queue structure containing an array of processes and some queue variables */
typedef struct {
    Process *processes;
    int front;
    int rear;
    int size;
} Queue;

/* Function to initialize a queue */
void init_queue(Queue *q) {
    q->processes = (Process *) malloc(MAX_QUEUE_SIZE * sizeof(Process));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

/* Function to check if a queue is empty */
int is_queue_empty(Queue *q) {
    return q->size == 0;
}

/* Function to check if a queue is full */
int is_queue_full(Queue *q) {
    return q->size == MAX_QUEUE_SIZE;
}

/* Function to add a process to the end of the queue */
void enqueue(Queue *q, Process process) {
    if (is_queue_full(q)) {
        printf("Queue is full.\n");
        return;
    }
    if (is_queue_empty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }
    q->processes[q->rear] = process;
    q->size++;
}

/* Function to remove a process from the beginning of the queue */
Process dequeue(Queue *q) {
    if (is_queue_empty(q)) {
        printf("Queue is empty.\n");
        Process dummy = {-1, -1, -1, -1, -1};
        return dummy;
    }
    Process process = q->processes[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    q->size--;
    return process;
}

/* Function to print the current state of the queue */
void print_queue(Queue *q) {
    if (is_queue_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Current state of the queue:\n");
    int i;
    for (i = 0; i < q->size; i++) {
        printf("[ Process %d: Burst Time=%d, Remaining Time=%d, Arrival Time=%d, Waiting Time=%d]\n",
               q->processes[(q->front + i) % MAX_QUEUE_SIZE].pid,
               q->processes[(q->front + i) % MAX_QUEUE_SIZE].burst_time,
               q->processes[(q->front + i) % MAX_QUEUE_SIZE].remaining_time,
               q->processes[(q->front + i) % MAX_QUEUE_SIZE].arrival_time,
               q->processes[(q->front + i) % MAX_QUEUE_SIZE].waiting_time);
    }
}

/* Function to simulate the first-come, first-served (FCFS) scheduling algorithm */
void fcfs_scheduling(Process *processes, int num_processes) {
    int current_time = 0;
    int total_waiting_time = 0;
    int i;
    for (i = 0; i < num_processes; i++) {
        Process *process = &processes[i];
        process->remaining_time = process->burst_time;
        process->waiting_time = current_time - process->arrival_time;
        total_waiting_time += process->waiting_time;
        current_time += process->burst_time;
    }
    float average_waiting_time = (float) total_waiting_time / num_processes;
    printf("Average waiting time for FCFS scheduling algorithm: %.2f\n", average_waiting_time);
}

/* Function to simulate the round-robin (RR) scheduling algorithm */
void rr_scheduling(Process *processes, int num_processes, int time_quantum) {
    Queue ready_queue;
    init_queue(&ready_queue);
    int current_time = 0;
    int total_waiting_time = 0;
    int i;
    for (i = 0; i < num_processes; i++) {
        Process *process = &processes[i];
        process->remaining_time = process->burst_time;
        process->waiting_time = -1;
    }
    while (1) {
        int all_finished = 1;
        for (i = 0; i < num_processes; i++) {
            Process *process = &processes[i];
            if (process->remaining_time > 0) {
                all_finished = 0;
                if (process->waiting_time == -1) {
                    process->waiting_time = current_time - process->arrival_time;
                }
                if (process->remaining_time <= time_quantum) {
                    current_time += process->remaining_time;
                    total_waiting_time += process->waiting_time;
                    process->remaining_time = 0;
                    process->waiting_time = current_time - process->burst_time - process->arrival_time;
                } else {
                    current_time += time_quantum;
                    process->remaining_time -= time_quantum;
                    enqueue(&ready_queue, *process);
                }
            }
        }
        if (all_finished) {
            break;
        }
        while (!is_queue_empty(&ready_queue)) {
            Process process = dequeue(&ready_queue);
            if (process.remaining_time > 0) {
                if (process.remaining_time <= time_quantum) {
                    current_time += process.remaining_time;
                    total_waiting_time += process.waiting_time;
                    process.remaining_time = 0;
                    process.waiting_time = current_time - process.burst_time - process.arrival_time;
                } else {
                    current_time += time_quantum;
                    process.remaining_time -= time_quantum;
                    enqueue(&ready_queue, process);
                }
            }
        }
    }
    float average_waiting_time = (float) total_waiting_time / num_processes;
    printf("Average waiting time for RR scheduling algorithm: %.2f\n", average_waiting_time);
}

/* Main function */
int main(void) {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    Process *processes = (Process *) malloc(num_processes * sizeof(Process));
    int i;
    for (i = 0; i < num_processes; i++) {
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        processes[i].pid = i + 1;
    }
    printf("Enter the time quantum for round-robin scheduling algorithm: ");
    int time_quantum;
    scanf("%d", &time_quantum);
    printf("\n");
    fcfs_scheduling(processes, num_processes);
    rr_scheduling(processes, num_processes, time_quantum);
    free(processes);
    return 0;
}