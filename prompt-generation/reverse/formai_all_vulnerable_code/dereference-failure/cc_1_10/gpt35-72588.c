//FormAI DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define PID_LENGTH 6
#define CMD_LENGTH 50
#define STAT_LENGTH 150

typedef struct Process {
    char pid[PID_LENGTH];
    char cmd[CMD_LENGTH];
    char stat[STAT_LENGTH];
} Process;

void printHeader() {
    printf(" PID   CMD                     STATUS\n");
    printf("----------------------------------------\n");
}

void printProcess(Process p) {
    printf("%s", p.pid);
    int pidLength = strlen(p.pid);
    for (int i = 0; i < PID_LENGTH - pidLength; i++) {
        printf(" ");
    }
    printf("%s", p.cmd);
    int cmdLength = strlen(p.cmd);
    for (int i = 0; i < CMD_LENGTH - cmdLength; i++) {
        printf(" ");
    }
    printf("%s\n", p.stat);
}

void viewProcesses() {
    DIR* dir = opendir("/proc/");
    if (dir == NULL) {
        printf("Error: Could not open /proc directory.");
        return;
    }

    struct dirent* dp;
    while ((dp = readdir(dir)) != NULL) {
        if (isdigit(dp->d_name[0])) {
            Process p;
            strcpy(p.pid, dp->d_name);

            // Read command
            char cmdPath[100];
            sprintf(cmdPath, "/proc/%s/cmdline", dp->d_name);
            FILE* cmdFile = fopen(cmdPath, "r");
            if (cmdFile == NULL) {
                printf("Error: Could not open command file for PID %s.", p.pid);
                continue;
            }
            fgets(p.cmd, CMD_LENGTH, cmdFile);
            fclose(cmdFile);

            // Read status
            char statPath[100];
            sprintf(statPath, "/proc/%s/stat", dp->d_name);
            FILE* statFile = fopen(statPath, "r");
            if (statFile == NULL) {
                printf("Error: Could not open status file for PID %s.", p.pid);
                continue;
            }
            fgets(p.stat, STAT_LENGTH, statFile);
            fclose(statFile);

            printProcess(p);
        }
    }
    closedir(dir);
}

int main() {
    printf("=== SYSTEM PROCESS VIEWER ===\n\n");

    viewProcesses();

    printf("\n=== END OF LIST ===\n");
    return 0;
}