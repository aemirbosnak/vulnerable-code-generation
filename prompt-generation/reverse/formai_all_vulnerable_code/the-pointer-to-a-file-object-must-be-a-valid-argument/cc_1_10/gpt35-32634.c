//FormAI DATASET v1.0 Category: System process viewer ; Style: expert-level
#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define PROC_DIRECTORY "/proc/"

struct ProcessInfo {
    char pid[10]; 
    char name[100];
    char status[25];
    char threads[25];
    char virtualMemory[50];
};

void displayProcessInfo(char *pid) {
    // Open the process status file.
    char path[100];
    sprintf(path, "%s%s/status", PROC_DIRECTORY, pid);
    FILE *statusFile = fopen(path, "r");

    // Read the information from the status file.
    char line[200];
    struct ProcessInfo processInfo;
    while (fgets(line, 200, statusFile)) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line + 5, "%[^\n]", processInfo.name);
        } else if (strncmp(line, "State:", 6) == 0) {
            sscanf(line + 6, "%s", processInfo.status);
        } else if (strncmp(line, "Threads:", 8) == 0) {
            sscanf(line + 8, "%s", processInfo.threads);
        } else if (strncmp(line, "VmSize:", 7) == 0) {
            sscanf(line + 7, "%s", processInfo.virtualMemory);
            strcat(processInfo.virtualMemory, " KB");
        }
    }
    fclose(statusFile);

    printf("%-10s%-25s%-25s%-10s%-20s\n", pid, processInfo.name,
           processInfo.status, processInfo.threads, processInfo.virtualMemory);
}

void displayProcessList() {
    printf("%-10s%-25s%-25s%-10s%-20s\n", "PID", "NAME", "STATUS", "THREADS", "VIRTUAL MEMORY");
    printf("------------------------------------------------------------\n");
    DIR *procDir = opendir(PROC_DIRECTORY);
    if (procDir == NULL) {
        printf("Failed to open %s directory", PROC_DIRECTORY);
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(procDir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            displayProcessInfo(entry->d_name);
        }
    }
    closedir(procDir);
}

int main() {
    displayProcessList();
    return 0;
}