//FormAI DATASET v1.0 Category: System process viewer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_CMD 256
#define MAX_PATH 1024

/* Function to get process name */
void getProcessName(char *pid, char *name) {
    char path[MAX_PATH];
    FILE *fp;
    sprintf(path, "/proc/%s/cmdline", pid);
    fp = fopen(path, "r");
    if (fp != NULL) {
        fgets(name, MAX_CMD, fp);
        fclose(fp);
    }
}

/* Function to print process details */
void printProcDetails(struct dirent *entry) {
    char pid[10];
    char name[MAX_CMD];
    char path[MAX_PATH];
    char commandLine[MAX_CMD];
    char *status = "N/A";
    DIR *dir;
    FILE *fp;
    struct dirent *dp;
    sprintf(path, "/proc/%s/status", entry->d_name);
    fp = fopen(path, "r");
    if (fp != NULL) {
        fscanf(fp, "%*s %s", pid);
        fscanf(fp, "%*s %s", name);
        fclose(fp);
        getProcessName(pid, name);
        sprintf(path, "/proc/%s/cmdline", pid);
        fp = fopen(path, "r");
        if (fp != NULL) {
            fgets(commandLine, MAX_CMD, fp);
            fclose(fp);
        }
        printf("PID: %s\tNAME: %s\tCOMMAND: %s\n", pid, name, commandLine);
    }
}

int main(void) {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH];
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Failed to open /proc directory");
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name) != 0) {
            printProcDetails(entry);
        }
    }
    closedir(dir);
    return EXIT_SUCCESS;
}