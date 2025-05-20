//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

// Define a structure to hold process information
typedef struct {
    int pid;
    char comm[256];
    char state[16];
} ProcessInfo;

// Function to retrieve process information from /proc filesystem
void get_process_info(ProcessInfo *process) {
    char path[256];
    snprintf(path, sizeof(path), "/proc/%d/stat", process->pid);
    
    FILE *file = fopen(path, "r");
    if (file) {
        fscanf(file, "%d %s %s", &process->pid, process->comm, process->state);
        fclose(file);
    }
}

// Function to list all processes
void list_processes() {
    DIR *dir;
    struct dirent *entry;
    ProcessInfo process;

    if ((dir = opendir("/proc")) == NULL) {
        perror("Failed to open /proc directory");
        return;
    }

    printf("%-6s %-25s %-16s\n", "PID", "COMMAND", "STATE");
    printf("---------------------------------------------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Check if the directory name is a number (i.e., PID)
            if (isdigit(entry->d_name[0])) {
                process.pid = atoi(entry->d_name);
                get_process_info(&process);
                printf("%-6d %-25s %-16s\n", process.pid, process.comm, process.state);
            }
        }
    }

    closedir(dir);
}

int main() {
    printf("Exploring the realm of processes...\n\n");
    list_processes();
    
    printf("\nCuriosity quenched! Now you're aware of the processes running in your system.\n");
    return 0;
}