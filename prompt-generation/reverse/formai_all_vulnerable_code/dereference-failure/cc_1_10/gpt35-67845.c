//FormAI DATASET v1.0 Category: System process viewer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define PID_LENGTH 6

int isNumber(char* str) {
    int i;
    for (i=0; i<strlen(str); i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

void printProcessInfo(char* pid) {
    char statPath[20];
    char cmdLinePath[25];
    char procState[15];
    char procName[25];
    char cmdLine[200];
    char state;
    int uid, gid, ppid;
    long unsigned int vsize;

    snprintf(statPath, sizeof(statPath), "/proc/%s/stat", pid);
    FILE *statFile = fopen(statPath, "r");
    if (statFile == NULL) {
        printf("Error: Couldn't open file %s\n", statPath);
        exit(1);
    }

    fscanf(statFile, "%*s %s %c %d %d %*s %*s %*s %*s %*s %*s %*s %*s %lu "
                      "%lu %*s %*s %d %*s %*s %*s %*s %lu", procName, &state, &ppid, &gid, &uid, &vsize);

    snprintf(cmdLinePath, sizeof(cmdLinePath), "/proc/%s/cmdline", pid);
    FILE *cmdLineFile = fopen(cmdLinePath, "r");
    if (cmdLineFile == NULL) {
        printf("Error: Couldn't open file %s\n", cmdLinePath);
        fclose(statFile);
        exit(1);
    }

    fgets(cmdLine, sizeof(cmdLine), cmdLineFile);

    if (state == 'R') {
        strcpy(procState, "RUNNING");
    } else if (state == 'S') {
        strcpy(procState, "SLEEPING");
    } else if (state == 'Z') {
        strcpy(procState, "ZOMBIE");
    } else {
        strcpy(procState, "UNKNOWN");
    }

    printf("%-6s %-12s %-8d %-8d %-8d %-8lu %s %s\n", pid, procName, ppid, uid, gid, vsize, procState, cmdLine);

    fclose(statFile);
    fclose(cmdLineFile);
}

int main() {
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: Couldn't open directory /proc\n");
        exit(1);
    }

    struct dirent *entry;
    printf("%-6s %-12s %-8s %-8s %-8s %-8s %s %s\n", "PID", "PROCESS",
           "PPID", "UID", "GID", "VSIZE", "STATE", "COMMAND");
    while ((entry = readdir(dir)) != NULL) {
        if (isNumber(entry->d_name)) {
            printProcessInfo(entry->d_name);
        }
    }

    closedir(dir);
    return 0;
}