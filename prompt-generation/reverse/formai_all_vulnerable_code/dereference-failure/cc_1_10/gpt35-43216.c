//FormAI DATASET v1.0 Category: System process viewer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// function to check if a string is an integer
int isInt(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

// function to read the contents of a file and return it as a string
char* readFile(char* path) {
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", path);
        return "";
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char* fileContent = (char*) malloc(fileSize + 1);
    fread(fileContent, fileSize, 1, file);
    fclose(file);

    fileContent[fileSize] = '\0';
    return fileContent;
}

// function to get the name of the process from its process ID
char* getProcessName(int pid) {
    char* path = (char*) malloc(30 * sizeof(char));
    sprintf(path, "/proc/%d/cmdline", pid);

    char* cmdLine = readFile(path);
    if (strlen(cmdLine) > 0) {
        char* processName = (char*) malloc(30 * sizeof(char));
        sscanf(cmdLine, "%s", processName);
        return processName;
    } else {
        return "";
    }
}

// function to get the status of a process (e.g. running, sleeping, etc.)
char* getProcessStatus(int pid) {
    char* path = (char*) malloc(30 * sizeof(char));
    sprintf(path, "/proc/%d/status", pid);

    char* statusContent = readFile(path);
    char* status = (char*) malloc(30 * sizeof(char));

    char* token = strtok(statusContent, "\n");
    while (token != NULL) {
        if (strncmp(token, "State:", 6) == 0) {
            strcpy(status, token + 7);
            break;
        }
        token = strtok(NULL, "\n");
    }

    return status;
}

// function to get the amount of memory currently used by the process
int getProcessMemory(int pid) {
    char* path = (char*) malloc(30 * sizeof(char));
    sprintf(path, "/proc/%d/statm", pid);

    char* statmContent = readFile(path);
    char* token = strtok(statmContent, " ");
    int memSize = 0;
    if (token != NULL) {
        memSize = atoi(token);
    }

    return memSize * getpagesize();
}

int main() {
    printf("Process Viewer\n\n");

    DIR* dir = opendir("/proc/");
    if (dir == NULL) {
        printf("Error opening directory\n");
        return 1;
    }

    struct dirent* entry;
    printf("%-10s%-20s%-15s%s\n", "PID", "Process Name", "Status", "Memory Usage");
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type != DT_DIR || !isInt(entry->d_name)) {
            continue;
        }

        int pid = atoi(entry->d_name);
        char* processName = getProcessName(pid);
        char* status = getProcessStatus(pid);
        int memoryUsage = getProcessMemory(pid);

        if (strlen(processName) > 0) {
            printf("%-10d%-20s%-15s%d KB\n", pid, processName, status, memoryUsage / 1024);
        }

        free(processName);
        free(status);
    }

    closedir(dir);
    return 0;
}