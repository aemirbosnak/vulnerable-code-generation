//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256
#define MAX_PROCESSES 1024

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    char state[BUFFER_SIZE];
} ProcessInfo;

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int read_process_info(int pid, ProcessInfo *proc) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
    
    FILE *file = fopen(path, "r");
    if (!file) {
        return -1; // Could not open the file
    }
    
    // Read the first few fields of /proc/<pid>/stat
    fscanf(file, "%d %s %s", &proc->pid, proc->name, proc->state);
    fclose(file);
    
    // Remove parentheses from the process name
    char *name_without_parentheses = strtok(proc->name, "()");
    if (name_without_parentheses != NULL) {
        strcpy(proc->name, name_without_parentheses);
    }
    
    return 0;
}

void display_processes() {
    DIR *dir;
    struct dirent *ent;
    ProcessInfo proc;

    dir = opendir("/proc");
    if (dir != NULL) {
        printf("%-10s %-25s %-10s\n", "PID", "Process Name", "State");
        printf("------------------------------------------\n");
        
        while ((ent = readdir(dir)) != NULL) {
            if (isdigit(ent->d_name[0])) { // Check if the name is a number (PID)
                int pid = atoi(ent->d_name);
                if (read_process_info(pid, &proc) == 0) {
                    printf("%-10d %-25s %-10s\n", proc.pid, proc.name, proc.state);
                }
            }
        }
        closedir(dir);
    } else {
        perror("Failed to open /proc directory");
    }
}

void handle_signals() {
    // Placeholder for signal handling if needed in the future
}

int main() {
    // Set up signal handlers if needed
    handle_signals();
    
    printf("Process Viewer\n");
    printf("============================\n");
    display_processes();
    
    return 0;
}