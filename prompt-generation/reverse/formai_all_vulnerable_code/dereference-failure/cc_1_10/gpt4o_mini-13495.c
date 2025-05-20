//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define STATUS_FILE_FORMAT "/proc/%d/status"
#define STAT_FILE_FORMAT "/proc/%d/stat"

typedef struct {
    pid_t pid;
    char comm[50];
    char state;
    long int utime;  // user time
    long int stime;  // system time
    long int vsize;  // virtual memory size
    long int rss;    // resident set size
} ProcessInfo;

void read_process_info(pid_t pid, ProcessInfo* process_info) {
    char status_file[MAX_LINE_LENGTH];
    snprintf(status_file, sizeof(status_file), STATUS_FILE_FORMAT, pid);
    
    FILE* file = fopen(status_file, "r");
    if (file == NULL) {
        perror("fopen status");
        return;
    }

    // Read and parse status file
    while (fgets(status_file, sizeof(status_file), file)) {
        if (strstr(status_file, "State:") != NULL) {
            sscanf(status_file, "State:\t%c", &process_info->state);
        }
        if (strstr(status_file, "VmSize:") != NULL) {
            sscanf(status_file, "VmSize:\t%ld kB", &process_info->vsize);
        }
        if (strstr(status_file, "VmRSS:") != NULL) {
            sscanf(status_file, "VmRSS:\t%ld kB", &process_info->rss);
        }
    }
    fclose(file);

    // Read command name from the stat file
    char stat_file[MAX_LINE_LENGTH];
    snprintf(stat_file, sizeof(stat_file), STAT_FILE_FORMAT, pid);
    
    file = fopen(stat_file, "r");
    if (file == NULL) {
        perror("fopen stat");
        return;
    }

    // Read and parse stat file
    fscanf(file, "%d %s %c %*d %*d %*d %*d %*d %*d %*d %ld %ld",
           &process_info->pid, process_info->comm, &process_info->utime, &process_info->stime);
    fclose(file);
}

void list_processes() {
    DIR* dir = opendir("/proc");
    struct dirent* entry;
    
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    
    printf("%-10s %-25s %-10s %-10s %-10s %-10s\n", "PID", "COMMAND", "STATE", "UTIME", "STIME", "RSS(KB)");
    
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {  // Only process directories
            pid_t pid = atoi(entry->d_name);
            ProcessInfo process_info = {0};
            read_process_info(pid, &process_info);
            
            if (process_info.pid > 0) {
                printf("%-10d %-25s %-10c %-10ld %-10ld %-10ld\n",
                       process_info.pid,
                       process_info.comm,
                       process_info.state,
                       process_info.utime,
                       process_info.stime,
                       process_info.rss);
            }
        }
    }
    closedir(dir);
}

int main() {
    printf("Linux Process Viewer\n");
    printf("=====================\n");
    list_processes();
    return 0;
}