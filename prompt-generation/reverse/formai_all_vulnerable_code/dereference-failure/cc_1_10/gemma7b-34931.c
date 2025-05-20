//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct Process {
    int pid;
    int burst_time;
    int waiting_time;
    struct Process* next;
} Process;

Process* createProcess(int pid, int burst_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->pid = pid;
    process->burst_time = burst_time;
    process->waiting_time = 0;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, int pid, int burst_time) {
    Process* process = createProcess(pid, burst_time);
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void roundRobin(Process* head) {
    time_t start_time = time(NULL);
    int current_process = 0;
    int time_quantum = 5;

    while (head) {
        Process* process = head->next;
        int remaining_time = process->burst_time - process->waiting_time;

        if (remaining_time > 0) {
            process->waiting_time++;
            printf("Process %d is waiting for %d units of time.\n", process->pid, process->waiting_time);
        } else {
            process->waiting_time = 0;
            printf("Process %d has completed its burst time.\n", process->pid);
            current_process++;
            if (current_process == MAX_PROCESS) {
                current_process = 0;
            }
            head = process->next;
        }

        sleep(time_quantum);
    }
}

int main() {
    Process* head = NULL;
    addProcess(head, 1, 8);
    addProcess(head, 2, 4);
    addProcess(head, 3, 12);
    addProcess(head, 4, 6);
    addProcess(head, 5, 10);

    roundRobin(head);

    return 0;
}