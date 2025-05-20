//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PROCESSES 10

struct process {
    int id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct process* next;
};

struct process* create_process(int id, int arrival_time, int service_time) {
    struct process* new_process = (struct process*)malloc(sizeof(struct process));
    new_process->id = id;
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->completion_time = 0;
    new_process->next = NULL;

    return new_process;
}

void schedule_processes(struct process* head) {
    // Round Robin algorithm
    struct process* current_process = head;
    int quantum = 0;

    while (current_process) {
        // Calculate the time quantum
        if (quantum == 0) {
            quantum = current_process->arrival_time;
        }

        // Wait for the process to arrive
        if (current_process->arrival_time <= quantum) {
            // Execute the process for its service time
            current_process->completion_time = quantum + current_process->service_time;
            quantum = current_process->completion_time;
        }

        current_process = current_process->next;
    }
}

int main() {
    // Create a list of processes
    struct process* head = create_process(1, 0, 5);
    head = create_process(2, 2, 4);
    head = create_process(3, 4, 3);
    head = create_process(4, 6, 2);

    // Schedule the processes
    schedule_processes(head);

    // Print the completion time for each process
    struct process* current_process = head;
    while (current_process) {
        printf("Process ID: %d, Completion Time: %d\n", current_process->id, current_process->completion_time);
        current_process = current_process->next;
    }

    return 0;
}