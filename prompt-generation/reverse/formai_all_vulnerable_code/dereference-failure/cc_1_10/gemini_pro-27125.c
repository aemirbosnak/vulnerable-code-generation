//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    bool is_completed;
} Process;

typedef struct Queue {
    Process* processes;
    int size;
    int front;
    int rear;
} Queue;

void enqueue(Queue* queue, Process* process) {
    if (queue->size == 0) {
        queue->processes = malloc(sizeof(Process));
        queue->processes[0] = *process;
        queue->size = 1;
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->processes = realloc(queue->processes, (queue->size + 1) * sizeof(Process));
        queue->processes[queue->size] = *process;
        queue->size++;
        queue->rear++;
    }
}

Process* dequeue(Queue* queue) {
    if (queue->size == 0) {
        return NULL;
    } else {
        Process* process = &queue->processes[queue->front];
        queue->processes = realloc(queue->processes, (queue->size - 1) * sizeof(Process));
        queue->size--;
        queue->front++;
        return process;
    }
}

int main() {
    // Initialize the processes
    Process processes[] = {
        {1, 0, 5, 3},
        {2, 1, 4, 2},
        {3, 2, 6, 1},
        {4, 3, 7, 4},
        {5, 4, 3, 5}
    };
    const int num_processes = sizeof(processes) / sizeof(processes[0]);

    // Initialize the ready queue
    Queue ready_queue;
    ready_queue.processes = NULL;
    ready_queue.size = 0;
    ready_queue.front = 0;
    ready_queue.rear = 0;

    // Initialize the gantt chart
    char gantt_chart[100];
    strcpy(gantt_chart, "|");

    // Initialize the time
    int time = 0;

    // Run the scheduling algorithm
    while (true) {
        // Enqueue the processes that have arrived
        for (int i = 0; i < num_processes; ++i) {
            Process* process = &processes[i];
            if (process->arrival_time <= time && !process->is_completed) {
                enqueue(&ready_queue, process);
            }
        }

        // If the ready queue is empty, then increment the time
        if (ready_queue.size == 0) {
            time++;
            continue;
        }

        // Dequeue the process with the highest priority
        Process* process = dequeue(&ready_queue);

        // Execute the process
        process->remaining_time--;
        strcat(gantt_chart, process->id + '0');
        strcat(gantt_chart, "|");

        // If the process is completed, then mark it as completed
        if (process->remaining_time == 0) {
            process->is_completed = true;
        } else {
            // Otherwise, enqueue the process back into the ready queue
            enqueue(&ready_queue, process);
        }

        // Increment the time
        time++;

        // Check if all processes are completed
        bool all_completed = true;
        for (int i = 0; i < num_processes; ++i) {
            Process* process = &processes[i];
            if (!process->is_completed) {
                all_completed = false;
                break;
            }
        }

        // If all processes are completed, then break out of the loop
        if (all_completed) {
            break;
        }
    }

    // Print the gantt chart
    printf("%s\n", gantt_chart);

    return 0;
}