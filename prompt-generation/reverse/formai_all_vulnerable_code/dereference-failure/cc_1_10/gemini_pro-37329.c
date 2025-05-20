//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct Process {
    int pid;                // Process ID
    int arrivalTime;        // Arrival time
    int burstTime;          // Burst time
    int priority;           // Priority
    int remainingTime;     // Remaining burst time
    int completionTime;    // Completion time
    int turnaroundTime;    // Turnaround time
    int waitingTime;       // Waiting time
} Process;

// Queue structure
typedef struct Queue {
    Process *processes;    // Array of processes
    int size;               // Size of the queue
    int front;              // Front of the queue
    int rear;               // Rear of the queue
} Queue;

// Function to create a new process
Process *createProcess(int pid, int arrivalTime, int burstTime, int priority) {
    Process *process = (Process *)malloc(sizeof(Process));
    process->pid = pid;
    process->arrivalTime = arrivalTime;
    process->burstTime = burstTime;
    process->priority = priority;
    process->remainingTime = burstTime;
    process->completionTime = 0;
    process->turnaroundTime = 0;
    process->waitingTime = 0;
    return process;
}

// Function to create a new queue
Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->processes = (Process *)malloc(sizeof(Process) * size);
    queue->size = size;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

// Function to enqueue a process
void enqueue(Queue *queue, Process *process) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full!\n");
        return;
    }
    queue->rear++;
    queue->processes[queue->rear] = *process;
}

// Function to dequeue a process
Process *dequeue(Queue *queue) {
    if (queue->front > queue->rear) {
        printf("Queue is empty!\n");
        return NULL;
    }
    Process *process = &queue->processes[queue->front];
    queue->front++;
    return process;
}

int main() {
    // Process parameters
    int numProcesses = 4;
    int arrivalTimes[] = {0, 1, 2, 3};
    int burstTimes[] = {5, 2, 3, 4};
    int priorities[] = {1, 3, 2, 4};

    // Create processes
    Process *processes[numProcesses];
    for (int i = 0; i < numProcesses; i++) {
        processes[i] = createProcess(i + 1, arrivalTimes[i], burstTimes[i], priorities[i]);
    }

    // Create queue
    Queue *queue = createQueue(numProcesses);

    // Enqueue processes
    for (int i = 0; i < numProcesses; i++) {
        enqueue(queue, processes[i]);
    }

    // Schedule processes
    int time = 0;
    while (queue->front <= queue->rear) {
        // Get the next process from the queue
        Process *process = dequeue(queue);

        // Execute the process
        if (process->remainingTime > 0) {
            if (process->remainingTime <= time) {
                process->remainingTime = 0;
                process->completionTime = time;
            } else {
                process->remainingTime -= time;
                enqueue(queue, process);
            }
        }

        // Update the time
        time++;
    }

    // Calculate the average waiting time
    int totalWaitingTime = 0;
    for (int i = 0; i < numProcesses; i++) {
        processes[i]->turnaroundTime = processes[i]->completionTime - processes[i]->arrivalTime;
        processes[i]->waitingTime = processes[i]->turnaroundTime - processes[i]->burstTime;
        totalWaitingTime += processes[i]->waitingTime;
    }
    float avgWaitingTime = (float)totalWaitingTime / numProcesses;

    // Print the results
    printf("Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i]->pid, processes[i]->arrivalTime, processes[i]->burstTime, processes[i]->priority, processes[i]->completionTime, processes[i]->turnaroundTime, processes[i]->waitingTime);
    }
    printf("Average waiting time: %.2f\n", avgWaitingTime);

    return 0;
}