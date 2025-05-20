//FormAI DATASET v1.0 Category: System process viewer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define MAX_PATH_LENGTH 1024
#define MAX_BUFFER_SIZE 1024

typedef struct {
    char* pid;
    char* pname;
    char* status;
    char* memory;
    char* cpu;
} Process;

Process* get_process_info(char* pid) {
    char proc_path[MAX_PATH_LENGTH];
    FILE* fp;

    // Construct path to the process status file
    sprintf(proc_path, "/proc/%s/status", pid); 

    // Open process status file for reading
    fp = fopen(proc_path, "r"); 
    if (fp == NULL) {
        fprintf(stderr, "Failed to open process status file: %s\n", strerror(errno));
        return NULL;
    }

    // Read process information from status file
    Process* proc = malloc(sizeof(Process));
    proc->pid = strdup(pid);
    char buffer[MAX_BUFFER_SIZE];
    while(fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL) {
        char* token = strtok(buffer, ":");
        if (strcmp(token, "Name") == 0) {
            token = strtok(NULL, " ");
            proc->pname = strdup(token);
        } else if (strcmp(token, "State") == 0) {
            token = strtok(NULL, " ");
            proc->status = strdup(token);
        } else if (strcmp(token, "VmRSS") == 0) {
            token = strtok(NULL, " ");
            proc->memory = strdup(token);
        }
    }

    // Close file pointer and return process information
    fclose(fp);
    return proc;
}

void print_processes() {
    DIR* proc_dir;

    // Open /proc directory for reading
    proc_dir = opendir("/proc"); 
    if (proc_dir == NULL) {
        fprintf(stderr, "Failed to open /proc directory: %s\n", strerror(errno));
        return;
    }

    // Iterate over contents of /proc directory
    struct dirent* de;
    while ((de = readdir(proc_dir)) != NULL) {
        // Check if directory entry is a process directory
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
            continue;
        }
        char* ptr;
        strtol(de->d_name, &ptr, 10);
        if (*ptr != '\0') {
            continue;
        }

        // Retrieve process information and print
        Process* proc = get_process_info(de->d_name);
        if (proc != NULL) {
            printf("%-10s %-20s %-10s %-10s\n", proc->pid, proc->pname, proc->status, proc->memory);
            free(proc->pid);
            free(proc->pname);
            free(proc->status);
            free(proc->memory);
            free(proc);
        }
    }

    // Close directory
    closedir(proc_dir);
}

int main() {
    // Print header
    printf("%-10s %-20s %-10s %-10s\n", "PID", "Name", "Status", "Memory");

    // Print process information
    print_processes();

    return 0;
}