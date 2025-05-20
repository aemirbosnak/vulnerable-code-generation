//FormAI DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH 1024

void showProcess(char* pid);
void showCommand(char* pid);
void showCpuInfo(char* pid);
void showMemoryInfo(char* pid);
void showAllProcesses();
char* getProcessName(char* pid);
int checkIfNumber(char* str);

int main(int argc, char* argv[]) {
    // Check if pid is supplied in the argument
    if(argc == 2) {
        showProcess(argv[1]);
    }
    else {
        showAllProcesses();
    }
    return 0;
}

// Function to display CPU information of the process
void showCpuInfo(char* pid) {
    char buffer[MAX_PATH];
    sprintf(buffer, "/proc/%s/stat", pid);    
    FILE* file = fopen(buffer, "r");
    if(file) {
        char cpuTime[1024];
        int count = 0;
        while(count < 14) {
            fscanf(file, "%s", cpuTime);
            count++;
        }
        printf("CPU Time: %s\n", cpuTime);
        fclose(file);
    }
}

// Function to display memory information of the process
void showMemoryInfo(char* pid) {
    char buffer[MAX_PATH];
    sprintf(buffer, "/proc/%s/status", pid);
    FILE* file = fopen(buffer, "r");
    if(file) {
        char memInfo[1024];
        while(fscanf(file, "%s", memInfo) != EOF) {
            if(strcmp(memInfo, "VmPeak:") == 0 || 
               strcmp(memInfo, "VmSize:") == 0 || 
               strcmp(memInfo, "VmLck:") == 0 || 
               strcmp(memInfo, "VmPin:") == 0 || 
               strcmp(memInfo, "VmHWM:") == 0 || 
               strcmp(memInfo, "VmRSS:") == 0 || 
               strcmp(memInfo, "VmData:") == 0 || 
               strcmp(memInfo, "VmStk:") == 0 || 
               strcmp(memInfo, "VmExe:") == 0 || 
               strcmp(memInfo, "VmLib:") == 0 || 
               strcmp(memInfo, "VmPTE:") == 0) {
                fscanf(file, "%s", memInfo);
                printf("%s\n", memInfo);
            }
        }
        fclose(file);
    }
}

// Function to display command line used to run the process
void showCommand(char* pid) {
    char buffer[MAX_PATH];
    sprintf(buffer, "/proc/%s/cmdline", pid);
    FILE* file = fopen(buffer, "r");
    if(file) {
        char commandLine[1024];
        fscanf(file, "%s", commandLine);
        printf("Command: %s\n", commandLine);
        fclose(file);
    }
}

// Function to display process id, name, cpu and memory information
void showProcess(char* pid) {
    printf("\n[Process %s]\n", pid);
    char* processName = getProcessName(pid);
    if(processName) {
        printf("Process Name: %s\n", processName);
    }
    else {
        printf("Process Name: Unknown\n");
    }
    showCommand(pid);
    showCpuInfo(pid);
    showMemoryInfo(pid);
}

// Function to display all processes showing pid and name only
void showAllProcesses() {
    DIR* dir = opendir("/proc");
    struct dirent* entry;
    while((entry = readdir(dir)) != NULL) {
        if(checkIfNumber(entry->d_name)) {
            char* processName = getProcessName(entry->d_name);
            if(processName) {
                printf("[%s] %s\n", entry->d_name, processName);
            }
            else {
                printf("[%s] Unknown\n", entry->d_name);
            }
        }
    }
    closedir(dir);
}

// Function to obtain process name by using the pid
char* getProcessName(char* pid) {
    char buffer[MAX_PATH];
    sprintf(buffer, "/proc/%s/stat", pid);    
    FILE* file = fopen(buffer, "r");
    if(file) {
        char name[1024];
        fscanf(file, "%*d (%[^)])", name);
        fclose(file);
        char* processName = malloc(sizeof(char)*strlen(name)+1);
        strcpy(processName, name);
        return processName;
    }
    return NULL;
}

// Function to check if a given character string only contains numbers
int checkIfNumber(char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}