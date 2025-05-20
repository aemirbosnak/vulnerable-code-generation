//FormAI DATASET v1.0 Category: System process viewer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 2048
#define MAX_NUMBER_OF_PROCESS 1024

typedef struct {
    int pid;
    char comm[MAX_COMMAND_LENGTH];
    char state;
    int parent_pid;
    int utime;
    int stime;
    int vm_size;
    int rss;
} ProcessInformation;

void printHeader() {
    printf("%5s %20s %5s %10s %10s %10s %10s %10s\n", 
            "PID", "COMMAND", "STATE", "PARENT", "UTIME", "STIME", "VM_SIZE", "RSS");
}

void printProcessInformation(ProcessInformation *process) {
    printf("%5d %20s %5c %10d %10d %10d %10d %10d\n", 
            process->pid, process->comm, process->state, 
            process->parent_pid, process->utime, process->stime,
            process->vm_size, process->rss
    );
}

char *parseProcessState(char *state) {
    if (strcmp(state, "R") == 0) {
        return "Running";
    } else if (strcmp(state, "S") == 0) {
        return "Sleeping";
    } else if (strcmp(state, "D") == 0) {
        return "Disk sleep";
    } else if (strcmp(state, "T") == 0) {
        return "Stopped";
    } else if (strcmp(state, "t") == 0) {
        return "Tracing stop";
    } else if (strcmp(state, "Z") == 0) {
        return "Zombie";
    } else {
        return "Unknown";
    }
}

void parseProcessStat(char *stat, ProcessInformation *process) {
    char *token = strtok(stat, " ");
    int i = 0;
    while (token) {
        switch (i) {
            case 0:
                process->pid = atoi(token);
                break;
            case 1:
                strcpy(process->comm, token+1);
                process->comm[strlen(process->comm)-1] = '\0';
                break;
            case 2:
                process->state = token[0];
                break;
            case 3:
                process->parent_pid = atoi(token);
                break;
            case 13:
                process->utime = atoi(token);
                break;
            case 14:
                process->stime = atoi(token);
                break;
            case 22:
                process->vm_size = atoi(token);
                break;
            case 23:
                process->rss = atoi(token);
                break;
        }
        token = strtok(NULL, " ");
        i++;
    }
}

int isNumber(char *string) {
    for (int i = 0; i < strlen(string); i++) {
        if (!isdigit(string[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    DIR *directory = opendir("/proc");
    struct dirent *entry;
    int numberOfProcess = 0;
    ProcessInformation processArray[MAX_NUMBER_OF_PROCESS];

    while ((entry = readdir(directory)) != NULL) {
        if (isNumber(entry->d_name)) {
            char filename[MAX_COMMAND_LENGTH];
            snprintf(filename, sizeof(filename), "/proc/%s/stat", entry->d_name);
            FILE *file = fopen(filename, "r");
            if (file) {
                char stat[MAX_COMMAND_LENGTH];
                fgets(stat, sizeof(stat), file);
                fclose(file);
                parseProcessStat(stat, &processArray[numberOfProcess]);
                numberOfProcess++;
            }
        }
    }
    closedir(directory);
    
    printHeader();

    for (int i = 0; i < numberOfProcess; i++) {
        processArray[i].state = *parseProcessState(&processArray[i].state);
        printProcessInformation(&processArray[i]);
    }
    
    return 0;
}