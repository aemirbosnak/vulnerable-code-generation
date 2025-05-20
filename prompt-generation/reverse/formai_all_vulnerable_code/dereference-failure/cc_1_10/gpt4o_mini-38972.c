//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PROCESSES 100
#define BUFFER_SIZE 256
#define STAT_PATH "/proc/%s/stat"

typedef struct {
    int pid;
    char comm[BUFFER_SIZE];
    char state;
    int ppid;
    unsigned long utime, stime;
} ProcessInfo;

void get_process_info(const char *pid_str, ProcessInfo *proc_info) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), STAT_PATH, pid_str);
    
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return;
    }

    fscanf(fp, "%d %s %c %d", &proc_info->pid, proc_info->comm, &proc_info->state, &proc_info->ppid);
    fseek(fp, 13 * sizeof(int), SEEK_CUR); // Skip the next 13 fields
    fscanf(fp, "%lu %lu", &proc_info->utime, &proc_info->stime);
    
    fclose(fp);
}

void print_process_info(ProcessInfo *proc_info) {
    printf("PID: %d\n", proc_info->pid);
    printf("Command: %s\n", proc_info->comm);
    printf("State: %c\n", proc_info->state);
    printf("PPID: %d\n", proc_info->ppid);
    printf("User Time: %lu\n", proc_info->utime);
    printf("System Time: %lu\n", proc_info->stime);
    printf("-------------------------------\n");
}

int is_number(const char *str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void list_processes() {
    DIR *proc_dir = opendir("/proc");
    
    if (proc_dir == NULL) {
        perror("Failed to open /proc directory");
        return;
    }

    struct dirent *entry;
    ProcessInfo proc_info;

    printf("Listing all processes:\n");
    printf("====================\n");
    
    while ((entry = readdir(proc_dir)) != NULL) {
        // Only process directories that contain numeric PIDs
        if (is_number(entry->d_name)) {
            get_process_info(entry->d_name, &proc_info);
            print_process_info(&proc_info);
        }
    }

    closedir(proc_dir);
}

int main() {
    printf("Welcome to the Irregular Process Viewer v1.0\n");
    printf("===========================================\n");
    
    list_processes();

    printf("Process listing complete. Goodbye!\n");
    return 0;
}