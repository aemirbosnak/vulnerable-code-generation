//FormAI DATASET v1.0 Category: System process viewer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    char dirname[] = "/proc";
    char *name;
    char state;
    int pid, ppid, pgrp, session, tty_nr, tpgid;
    unsigned int flags;
    long unsigned int minflt, cminflt, majflt, cmajflt, utime, stime;
    long int cutime, cstime, priority, nice, num_threads, itrealvalue;
    unsigned long long starttime;

    printf("Welcome to the Process Viewer!\n\n");

    dir = opendir(dirname);
    if (dir == NULL) {
        printf("Failed to access %s directory\n", dirname);
        exit(1);
    }

    // Print table headers
    printf("%-8s %-15s %-6s %-6s %-6s %-10s %-6s\n", 
        "PID", "NAME", "STATE", "PPID", "PGRP", "SESSION", "NUM_THREADS");

    // Read through the directory and print info for all processes
    while ((entry = readdir(dir)) != NULL) {
        // Ensure entry is a directory and has a numeric name
        if (entry->d_type == DT_DIR && atoi(entry->d_name) != 0) {
            pid = atoi(entry->d_name);
            // Open the corresponding status file for process info
            char filepath[256];
            snprintf(filepath, sizeof(filepath), "%s/%s/status", dirname, entry->d_name);
            FILE *fp = fopen(filepath, "r");
            if (fp != NULL) {
                name = malloc(256);
                fscanf(fp, "Name: %[^\n]", name);
                fscanf(fp, "\nState: %c", &state);
                fscanf(fp, "\nTgid: %d", &pgrp);
                fscanf(fp, "\nPid: %d", &pid);
                fscanf(fp, "\nPPid: %d", &ppid);
                fscanf(fp, "\nSession: %d", &session);
                fscanf(fp, "\nNumThreads: %ld", &num_threads);
                printf("%-8d %-15s %-6c %-6d %-6d %-10d %-6ld\n", 
                    pid, name, state, ppid, pgrp, session, num_threads);
                free(name);
                fclose(fp);
            }
        }
    }
    closedir(dir);

    return 0;
}