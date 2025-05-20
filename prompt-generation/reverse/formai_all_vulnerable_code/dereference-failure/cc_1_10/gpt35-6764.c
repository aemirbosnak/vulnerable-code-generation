//FormAI DATASET v1.0 Category: System process viewer ; Style: rigorous
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PID_LENGTH 6

void printProcessInfo(char* dirName) {
    FILE *fp;
    char statFilePath[256];
    char statusFilePath[256];
    char line[512];
    char* token;
    char* name;
    char* pid;
    char* state;

    sprintf(statFilePath, "%s/stat", dirName);
    sprintf(statusFilePath, "%s/status", dirName);

    fp = fopen(statFilePath, "r");

    if (fp == NULL) {
        return;
    }

    fgets(line, sizeof(line), fp);

    token = strtok(line, " ");
    pid = token;

    token = strtok(NULL, " ");
    name = token + 1;
    name[strlen(name) - 1] = '\0';

    token = strtok(NULL, " ");
    state = token;

    fclose(fp);

    fp = fopen(statusFilePath, "r");

    if (fp == NULL) {
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "Threads:", strlen("Threads:")) == 0) {
            token = strtok(line, " ");
            token = strtok(NULL, " ");

            printf("%6s %15s %5s %7s\n", pid, name, state, token);
            break;
        }
    }

    fclose(fp);
}

void printProcessList() {
    DIR* dir;
    struct dirent* dirEntry;
    char dirName[256];

    dir = opendir("/proc");

    if (dir == NULL) {
        return;
    }

    printf("%6s %15s %5s %7s\n", "PID", "Name", "State", "Threads");

    while ((dirEntry = readdir(dir)) != NULL) {
        if (isdigit(dirEntry->d_name[0])) {
            sprintf(dirName, "/proc/%s", dirEntry->d_name);
            printProcessInfo(dirName);
        }
    }

    closedir(dir);
}

int main() {
    printProcessList();
    return 0;
}