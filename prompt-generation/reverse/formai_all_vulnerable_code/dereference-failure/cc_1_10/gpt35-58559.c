//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10 // maximum number of processes
#define QUANTUM 2 // quantum time in milliseconds

// process structure
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
} Process;

// queue structure
typedef struct {
    Process *processes[MAX_PROCESSES];
    int front;
    int rear;
} Queue;

// function to create a new process
Process *create_process(int pid, int arrival_time, int burst_time) {
    Process *process = malloc(sizeof(Process));
    process->pid = pid;
    process->arrival_time = arrival_time;
    process->burst_time = burst_time;
    process->remaining_time = burst_time;
    return process;
}

// function to create a new queue
Queue *create_queue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    return queue;
}

// function to check if the queue is empty
int is_empty(Queue *queue) {
    return queue->front == -1;
}

// function to check if the queue is full
int is_full(Queue *queue) {
    return (queue->rear + 1) % MAX_PROCESSES == queue->front;
}

// function to enqueue a process in the queue
void enqueue(Queue *queue, Process *process) {
    if (!is_full(queue)) {
        queue->rear = (queue->rear + 1) % MAX_PROCESSES;
        queue->processes[queue->rear] = process;
        if (queue->front == -1)
            queue->front = 0;
    }
}

// function to dequeue a process from the queue
Process *dequeue(Queue *queue) {
    if (!is_empty(queue)) {
        Process *process = queue->processes[queue->front];
        if (queue->front == queue->rear)
            queue->front = queue->rear = -1;
        else
            queue->front = (queue->front + 1) % MAX_PROCESSES;
        return process;
    }
    return NULL;
}

// function to simulate the Round Robin CPU scheduling algorithm
void round_robin(Process **processes, int n) {
    Queue *queue = create_queue();
    int i, current_time = 0, total_time = 0;
    float waiting_time = 0, turnaround_time = 0;
    // loop until all processes are completed
    while (1) {
        int done = 1;
        // check if any process has remaining time
        for (i = 0; i < n; i++) {
            if (processes[i]->remaining_time > 0) {
                done = 0;
                if (processes[i]->arrival_time <= current_time)
                    enqueue(queue, processes[i]);
            }
        }
        // all processes completed
        if (done) break;
        // process the next process in the queue
        if (!is_empty(queue)) {
            Process *process = dequeue(queue);
            // check if the process can complete in the quantum time
            if (process->remaining_time <= QUANTUM) {
                current_time += process->remaining_time;
                total_time += process->remaining_time;
                process->remaining_time = 0;
            }
            // process the process for the quantum time
            else {
                current_time += QUANTUM;
                total_time += QUANTUM;
                process->remaining_time -= QUANTUM;
                // enqueue the process again
                enqueue(queue, process);
            }
            // calculate waiting and turnaround time
            int waiting = current_time - process->arrival_time - process->burst_time;
            int turnaround = current_time - process->arrival_time;
            waiting_time += waiting;
            turnaround_time += turnaround;
        }
        // no process in the queue, increment the current time
        else {
            current_time++;
            total_time++;
        }
    }
    // calculate average waiting and turnaround time
    waiting_time /= n;
    turnaround_time /= n;
    // print the results
    printf("Scheduling algorithm: Round Robin\n");
    printf("Quantum time: %d milliseconds\n", QUANTUM);
    printf("Processes\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++)
        printf("P%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n", processes[i]->pid, processes[i]->arrival_time, processes[i]->burst_time,
            current_time - processes[i]->arrival_time - processes[i]->burst_time, current_time - processes[i]->arrival_time);
    printf("Average waiting time: %f milliseconds\n", waiting_time);
    printf("Average turnaround time: %f milliseconds\n", turnaround_time);
    printf("Total time: %d milliseconds\n", total_time);
}

// main function
int main() {
    Process *processes[MAX_PROCESSES];
    int i, n;
    // read number of processes
    printf("Enter the number of processes (maximum %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    // read process arrival time and burst time
    for (i = 0; i < n; i++) {
        int arrival_time, burst_time;
        printf("Enter the arrival time and burst time for process P%d: ", i);
        scanf("%d %d", &arrival_time, &burst_time);
        processes[i] = create_process(i, arrival_time, burst_time);
    }
    // simulate the Round Robin CPU scheduling algorithm
    round_robin(processes, n);
    // free memory allocated for processes
    for (i = 0; i < n; i++)
        free(processes[i]);
    return 0;
}