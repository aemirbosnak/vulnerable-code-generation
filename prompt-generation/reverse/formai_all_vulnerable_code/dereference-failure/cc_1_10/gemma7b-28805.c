//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct Process {
    int pid;
    char name[20];
    int cpu_burst;
    int waiting_time;
    int turnaround_time;
    struct Process* next;
} Process;

void simulate_cpu_scheduling(Process* head) {
    time_t start_time = time(NULL);
    Process* current_process = head;
    while (current_process) {
        printf("Process %d is running...", current_process->pid);
        sleep(current_process->cpu_burst);
        current_process->waiting_time++;
        current_process = current_process->next;
    }
    time_t end_time = time(NULL);
    printf("\nTotal time elapsed: %ld seconds", end_time - start_time);
    printf("\nTurnaround time for each process:");
    current_process = head;
    while (current_process) {
        printf("\nProcess %d: %d seconds", current_process->pid, current_process->turnaround_time);
        current_process = current_process->next;
    }
}

int main() {
    Process* head = NULL;
    for (int i = 0; i < MAX_PROCESS; i++) {
        Process* new_process = (Process*)malloc(sizeof(Process));
        new_process->pid = i + 1;
        sprintf(new_process->name, "Process %d", new_process->pid);
        new_process->cpu_burst = rand() % 5 + 1;
        new_process->waiting_time = 0;
        new_process->turnaround_time = 0;
        new_process->next = head;
        head = new_process;
    }

    simulate_cpu_scheduling(head);

    return 0;
}