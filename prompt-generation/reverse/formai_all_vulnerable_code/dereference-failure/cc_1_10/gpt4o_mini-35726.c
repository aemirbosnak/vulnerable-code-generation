//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PROCESSES 1024

typedef struct {
    int pid;
    char name[256];
    char state[16];
    unsigned long utime;
    unsigned long stime;
} ProcessInfo;

// Function to get process information from /proc/[pid]/stat
int get_process_info(int pid, ProcessInfo *pinfo) {
    char path[256];
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);

    FILE *file = fopen(path, "r");
    if (!file) {
        return -1; // Unable to open the stat file
    }

    fscanf(file,
           "%d %s %s %*d %*d %*d %*d %*d %*d %*d %*d "
           "%lu %lu",
           &pinfo->pid,
           pinfo->name,
           pinfo->state,
           &pinfo->utime,
           &pinfo->stime);

    fclose(file);
    pinfo->name[strlen(pinfo->name) - 1] = 0; // Remove trailing parentheses
    return 0;
}

// Function to list all processes
void list_processes() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    ProcessInfo processes[MAX_PROCESSES];
    int count = 0;

    if (!dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) { // Check if the name is a number (pid)
            int pid = atoi(entry->d_name);
            if (get_process_info(pid, &processes[count]) == 0) {
                count++;
                if (count >= MAX_PROCESSES) {
                    break; // Avoid overflow
                }
            }
        }
    }

    closedir(dir);

    printf("%-6s %-30s %-10s %-10s\n", "PID", "Name", "State", "Usage Time");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-30s %-10s %-10lu\n", processes[i].pid, processes[i].name,
               processes[i].state, processes[i].utime + processes[i].stime);
    }
}

// Main function
int main() {
    printf("Process Viewer\n");
    printf("=========================\n");
    list_processes();
    return 0;
}