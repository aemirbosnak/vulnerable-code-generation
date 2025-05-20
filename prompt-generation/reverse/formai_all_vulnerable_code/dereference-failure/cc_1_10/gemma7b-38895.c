//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

#define MAX_PROC_NUM 1024

typedef struct Process {
    char name[256];
    int pid;
    long start_time;
    long end_time;
    long cpu_usage;
    struct Process* next;
} Process;

Process* createProcess(char* name, int pid) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    strcpy(newProcess->name, name);
    newProcess->pid = pid;
    newProcess->start_time = time(NULL);
    newProcess->end_time = 0;
    newProcess->cpu_usage = 0;
    newProcess->next = NULL;
    return newProcess;
}

void calculateCPUUsage(Process* process) {
    process->end_time = time(NULL);
    long cpu_usage_seconds = process->end_time - process->start_time;
    long cpu_usage_miliseconds = (process->end_time - process->start_time) * 1000 % 1000;
    process->cpu_usage = (cpu_usage_seconds * 100) + cpu_usage_miliseconds;
}

void displayProcesses(Process* head) {
    Process* currentProcess = head;
    while (currentProcess) {
        printf("Process: %s (PID: %d)\n", currentProcess->name, currentProcess->pid);
        printf("CPU Usage: %.2f%% (seconds: %.2f, milliseconds: %.2f)\n", currentProcess->cpu_usage, currentProcess->start_time, currentProcess->end_time);
        printf("--------------------------------------------------------\n");
        currentProcess = currentProcess->next;
    }
}

int main() {
    Process* head = NULL;
    for (int i = 0; i < MAX_PROC_NUM; i++) {
        createProcess("Process ", i);
    }

    calculateCPUUsage(head);
    displayProcesses(head);

    return 0;
}