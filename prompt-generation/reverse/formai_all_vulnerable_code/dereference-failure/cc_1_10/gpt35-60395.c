//FormAI DATASET v1.0 Category: System process viewer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void printProcessDetails(char* pid) {
    char* statPath = malloc(strlen("/proc//stat") + strlen(pid) + 1);
    sprintf(statPath, "/proc/%s/stat", pid);

    FILE* statFile = fopen(statPath, "r");

    char* name = malloc(100);
    char* status = malloc(10);
    int parentPid;

    fscanf(statFile, "%*d %s %*c %*d %*d %*d %*d %*d %*u"
                "%*u %*u %*u %*u %*u %*u %d", name, &parentPid);
    fclose(statFile);

    // Get parent process name
    char* parentName = malloc(100);
    char* parentStatPath = malloc(strlen("/proc//stat") + 6);
    sprintf(parentStatPath, "/proc/%d/stat", parentPid);
    FILE* parentStatFile = fopen(parentStatPath, "r");
    fscanf(parentStatFile, "%*d %s", parentName);
    fclose(parentStatFile);

    // Get process status
    char* statusPath = malloc(strlen("/proc//status") + strlen(pid) + 1);
    sprintf(statusPath, "/proc/%s/status", pid);
    FILE* statusFile = fopen(statusPath, "r");
    while (fgets(status, 10, statusFile)) {
        if (strstr(status, "State")) {
            break;
        }
    }
    fclose(statusFile);

    char* executablePath = malloc(strlen("/proc//exe") + strlen(pid) + 1);
    sprintf(executablePath, "/proc/%s/exe", pid);
    char* executableName = malloc(100);
    readlink(executablePath, executableName, 100);

    printf("PID: %s\n", pid);
    printf("Name: %s\n", name);
    printf("Executable: %s\n", executableName);
    printf("Parent PID: %d\n", parentPid);
    printf("Parent Name: %s\n", parentName);
    printf("Status: %s\n\n", status);

    free(statPath);
    free(name);
    free(statusPath);
    free(executablePath);
    free(parentName);
    free(parentStatPath);
    free(executableName);
}

void listProcesses() {
    printf("Listing all processes:\n\n");

    DIR* procDir = opendir("/proc");

    struct dirent* procEntry;
    while ((procEntry = readdir(procDir))) {
        if (isdigit(*procEntry->d_name)) {
            printProcessDetails(procEntry->d_name);
        }
    }

    closedir(procDir);
}

int main() {
    listProcesses();

    return 0;
}