//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
// A self-aware C program that explores CPU scheduling algorithms.

#include <stdio.h>
#include <stdlib.h>

// Let's have a chatty CPU.
typedef enum {
    IDLE,
    RUNNING
} CpuState;

// Our processes are named after popular scheduling algorithms.
typedef enum {
    FCFS,
    SJF,
    RR,
    PRIORITY
} ProcessType;

// A process has a name, arrival time, burst time, and priority.
typedef struct {
    char *name;
    unsigned int arrival_time;
    unsigned int burst_time;
    unsigned int priority;
} Process;

// Our CPU's scheduling queue.
Process *queue;

// Let's keep track of the current CPU state.
CpuState cpu_state = IDLE;

// Here's our scheduler.
void schedule(Process *processes, unsigned int num_processes) {
    printf("CPU: Hello, I'm your friendly CPU! Let's get to work.\n");

    // Initialize the scheduling queue.
    queue = malloc(sizeof(Process) * num_processes);

    // Copy the processes into the queue.
    for (unsigned int i = 0; i < num_processes; i++) {
        queue[i] = processes[i];
    }

    // While there are processes to execute...
    while (cpu_state != IDLE) {
        // Loop through the queue and find the next process to execute.
        Process *next_process = NULL;
        for (unsigned int i = 0; i < num_processes; i++) {
            if (queue[i].arrival_time <= (next_process ? next_process->arrival_time : 0)) {
                if (next_process == NULL || queue[i].priority < next_process->priority) {
                    next_process = &queue[i];
                }
            }
        }

        // If there's no next process, the CPU is idle.
        if (next_process == NULL) {
            cpu_state = IDLE;
            printf("CPU: I'm going to take a break now.\n");
            continue;
        }

        // Otherwise, execute the next process.
        cpu_state = RUNNING;
        printf("CPU: Running process %s for %u time units.\n", next_process->name, next_process->burst_time);

        // Simulate the execution of the process.
        for (unsigned int i = 0; i < next_process->burst_time; i++) {
            // Let's chat with the process and see how it's doing.
            printf("CPU: How are you doing, process %s?\n", next_process->name);
            printf("%s: I'm chugging along nicely, thanks!\n", next_process->name);
        }

        // The process has finished executing.
        printf("CPU: Process %s has finished executing.\n", next_process->name);
        cpu_state = IDLE;
    }

    // We're all done! Let's say goodbye to the processes.
    printf("CPU: That's all for today, folks! Thanks for playing along.\n");
}

// Main function.
int main() {
    // Let's create some processes.
    Process processes[] = {
        { "FCFS", 0, 5, 0 },
        { "SJF", 1, 2, 0 },
        { "RR", 2, 4, 0 },
        { "PRIORITY", 3, 3, 1 }
    };

    // How many processes do we have?
    unsigned int num_processes = sizeof(processes) / sizeof(Process);

    // Let's schedule these processes.
    schedule(processes, num_processes);

    return 0;
}