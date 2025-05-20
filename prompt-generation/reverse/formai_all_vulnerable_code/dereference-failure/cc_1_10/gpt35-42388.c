//FormAI DATASET v1.0 Category: System process viewer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define STAT_FILE "/proc/%s/stat"
#define BUFFER_SIZE 1024

struct procStats {
    int pid;
    char processName[100];
    char state;
    int parentPid;
    int processGroup;
    unsigned int utime;
    unsigned int stime;
    unsigned int startTime;
    unsigned int vsize;
    unsigned long int rss;
};

void printProcStats(struct procStats *stats) {
    printf("%d %s %c %d %d %u %u %u %u %lu\n", stats->pid, stats->processName, stats->state,
           stats->parentPid, stats->processGroup, stats->utime, stats->stime,
           stats->startTime, stats->vsize, stats->rss);
}

int getProcessNumber() {
    DIR *dir;
    struct dirent *entry;
    int n = 0;

    dir = opendir("/proc");
    if (!dir) {
        printf("Error opening /proc directory.\n");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            n++;
        }
    }

    closedir(dir);
    return n;
}

void parseStatFile(char *statFile, struct procStats *stats) {
    char *token;
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(statFile, "r");

    if (!file) {
        return;
    }

    fgets(buffer, BUFFER_SIZE, file);

    token = strtok(buffer, " ");
    stats->pid = atoi(token);

    token = strtok(NULL, " ");
    strcpy(stats->processName, token);

    token = strtok(NULL, " ");
    stats->state = token[0];

    token = strtok(NULL, " ");
    stats->parentPid = atoi(token);

    token = strtok(NULL, " ");
    stats->processGroup = atoi(token);

    // Skip next 14 tokens (fields)
    for (int i = 0; i < 14; i++) {
        strtok(NULL, " ");
    }

    token = strtok(NULL, " ");
    stats->utime = atoi(token);

    token = strtok(NULL, " ");
    stats->stime = atoi(token);

    // Skip next 7 tokens (fields)
    for (int i = 0; i < 7; i++) {
        strtok(NULL, " ");
    }

    token = strtok(NULL, " ");
    stats->startTime = atoi(token);

    token = strtok(NULL, " ");
    stats->vsize = atoi(token);

    token = strtok(NULL, " ");
    stats->rss = atol(token);

    fclose(file);
}

int main(int argc, char *argv[]) {
    int numProcesses = getProcessNumber();
    struct procStats *processes = malloc(numProcesses * sizeof(struct procStats));

    DIR *dir;
    struct dirent *entry;
    int i = 0;

    dir = opendir("/proc");
    if (!dir) {
        printf("Error opening /proc directory.\n");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL && i < numProcesses) {
        if (isdigit(entry->d_name[0])) {
            char statFile[BUFFER_SIZE];
            sprintf(statFile, STAT_FILE, entry->d_name);
            parseStatFile(statFile, &processes[i]);
            i++;
        }
    }

    printf("PID  ProcessName State PPID  PGRP  Utime Stime StartTime Vsize RSS\n");

    for (int i = 0; i < numProcesses; i++) {
        printProcStats(&processes[i]);
    }

    free(processes);
    closedir(dir);
    return 0;
}