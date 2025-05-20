//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define PROC_PATH "/proc"
#define BUFFER_SIZE 256

void print_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    FILE *fp;

    snprintf(path, sizeof(path), "%s/%s/stat", PROC_PATH, pid);
    fp = fopen(path, "r");
    if (fp == NULL) {
        return; // process might have exited
    }

    // Read process information from stat file
    if (fgets(line, sizeof(line), fp) != NULL) {
        char comm[BUFFER_SIZE];
        char state;
        int ppid;
        int pgrp;
        unsigned long memory;

        // Parse the relevant fields
        sscanf(line, "%s %s %c %d %d %*d %*d %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %lu",
               pid, comm, &state, &ppid, &pgrp, &memory);

        // Print process information
        printf("PID: %s, CMD: %s, State: %c, PPID: %d, PGRP: %d, Memory: %lu kB\n",
               pid, comm, state, ppid, pgrp, memory / 1024); // Convert from bytes to kB
    }

    fclose(fp);
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;

    // Open the /proc directory
    dir = opendir(PROC_PATH);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    // Read entries in /proc
    while ((entry = readdir(dir)) != NULL) {
        // Check if entry is a PID
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            print_process_info(entry->d_name);
        }
    }

    closedir(dir);
}

int main() {
    printf("Process Viewer\n");
    printf("---------------\n");

    // List all running processes
    list_processes();

    return 0;
}