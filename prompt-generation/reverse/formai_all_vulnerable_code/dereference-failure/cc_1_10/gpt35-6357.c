//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the process structure
typedef struct {
    int pid;            // Process ID
    int arrivalTime;    // Arrival Time
    int burstTime;      // Burst Time
    int priority;       // Priority (1-5)
    int waitingTime;    // Waiting Time
    int turnaroundTime; // Turnaround Time
    bool executed;      // Has the process been executed?
} Process;

// Define the queue structure
typedef struct {
    int front;
    int rear;
    int size;
    int capacity;
    Process *processes;
} Queue;

// Define the function to create a new process
Process createProcess(int pid, int arrivalTime, int burstTime, int priority) {
    Process process;
    process.pid = pid;
    process.arrivalTime = arrivalTime;
    process.burstTime = burstTime;
    process.priority = priority;
    process.waitingTime = 0;
    process.turnaroundTime = 0;
    process.executed = false;
    return process;
}

// Define the function to create a new queue
Queue createQueue(int capacity) {
    Queue queue;
    queue.front = 0;
    queue.rear = -1;
    queue.size = 0;
    queue.capacity = capacity;
    queue.processes = (Process*) malloc(capacity * sizeof(Process));
    return queue;
}

// Define the function to check if the queue is empty
bool isQueueEmpty(Queue *queue) {
    return queue->size == 0;
}

// Define the function to check if the queue is full
bool isQueueFull(Queue *queue) {
    return queue->size == queue->capacity;
}

// Define the function to enqueue a process
void enqueue(Queue *queue, Process process) {
    if (isQueueFull(queue)) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->processes[queue->rear] = process;
    queue->size++;
}

// Define the function to dequeue a process
Process dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        Process process;
        process.pid = -1;
        return process;
    }
    Process process = queue->processes[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return process;
}

// Define the function to sort the queue by arrival time
void sortByArrivalTime(Queue *queue) {
    int i, j;
    Process temp;
    for (i = 0; i < queue->size - 1; i++) {
        for (j = i + 1; j < queue->size; j++) {
            if (queue->processes[i].arrivalTime > queue->processes[j].arrivalTime) {
                temp = queue->processes[i];
                queue->processes[i] = queue->processes[j];
                queue->processes[j] = temp;
            }
        }
    }
}

// Define the function to sort the queue by priority
void sortByPriority(Queue *queue) {
    int i, j;
    Process temp;
    for (i = 0; i < queue->size - 1; i++) {
        for (j = i + 1; j < queue->size; j++) {
            if (queue->processes[i].priority > queue->processes[j].priority) {
                temp = queue->processes[i];
                queue->processes[i] = queue->processes[j];
                queue->processes[j] = temp;
            }
        }
    }
}

// Define the function to execute the processes using FCFS algorithm
void executeFCFS(Queue *queue) {
    int currentTime = queue->processes[0].arrivalTime;
    int i;
    for (i = 0; i < queue->size; i++) {
        currentTime += queue->processes[i].burstTime;  // Update the current time
        queue->processes[i].turnaroundTime = currentTime - queue->processes[i].arrivalTime;
        queue->processes[i].waitingTime = queue->processes[i].turnaroundTime - queue->processes[i].burstTime;
        queue->processes[i].executed = true;  // Mark the process as executed
    }
}

// Define the function to execute the processes using SJF algorithm
void executeSJF(Queue *queue) {
    int currentTime = queue->processes[0].arrivalTime;
    int i, j, minIndex;
    Process temp;
    for (i = 0; i < queue->size; i++) {
        minIndex = i;
        for (j = i + 1; j < queue->size; j++) {
            if (queue->processes[j].burstTime < queue->processes[minIndex].burstTime &&
                queue->processes[j].arrivalTime <= currentTime) {
                minIndex = j;
            }
        }
        temp = queue->processes[i];
        queue->processes[i] = queue->processes[minIndex];
        queue->processes[minIndex] = temp;
        currentTime += queue->processes[i].burstTime;  // Update the current time
        queue->processes[i].turnaroundTime = currentTime - queue->processes[i].arrivalTime;
        queue->processes[i].waitingTime = queue->processes[i].turnaroundTime - queue->processes[i].burstTime;
        queue->processes[i].executed = true;  // Mark the process as executed
    }
}

