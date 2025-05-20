//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Process
typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int finish_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Ready queue
typedef struct {
    int count;
    Process **processes;
} ReadyQueue;

Process *create_process(int id, int arrival_time, int burst_time) {
    Process *process = malloc(sizeof(Process));
    process->id = id;
    process->arrival_time = arrival_time;
    process->burst_time = burst_time;
    process->remaining_time = burst_time;
    process->finish_time = 0;
    process->waiting_time = 0;
    process->turnaround_time = 0;
    return process;
}

ReadyQueue *create_ready_queue() {
    ReadyQueue *ready_queue = malloc(sizeof(ReadyQueue));
    ready_queue->count = 0;
    ready_queue->processes = malloc(0);
    return ready_queue;
}

void add_process_to_ready_queue(ReadyQueue *ready_queue, Process *process) {
    ready_queue->processes = realloc(ready_queue->processes, sizeof(Process) * (ready_queue->count + 1));
    ready_queue->processes[ready_queue->count] = process;
    ready_queue->count++;
}

Process *get_next_process_from_ready_queue(ReadyQueue *ready_queue) {
    if (ready_queue->count == 0) {
        return NULL;
    }

    int next_process_index = 0;
    for (int i = 1; i < ready_queue->count; i++) {
        if (ready_queue->processes[i]->remaining_time < ready_queue->processes[next_process_index]->remaining_time) {
            next_process_index = i;
        }
    }

    Process *next_process = ready_queue->processes[next_process_index];

    ready_queue->count--;
    for (int i = next_process_index; i < ready_queue->count; i++) {
        ready_queue->processes[i] = ready_queue->processes[i+1];
    }
    ready_queue->processes = realloc(ready_queue->processes, sizeof(Process) * ready_queue->count);

    return next_process;
}

void run_simulation(ReadyQueue *ready_queue) {
    // Sort the processes by arrival time
    for (int i = 0; i < ready_queue->count; i++) {
        for (int j = i+1; j < ready_queue->count; j++) {
            if (ready_queue->processes[i]->arrival_time > ready_queue->processes[j]->arrival_time) {
                Process *temp = ready_queue->processes[i];
                ready_queue->processes[i] = ready_queue->processes[j];
                ready_queue->processes[j] = temp;
            }
        }
    }

    // Run the simulation
    int current_time = 0;
    while (ready_queue->count > 0) {
        Process *next_process = get_next_process_from_ready_queue(ready_queue);
        int next_process_burst_time = next_process->remaining_time;
        next_process->finish_time = current_time + next_process_burst_time;
        next_process->waiting_time = current_time - next_process->arrival_time;
        next_process->turnaround_time = next_process->waiting_time + next_process_burst_time;
        current_time += next_process_burst_time;
        free(next_process);
    }
}

int main() {
    ReadyQueue *ready_queue = create_ready_queue();

    // Create the processes
    Process *process1 = create_process(1, 0, 10);
    Process *process2 = create_process(2, 2, 5);
    Process *process3 = create_process(3, 3, 15);

    // Add the processes to the ready queue
    add_process_to_ready_queue(ready_queue, process1);
    add_process_to_ready_queue(ready_queue, process2);
    add_process_to_ready_queue(ready_queue, process3);

    // Run the simulation
    run_simulation(ready_queue);

    // Print the results
    printf("Process  Waiting time  Turnaround time\n");
    printf("-------  ------------  ----------------\n");
    for (int i = 0; i < ready_queue->count; i++) {
        printf("%7d  %12d  %16d\n", ready_queue->processes[i]->id, ready_queue->processes[i]->waiting_time, ready_queue->processes[i]->turnaround_time);
    }

    // Clean up the memory
    free(process1);
    free(process2);
    free(process3);
    free(ready_queue->processes);
    free(ready_queue);

    return 0;
}