//FormAI DATASET v1.0 Category: System process viewer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to check if a given string represents a number
int is_number(char* str) {
    int i = 0;
    while(str[i]) {
        if (!isdigit(str[i++]))
            return 0;
    }
    return 1;
}

// Function to get process information from procfs
void get_process_info(char* pid) {
    char path[50];
    sprintf(path, "/proc/%s/stat", pid);

    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file for process %s\n", pid);
        return;
    }

    // Read the stat file and extract the process name and status
    char name[50], status;
    fscanf(fp, "%s %*s %c", name, &status);
    fclose(fp);

    printf("%-10s%-20s%s\n", pid, name, status == 'R' ? "Running" : "Stopped");
}

int main() {
    // Open the directory /proc and traverse through all directories inside it
    DIR* proc_dir = opendir("/proc");
    struct dirent* dir_info;

    printf("%-10s%-20s%s\n", "PID", "NAME", "STATUS");

    while((dir_info = readdir(proc_dir)) != NULL) {
        // Check if the name of the directory represents a process ID
        if (is_number(dir_info->d_name)) {
            get_process_info(dir_info->d_name);
        }
    }

    closedir(proc_dir);
    return 0;
}