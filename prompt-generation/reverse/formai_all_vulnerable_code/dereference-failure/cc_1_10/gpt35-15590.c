//FormAI DATASET v1.0 Category: System process viewer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Function to check if a strng is a valid number
int isNumber(char* str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

// Function to read the status file of a process
void readStatusFile(pid_t pid, char* status) {
    char fileName[64];
    sprintf(fileName, "/proc/%d/status", pid);
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Failed to read status file for process %d\n", pid);
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, status) != NULL) {
            printf("%s", line);
        }
    }

    fclose(fp);
}

// Main function to read the active processes on the system
int main() {
    DIR* dir = opendir("/proc");
    struct dirent* entry;

    printf("PID\tName\t\tStatus\n");
    printf("--------------------------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        if (isNumber(entry->d_name)) {
            pid_t pid = strtol(entry->d_name, NULL, 10);

            char cmdFileName[64];
            sprintf(cmdFileName, "/proc/%d/cmdline", pid);
            FILE* cmdFile = fopen(cmdFileName, "r");

            // Skip kernel threads and system processes
            if (cmdFile == NULL) continue;

            char cmd[256];
            fgets(cmd, sizeof(cmd), cmdFile);
            fclose(cmdFile);

            if (strlen(cmd) == 0) continue;

            // Get the process status
            readStatusFile(pid, "State:");

            // Get the process name
            char *token = strtok(cmd, "/");
            char name[64];
            while (token != NULL) {
                strcpy(name, token);
                token = strtok(NULL, "/");
            }
            printf("%d\t%s\t\t\n", pid, name);
        }
    }
    closedir(dir);
    return 0;
}