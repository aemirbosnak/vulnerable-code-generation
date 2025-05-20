//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define PROC_DIRECTORY "/proc"

typedef struct {
    int pid;
    char command[MAX_LINE_LENGTH];
    int ppid;
    float cpu_usage;
    long memory_usage;
} process_info;

void trim_newline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}

int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void read_process_info(int pid, process_info *info) {
    char path[MAX_LINE_LENGTH];
    snprintf(path, sizeof(path), "%s/%d/status", PROC_DIRECTORY, pid);
    
    FILE *file = fopen(path, "r");
    if (!file) return;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line + 5, "%s", info->command);
        }
        else if (strncmp(line, "PPid:", 5) == 0) {
            sscanf(line + 5, "%d", &info->ppid);
        }
    }
    fclose(file);
    
    // Simulate CPU usage and memory used (as placeholders)
    info->cpu_usage = (float)(rand() % 100) / 100.0; // Random percentage
    info->memory_usage = (long) rand() % 10000; // Random memory in KB
}

void list_processes() {
    DIR *dir = opendir(PROC_DIRECTORY);
    struct dirent *entry;

    if (!dir) {
        perror("Could not open /proc");
        return;
    }

    printf("%-10s %-25s %-10s %-10s %s\n", "PID", "COMMAND", "PPID", "CPU (%)", "MEMORY (KB)");
    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            int pid = atoi(entry->d_name);
            process_info info = {0};

            info.pid = pid;
            read_process_info(pid, &info);
            if (info.pid != 0) {
                printf("%-10d %-25s %-10d %-10.2f %ld\n", info.pid, info.command, info.ppid, info.cpu_usage * 100, info.memory_usage);
            }
        }
    }
    closedir(dir);
}

int main() {
    // Initialize the random number generator for fake CPU and memory usage.
    srand((unsigned int)time(NULL));
    
    printf("Welcome to Brave Process Viewer!\n");
    printf("Gathering process information...\n");
    
    list_processes();
    
    printf("End of processes.\n");
    return 0;
}