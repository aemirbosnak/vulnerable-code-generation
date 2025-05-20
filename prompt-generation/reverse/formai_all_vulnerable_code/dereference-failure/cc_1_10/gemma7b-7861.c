//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5

// Define a process structure
typedef struct process {
    int pid;
    int burst_time;
    struct process* next;
} process;

// Function to simulate CPU scheduling algorithms
void simulate_scheduling(process* head) {
    // Round robin algorithm
    process* current_process = head;
    while (current_process) {
        printf("Process %d is running...\n", current_process->pid);
        current_process->burst_time--;
        if (current_process->burst_time == 0) {
            current_process = current_process->next;
        }
    }

    // Shortest job first algorithm
    /*
    process* current_process = head;
    while (current_process) {
        printf("Process %d is running...\n", current_process->pid);
        current_process->burst_time--;
        if (current_process->burst_time == 0) {
            process* temp = current_process;
            current_process = current_process->next;
            free(temp);
        }
    }
    */

    // First come first served algorithm
    /*
    process* current_process = head;
    while (current_process) {
        printf("Process %d is running...\n", current_process->pid);
        current_process->burst_time--;
        if (current_process->burst_time == 0) {
            current_process = current_process->next;
        }
    }
    */
}

int main() {
    // Create a linked list of processes
    process* head = NULL;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        process* new_process = malloc(sizeof(process));
        new_process->pid = i + 1;
        new_process->burst_time = rand() % 10;
        new_process->next = head;
        head = new_process;
    }

    // Simulate CPU scheduling algorithms
    simulate_scheduling(head);

    return 0;
}