//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

void displayProcessName(char* pid) {
    char name[BUF_SIZE];
    char buffer[BUF_SIZE];
    snprintf(buffer, BUF_SIZE, "/proc/%s/stat", pid);
    FILE* fp = fopen(buffer, "r");
    if (fp == NULL) {
        return;
    }
    fscanf(fp, "%*s %s", name);
    fclose(fp);
    printf("  Name: %s\n", name);
}

void displayProcessStatus(char* pid) {
    char status[BUF_SIZE];
    char buffer[BUF_SIZE];
    snprintf(buffer, BUF_SIZE, "/proc/%s/status", pid);
    FILE* fp = fopen(buffer, "r");
    if (fp == NULL) {
        return;
    }
    while (fgets(status, BUF_SIZE, fp) != NULL) {
        if (strstr(status, "Uid:") != NULL) {
            printf("  UID: %s", &status[5]);
        } else if (strstr(status, "VmSize:") != NULL) {
            printf("  VM size: %s", &status[8]);
        } else if (strstr(status, "VmRSS:") != NULL) {
            printf("  VM RSS: %s", &status[7]);
        }
    }
    fclose(fp);
}

void displayProcessFiles(char* pid) {
    char buffer[BUF_SIZE];
    snprintf(buffer, BUF_SIZE, "/proc/%s/fd/", pid);
    DIR* dir = opendir(buffer);
    if (dir == NULL) {
        return;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            printf("  File: %s/%s", buffer, entry->d_name);
        }
    }
    closedir(dir);
}

void displayProcessInfo(char* pid) {
    printf("PID: %s\n", pid);
    displayProcessName(pid);
    displayProcessStatus(pid);
    displayProcessFiles(pid);
}

int main() {
    printf("--------------------------------------------\n");
    printf("---- Surrealist Process Viewer ------------\n");
    printf("--------------------------------------------\n");
    printf("\n");

    DIR* dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: Could not read /proc directory.\n");
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            displayProcessInfo(entry->d_name);
            printf("\n");
        }
    }
    closedir(dir);
    return 0;
}