//FormAI DATASET v1.0 Category: System process viewer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

void displayProcessInfo(char *procName, char *ppid, char *status) {
    printf("Process Name: %s\n"
           "Parent Process ID: %s\n"
           "Status: %s\n", procName, ppid, status);
}

int isNumeric(char *value) {
    for (int i = 0; i < strlen(value); i++)
        if (!isdigit(value[i]))
            return 0;
    return 1;
}

void readProcessStatus(char *pid) {
    char filePath[100];
    char line[100];
    char *ppid = "";
    char *procName = "";
    char *status = "";

    sprintf(filePath, "/proc/%s/status", pid);

    FILE* fp = fopen(filePath, "r");
    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, "PPid:")) {
                ppid = strtok(line, "PPid:");
                ppid = strtok(ppid, "\n\t ");
            } else if (strstr(line, "Name:")) {
                procName = strtok(line, "Name:");
                procName = strtok(procName, "\n\t ");
            } else if (strstr(line, "State:")) {
                status = strtok(line, "State:");
                status = strtok(status, "\n\t ");
            }
        }
        fclose(fp);
    }
    displayProcessInfo(procName, ppid, status);
}

void listProcesses() {
    DIR *directory;
    struct dirent *entry;

    directory = opendir("/proc");
    if (directory) {
        while ((entry = readdir(directory))) {
            if (isNumeric(entry->d_name)) {
                readProcessStatus(entry->d_name);
            }
        }
        closedir(directory);
    } else {
        printf("Error reading directory!\n");
    }
}

int main() {
    listProcesses();
    return 0;
}