//FormAI DATASET v1.0 Category: System process viewer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

// Define a struct to store process information
typedef struct {
    char pid[10];
    char name[50];
    char status[20];
    char mem[20];
} Process;

// Function to parse the status file of a process
void parseStatusFile(char *pid, char *name, char *status) {
    char path[50];
    sprintf(path, "/proc/%s/status", pid);
    FILE *fp = fopen(path, "r");
    char line[100];
    while(fgets(line, 100, fp)) {
        if(strncmp(line, "Name:", 5) == 0) {
            // Parse process name
            sscanf(line, "%*s %s", name);
        } else if(strncmp(line, "State:", 6) == 0) {
            // Parse process state
            sscanf(line, "%*s %s", status);
        }
    }
    fclose(fp);
}

// Function to parse the statm file of a process
void parseStatmFile(char *pid, char *mem) {
    char path[50];
    sprintf(path, "/proc/%s/statm", pid);
    FILE *fp = fopen(path, "r");
    char line[100];
    fgets(line, 100, fp);
    // Parse process memory usage
    sscanf(line, "%s", mem);
    fclose(fp);
}

// Function to retrieve a list of processes
int getProcessList(Process *processList, int maxProcesses) {
    DIR *dir;
    struct dirent *ent;
    int i = 0;
    if((dir = opendir("/proc")) != NULL) {
        while((ent = readdir(dir)) != NULL) {
            if(isdigit(*ent->d_name)) {
                char pid[10];
                strcpy(pid, ent->d_name);
                char name[50];
                char status[20];
                char mem[20];
                parseStatusFile(pid, name, status);
                parseStatmFile(pid, mem);
                // Add process information to the list
                strcpy(processList[i].pid, pid);
                strcpy(processList[i].name, name);
                strcpy(processList[i].status, status);
                strcpy(processList[i].mem, mem);
                i++;
                if(i == maxProcesses) {
                    break;
                }
            }
        }
        closedir(dir);
    } else {
        return -1;
    }
    return i;
}

int main() {
    Process processList[100];
    int nProcesses = getProcessList(processList, 100);
    printf("PID\tNAME\t\t\tSTATUS\t\tMEMORY USAGE\n");
    for(int i = 0; i < nProcesses; i++) {
        printf("%s\t%-20s\t%-10s\t%s\n", processList[i].pid, processList[i].name, processList[i].status, processList[i].mem);
    }
    return 0;
}