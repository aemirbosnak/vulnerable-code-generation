//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5

typedef struct Process {
    int pid;
    int burst_time;
    int waiting_time;
    struct Process* next;
} Process;

void simulate_cpu_scheduling(Process* head) {
    int quantum = 0;
    Process* current_process = head;

    while (current_process) {
        if (quantum < current_process->burst_time) {
            quantum++;
        } else {
            current_process->waiting_time++;
            current_process = current_process->next;
            quantum = 0;
        }
    }

    printf("Process Scheduling Simulation\n");
    printf("--------------------\n");
    printf("PID\tBurst Time\tWaiting Time\n");
    printf("--------------------\n");

    current_process = head;
    while (current_process) {
        printf("%d\t%d\t%d\n", current_process->pid, current_process->burst_time, current_process->waiting_time);
        current_process = current_process->next;
    }
}

int main() {
    Process* head = NULL;

    // Create a few processes
    Process* process1 = malloc(sizeof(Process));
    process1->pid = 1;
    process1->burst_time = 5;

    Process* process2 = malloc(sizeof(Process));
    process2->pid = 2;
    process2->burst_time = 3;

    Process* process3 = malloc(sizeof(Process));
    process3->pid = 3;
    process3->burst_time = 4;

    Process* process4 = malloc(sizeof(Process));
    process4->pid = 4;
    process4->burst_time = 2;

    Process* process5 = malloc(sizeof(Process));
    process5->pid = 5;
    process5->burst_time = 6;

    // Link the processes together
    process1->next = process2;
    process2->next = process3;
    process3->next = process4;
    process4->next = process5;

    // Simulate CPU scheduling
    simulate_cpu_scheduling(head);

    return 0;
}