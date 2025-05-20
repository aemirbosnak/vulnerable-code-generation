//FormAI DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_PID_LEN 10
#define MAX_CMDLINE_LEN 256

typedef struct {
    char pid[MAX_PID_LEN];
    char cmdline[MAX_CMDLINE_LEN];
} ProcessInfo;

void printProcesses(ProcessInfo *processes, int numProcesses) {
    printf("%-10s\t%s\n", "PID", "COMMAND");
    for (int i = 0; i < numProcesses; i++) {
        printf("%-10s\t%s\n", processes[i].pid, processes[i].cmdline);
    }
}

int main() {
    DIR *dir;
    struct dirent *entry;
    char path[64];
    ProcessInfo processes[1000];
    int numProcesses = 0;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && atoi(entry->d_name) != 0) {
            strcpy(path, "/proc/");
            strcat(path, entry->d_name);
            strcat(path, "/cmdline");

            FILE *fp = fopen(path, "r");
            if (fp == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
            }

            char cmdline[MAX_CMDLINE_LEN];
            fgets(cmdline, MAX_CMDLINE_LEN, fp);
            fclose(fp);

            strcpy(processes[numProcesses].pid, entry->d_name);
            strcpy(processes[numProcesses].cmdline, cmdline);
            numProcesses++;
        }
    }

    closedir(dir);

    printProcesses(processes, numProcesses);

    return 0;
}