// Define the function to execute the processes using Priority algorithm
void executePriority(Queue *queue) {
    int currentTime = queue->processes[0].arrivalTime;
    int i, j, minIndex;
    Process temp;
    for (i = 0; i < queue->size; i++) {
        minIndex = i;
        for (j = i + 1; j < queue->size; j++) {
            if (queue->processes[j].priority < queue->processes[minIndex].priority &&
                queue->processes[j].arrivalTime <= currentTime) {
                minIndex = j;
            }
        }
        temp = queue->processes[i];
        queue->processes[i] = queue->processes[minIndex];
        queue->processes[minIndex] = temp;
        currentTime += queue->processes[i].burstTime;  // Update the current time
        queue->processes[i].turnaroundTime = currentTime - queue->processes[i].arrivalTime;
        queue->processes[i].waitingTime = queue->processes[i].turnaroundTime - queue->processes[i].burstTime;
        queue->processes[i].executed = true;  // Mark the process as executed
    }
}

int main() {
    int i, n, pid, arrivalTime, burstTime, priority;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Queue queue = createQueue(n);
    for (i = 0; i < n; i++) {
        printf("Enter the details of process %d:\n", i + 1);
        printf("PID: ");
        scanf("%d", &pid);
        printf("Arrival Time: ");
        scanf("%d", &arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &burstTime);
        printf("Priority (1-5): ");
        scanf("%d", &priority);
        queue.processes[i] = createProcess(pid, arrivalTime, burstTime, priority);
        queue.size++;
    }
    printf("\n*** FCFS Scheduling Algorithm ***\n");
    sortByArrivalTime(&queue);  // Sort the queue by arrival time
    executeFCFS(&queue);        // Execute the processes using FCFS algorithm
    // Print the results
    printf("\nPID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               queue.processes[i].pid,
               queue.processes[i].arrivalTime,
               queue.processes[i].burstTime,
               queue.processes[i].priority,
               queue.processes[i].waitingTime,
               queue.processes[i].turnaroundTime);
    }
    Queue queue2 = createQueue(n);
    for (i = 0; i < n; i++) {
        queue2.processes[i] = queue.processes[i];  // Copy the processes to the new queue
    }
    printf("\n*** SJF Scheduling Algorithm ***\n");
    sortByArrivalTime(&queue2);  // Sort the queue by arrival time
    executeSJF(&queue2);          // Execute the processes using SJF algorithm
    // Print the results
    printf("\nPID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               queue2.processes[i].pid,
               queue2.processes[i].arrivalTime,
               queue2.processes[i].burstTime,
               queue2.processes[i].priority,
               queue2.processes[i].waitingTime,
               queue2.processes[i].turnaroundTime);
    }
    Queue queue3 = createQueue(n);
    for (i = 0; i < n; i++) {
        queue3.processes[i] = queue.processes[i];  // Copy the processes to the new queue
    }
    printf("\n*** Priority Scheduling Algorithm ***\n");
    sortByArrivalTime(&queue3);  // Sort the queue by arrival time
    sortByPriority(&queue3);     // Sort the queue by priority
    executePriority(&queue3);    // Execute the processes using Priority algorithm
    // Print the results
    printf("\nPID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               queue3.processes[i].pid,
               queue3.processes[i].arrivalTime,
               queue3.processes[i].burstTime,
               queue3.processes[i].priority,
               queue3.processes[i].waitingTime,
               queue3.processes[i].turnaroundTime);
    }
    return 0;
}