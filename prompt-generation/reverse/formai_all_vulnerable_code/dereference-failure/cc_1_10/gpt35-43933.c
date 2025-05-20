//FormAI DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a number
int isNumber(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to get the process name from the process status file
char* getProcessName(char *pid) {
    char *filename = malloc(255 * sizeof(char));
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    sprintf(filename, "/proc/%s/status", pid);
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open process status file for PID %s\n", pid);
        return "";
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strncmp(line, "Name:", 5) == 0) {
            char *processName = malloc(255 * sizeof(char));
            sscanf(line, "Name:\t%s", processName);
            fclose(fp);
            return processName;
        }
    }

    fclose(fp);

    return "";
}

// Function to print the process information
void printProcessInfo(char *pid) {
    char *filename = malloc(255 * sizeof(char));
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    sprintf(filename, "/proc/%s/status", pid);
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open process status file for PID %s\n", pid);
        return;
    }

    printf("PID: %s\n", pid);

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strncmp(line, "Name:", 5) == 0) {
            printf("Name: %s\n", getProcessName(pid));
        } else if (strncmp(line, "State:", 6) == 0) {
            char state;
            sscanf(line, "State:\t%c", &state);
            printf("State: %c\n", state);
        } else if (strncmp(line, "PPid:", 5) == 0) {
            char ppid[255];
            sscanf(line, "PPid:\t%s", ppid);
            printf("Parent PID: %s\n", ppid);
        } else if (strncmp(line, "Threads:", 8) == 0) {
            int threads;
            sscanf(line, "Threads:\t%d", &threads);
            printf("Number of threads: %d\n", threads);
        }
    }

    fclose(fp);

    printf("\n");
}

int main() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");

    if (dir == NULL) {
        printf("Could not open /proc directory\n");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isNumber(entry->d_name)) {
            printProcessInfo(entry->d_name);
        }
    }

    closedir(dir);

    return 0;
}