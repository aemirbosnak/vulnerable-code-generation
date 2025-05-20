//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PATH 256
#define MAX_LINE 1024

void print_process_info(const char *pid) {
    char path[MAX_PATH];
    char line[MAX_LINE];
    FILE *status_file;

    snprintf(path, sizeof(path), "/proc/%s/stat", pid);
    
    status_file = fopen(path, "r");
    if (!status_file) {
        perror("Could not open status file");
        return;
    }

    // Read the process info from the stat file
    int ppid, pgrp, session;
    char state, comm[MAX_LINE];
    fscanf(status_file, "%*d %s %c %d %d %d", comm, &state, &ppid, &pgrp, &session);
    fclose(status_file);

    // Print the process info
    printf("PID: %s, CMD: %s, State: %c, PPID: %d, PGRP: %d, Session: %d\n", pid, comm, state, ppid, pgrp, session);
}

void list_processes() {
    struct dirent *entry;
    DIR *proc_dir = opendir("/proc");

    if (!proc_dir) {
        perror("Failed to open /proc directory");
        return;
    }

    printf("Current running processes:\n");
    printf("---------------------------------------------------------------\n");
    printf("%-10s %-30s %-10s %-10s %-10s %-10s\n", "PID", "COMMAND", "STATE", "PPID", "PGRP", "SESSION");
    printf("---------------------------------------------------------------\n");

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(*entry->d_name)) { // Skip non-PID entries
            print_process_info(entry->d_name);
        }
    }

    closedir(proc_dir);
    printf("---------------------------------------------------------------\n");
}

int main() {
    printf("✨ Welcome to the Energetic Process Viewer! ✨\n");
    printf("✨ Let's explore the processes running on your machine! ✨\n\n");

    list_processes();

    printf("\n🎉 Thanks for using the Energetic Process Viewer! 🎉\n");
    return 0;
}