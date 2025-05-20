//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define PROC_DIR "/proc"

// Structure to store process information
typedef struct {
    int pid;
    char state[16];
    char cmdline[MAX_LINE_LENGTH];
    int uid;
} ProcessInfo;

// Function to get the command line of a process
void get_cmdline(int pid, char *cmdline) {
    char path[MAX_LINE_LENGTH];
    snprintf(path, sizeof(path), "%s/%d/cmdline", PROC_DIR, pid);
    FILE *file = fopen(path, "r");
    if (file) {
        fread(cmdline, sizeof(char), MAX_LINE_LENGTH, file);
        fclose(file);
    }
}

// Function to get the state and UID of a process
void get_process_info(int pid, ProcessInfo *process) {
    char path[MAX_LINE_LENGTH];
    snprintf(path, sizeof(path), "%s/%d/stat", PROC_DIR, pid);
    FILE *file = fopen(path, "r");
    if (file) {
        // The information we need is in specific fields: 
        // pid, state and uid
        int uid;
        fscanf(file, "%d %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %d", 
               process->state, &uid);
        fclose(file);
        process->uid = uid;
    }
}

// Function to check if a string is a number
int is_number(const char *str) {
    for (const char *s = str; *s; s++) {
        if (!isdigit(*s)) return 0;
    }
    return 1;
}

// Function to list all processes
void list_processes() {
    DIR *dir = opendir(PROC_DIR);
    struct dirent *entry;

    printf("%-6s %-10s %-30s %-10s\n", "PID", "UID", "Command", "State");
    printf("--------------------------------------------------------------\n");

    // Read through /proc directory
    while ((entry = readdir(dir))) {
        if (is_number(entry->d_name)) {
            int pid = atoi(entry->d_name);
            ProcessInfo process;
            get_process_info(pid, &process);
            get_cmdline(pid, process.cmdline);
            printf("%-6d %-10d %-30s %-10s\n", process.pid, process.uid, process.cmdline, process.state);
        }
    }
    closedir(dir);
}

int main() {
    printf("Process Viewer\n");
    printf("====================\n");
    list_processes();
    return 0;
}