//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME_SLICE 10

// Define a structure to represent a process
typedef struct process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    struct process* next;
} process;

// Function to simulate a round robin scheduling algorithm
void roundRobin(process* head) {
    time_t start_time = time(NULL);
    process* current_process = head;
    int time_slice = 0;

    // Loop until all processes are complete or the time slice is reached
    while (current_process && time_slice < MAX_TIME_SLICE) {
        // Calculate the time remaining for the current process
        int remaining_time = current_process->remaining_time;

        // If the time remaining is less than the time slice, complete the process
        if (remaining_time < time_slice) {
            current_process->remaining_time = 0;
            printf("Process %d completed.\n", current_process->id);
            current_process = current_process->next;
        } else {
            // Otherwise, decrement the remaining time and move to the next process in the queue
            current_process->remaining_time -= time_slice;
            current_process = current_process->next;
        }

        // Increment the time slice
        time_slice++;
    }

    // Print the remaining processes
    process* remaining_processes = head;
    printf("Remaining processes:\n");
    while (remaining_processes) {
        printf("Process %d is waiting.\n", remaining_processes->id);
        remaining_processes = remaining_processes->next;
    }

    // Calculate the total time taken for all processes to complete
    time_t end_time = time(NULL);
    int total_time = end_time - start_time;

    // Print the total time taken
    printf("Total time taken: %d seconds.\n", total_time);
}

// Main function
int main() {
    // Create a linked list of processes
    process* head = NULL;
    process* process_node = NULL;

    // Populate the linked list with processes
    for (int i = 0; i < MAX_PROCESSES; i++) {
        process_node = (process*)malloc(sizeof(process));
        process_node->id = i + 1;
        process_node->arrival_time = rand() % MAX_TIME_SLICE;
        process_node->burst_time = rand() % MAX_TIME_SLICE;
        process_node->remaining_time = process_node->burst_time;

        if (head == NULL) {
            head = process_node;
        } else {
            process_node->next = head;
            head = process_node;
        }
    }

    // Simulate the round robin scheduling algorithm
    roundRobin(head);

    return 0;
}