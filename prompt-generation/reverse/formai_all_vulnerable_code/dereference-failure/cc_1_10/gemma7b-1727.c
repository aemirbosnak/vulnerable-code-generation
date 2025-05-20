//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_SCHEDULE_SIZE 20

typedef struct Process {
    int id;
    int cpu_burst;
    int waiting_time;
    int turnaround_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int cpu_burst) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->cpu_burst = cpu_burst;
    process->waiting_time = 0;
    process->turnaround_time = 0;
    process->next = NULL;
    return process;
}

void scheduleProcess(Process* process) {
    // Round robin scheduling algorithm
    process->waiting_time++;
    if (process->waiting_time >= MAX_SCHEDULE_SIZE) {
        process->waiting_time = 0;
    }
}

int main() {
    // Create a list of processes
    Process* head = createProcess(1, 5);
    head->next = createProcess(2, 3);
    head->next->next = createProcess(3, 8);
    head->next->next->next = createProcess(4, 2);

    // Simulate the CPU scheduling algorithm
    for (int i = 0; i < 10; i++) {
        scheduleProcess(head);
    }

    // Print the turnaround time for each process
    Process* current = head;
    while (current) {
        printf("Process %d has a turnaround time of %d\n", current->id, current->turnaround_time);
        current = current->next;
    }

    return 0;
}