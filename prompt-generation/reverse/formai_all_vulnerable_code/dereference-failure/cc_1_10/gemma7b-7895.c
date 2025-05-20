//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct Process {
    char name[20];
    int pid;
    int memoryUsage;
    int cpuUsage;
    struct Process* next;
};

struct Process* head = NULL;

void addProcess(char* name, int pid, int memoryUsage, int cpuUsage) {
    struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
    strcpy(newProcess->name, name);
    newProcess->pid = pid;
    newProcess->memoryUsage = memoryUsage;
    newProcess->cpuUsage = cpuUsage;
    newProcess->next = NULL;

    if (head == NULL) {
        head = newProcess;
    } else {
        struct Process* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newProcess;
    }
}

void viewProcesses() {
    struct Process* currentProcess = head;
    printf("Processes:\n");
    while (currentProcess) {
        printf("Name: %s, PID: %d, Memory Usage: %d, CPU Usage: %d\n", currentProcess->name, currentProcess->pid, currentProcess->memoryUsage, currentProcess->cpuUsage);
        currentProcess = currentProcess->next;
    }
}

int main() {
    addProcess("Process A", 1234, 50, 20);
    addProcess("Process B", 5678, 20, 10);
    addProcess("Process C", 9102, 70, 30);

    viewProcesses();

    return 0;
}