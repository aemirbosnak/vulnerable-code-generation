//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PROC_NUMBER 10

typedef struct Process {
    char name[256];
    int pid;
    int cpu_usage;
    struct Process* next;
} Process;

Process* head = NULL;

void insertProcess(char* name, int pid, int cpu_usage) {
    Process* newProcess = malloc(sizeof(Process));
    strcpy(newProcess->name, name);
    newProcess->pid = pid;
    newProcess->cpu_usage = cpu_usage;
    newProcess->next = NULL;

    if (head == NULL) {
        head = newProcess;
    } else {
        Process* tempProcess = head;
        while (tempProcess->next) {
            tempProcess = tempProcess->next;
        }
        tempProcess->next = newProcess;
    }
}

void calculateCPUUsage() {
    FILE* file = fopen("/proc/stat", "r");
    if (file) {
        char line[256];
        fscanf(file, "%s", line);
        fclose(file);

        char* cpu_usage_str = strstr(line, "us");
        int cpu_usage = atoi(cpu_usage_str);

        insertProcess("System", -1, cpu_usage);
    }
}

int main() {
    calculateCPUUsage();

    Process* process = head;
    while (process) {
        printf("%s (PID: %d) - CPU usage: %.2f%%\n", process->name, process->pid, (float)process->cpu_usage);
        process = process->next;
    }

    return 0;
}