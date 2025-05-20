//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH 256
#define MAX_PROC_INFO 1024

void display_process_info(const char *pid) {
    char path[MAX_PATH];
    snprintf(path, sizeof(path), "/proc/%s/stat", pid);
    
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return; // Process not accessible, it might have ended
    }

    char comm[256];
    char state;
    int ppid;
    
    fscanf(fp, "%*d %s %c %d", comm, &state, &ppid);
    fclose(fp);

    printf("PID: %s\t Command: %s\t State: %c\t PPID: %d\n", pid, comm, state, ppid);
}

void list_processes() {
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;

    if (proc_dir == NULL) {
        perror("Couldn't open /proc directory");
        exit(EXIT_FAILURE);
    }

    printf("********** PROCESS VIEWER **********\n");
    printf("PID\t\tCommand\t\t\tState\tPPID\n");
    printf("===========================================\n");

    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a valid process ID (a numeric directory name)
        if (atoi(entry->d_name) > 0) {
            display_process_info(entry->d_name);
        }
    }

    closedir(proc_dir);
}

int main() {
    while (1) {
        system("clear"); // Clear the terminal for a fresh view
        list_processes();
        sleep(2); // Update every 2 seconds
    }
    return 0;
}