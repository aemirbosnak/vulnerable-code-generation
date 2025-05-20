//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_LINE 256
#define MAX_PROCESSES 1024

typedef struct {
    int pid;
    char comm[MAX_LINE];
    char state[2];
} Process;

void read_process_info(Process *proc, const char *path) {
    FILE *fp;
    char buffer[MAX_LINE];
    
    sprintf(buffer, "%s/stat", path);
    fp = fopen(buffer, "r");
    if (fp == NULL) {
        perror("Failed to open process file");
        return;
    }
    fscanf(fp, "%d %s %s", &proc->pid, proc->comm, proc->state);
    fclose(fp);
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;
    Process processes[MAX_PROCESSES];
    int count = 0;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Failed to open /proc directory");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                read_process_info(&processes[count], entry->d_name);
                count++;
                if (count >= MAX_PROCESSES) {
                    break;
                }
            }
        }
    }
    
    closedir(dir);
   
    printf("%-6s %-40s %-6s\n", "PID", "COMMAND", "STATE");
    printf("-------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-40s %-6s\n", processes[i].pid, processes[i].comm, processes[i].state);
    }
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    printf("Simple Process Viewer\n");
    printf("======================\n\n");
    
    list_processes();

    return 0;
}