//FormAI DATASET v1.0 Category: System process viewer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

const char* PROC_DIRECTORY = "/proc";

void printProcessInfo(char* processID) {
    char processInfoPath[50];
    sprintf(processInfoPath, "%s/%s/stat", PROC_DIRECTORY, processID);
    
    FILE* processInfoFile = fopen(processInfoPath, "r");
    if (processInfoFile) {
        char processName[255];
        char processState;
        
        fscanf(processInfoFile, "%*d %s %c", processName, &processState);
        
        printf("PID: %s\n", processID);
        printf("Name: %s\n", processName);
        printf("State: %c\n\n", processState);
        
        fclose(processInfoFile);
    }
}

void getProcesses() {
    DIR* procDirectory = opendir(PROC_DIRECTORY);
    
    if (procDirectory == NULL) {
        printf("Error opening /proc directory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    struct dirent* entry;
    while ((entry = readdir(procDirectory)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char* processID = entry->d_name;
            if (atoi(processID) != 0) {
                printProcessInfo(processID);
            }
        }
    }
    
    closedir(procDirectory);
}

int main() {
    printf("Here are all the currently running processes:\n\n");
    getProcesses();
    return 0;
}