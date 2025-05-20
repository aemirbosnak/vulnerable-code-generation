//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10

struct process {
    int pid;
    char name[20];
    int burst_time;
    int waiting_time;
    int turnaround_time;
    struct process* next;
};

void roundrobin(struct process* head) {
    struct process* current = head;
    struct process* next = NULL;

    while (current) {
        next = current->next;

        // Simulate process execution
        printf("Process %d (%s) is running...\n", current->pid, current->name);
        sleep(current->burst_time);

        // Update waiting time and calculate turnaround time
        current->waiting_time++;
        current->turnaround_time = current->waiting_time + current->burst_time;

        // Move to the next process
        current = next;
    }
}

int main() {
    struct process* head = NULL;

    // Create some processes
    for (int i = 0; i < MAX_PROCESS; i++) {
        struct process* new_process = (struct process*)malloc(sizeof(struct process));
        new_process->pid = i + 1;
        snprintf(new_process->name, 20, "Process %d", new_process->pid);
        new_process->burst_time = rand() % 5 + 1;
        new_process->waiting_time = 0;
        new_process->turnaround_time = 0;
        new_process->next = head;
        head = new_process;
    }

    // Round robin scheduling
    roundrobin(head);

    // Print results
    printf("Process Statistics:\n");
    for (struct process* process = head; process; process = process->next) {
        printf("PID: %d, Name: %s, Burst Time: %d, Waiting Time: %d, Turnaround Time: %d\n", process->pid, process->name, process->burst_time, process->waiting_time, process->turnaround_time);
    }

    return 0;
}