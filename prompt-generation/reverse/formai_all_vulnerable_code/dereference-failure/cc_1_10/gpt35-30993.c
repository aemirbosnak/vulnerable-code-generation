//FormAI DATASET v1.0 Category: System process viewer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH 1024

void print_process_stats(int pid) {
    char path[MAX_PATH];

    // Get the process status from proc file system
    sprintf(path, "/proc/%d/status", pid);

    FILE* status_file = fopen(path, "r");

    if (status_file == NULL) {
        printf("Error: cannot open file '%s'.\n", path);
        exit(1);
    }

    int ppid = -1;
    char name[50];
    char state[10];

    // Parse the status file
    while (!feof(status_file)) {
        char line[256];
        fgets(line, 256, status_file);

        if (strncmp(line, "PPid:", 5) == 0) {
            sscanf(line, "PPid:\t%d", &ppid);
        } else if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line, "Name:\t%s", name);
        } else if (strncmp(line, "State:", 6) == 0) {
            sscanf(line, "State:\t%s", state);
        }
    }

    fclose(status_file);

    if (ppid == -1) {
        printf("Error: cannot find PPid in file '%s'.\n", path);
        exit(1);
    }

    // Print process statistics
    printf("%5d %5d %-20s %s\n", pid, ppid, name, state);
}

void proc_tree(int pid, int level) {
    DIR* dir;
    struct dirent* entry;

    char path[MAX_PATH];
    sprintf(path, "/proc/%d/task", pid);

    dir = opendir(path);

    if (dir == NULL) {
        printf("Error: cannot open directory '%s'.\n", path);
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        int tid = atoi(entry->d_name);

        print_process_stats(tid);

        proc_tree(tid, level + 1);
    }

    closedir(dir);
}

int main() {
    printf("%5s %5s %-20s %s\n", "PID", "PPID", "NAME", "STATE");

    // Print system process tree
    proc_tree(1, 0);
    
    return 0;
}