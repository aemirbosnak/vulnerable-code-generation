//FormAI DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define PROCESSNAME_MAXLENGTH 1024 

// This function prints the process information for a given pid
void printProcessInfo(int pid) {
    char buffer[PROCESSNAME_MAXLENGTH];
    sprintf(buffer, "/proc/%d/stat", pid);
    FILE *file = fopen(buffer, "r");
    if (file) {
        char processStatus[4096];
        fgets(processStatus, 4096, file);
        fclose(file);
        char *token = strtok(processStatus, " ");
        int count = 0;
        while (token != NULL) {
            switch (count) {
                case 0: printf("PID:\t\t%s\n", token); break;
                case 1: printf("COMMAND:\t%s\n", token); break;
                case 2: printf("STATE:\t\t%s\n", token); break;
                case 22: printf("START:\t\t%s\n", token); break;
                case 23: printf("MEMORY:\t\t%s\n", token); break;
                case 24: printf("RSS:\t\t%s\n", token); break;
            }
            token = strtok(NULL, " ");
            count++;
        }
        printf("\n");
    }
}

// This function finds all the running processes and prints their information
void viewProcesses() {
    DIR *directory;
    struct dirent *dir;
    directory = opendir("/proc");
    if (directory) {
        while ((dir = readdir(directory)) != NULL) {
            if (dir->d_type == DT_DIR && isdigit(*dir->d_name)) {
                int pid = atoi(dir->d_name);
                printProcessInfo(pid);
            }
        }
        closedir(directory);
    }
}

int main() {
    printf("Current running processes:\n\n");
    viewProcesses();
    return 0;
}