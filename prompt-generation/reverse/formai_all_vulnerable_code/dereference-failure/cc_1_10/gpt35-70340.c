//FormAI DATASET v1.0 Category: System process viewer ; Style: retro
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_PID_LENGTH 6

// Struct to store Process information
struct Process {
    char pid[MAX_PID_LENGTH];
    char command[MAX_COMMAND_LENGTH];
};

// Function to parse /proc directory and retrieve process information
void getProcesses(struct Process *processes, int *numProcesses) {
    DIR *dir;
    struct dirent *entry;

    // Open /proc directory
    dir = opendir("/proc");

    // Loop through each directory entry
    while ((entry = readdir(dir)) != NULL) {
        char pid[MAX_PID_LENGTH];
        strcpy(pid, entry->d_name);

        // Check if directory entry is a number (PID)
        if (atoi(pid) > 0) {
            char statFile[MAX_COMMAND_LENGTH];

            // Retrieve command information from /proc/[PID]/stat file
            sprintf(statFile, "/proc/%s/stat", pid);
            FILE *file = fopen(statFile, "r");
            fscanf(file, "%s %s", pid, processes[*numProcesses].command);

            // Remove parentheses from command string
            int len = strlen(processes[*numProcesses].command);
            processes[*numProcesses].command[len - 1] = '\0';
            for (int i = 1; i < len - 1; i++) {
                processes[*numProcesses].command[i - 1] = processes[*numProcesses].command[i];
            }
            processes[*numProcesses].command[len - 2] = '\0';

            (*numProcesses)++;

            fclose(file);
        }
    }

    closedir(dir);
}

// Function to print process information in a table
void printTable(struct Process *processes, int numProcesses) {
    printf("PID\tCOMMAND\n");
    printf("===\t=======\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%s\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    struct Process processes[100];
    int numProcesses = 0;

    // Retrieve process information
    getProcesses(processes, &numProcesses);

    // Print process table
    printTable(processes, numProcesses);

    return 0;
}