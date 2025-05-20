//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
};

struct Node {
    struct Process process;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

struct Queue *create_queue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue *queue, struct Process process) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->process = process;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

struct Process dequeue(struct Queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        exit(1);
    }

    struct Process process = queue->front->process;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return process;
}

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    struct Queue *ready_queue = create_queue();

    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        // Add all the processes that have arrived at the current time to the ready queue
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                enqueue(ready_queue, processes[i]);
            }
        }

        // If the ready queue is not empty, dequeue the process with the highest priority
        if (ready_queue->front != NULL) {
            struct Process process = dequeue(ready_queue);

            // Execute the process for one time unit
            process.remaining_time--;
            current_time++;

            // If the process has finished executing, print its details
            if (process.remaining_time == 0) {
                printf("Process %d completed at time %d.\n", process.pid, current_time);
                completed_processes++;
            } else {
                // If the process has not finished executing, enqueue it back into the ready queue
                enqueue(ready_queue, process);
            }
        }
    }

    return 0;
}