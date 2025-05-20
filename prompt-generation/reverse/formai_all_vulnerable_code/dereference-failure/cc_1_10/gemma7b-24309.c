//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    char name[20];
    int arrival_time;
    int service_time;
    int remaining_service_time;
    int status;
} Process;

void create_process(Process *process) {
    process->process_id = rand() % MAX_PROCESSES;
    process->name[0] = 'A' + process->process_id;
    process->arrival_time = rand() % MAX_QUEUE_SIZE;
    process->service_time = rand() % MAX_QUEUE_SIZE;
    process->remaining_service_time = process->service_time;
    process->status = 0;
}

void simulate_scheduler(Process *processes) {
    int time = 0;
    int quantum = 5;
    int ready_queue[MAX_QUEUE_SIZE] = {0};
    int i = 0;

    while (!processes[i].status) {
        time++;

        // Check if the process is ready
        if (processes[i].arrival_time <= time) {
            processes[i].status = 1;
            ready_queue[i] = 1;
        }

        // If the queue is not full, add the process to the ready queue
        if (ready_queue[i] && !ready_queue[i + 1]) {
            i++;
            create_process(processes + i);
            ready_queue[i] = 1;
        }

        // Execute the process for the quantum
        if (processes[i].remaining_service_time > 0) {
            processes[i].remaining_service_time -= quantum;
        } else {
            processes[i].status = 2;
        }

        // Update the time
        if (time % 20 == 0) {
            printf("%d: ", time);
            for (int j = 0; j < MAX_PROCESSES; j++) {
                printf("%c ", processes[j].name);
            }
            printf("\n");
        }
    }

    // Print the completion time for each process
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%c completed at time %d\n", processes[i].name, processes[i].arrival_time + processes[i].service_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];

    // Create the processes
    for (int i = 0; i < MAX_PROCESSES; i++) {
        create_process(processes + i);
    }

    // Simulate the scheduler
    simulate_scheduler(processes);

    return 0;
}