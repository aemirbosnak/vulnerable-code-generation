//FormAI DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAXLEN 128 

// Define a struct to hold the information of a process in the system
struct process {
    char name[MAXLEN];
    int pid;
    char status[MAXLEN];
    int memory;
};

// Define a function to get the status of a process given the pid
char* get_process_status(int pid) {
    char* status = malloc(sizeof(char)*MAXLEN);
    char path[MAXLEN];
    FILE* fp;

    // Generate the path to the status file of the process
    sprintf(path, "/proc/%d/status", pid);

    fp = fopen(path, "r");
    if (fp == NULL) {
        free(status);
        return "unknown";
    }

    // Search for the line containing the status information
    char line[MAXLEN];
    while (fgets(line, MAXLEN, fp)) {
        if (strncmp(line, "State:", 6) == 0) {
            strncpy(status, line+7, 2);
            break;
        }
    }

    fclose(fp);
    return status;
}

// Define a function to get the memory usage of a process given the pid
int get_process_memory(int pid) {
    char path[MAXLEN];
    FILE* fp;

    // Generate the path to the statm file of the process
    sprintf(path, "/proc/%d/statm", pid);

    fp = fopen(path, "r");
    if (fp == NULL) {
        return -1;
    }

    // Extract the memory usage from the first line of the file
    int memory;
    fscanf(fp, "%d", &memory);

    fclose(fp);
    return memory;
}

int main() {
    // Open the /proc directory
    DIR* dir = opendir("/proc");
    if (dir == NULL) {
        perror("Could not open /proc directory");
        return -1;
    }

    struct dirent* dp;
    struct process processes[MAXLEN];
    int count = 0;

    while ((dp = readdir(dir)) != NULL) {
        // Check if the d_name is a directory and represents a process
        if (dp->d_type == DT_DIR && atoi(dp->d_name) != 0) {
            // Get the name and pid of the process
            strcpy(processes[count].name, dp->d_name);

            processes[count].pid = atoi(dp->d_name);

            // Get the status of the process
            strcpy(processes[count].status, get_process_status(processes[count].pid));

            // Get the memory usage of the process
            processes[count].memory = get_process_memory(processes[count].pid);

            count++;
        }
    }

    closedir(dir);

    // Print the header of the table
    printf("+-");
    for (int i = 0; i < 64; i++) {
        printf("-");
    }
    printf("-+\n");
    printf("| %-16s | %-6s | %-8s | %-10s |\n", "Process Name", "PID", "Status", "Memory");
    printf("+-");
    for (int i = 0; i < 64; i++) {
        printf("-");
    }
    printf("-+\n");

    // Print the information of each process in the table
    for (int i = 0; i < count; i++) {
        printf("| %-16s | %-6d | %-8s | %-10d |\n", processes[i].name, processes[i].pid, processes[i].status, processes[i].memory);
    }

    // Print the footer of the table
    printf("+-");
    for (int i = 0; i < 64; i++) {
        printf("-");
    }
    printf("-+\n");

    return 0;
}