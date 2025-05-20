//FormAI DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

struct ProcessInfo {
    char pid[20];
    char name[200];
    char status[20];
};

int isNumber(char* str) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        if(!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void getProcessName(char pid[20], char processName[200]) {
    char path[60] = "/proc/";
    strcat(path, pid);
    strcat(path, "/comm");
    FILE* fp = fopen(path, "r");
    if(fp != NULL) {
        fscanf(fp, "%s", processName);
        fclose(fp);
    }
}

void getProcessStatus(char pid[20], char processStatus[20]) {
    char path[60] = "/proc/";
    strcat(path, pid);
    strcat(path, "/status");
    FILE* fp = fopen(path, "r");
    if(fp != NULL) {
        char buffer[255];
        while(fgets(buffer, 255, fp)) {
            if(strncmp("State:", buffer, 6) == 0) {
                sscanf(buffer, "%*s %s", processStatus);
                break;
            }
        }
        fclose(fp);
    }
}

int main() {
    DIR* dirPointer = opendir("/proc");
    struct dirent* dirEntity;
    struct ProcessInfo processes[200];
    int count = 0;
    while((dirEntity = readdir(dirPointer))) {
        if(isNumber(dirEntity->d_name)) {
            strcpy(processes[count].pid, dirEntity->d_name);
            getProcessName(dirEntity->d_name, processes[count].name);
            getProcessStatus(dirEntity->d_name, processes[count].status);
            count++;
        }
    }
    closedir(dirPointer);

    printf("PID\tPROCESS NAME\t\t\tPROCESS STATUS\n");
    for(int i=0; i<count; i++) {
        printf("%s\t%-30s%s\n", processes[i].pid, processes[i].name, processes[i].status);
    }
    return 0;
}