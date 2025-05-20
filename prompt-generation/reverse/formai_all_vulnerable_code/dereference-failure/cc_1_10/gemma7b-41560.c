//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PROCESSES 1024

typedef struct Process {
    char name[256];
    int pid;
    struct Process* next;
} Process;

Process* head = NULL;

void addProcess(char* name) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    strcpy(newProcess->name, name);
    newProcess->pid = getpid();
    newProcess->next = head;
    head = newProcess;
}

void monitorCPUUsage() {
    FILE* file = fopen("/proc/stat", "r");
    char line[1024];
    char* ptr;
    int totalUserTime = 0;
    int totalSystemTime = 0;
    int totalIdleTime = 0;

    while (fgets(line, 1024, file) != NULL) {
        ptr = line;
        while (*ptr != '\0') {
            if (strcmp(ptr, "user") == 0) {
                totalUserTime++;
            } else if (strcmp(ptr, "system") == 0) {
                totalSystemTime++;
            } else if (strcmp(ptr, "idle") == 0) {
                totalIdleTime++;
            }
            ptr++;
        }
    }

    fclose(file);

    int totalTime = totalUserTime + totalSystemTime + totalIdleTime;
    double cpuUsage = (double)totalUserTime * 100.0 / (double)totalTime;

    printf("CPU Usage: %.2f%%", cpuUsage);
}

int main() {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        addProcess("Process A");
    }

    for (int i = 0; i < MAX_PROCESSES; i++) {
        addProcess("Process B");
    }

    monitorCPUUsage();

    return 0;
}