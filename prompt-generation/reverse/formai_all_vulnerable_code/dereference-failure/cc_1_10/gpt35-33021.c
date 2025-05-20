//FormAI DATASET v1.0 Category: System process viewer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

struct ProcessInfo {
    int pid;
    char name[50];
    char state[20];
    uid_t uid;
    unsigned long int mem;
};

// Function to get all the process info from the /proc directory
int getProcessInfo(struct ProcessInfo* processInfoArray, int maxProcessCount) {
    DIR *procDir;
    struct dirent *dirEntry;
    procDir = opendir("/proc");
    int processCount = 0;

    if(procDir != NULL) {
        while((dirEntry = readdir(procDir)) != NULL) {
            if(dirEntry->d_type != DT_DIR) {
                continue;
            }
            char* pidStr = dirEntry->d_name;
            int pid = atoi(pidStr);
            if(pid == 0) {
                continue;
            }

            char procStatusFilePath[50];
            sprintf(procStatusFilePath, "/proc/%s/status", pidStr);

            FILE* procStatusFile = fopen(procStatusFilePath, "r");
            if(procStatusFile == NULL) {
                continue;
            }

            char line[256];
            char name[50], state[20];
            uid_t uid;
            unsigned long int mem;

            while(fgets(line, sizeof(line), procStatusFile)) {
                if(sscanf(line, "Name: %s", name) == 1) {
                    continue;
                }
                if(sscanf(line, "State: %s", state) == 1) {
                    continue;
                }
                if(sscanf(line, "Uid: %d", &uid) == 1) {
                    continue;
                }
                if(sscanf(line, "VmSize: %lu kB", &mem) == 1) {
                    mem *= 1024;
                    break;
                }
            }

            fclose(procStatusFile);

            if(strlen(name) == 0) {
                continue;
            }

            processInfoArray[processCount].pid = pid;
            strcpy(processInfoArray[processCount].name, name);
            strcpy(processInfoArray[processCount].state, state);
            processInfoArray[processCount].uid = uid;
            processInfoArray[processCount].mem = mem;

            processCount++;
            if(processCount >= maxProcessCount) {
                break;
            }
        }

        closedir(procDir);
    }

    return processCount;
}

// Function to print the process info array
void printProcessInfo(struct ProcessInfo* processInfoArray, int processCount) {
    printf("| %5s | %-20s | %-10s | %8s | %10s |\n",
           "PID", "NAME", "STATE", "UID", "MEMORY");
    printf("|-------|----------------------|------------|----------|------------|\n");
    for(int i = 0; i < processCount; i++) {
        printf("| %5d | %-20s | %-10s | %8d | %10lu |\n",
               processInfoArray[i].pid, processInfoArray[i].name, processInfoArray[i].state,
               processInfoArray[i].uid, processInfoArray[i].mem);
    }
}

int main(void) {
    int maxProcessCount = 1000;
    struct ProcessInfo* processInfoArray = malloc(maxProcessCount * sizeof(struct ProcessInfo));
    if(processInfoArray == NULL) {
        printf("Error: Unable to allocate memory for process info array.\n");
        return 1;
    }

    int processCount = getProcessInfo(processInfoArray, maxProcessCount);
    printProcessInfo(processInfoArray, processCount);

    free(processInfoArray);
    return 0;
}