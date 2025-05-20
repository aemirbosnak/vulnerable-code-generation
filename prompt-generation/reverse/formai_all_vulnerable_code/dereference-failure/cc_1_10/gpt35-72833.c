//FormAI DATASET v1.0 Category: System process viewer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Function to get the process name given the PID
void get_process_name(char* pid, char* process_name) {
    FILE* fp = NULL;
    char file_path[100];
    char buffer[100];

    sprintf(file_path, "/proc/%s/status", pid);
    fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", file_path);
        return;
    }

    while (fgets(buffer, 100, fp) != NULL) {
        if (strncmp(buffer, "Name:", 5) == 0) {
            strcpy(process_name, &buffer[6]);
            break;
        }
    }

    fclose(fp);
}

// Function to get the status of the given process
void get_process_status(char* pid, char* status) {
    FILE* fp = NULL;
    char file_path[100];
    char buffer[100];

    sprintf(file_path, "/proc/%s/status", pid);
    fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", file_path);
        return;
    }

    while (fgets(buffer, 100, fp) != NULL) {
        if (strncmp(buffer, "State:", 6) == 0) {
            strcpy(status, &buffer[7]);
            break;
        }
    }

    fclose(fp);
}

// Function to get the parent PID of the given process
void get_process_parent_pid(char* pid, char* ppid) {
    FILE* fp = NULL;
    char file_path[100];
    char buffer[100];

    sprintf(file_path, "/proc/%s/status", pid);
    fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", file_path);
        return;
    }

    while (fgets(buffer, 100, fp) != NULL) {
        if (strncmp(buffer, "PPid:", 5) == 0) {
            strcpy(ppid, &buffer[6]);
            break;
        }
    }

    fclose(fp);
}

int main() {
    DIR* proc_dir = NULL;
    struct dirent* entry = NULL;
    char pid[10];
    char process_name[100];
    char status[10];
    char ppid[10];
    int count = 0;

    // Open the /proc directory
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Error: Could not open /proc.\n");
        return 0;
    }

    // Loop through each directory in the /proc directory
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the directory is a process directory (i.e. a directory with an all-numeric name)
        if (isdigit(entry->d_name[0])) {
            count++;
            strcpy(pid, entry->d_name);
            // Get the process name, status, and parent PID
            get_process_name(pid, process_name);
            get_process_status(pid, status);
            get_process_parent_pid(pid, ppid);
            // Print the process information
            printf("%-10s%-25s%-15s%-10s\n", pid, process_name, status, ppid);
        }
    }

    closedir(proc_dir);

    printf("Total number of processes: %d\n", count);

    return 0;
}