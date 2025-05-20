//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    struct Process* next;
} Process;

void schedule_processes(Process* head) {
    // Round robin scheduling algorithm
    Process* current_process = head;
    time_t start_time = time(NULL);
    while (current_process) {
        // Calculate the time spent by the process
        time_t time_spent = time(NULL) - start_time;
        // If the process has completed its service time, move it to the completed processes list
        if (time_spent >= current_process->service_time) {
            Process* next_process = current_process->next;
            free(current_process);
            current_process = next_process;
        } else {
            // Otherwise, keep the process in the ready queue
            printf("Process %d is waiting...\n", current_process->process_id);
            sleep(1);
        }
    }
}

int main() {
    // Create a linked list of processes
    Process* head = NULL;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        Process* new_process = (Process*)malloc(sizeof(Process));
        new_process->process_id = i + 1;
        new_process->arrival_time = rand() % 10;
        new_process->service_time = rand() % 5;
        new_process->next = head;
        head = new_process;
    }

    // Schedule the processes
    schedule_processes(head);

    return 0;
}