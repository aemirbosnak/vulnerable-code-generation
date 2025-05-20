//FormAI DATASET v1.0 Category: System process viewer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

void printHeader() {
    printf("\033[1;34m");
    printf("%-10s %-20s %-20s\n", "PID", "NAME", "STATUS");
    printf("\033[0m");
}

void printRow(char* pid, char* name, char* status) {
    printf("%-10s %-20s %-20s\n", pid, name, status);
}

int main() {
    printHeader();

    DIR *dir;
    struct dirent *entry;
    char* pid;
    char* name;
    char* status;
    FILE *fp;
    char path[1035];

    dir = opendir("/proc/");
    if (dir == NULL) {
        printf("Error: could not open proc directory");    
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Check if it's a directory whose name is a number (represents a process ID)
        if (entry->d_type == DT_DIR && strtol(entry->d_name, NULL, 10) != 0) {

            pid = entry->d_name;

            // Read the status file to get the process name and status
            char statusFileName[128];
            sprintf(statusFileName, "/proc/%s/status", pid);

            fp = fopen(statusFileName, "r");
            if (fp == NULL) {
                printf("Error: could not open status file for process %s", pid);
            }

            char* line = NULL;
            size_t len = 0;
            ssize_t read;

            // Read the status file line by line
            while ((read = getline(&line, &len, fp)) != -1) {
                if (strstr(line, "Name:") != NULL) {
                    // Extract the process name
                    name = strtok(line, " \t\n");
                    name = strtok(NULL, " \t\n");
                } else if (strstr(line, "State:") != NULL) {
                    // Extract the process status
                    status = strtok(line, " \t\n");
                    status = strtok(NULL, " \t\n");
                }
            }

            if (line) {
                free(line);
            }

            fclose(fp);

            printRow(pid, name, status);            
        }
    }

    closedir(dir);

    return 0;
}