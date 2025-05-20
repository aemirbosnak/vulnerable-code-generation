//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESS 20
#define MAX_TIME_QUANTUM 100
#define MAX_ATTEMPTS 5

typedef struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    bool is_completed;
} Process;

typedef struct Queue {
    Process *processes[MAX_PROCESS];
    int front;
    int rear;
} Queue;

void enqueue(Queue *queue, Process *process) {
    queue->processes[queue->rear] = process;
    queue->rear++;
}

Process *dequeue(Queue *queue) {
    Process *process = queue->processes[queue->front];
    queue->front++;
    return process;
}

Process *create_process(int pid, int arrival_time, int burst_time) {
    Process *process = (Process *) malloc(sizeof(Process));
    process->pid = pid;
    process->arrival_time = arrival_time;
    process->burst_time = burst_time;
    process->remaining_time = burst_time;
    process->is_completed = false;
    return process;
}

void fcfs(Queue *queue, int n) {
    for (int i = 0; i < n; i++) {
        Process *process = dequeue(queue);
        printf("\nExecuting process with PID %d", process->pid);

        while (process->remaining_time > 0) {
            process->remaining_time--;
        }

        printf("\nProcess with PID %d completed", process->pid);
        process->is_completed = true;
    }
}

void sjf(Queue *queue, int n) {
    int current_time = 0;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS && current_time < MAX_TIME_QUANTUM) {
        int shortest_index = -1;
        int shortest_burst_time = MAX_TIME_QUANTUM;

        for (int i = 0; i < n; i++) {
            Process *process = queue->processes[i];

            if (!process->is_completed && process->arrival_time <= current_time) {
                if (process->burst_time < shortest_burst_time) {
                    shortest_index = i;
                    shortest_burst_time = process->burst_time;
                }
            }
        }

        if (shortest_index == -1) {
            printf("\nNo more processes can be executed");
            attempts++;
            continue;
        }

        Process *process = queue->processes[shortest_index];
        printf("\nExecuting process with PID %d", process->pid);

        while (process->remaining_time > 0) {
            process->remaining_time--;
        }

        printf("\nProcess with PID %d completed", process->pid);
        process->is_completed = true;
        current_time++;
    }
}

void round_robin(Queue *queue, int n, int time_quantum) {
    int current_time = 0;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS && current_time < MAX_TIME_QUANTUM) {
        bool is_completed = true;

        for (int i = 0; i < n; i++) {
            Process *process = queue->processes[i];

            if (!process->is_completed && process->arrival_time <= current_time) {
                is_completed = false;

                printf("\nExecuting process with PID %d", process->pid);

                if (process->remaining_time > time_quantum) {
                    process->remaining_time -= time_quantum;
                    current_time += time_quantum;
                } else {
                    current_time += process->remaining_time;
                    process->remaining_time = 0;
                }

                if (process->remaining_time == 0) {
                    printf("\nProcess with PID %d completed", process->pid);
                    process->is_completed = true;
                }
            }
        }

        if (is_completed) {
            printf("\nNo more processes can be executed");
            attempts++;
        }
    }
}

int main() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = 0;

    enqueue(queue, create_process(1, 0, 8));
    enqueue(queue, create_process(2, 1, 4));
    enqueue(queue, create_process(3, 2, 9));
    enqueue(queue, create_process(4, 3, 5));
    enqueue(queue, create_process(5, 4, 2));

    printf("FCFS Scheduling:");
    fcfs(queue, 5);
    printf("\n");

    queue->front = 0;
    queue->rear = 0;

    enqueue(queue, create_process(1, 0, 8));
    enqueue(queue, create_process(2, 1, 4));
    enqueue(queue, create_process(3, 2, 9));
    enqueue(queue, create_process(4, 3, 5));
    enqueue(queue, create_process(5, 4, 2));

    printf("SJF Scheduling:");
    sjf(queue, 5);
    printf("\n");

    queue->front = 0;
    queue->rear = 0;

    enqueue(queue, create_process(1, 0, 8));
    enqueue(queue, create_process(2, 1, 4));
    enqueue(queue, create_process(3, 2, 9));
    enqueue(queue, create_process(4, 3, 5));
    enqueue(queue, create_process(5, 4, 2));

    printf("Round Robin Scheduling:");
    round_robin(queue, 5, 2);
    printf("\n");

    return 0;
}