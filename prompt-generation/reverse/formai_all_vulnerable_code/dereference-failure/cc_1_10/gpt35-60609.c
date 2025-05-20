//FormAI DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_BUFFER 1024
#define MAX_FILES 100

int processExists(char *pidPath) {
    FILE *fp;
    int pid;
    fp = fopen(pidPath, "r");
    if(fp == NULL) {
        return -1;
    }
    fscanf(fp, "%d", &pid);
    fclose(fp);
    if(kill(pid, 0) == 0) {
        return pid;
    } else {
        return -1;
    }
}

void printProcessInfo(char *pidPath) {
    FILE *fp;
    char buffer[MAX_BUFFER], *token;
    fp = fopen(pidPath, "r");
    if(fp == NULL) {
        return;
    }
    while(fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    fclose(fp);
}

void printProcess(char *pid) {
    char pidPath[MAX_BUFFER];
    snprintf(pidPath, sizeof(pidPath), "/proc/%s/status", pid);
    if(processExists(pidPath) != -1) {
        printf("\nPID: %s\n", pid);
        printProcessInfo(pidPath);
    }
}

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;
    char taskPath[MAX_BUFFER], pid[MAX_BUFFER], filePath[MAX_BUFFER];
    int i, processCount = 0, pidLength;
    if(argc != 1) {
        printf("USAGE: ./process_monitor\n");
        exit(1);
    }
    printf("\nPROCESS MONITOR\n");
    sprintf(taskPath, "/proc/");
    dp = opendir(taskPath);
    if(dp == NULL) {
        printf("ERROR: Unable to open /proc directory\n");
        exit(1);
    }
    while((dirp = readdir(dp))) {
        if(dirp->d_type == DT_DIR) {
            pidLength = strlen(dirp->d_name);
            for(i=0; i<pidLength; i++) {
                if(!isdigit(dirp->d_name[i])) {
                    break;
                }
            }
            if(i == pidLength) {
                strncpy(pid, dirp->d_name, sizeof(pid));
                printProcess(pid);
                processCount++;
                if(processCount >= MAX_FILES) {
                    printf("\nMax number of processes reached: %d\n", MAX_FILES);
                    break;
                }
            }
        }
    }
    closedir(dp);
    return 0;
}