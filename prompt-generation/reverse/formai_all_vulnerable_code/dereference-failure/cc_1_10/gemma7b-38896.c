//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define NUM_PROC 4
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
    int pid;
    char name[20];
    int cpu_time;
    int waiting_time;
    struct Process* next;
} Process;

Process* head = NULL;

void schedule_process(Process* process) {
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void simulate_cpu(Process* process) {
    printf("Process %s is running...\n", process->name);
    sleep(process->cpu_time);
    printf("Process %s has finished running.\n", process->name);
}

int main() {
    for (int i = 0; i < NUM_PROC; i++) {
        Process* process = malloc(sizeof(Process));
        process->pid = i + 1;
        sprintf(process->name, "Process %d", process->pid);
        process->cpu_time = rand() % MAX_SCHEDULE_SIZE;
        process->waiting_time = 0;
        process->next = NULL;
        schedule_process(process);
    }

    while (!head->next) {
        simulate_cpu(head);
        head = head->next;
    }

    return 0;
}