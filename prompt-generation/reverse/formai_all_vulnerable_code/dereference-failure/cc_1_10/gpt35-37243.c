//FormAI DATASET v1.0 Category: System process viewer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Define the structure to store the process information
typedef struct {
    char pid[10];
    char name[100];
    char state[10];
    char mem[20];
} process_info;

// Return the process information of a given PID
process_info* get_process_info(const char* pid) {
    // Create the file path for the process status
    char filepath[100];
    sprintf(filepath, "/proc/%s/status", pid);
    
    // Open the file
    FILE* fp = fopen(filepath, "r");
    if (fp == NULL) {
        return NULL;
    }
    
    // Read the file line by line
    char line[200];
    process_info* info = (process_info*)malloc(sizeof(process_info));
    while (fgets(line, 200, fp)) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line, "Name:\t%s", info->name);
        }
        else if (strncmp(line, "State:", 6) == 0) {
            sscanf(line, "State:\t%s", info->state);
        }
        else if (strncmp(line, "VmRSS:", 6) == 0) {
            sscanf(line, "VmRSS:\t%s", info->mem);
        }
    }
    fclose(fp);
    
    // Store the PID
    strcpy(info->pid, pid);
    
    return info;
}

// Return the number of running processes
int get_num_running_processes() {
    DIR* dir = opendir("/proc");
    if (dir == NULL) {
        return -1;
    }
    
    int count = 0;
    struct dirent* dp;
    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }
        
        // Check if the directory name is a number (i.e. a PID)
        int is_pid = 1;
        for (int i = 0; i < strlen(dp->d_name); i++) {
            if (dp->d_name[i] < '0' || dp->d_name[i] > '9') {
                is_pid = 0;
                break;
            }
        }
        if (is_pid) {
            // Check the state of the process
            process_info* info = get_process_info(dp->d_name);
            if (info == NULL) {
                continue;
            }
            if (strcmp(info->state, "R") == 0) {
                count++;
            }
            free(info);
        }
    }
    closedir(dir);
    
    return count;
}

int main() {
    int num_running_processes = get_num_running_processes();
    printf("Number of running processes: %d\n", num_running_processes);
    return 0;
}