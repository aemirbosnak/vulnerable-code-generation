//FormAI DATASET v1.0 Category: System process viewer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_PID_LENGTH 64
#define MAX_PROC_PATH_LENGTH 256
#define MAX_COMMAND_LENGTH 4096

/* Define a struct to store process information */
typedef struct {
    char pid[MAX_PID_LENGTH];
    char comm[MAX_COMMAND_LENGTH];
    char state[16];
    char utime[32];
    char stime[32];
} process_info;

/* Function for getting process information from proc directory */
void get_process_info(char *pid, process_info *info) {
    char proc_path[MAX_PROC_PATH_LENGTH];
    sprintf(proc_path, "/proc/%s/stat", pid);
    FILE *f = fopen(proc_path, "r");

    if (!f) {
        printf("Error: Failed to open stat file for process %s\n", pid);
        exit(1);
    }

    fscanf(f, "%s %s %s %s %*s %*s %*s %*s %*s %*s %s %s", info->pid, info->comm, 
           info->state, info->utime, info->stime);

    fclose(f);
}

/* Function for printing process information */
void print_process_info(process_info *info) {
    printf("%-10s %-20s %-10s %-10s %-10s\n", info->pid, info->comm, 
           info->state, info->utime, info->stime);
}

/* Main function */
int main() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    printf("%-10s %-20s %-10s %-10s %-10s\n", "PID", "COMMAND", "STATE", "UTIME", "STIME");
    printf("--------------------------------------------------------------\n");

    /* Iterate over all directories in /proc */
    while ((entry = readdir(dir))) {
        /* If the directory is not a process directory, continue */
        if (!isdigit(entry->d_name[0])) {
            continue;
        }

        /* Get process information and print it */
        char pid[MAX_PID_LENGTH];
        strcpy(pid, entry->d_name);
        process_info info;
        get_process_info(pid, &info);
        print_process_info(&info);
    }

    closedir(dir);

    return 0;
}