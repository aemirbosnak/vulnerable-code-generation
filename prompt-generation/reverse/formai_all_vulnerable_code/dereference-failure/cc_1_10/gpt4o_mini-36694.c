//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define PROC_PATH "/proc"
#define MAX_CMD_LENGTH 256

void print_process_info(pid_t pid) {
    char path[512];
    snprintf(path, sizeof(path), "%s/%d/stat", PROC_PATH, pid);
    
    FILE *stat_file = fopen(path, "r");
    if (!stat_file) {
        perror("fopen");
        return;
    }

    char comm[MAX_CMD_LENGTH];
    char state;
    unsigned long utime, stime;

    fscanf(stat_file, "%*d %s %*c %*d %*d %*d %*d %*d %*d %*d %*d %*u %*u %*u %*u %lu %lu",
           comm, &utime, &stime);
    
    printf("PID: %d | Command: %s | State: %c | User Time: %lu | Sys Time: %lu\n",
           pid, comm, state, utime, stime);
    fclose(stat_file);
}

void list_processes() {
    DIR *proc_dir = opendir(PROC_PATH);
    if (!proc_dir) {
        perror("opendir");
        return;
    }
    
    struct dirent *entry;
    
    // Iterate through directory entries
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if entry is a number (i.e., process ID)
        if (isdigit(entry->d_name[0])) {
            pid_t pid = atoi(entry->d_name);
            print_process_info(pid);
        }
    }

    closedir(proc_dir);
}

void display_usage() {
    printf("Usage: procviewer [options]\n");
    printf("Options:\n");
    printf("  -h, --help      Show this help message and exit\n");
    printf("  -l, --list      List all running processes\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            display_usage();
            return 0;
        }
        if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0) {
            list_processes();
            return 0;
        }
    } else {
        printf("No command provided. Use -h for help.\n");
    }
    
    return 0;
}