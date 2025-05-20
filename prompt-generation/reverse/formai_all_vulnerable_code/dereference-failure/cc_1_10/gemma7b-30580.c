//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4
#define MAX_SCHEDULE_SIZE 10

typedef struct process {
    int id;
    int arrival_time;
    int execution_time;
    struct process* next;
} process;

void schedule_process(process* head) {
    // Create a circular linked list to store the processes in the ready queue
    process* ready_queue = (process*)malloc(sizeof(process));
    ready_queue->next = head;

    // Simulate the clock
    int time = 0;
    while (!ready_queue->next) {
        // Wait for the next process to arrive
        time++;
    }

    // Round robin scheduling
    process* current_process = ready_queue->next;
    while (current_process) {
        // Execute the process
        time += current_process->execution_time;

        // Move the process to the completed queue
        process* completed_process = current_process;
        current_process = current_process->next;
        completed_process->next = NULL;
    }

    // Print the completion times of each process
    process* completed_queue = head;
    while (completed_queue) {
        printf("Process %d completed at time %d\n", completed_queue->id, time);
        completed_queue = completed_queue->next;
    }
}

int main() {
    // Create a list of processes
    process* head = (process*)malloc(sizeof(process));
    head->id = 1;
    head->arrival_time = 0;
    head->execution_time = 5;
    head->next = (process*)malloc(sizeof(process));
    head->next->id = 2;
    head->next->arrival_time = 2;
    head->next->execution_time = 3;
    head->next->next = (process*)malloc(sizeof(process));
    head->next->next->id = 3;
    head->next->next->arrival_time = 4;
    head->next->next->execution_time = 2;

    // Schedule the processes
    schedule_process(head);

    return 0;
}