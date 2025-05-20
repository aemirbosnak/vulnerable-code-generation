//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define PROC_DIR "/proc"
#define STAT_FILE_SIZE 1024

typedef struct {
    char pid[6];
    char comm[256];
    char state[32];
    long utime;
    long stime;
    long cutime;
    long cstime;
    long starttime;
} ProcessInfo;

void read_process_info(const char* pid, ProcessInfo* proc_info) {
    char stat_file[STAT_FILE_SIZE];
    snprintf(stat_file, sizeof(stat_file), "%s/%s/stat", PROC_DIR, pid);
    
    FILE *file = fopen(stat_file, "r");
    if (file == NULL) {
        perror("Failed to open stat file");
        return;
    }
    
    fscanf(file, "%5s %255s %31s %*d %*d %*d %*d %*d %*d "
               "%ld %ld %ld %ld %ld", 
           proc_info->pid, 
           proc_info->comm, 
           proc_info->state, 
           &proc_info->utime, 
           &proc_info->stime, 
           &proc_info->cutime, 
           &proc_info->cstime, 
           &proc_info->starttime);
    
    fclose(file);
}

void traverse_proc_directory() {
    DIR *dir = opendir(PROC_DIR);
    struct dirent *entry;
    
    if (dir == NULL) {
        perror("Failed to open /proc directory");
        return;
    }
    
    printf("%-6s %-20s %-8s %-12s %-12s %-12s %-12s\n", 
           "PID", "COMMAND", "STATE", "UTIME", "STIME", "CUTIME", "CSTIME");
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (isdigit(entry->d_name[0])) {
                ProcessInfo proc_info;
                read_process_info(entry->d_name, &proc_info);
                
                printf("%-6s %-20s %-8s %-12ld %-12ld %-12ld %-12ld\n", 
                       proc_info.pid, 
                       proc_info.comm, 
                       proc_info.state, 
                       proc_info.utime, 
                       proc_info.stime, 
                       proc_info.cutime, 
                       proc_info.cstime);
            }
        }
    }
    
    closedir(dir);
}

int main() {
    printf("System Process Viewer\n");
    printf("=======================\n");

    traverse_proc_directory();
    
    return 0;
}