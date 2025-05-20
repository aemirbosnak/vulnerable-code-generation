//FormAI DATASET v1.0 Category: System process viewer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>

// Define a struct to store information about the process
typedef struct {
    char pid[10];
    char ppid[10];
    char user[20];
    char name[100];
    char state[5];
} Process;

// Helper function to get the command line associated with a process
char* get_cmdline(char* pid) {
    char path[50] = "/proc/";
    strcat(path, pid);
    strcat(path, "/cmdline");
    FILE* file = fopen(path, "r");
    if (!file) {
        return "";
    }
    char* cmdline = (char*) malloc(100);
    fgets(cmdline, 100, file);
    fclose(file);
    return cmdline;
}

// Helper function to check if a string is a number
int is_number(char* str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Main function to list all running processes
int main() {
    printf("*****************************\n");
    printf("*** RETRO SYSTEM VIEWER 1.0 ***\n");
    printf("*****************************\n");
    printf("\n");
    printf("PID    PPID   USER           STATE  COMMAND\n");
    printf("-------------------------------------------------------\n");
    char dirpath[]="/proc";
    DIR *d = opendir(dirpath);
    if (!d) {
        printf("Cannot open %s\n", dirpath);
        return 1;
    }
    struct dirent* dir;
    while ((dir = readdir(d))) {
        if (is_number(dir->d_name)) {
            char path[50] = "/proc/";
            strcat(path, dir->d_name);
            strcat(path, "/status");
            FILE* file = fopen(path, "r");
            if (!file) {
                continue;
            }
            Process process;
            strcpy(process.pid, dir->d_name);
            char line[100];
            while (fgets(line, 100, file)) {
                char* token = strtok(line, ":");
                if (strcmp(token, "PPid") == 0) {
                    token = strtok(NULL, " ");
                    strcpy(process.ppid, token);
                }
                else if (strcmp(token, "Uid") == 0) {
                    token = strtok(NULL, " ");
                    token = strtok(NULL, " ");
                    token = strtok(NULL, " ");
                    token = strtok(NULL, " ");
                    strcpy(process.user, token);
                }
                else if (strcmp(token, "State") == 0) {
                    token = strtok(NULL, " ");
                    strcpy(process.state, token);
                }
                else if (strcmp(token, "Name") == 0) {
                    token = strtok(NULL, "\n");
                    strcpy(process.name, token);
                }
            }
            fclose(file);
            char* cmdline = get_cmdline(process.pid);
            printf("%-6s%-6s%-15s%-7s%s\n", process.pid, process.ppid, process.user, process.state, cmdline);
            free(cmdline);
        }
    }
    closedir(d);
    return 0;
}