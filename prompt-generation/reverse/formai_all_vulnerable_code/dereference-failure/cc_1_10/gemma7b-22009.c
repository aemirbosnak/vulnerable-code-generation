//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10

struct process {
    int id;
    int burst_time;
    int waiting_time;
    struct process* next;
};

void schedule_process(struct process* processes) {
    if (processes) {
        struct process* current_process = processes;
        int completed = 0;

        // Calculate the waiting time for each process
        for (struct process* process = processes; process; process = process->next) {
            process->waiting_time = completed;
            completed++;
        }

        // Select the process with the smallest waiting time
        struct process* next_process = processes;
        for (struct process* process = processes; process; process = process->next) {
            if (process->waiting_time < next_process->waiting_time) {
                next_process = process;
            }
        }

        // Execute the selected process
        printf("Process %d is running...\n", next_process->id);
        sleep(next_process->burst_time);

        // Update the waiting time of the process
        next_process->waiting_time++;

        // Recursively schedule the next process
        schedule_process(next_process->next);
    }
}

int main() {
    struct process* processes = NULL;

    // Create a few processes
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes = malloc(sizeof(struct process));
        processes->id = i + 1;
        processes->burst_time = rand() % 5;
        processes->waiting_time = 0;
        processes->next = processes;
    }

    // Schedule the processes
    schedule_process(processes);

    return 0;
}