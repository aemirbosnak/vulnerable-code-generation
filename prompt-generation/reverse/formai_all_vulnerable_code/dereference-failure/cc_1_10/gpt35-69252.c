//FormAI DATASET v1.0 Category: System process viewer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

// Define constants for sorting process list
#define SORT_BY_PID 1
#define SORT_BY_NAME 2
#define SORT_BY_CPU 3
#define SORT_BY_MEMORY 4

// Define struct for storing process information
typedef struct {
    int pid;
    char name[256];
    float cpu;
    float memory;
} ProcessInfo;

// Function to get process information from `/proc` directory
ProcessInfo getProcessInfo(char *dirName) {

    // Open directory
    DIR *dir = opendir(dirName);
    if (dir == NULL) {
        printf("Failed to open directory: %s\n", dirName);
        exit(1);
    }

    // Initialize process info struct
    ProcessInfo info;
    info.pid = atoi(dirName); // Process ID is directory name
    info.cpu = 0.0;
    info.memory = 0.0;

    // Read `status` file in directory
    char filePath[256];
    snprintf(filePath, sizeof(filePath), "%s/status", dirName);
    FILE *fp = fopen(filePath, "r");
    if (fp == NULL) {
        printf("Failed to open file: %s\n", filePath);
        closedir(dir);
        exit(1);
    }

    // Parse `status` file for process name and memory usage
    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *field = strtok(line, ":");
        if (field != NULL) {
            if (strcmp(field, "Name") == 0) {
                field = strtok(NULL, ":");
                if (field != NULL) {
                    strcpy(info.name, field);
                    // Remove trailing whitespace from name
                    int i = strlen(info.name) - 1;
                    while (isspace(info.name[i])) {
                        info.name[i] = '\0';
                        i--;
                    }
                }
            } else if (strcmp(field, "VmRSS") == 0) {
                field = strtok(NULL, ":");
                if (field != NULL) {
                    // Convert memory usage from kB to MB
                    float usage = atof(field) / 1024.0;
                    info.memory = usage;
                }
            }
        }
    }

    // Close file and directory
    fclose(fp);
    closedir(dir);

    return info;
}

// Function to get CPU usage for a process
float getProcessCpu(int pid) {
    // TODO: Implement getting CPU usage for a process
    return 0.0;
}

// Function to print a process list
void printProcessList(ProcessInfo *list, int numProcesses) {
    printf("%-10s %-25s %-10s %-10s\n", "PID", "Name", "CPU", "Memory");
    for (int i = 0; i < numProcesses; i++) {
        printf("%-10d %-25s %-10.2f %-10.2f\n", list[i].pid, list[i].name, list[i].cpu, list[i].memory);
    }
}

// Function to sort process list based on specified criteria
void sortProcessList(ProcessInfo *list, int numProcesses, int sortCriteria) {
    if (sortCriteria == SORT_BY_PID) {
        // Sort by process ID
        for (int i = 0; i < numProcesses - 1; i++) {
            for (int j = i + 1; j < numProcesses; j++) {
                if (list[i].pid > list[j].pid) {
                    // Swap processes
                    ProcessInfo temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
    } else if (sortCriteria == SORT_BY_NAME) {
        // Sort by process name
        for (int i = 0; i < numProcesses - 1; i++) {
            for (int j = i + 1; j < numProcesses; j++) {
                if (strcmp(list[i].name, list[j].name) > 0) {
                    // Swap processes
                    ProcessInfo temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
    } else if (sortCriteria == SORT_BY_CPU) {
        // Sort by CPU usage
        for (int i = 0; i < numProcesses - 1; i++) {
            for (int j = i + 1; j < numProcesses; j++) {
                if (list[i].cpu < list[j].cpu) {
                    // Swap processes
                    ProcessInfo temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
    } else if (sortCriteria == SORT_BY_MEMORY) {
        // Sort by memory usage
        for (int i = 0; i < numProcesses - 1; i++) {
            for (int j = i + 1; j < numProcesses; j++) {
                if (list[i].memory < list[j].memory) {
                    // Swap processes
                    ProcessInfo temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
    }
}

int main() {

    // Define array for storing process information
    ProcessInfo processList[256];

    // Open `/proc` directory
    DIR *procDir = opendir("/proc");
    if (procDir == NULL) {
        printf("Failed to open directory: /proc\n");
        return 1;
    }

    // Read `/proc` directory and get process information
    int numProcesses = 0;
    struct dirent *entry;
    while ((entry = readdir(procDir)) != NULL) {
        // Get process ID by parsing directory name as integer
        int pid = atoi(entry->d_name);
        if (pid > 0) {
            // Get process information from `/proc` directory
            char dirName[256];
            snprintf(dirName, sizeof(dirName), "/proc/%d", pid);
            ProcessInfo info = getProcessInfo(dirName);
            if (strcmp(info.name, "") != 0) {
                // Add process to list if it has a name
                processList[numProcesses] = info;
                numProcesses++;
            }
        }
    }

    // Close directory
    closedir(procDir);

    // Get CPU usage for each process
    for (int i = 0; i < numProcesses; i++) {
        processList[i].cpu = getProcessCpu(processList[i].pid);
    }

    // Print process list
    printProcessList(processList, numProcesses);

    // Sort process list
    sortProcessList(processList, numProcesses, SORT_BY_MEMORY);

    // Print sorted process list
    printf("\nSorted by memory usage:\n");
    printProcessList(processList, numProcesses);

    return 0;
}