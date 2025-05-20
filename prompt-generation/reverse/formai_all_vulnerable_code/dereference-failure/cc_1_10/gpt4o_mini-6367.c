//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PATH 256
#define BUFFER_SIZE 1024

void getProcessInfo(const char *pid) {
    char path[MAX_PATH];
    char buffer[BUFFER_SIZE];
    FILE *statFile;
    snprintf(path, sizeof(path), "/proc/%s/stat", pid);
    statFile = fopen(path, "r");
    
    if (!statFile) {
        return; // Failed to open, probably not a valid PID
    }

    int pidNum, ppid, pgrp, session, tty_nr, tpgid;
    char comm[256], state;
    unsigned long utime, stime;
    unsigned long vsize;
    long rss;
    
    // Read the process information
    fscanf(statFile, "%d %s %c %d %d %d %d %lu %lu %lu %ld",
           &pidNum, comm, &state, &ppid, &pgrp, &session, &tty_nr, 
           &utime, &stime, &vsize, &rss);
    
    fclose(statFile);

    // Print Process Information
    printf("PID: %d | Command: %s | State: %c | PPID: %d | UTime: %lu | STime: %lu | VSize: %lu | RSS: %ld\n",
           pidNum, comm, state, ppid, utime, stime, vsize, rss);
}

void listProcesses() {
    struct dirent *entry;
    DIR *dp = opendir("/proc");
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }
    
    while ((entry = readdir(dp)) != NULL) {
        // We only care about numerical directory names (process IDs)
        if (isdigit(entry->d_name[0])) {
            getProcessInfo(entry->d_name);
        }
    }
    
    closedir(dp);
}

int main(int argc, char *argv[]) {
    printf("Simple Process Viewer\n");
    printf("=====================\n");

    // List processes
    listProcesses();

    return 0;
}