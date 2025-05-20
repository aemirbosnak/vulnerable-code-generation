//FormAI DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Define a struct for a process
typedef struct Process {
    int pid;
    char name[256];
    int memory;
} Process;

// Function to parse process details from proc file
void parseProcessDetails(char *path, Process *process) {
    char fullPath[256];
    snprintf(fullPath, sizeof(fullPath), "%s/%s", path, "cmdline");
    FILE *file = fopen(fullPath, "r");
    if (file) {
        fscanf(file, "%s", process->name);
        fclose(file);
    }
    snprintf(fullPath, sizeof(fullPath), "%s/%s", path, "status");
    file = fopen(fullPath, "r");
    if (file) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, "Pid:")) {
                sscanf(line, "%*s %d", &process->pid);
            } else if (strstr(line, "VmRSS:")) {
                int memory;
                sscanf(line, "%*s %d", &memory);
                process->memory = memory / 1024;
            }
        }
        fclose(file);
    }
}

int main() {
    DIR *directory = opendir("/proc");
    if (!directory) {
        printf("Failed to open /proc directory\n");
        return 1;
    }
    struct dirent *entry;
    Process processes[100];
    int numProcesses = 0;
    while ((entry = readdir(directory))) {
        int isNumeric = 1;
        for (int i = 0; entry->d_name[i]; i++) {
            if (entry->d_name[i] < '0' || entry->d_name[i] > '9') {
                isNumeric = 0;
                break;
            }
        }
        if (isNumeric) {
            char path[256];
            snprintf(path, sizeof(path), "/proc/%s", entry->d_name);
            Process process;
            parseProcessDetails(path, &process);
            if (process.pid) {
                processes[numProcesses++] = process;
            }
        }
    }
    closedir(directory);
    printf("PID\tMEMORY(KB)\tNAME\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t%d\t\t%s\n", processes[i].pid, processes[i].memory, processes[i].name);
    }
    return 0;
}