//FormAI DATASET v1.0 Category: System process viewer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void printProcess(char *pid){
    char path[50], proc[50], status[50], line[100];
    FILE *fp;

    sprintf(path, "/proc/%s", pid);
    sprintf(proc, "%s/%s", path, "cmdline");
    sprintf(status, "%s/%s", path, "status");

    fp = fopen(status, "r");
    if(fp == NULL){
        return;
    }
    printf("PID: %s\n", pid);
    while(fgets(line, 100, fp)){
        if(strncmp(line, "Name:", 5) == 0){
            printf("Process Name: %s", &line[6]);
        } else if(strncmp(line, "State:", 6) == 0){
            printf("Status: %s", &line[7]);
        } else if(strncmp(line, "VmSize:", 7) == 0){
            printf("Memory Usage: %s", &line[8]);
        }
    }
    fclose(fp);

    fp = fopen(proc, "r");
    if(fp == NULL){
        return;
    }
    fgets(line, 100, fp);
    printf("Command: %s\n\n", line);
    fclose(fp);
}

int main(){
    DIR *dp;
    struct dirent *entry;

    dp = opendir("/proc");
    if(dp == NULL){
        perror("Error: Failed to open directory");
        exit(1);
    }

    printf("--------Processes--------\n");

    while((entry = readdir(dp))){
        if(entry->d_type != DT_DIR){//Check if directory
            continue;
        }
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){//check for current and parent directory
            continue;
        }
        if(isdigit(entry->d_name[0])){//Check if all characters in directory name are digits
            printProcess(entry->d_name);
        }
    }
    closedir(dp);
    return 0;
}