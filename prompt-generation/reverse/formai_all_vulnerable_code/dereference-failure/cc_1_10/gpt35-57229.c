//FormAI DATASET v1.0 Category: System process viewer ; Style: brave
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to extract data from stat file
int getStatData(char pid[], char parameter[], int paramNumber){
    char path[1024], stat[1024], buffer[1024];
    sprintf(path, "/proc/%s/stat", pid);
    FILE* statFile = fopen(path, "r");

    if(statFile != NULL){
        fgets(stat, 1024, statFile);
        fclose(statFile);

        char *token = strtok(stat, " ");
        for(int i = 0; i < paramNumber - 1; i++){
            token = strtok(NULL, " ");
        }

        int data = atoi(token);
        if(strcmp(parameter, "cmdline") == 0){
            sprintf(path, "/proc/%s/cmdline", pid);
            FILE* cmdlineFile = fopen(path, "r");
            if(cmdlineFile != NULL){
                fgets(buffer, 1024, cmdlineFile);
                fclose(cmdlineFile);
                sprintf(parameter, "%s", buffer);
            }
        }
        return data;
    }
    else{
        return -1;
    }
}

// Function to get process name and status from status file
void getInfoData(char pid[], char info[]){
    char path[1024], buffer[1024];
    sprintf(path, "/proc/%s/status", pid);
    FILE* infoFile = fopen(path, "r");

    if(infoFile != NULL){
        while(fgets(buffer, 1024, infoFile)){
            if(strncmp(buffer, "Name:", 5) == 0){
                char name[1024];
                sscanf(buffer, "%*s %s", name);
                sprintf(info, "Name: %-20s", name);
            }

            if(strncmp(buffer, "State:", 6) == 0){
                char state[1024];
                sscanf(buffer, "%*s %s", state);
                sprintf(info, "%sState: %-10s", info, state);
            }
        }
        fclose(infoFile);
    }
}

int main(){
    DIR *dir = opendir("/proc");
    struct dirent *dp;
    char pid[1024], info[1024];
    int statData, paramNumber = 14;

    printf("    PID      Command                      State\n");

    while((dp = readdir(dir)) != NULL){
        // Check if it is a directory and contains only digits (PID)
        if(dp->d_type == DT_DIR && strspn(dp->d_name, "0123456789") == strlen(dp->d_name)){

            strcpy(pid, dp->d_name);
            statData = getStatData(pid, "", paramNumber);
            if(statData != -1){
                sprintf(info, "%-7s  ", pid);
                getInfoData(pid, info);
                printf("%s\n", info);
            }
        }
    }

    closedir(dir);
    return 0;
}