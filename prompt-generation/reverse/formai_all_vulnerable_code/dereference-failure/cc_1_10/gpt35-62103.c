//FormAI DATASET v1.0 Category: System process viewer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PATH_LEN 1024
#define MAX_PID_LEN 64
#define MAX_NAME_LEN 1024

typedef struct {
    char name[MAX_NAME_LEN];
    char state;
    float cpuUsage;
} ProcessInfo;

void printHeader() {
    printf("%-20s %-10s %-10s\n", "NAME", "PID", "STATE");
}

void printProcessInfo(ProcessInfo *info) {
    printf("%-20s %-10s %-10c\n", info->name, "N/A", info->state);
}

char *getCmdline(char *pid) {
    static char cmdline[MAX_PATH_LEN];
    sprintf(cmdline, "/proc/%s/cmdline", pid);

    FILE *fp = fopen(cmdline, "r");
    if (fp == NULL) {
        return NULL;
    }

    int i = 0;
    char c;
    while ((c = fgetc(fp)) != EOF && i < MAX_NAME_LEN - 1) {
        cmdline[i] = isprint(c) ? c : ' ';
        i++;
    }

    cmdline[i] = '\0';
    fclose(fp);

    return cmdline;
}

ProcessInfo *parseProcessInfo(char *pid) {
    static ProcessInfo info;

    char stat[MAX_PATH_LEN], line[MAX_PATH_LEN];
    sprintf(stat, "/proc/%s/stat", pid);

    FILE *fp = fopen(stat, "r");
    if (fp == NULL) {
        return NULL;
    }

    if (fgets(line, MAX_PATH_LEN, fp) != NULL) {
        char *token = strtok(line, " ");

        int i = 0;
        while (token != NULL && i < 13) {
            if (i == 1) {
                strcpy(info.name, getCmdline(pid));
            } else if (i == 2) {
                info.state = token[0];
            }

            token = strtok(NULL, " ");
            i++;
        }
    }

    fclose(fp);

    return &info;
}

float getProcessCPUUsage(char *pid) {
    static long prevTotalTicks = 0, prevProcessTicks = 0, curTotalTicks = 0, curProcessTicks = 0;
    static int isFirstTime = 1;

    char stat[MAX_PATH_LEN], line[MAX_PATH_LEN];
    sprintf(stat, "/proc/%s/stat", pid);

    FILE *fp = fopen(stat, "r");
    if (fp == NULL) {
        return 0.0;
    }

    if (fgets(line, MAX_PATH_LEN, fp) != NULL) {
        char *token = strtok(line, " ");

        int i = 0;
        while (token != NULL && i < 17) {
            if (i == 13) {
                curProcessTicks = strtol(token, NULL, 10);
            } else if (i >= 14 && i <= 16) {
                curTotalTicks += strtol(token, NULL, 10);
            }

            token = strtok(NULL, " ");
            i++;
        }
    }

    fclose(fp);

    if (isFirstTime) {
        prevTotalTicks = curTotalTicks;
        prevProcessTicks = curProcessTicks;
        isFirstTime = 0;
    } else {
        float deltaProcessTicks = (float)(curProcessTicks - prevProcessTicks);
        float deltaTotalTicks = (float)(curTotalTicks - prevTotalTicks);

        float cpuUsage = deltaProcessTicks / deltaTotalTicks * sysconf(_SC_NPROCESSORS_CONF) * 100.0;

        prevTotalTicks = curTotalTicks;
        prevProcessTicks = curProcessTicks;

        return cpuUsage;
    }

    return 0.0;
}

int main() {
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error opening /proc directory.\n");
        return 1;
    }

    printHeader();

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            char pid[MAX_PID_LEN];
            strcpy(pid, entry->d_name);

            ProcessInfo *info = parseProcessInfo(pid);
            if (info != NULL) {
                info->cpuUsage = getProcessCPUUsage(pid);

                printProcessInfo(info);
            }
        }
    }

    closedir(dir);

    return 0;
}